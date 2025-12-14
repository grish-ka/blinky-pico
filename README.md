# blinky-pico

A C-based firmware for the Raspberry Pi Pico that blinks the LED and prints to the USB Serial console.

## 📂 Project Structure

```text
blinky-pico/
├── LICENSE
├── README.md               # This documentation
└── src/
    ├── blink.c             # Source code
    ├── CMakeLists.txt      # Build configuration
    └── pico_sdk_import.cmake
```

---

## ⚡ Quick Start

**Prerequisites:** Pico SDK, ARM Toolchain, Screen.

### 1. Build the Firmware

```bash
# 1. Enter the source directory
cd src

# 2. Create and enter build directory
mkdir build
cd build

# 3. Configure and Compile
cmake ..
make
```

### 2. Flash the Pico
1.  Unplug the Pico.
2.  Hold the **BOOTSEL** button.
3.  Plug the Pico in via USB (keep holding until drive appears).
4.  Drag and drop `src/build/blink.uf2` onto the `RPI-RP2` drive.

---

## 🖥️ Serial Monitor Usage

To see the "Hello World" output:

### 1. Install Screen
```bash
sudo apt update
sudo apt install screen
```

### 2. Connect
```bash
# Connect at 115200 baud
sudo screen /dev/ttyACM0 115200
```
*(Exit screen: Press `Ctrl+A`, then `k`, then `y`)*

---

## 🛠 Detailed Setup (Prerequisites)

If this is your first time (Linux/Raspberry Pi OS):

### 1. Install Toolchain
```bash
sudo apt update
sudo apt install cmake gcc-arm-none-eabi libnewlib-arm-none-eabi build-essential
```

### 2. Install Pico SDK
```bash
mkdir -p ~/.sdks
cd ~/.sdks
git clone [https://github.com/raspberrypi/pico-sdk.git](https://github.com/raspberrypi/pico-sdk.git)
cd pico-sdk
git submodule update --init
```

### 3. Set Environment Variable
```bash
echo 'export PICO_SDK_PATH=~/.sdks/pico-sdk' >> ~/.bashrc
source ~/.bashrc
```

---

## 🚑 Troubleshooting

**"Directory not found"** or **Cache Errors**:
If you move the project or update the SDK path, clear the cache:
```bash
cd src/build
rm -rf *
cmake ..
make
```

**"Screen not found"**:
Run `sudo apt install screen`.

**No device `/dev/ttyACM0`**:
Ensure you have added `pico_enable_stdio_usb(blink 1)` to your `CMakeLists.txt` and re-flashed the board.