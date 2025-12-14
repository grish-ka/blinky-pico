cmake_minimum_required(VERSION 3.13)

# Initialize the SDK
include(pico_sdk_import.cmake)

project(blink_project C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the Pico SDK
pico_sdk_init()

# Add your executable (source file)
add_executable(blink
    blink.c
)

pico_enable_stdio_usb(blink 1)
pico_enable_stdio_uart(blink 0)

# Link the SDK libraries (stdlib allows use of sleep and gpio)
target_link_libraries(blink pico_stdlib)

# THIS generates the .uf2 file!
pico_add_extra_outputs(blink)

