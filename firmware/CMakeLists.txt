cmake_minimum_required(VERSION 3.0)

set(PRJ_NAME exa_tim)
set(MCU_FAMILY STM32L0xx)
set(MCU_LINE STM32L071xx)
set(MCU_ARCH cortex-m0plus)
set(MCU_LINKER_SCRIPT "${CMAKE_CURRENT_SOURCE_DIR}/stm32_flash.ld")

# Set a default build type if none was specified
set(default_build_type "Release")
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
  set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
     STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
    "Debug" "Release")
endif()

# Add custom command to print firmware size in Berkley format
function(firmware_size target)
    add_custom_command(TARGET ${target} POST_BUILD
        COMMAND ${CMAKE_SIZE_UTIL} -B
        "${CMAKE_CURRENT_BINARY_DIR}/${target}"
    )
endfunction()

# Add a command to generate firmare in a provided format
function(generate_object target filename type)
    add_custom_command(TARGET ${target} POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -O${type}
        "${CMAKE_CURRENT_BINARY_DIR}/${target}" "${CMAKE_CURRENT_BINARY_DIR}/${filename}"
)
endfunction()

project(${PRJ_NAME} C ASM)
set(CMAKE_EXPORT_COMPILE_COMMANDS On)

add_definitions(-D${MCU_LINE} -DUSE_HAL_LIBRARY)

file(GLOB_RECURSE C_SOURCES Src/*.c)
file(GLOB_RECURSE AS_SOURCES Src/*.s)
file(GLOB_RECURSE RTT_SOURCES Middleware/RTT/*.c)
file(GLOB_RECURSE U8G2_SOURCES Middleware/u8g2/*.c)
file(GLOB_RECURSE HAL_SOURCES Drivers/${MCU_FAMILY}_HAL_Driver/Src/*.c)

set(SOURCE_FILES ${C_SOURCES} ${AS_SOURCES} ${RTT_SOURCES} ${U8G2_SOURCES} ${HAL_SOURCES})

include_directories(Drivers/CMSIS/Device/ST/${MCU_FAMILY}/Include)
include_directories(Drivers/CMSIS/Include)
include_directories(Drivers/${MCU_FAMILY}_HAL_Driver/Inc)
include_directories(Middleware/RTT)
include_directories(Middleware/u8g2)
include_directories(Inc)

add_executable(${PROJECT_NAME}.elf ${SOURCE_FILES})

set(CMAKE_EXE_LINKER_FLAGS "-specs=nano.specs -specs=nosys.specs -lc -lm -lnosys -T${MCU_LINKER_SCRIPT} -Wl,--gc-sections")
SET(CMAKE_ASM_FLAGS "-mcpu=${MCU_ARCH} -mthumb -fdata-sections -ffunction-sections -Wall")
SET(CMAKE_ASM_FLAGS_DEBUG "-Og -g -gdwarf-2")
SET(CMAKE_ASM_FLAGS_RELEASE "-Os -flto")
SET(CMAKE_C_FLAGS "-mcpu=${MCU_ARCH} -mthumb -fdata-sections -ffunction-sections -Wall")
SET(CMAKE_C_FLAGS_DEBUG "-Og -g -gdwarf-2")
SET(CMAKE_C_FLAGS_RELEASE "-Os -flto")

generate_object(${PROJECT_NAME}.elf ${PROJECT_NAME}.hex ihex)
generate_object(${PROJECT_NAME}.elf ${PROJECT_NAME}.bin binary)
firmware_size(${PROJECT_NAME}.elf)
