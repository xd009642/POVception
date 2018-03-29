# POVception

Repo for 2017 Christmas Engineering challenge entry "POVception" using a STM32F469 MCU. This challenge was 
undertaken over 2-3 months with the aim of creating something truly unique. We settled on a dual ring 
Persistence-Of-Vision display with one ring inside the other and the rings counter-rotating. The 
POVception also has two single joysticks for users to interact with applications.

Included with the code is the following applications which can be triggered via the touchscreen display:

* Pong (with snow effect on outer ring)
* Image of the globe (with snow on outer ring)
* Bauble 
* Calibration - set the vertical origin for both globes.

As the challenged required usage of MathWorks Simulink<sup>&reg;</sup> Simulink is used for the motor control,
from simulink we generated C which was called from the application. The rest of the application is written in
C++ as Simulink didn't seem a suitable choice for creating the software rendering implementation for the rings
and BSP support for the board wasn't as good as offered by mbed which was a big consideration given the time
constraints of the challenge.

# Building the project

This project assumes you have GNU Make gcc-arm-eabi and st-flash (1.4). You can find st-flash as part of [st-link](https://github.com/texane/stlink)

To build the project and program the board in one go run the following command:
```
make flash
```
## Debugging

Easiest way to debug the board is using `st-util` to launch a debugging server and connect to that with gdb. If you don't want to use `st-util` an OpenOCD config file is included. Consult the relevant documentation for more guidance.

## Autogenerating code

Bitmaps can only be rendered if stored in internal flash using the STM32 HAL. With this in mind if you have python and xxd on your system path the python codegen script will replace `src/background.h`. However, use RGB565 as an export. Bitmaps are wide and varied and the STM32 HAL seems to have trouble supporting RGB888 and ARGB8888

## Video

Here you can see a video of the project in action with an explanation.

[![POVception](https://img.youtube.com/vi/aDJjjcXbvNg/0.jpg)](https://www.youtube.com/watch?v=aDJjjcXbvNg "POVception - Dual counter rotating persistence of vision display")

## Links and Resources

* [Dev board](https://www.st.com/en/evaluation-tools/32f469idiscovery.html)
