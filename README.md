# blinky-pico

A C-based firmware for the Raspberry Pi Pico that translates text input from USB Serial into Morse Code sequences on the onboard LED.

## 📂 Project Structure

```text
blinky-pico/
├── LICENSE
├── README.md               # This documentation
└── src/
    ├── blink.c             # Source code (Morse Logic)
    ├── CMakeLists.txt      # Build configuration
    └── pico_sdk_import.cmake
```

---

## ⚡ Quick Start

**Prerequisites:** Pico SDK, ARM Toolchain, Screen.

### 1. Build the Firmware

Because the source code is inside the `src` folder, we build there.

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
3.  Plug the Pico in via USB (keep holding until the drive appears).
4.  Drag and drop the file `src/build/blink.uf2` onto the `RPI-RP2` drive.

---

## 🖥️ Usage (Serial to Morse)

1.  **Install Screen** (if not installed):
    ```bash
    sudo apt update
    sudo apt install screen
    ```

2.  **Connect to the Pico:**
    ```bash
    # Connect to the first USB serial device at 115200 baud
    sudo screen /dev/ttyACM0 115200
    ```

3.  **Translate Text:**
    * Type any letter (A-Z) or number (0-9) and press **Enter** (or Space).
    * The character will echo to the terminal.
    * The onboard LED will blink the corresponding Morse code pattern.
    * *(To exit screen: Press `Ctrl+A`, then `k`, then `y`)*

---

## 🛠 Detailed Setup (Prerequisites)

If this is your first time setting up the Pico environment (Linux/Raspberry Pi OS):

### 1. Install Toolchain & Utilities
```bash
sudo apt update
sudo apt install cmake gcc-arm-none-eabi libnewlib-arm-none-eabi build-essential screen
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
Add the SDK path to your bash configuration:
```bash
echo 'export PICO_SDK_PATH=~/.sdks/pico-sdk' >> ~/.bashrc
source ~/.bashrc
```

---

## 🚑 Troubleshooting

**"Directory not found"** or **Cache Errors**:
If you move the project or update the SDK path, CMake might fail. Clear the cache:
```bash
cd src/build
rm -rf *
cmake ..
make
```

**"Screen not found"**:
Run `sudo apt install screen`.

**No device `/dev/ttyACM0`**:
Ensure you have added `pico_enable_stdio_usb(blink 1)` to your `src/CMakeLists.txt` and re-flashed the board.

**Can't see what I type**:
Ensure you have flashed the latest version of the code that includes `putchar(c)` to echo characters back to the terminal.

---

## 📝 Reference: .gitignore

To keep your repository clean, ensure your `.gitignore` file includes:

```gitignore
build/
*.uf2
*.elf
.vscode/
```