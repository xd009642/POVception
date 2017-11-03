# Christmas challenge 2017

Repo for 2017 Christmas Engineering challenge using a STM32F469 MCU.

# Building the project

This project assumes you have GNU Make gcc-arm-eabi and st-flash (1.4). You can find st-flash as part of [st-link](https://github.com/texane/stlink)

To build the project and program the board in one go run the following command:
```
make flash
```
## Autogenerating code

Bitmaps can only be rendered if stored in internal flash using the STM32 HAL. With this in mind if you have python and xxd on your system path the python codegen script will replace `src/background.h`. However, use RGB565 as an export. Bitmaps are wide and varied and the STM32 HAL seems to have trouble supporting RGB888 and ARGB8888

## Links and Resources

* [Dev board](https://www.st.com/en/evaluation-tools/32f469idiscovery.html)
