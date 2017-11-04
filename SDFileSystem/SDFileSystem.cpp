/* SD/MMC File System Library
 * Copyright (c) 2016 Neil Thiessen
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "SDFileSystem.h"
#include "diskio.h"
#include "pinmap.h"
#include "SDCRC.h"

SDFileSystem::SDFileSystem(const char* name)
    : FATFileSystem(name)
{
    //Initialize the member variables
    m_CardType = CARD_NONE;
    m_LargeFrames = false;
    m_WriteValidation = true;
    m_Status = STA_NOINIT;
    sd.Init();
} 

bool SDFileSystem::card_present()
{
    //Check the card socket
    checkSocket();

    //Return whether or not a card is present
    return !(m_Status & STA_NODISK);
}

SDFileSystem::CardType SDFileSystem::card_type()
{
    //Check the card socket
    checkSocket();

    //Return the card type
    return m_CardType;
}


bool SDFileSystem::large_frames()
{
    //Return whether or not 16-bit frames are enabled
    return m_LargeFrames;
}

void SDFileSystem::large_frames(bool enabled)
{
    //Set whether or not 16-bit frames are enabled
    m_LargeFrames = enabled;
}

bool SDFileSystem::write_validation()
{
    //Return whether or not write validation is enabled
    return m_WriteValidation;
}

void SDFileSystem::write_validation(bool enabled)
{
    //Set whether or not write validation is enabled
    m_WriteValidation = enabled;
}

int SDFileSystem::unmount()
{
    //Unmount the filesystem
    FATFileSystem::unmount();
    sd.DeInit();
    //Change the status to not initialized, and the card type to unknown
    m_Status |= STA_NOINIT;
    m_CardType = CARD_UNKNOWN;

    //Always succeeds
    return 0;
}

int SDFileSystem::disk_initialize()
{
    //Make sure there's a card in the socket before proceeding
    checkSocket();
    if (m_Status & STA_NODISK)
        return m_Status;

    //Make sure we're not already initialized before proceeding
    if (!(m_Status & STA_NOINIT))
        return m_Status;

    if(MSD_OK == sd.Init())
    {
        HAL_SD_CardInfoTypeDef info;
        sd.GetCardInfo(&info);
        //The card is now initialized
        m_Status &= ~STA_NOINIT;
        m_CardType =static_cast<SDFileSystem::CardType>( info.CardType);
        // Card connected cause got this far. But type not supported.
        if(m_CardType > CARD_MMC) {
            m_CardType = CARD_UNKNOWN;
        }
    }
    //Return the disk status
    return m_Status;
}

int SDFileSystem::disk_status()
{
    //Check the card socket
    checkSocket();

    //Return the disk status
    return m_Status;
}

int SDFileSystem::disk_read(uint8_t* buffer, uint32_t sector, uint32_t count)
{
    //Make sure the card is initialized before proceeding
    if (m_Status & STA_NOINIT)
        return RES_NOTRDY;

    //Read a single block, or multiple blocks
    if (count > 1) {
        return readBlocks((char*)buffer, sector, count) ? RES_OK : RES_ERROR;
    } else {
        return readBlock((char*)buffer, sector) ? RES_OK : RES_ERROR;
    }
}

int SDFileSystem::disk_write(const uint8_t* buffer, uint32_t sector, uint32_t count)
{
    //Make sure the card is initialized before proceeding
    if (m_Status & STA_NOINIT)
        return RES_NOTRDY;

    //Make sure the card isn't write protected before proceeding
    if (m_Status & STA_PROTECT)
        return RES_WRPRT;

    //Write a single block, or multiple blocks
    if (count > 1) {
        return writeBlocks((const char*)buffer, sector, count) ? RES_OK : RES_ERROR;
    } else {
        return writeBlock((const char*)buffer, sector) ? RES_OK : RES_ERROR;
    }
}

int SDFileSystem::disk_sync()
{
    //Select the card so we're forced to wait for the end of any internal write processes
    
    if (waitReady(2000)) {
        return RES_OK;
    } 
    return RES_ERROR;
}

uint32_t SDFileSystem::disk_sectors()
{
    //Make sure the card is initialized before proceeding
    if (m_Status & STA_NOINIT)
        return 0;

    //Try to read the CSD register up to 3 times
    HAL_SD_CardInfoTypeDef info;
    sd.GetCardInfo(&info);
    return info.LogBlockNbr;
}

void SDFileSystem::onCardRemoval()
{
    //Check the card socket
    checkSocket();
}

inline void SDFileSystem::checkSocket()
{
    //Use the card detect switch (if available) to determine if the socket is occupied
    if(sd.IsDetected()) 
    {
        m_Status &= ~STA_NODISK;
        if(m_CardType == CARD_NONE)
        {
            m_CardType = CARD_UNKNOWN;
        }
    }
    else
    {
        m_Status |= (STA_NODISK | STA_NOINIT);
        m_CardType = CARD_NONE;
    }
}

inline bool SDFileSystem::waitReady(int timeout)
{
    uint8_t resp;

    //Keep sending dummy clocks with DI held high until the card releases the DO line
    m_Timer.start();
    do {
        sd.GetCardState();
    } while (resp == SD_TRANSFER_BUSY && m_Timer.read_ms() < timeout);
    m_Timer.stop();
    m_Timer.reset();

    //Return success/failure
    return (resp != SD_TRANSFER_BUSY);
}





inline bool SDFileSystem::readBlock(char* buffer, unsigned int lba)
{
    return readBlocks(buffer, lba, 1);
}

inline bool SDFileSystem::readBlocks(char* buffer, unsigned int lba, unsigned int count)
{
    //Try to read each block up to 3 times
    for (int f = 0; f < 3;) {
        if(MSD_OK == sd.ReadBlocks_DMA((uint32_t*)buffer, lba, count))
        {
            return true;
        }
    }
    //The multiple block read failed
    return false;
}

inline bool SDFileSystem::writeBlock(const char* buffer, unsigned int lba)
{
    return writeBlocks(buffer, lba, 1);
}

inline bool SDFileSystem::writeBlocks(const char* buffer, unsigned int lba, unsigned int count)
{
    //Try to write each block up to 3 times
    for (int f = 0; f < 3;) {
        if(MSD_OK == sd.WriteBlocks_DMA((uint32_t*)buffer, lba, count))
        {
            return true;
        }
    }
    //The multiple block write failed
    return false;
}

