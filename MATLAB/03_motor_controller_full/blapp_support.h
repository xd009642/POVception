#ifndef __BL_APP_SUPPORT_H__
#define __BL_APP_SUPPORT_H__

#include "stm32f4xx.h"



#define ADDR_RAM_MSG_VALIDATION (0x20000000)
#define VAL_RAM_MSG_VALIDATION	(0x02233445)
#define ADDR_MEM_SERVICE_FCN  	(0x20000004)
#define ADDR_APP_COMMAND1		(0x20000008)
#define	VAL_APP_COMMAND1		(0x0000DEAD)
#define ADDR_APP_COMMAND2		(0x2000000C)
#define VAL_APP_COMMAND2		(0x0000FEED)


#define ADDR_ROM_APP_ComCtrl	(0x080043F8)//(1k-8)
#define VAL_ROM_APP_ComCtrl_BL	(0x0000BBBB)
#define VAL_ROM_APP_ComCtrl_APP	(0x0000AAAA)
#define VAL_ROM_APP_ComCtrl_NA	(0x0000FFFF)

#define ADDR_ROM_P2LAST			(0x080043FC) //(1k-4)
#define VAL_ROM_LAST			(0x0000FACE)

#define ADDR_UART_CONFIG		(0x20000018)
#define ADDR_UART_ISR			(0x2000001C)
#define ADDR_UART_IDLETASK		(0x20000020)




 extern uint8_t OkforMemServ;


 void bootloaderInit(void); 
 void Error_Handler(void);
 void bootloaderBackgroundTask(void);

#endif