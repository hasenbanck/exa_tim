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

The firmware uses the STM32 HAL. It can be build by either using cmake
with the ARM GCC toolchain or by using Atollic TrueStudio.

For the CMAKE build, you need to provide the ARM GCC toolchain in the
PATH of your system. You can choose any CMAKE target that you like
to use. I personaly use ninja.

```bash
mkdir -p firmware/build
cd firmware/build
cmake -DCMAKE_TOOLCHAIN_FILE=arm-gcc-toolchain.cmake -DCMAKE_BUILD_TYPE=Release -G Ninja ../
ninja
```

You can change ```-DCMAKE_BUILD_TYPE=Debug``` to produce debug build.

# Flashing

To programm the watch we are using the 10 pin 1.27mm (0.05") Cortex Debug
header. You need a programmer that can programm an ARM using the SWD
protocol.

A ST-Link V2 (and it's clones), a JLink (mini) or a blackmagic programmer
should work fine.

We included a OpenOCD file as an example how to programm the firmware.

You can also use any available flashing software available. For example:
 - OpenOCD
 - STM32CubeProgrammer
 - STM32 ST-Link utility
 - Segger J-Link JFlash (lite)

# License

The hardware components (case and PCB) are licensed under the CERN Open
Hardware Licence v1.2

The software components (firmware) are licensed under GPLv3.

The pcb/packages3d files are excluded from these license.
