# EXA_tim

EXA_tim is a wristwatch that uses GNSS for time synchronization.

![EXA_tim PCB front](images/PCB-front.png?raw=true)
![EXA_tim case](images/case.png?raw=true)

# Features

- 32bit STM32L0 MCU
- GNSS time synchronization (UTC)
- 1.54 inch e-paper display
- 4 buttons
- CR2032 battery

Currently we are aiming for 2-3 months of operation with one battery.

# Case

The case is designed in Fusion 360 and can be viewed here:
https://a360.co/2LLzCpt

A current snapshot is included in the source repository.

The case is designed to be 3D printable and uses a NATO strap.

If you want to 3D print them, you need to either use Fusion 360 or
FreeCAD to export the three components as STL files.

I printed them in PLA and PETG with good results. Low warp material
hightly recommended, since dimensional accuracy is key.

I designed the parts for a printer that can handle 0.1 mm clearance.
If you need looser clearance, please change the Fusion 360 user
variable "Clearance" for your needed value.

# Firmware

The firmware uses the STM32 HAL. It can be build by either using make
and a compatible GCC toolchain (I use the official gcc arm branch) or
by using Atollic TrueStudio.

You can build the firmeware image by specifying the path of the GCC
compiler and calling make in the firmware folder:

```bash
cd firmware
GCC_PATH=/opt/gcc-arm-none-eabi-7-2018-q2-update/bin make
```

# License

The hardware components (case and PCB) are licensed under CERN Open Hardware Licence v1.2
The software components (firmware) are licensed under GPLv3.

The pcb/packages3d files are excluded from these license.
