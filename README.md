# blinky-pico

A minimal C-based firmware to blink the onboard LED of a Raspberry Pi Pico.

## 📂 Project Structure

Ensure your project looks like this before running the build commands:

```text
blinky-pico/
├── src/
│   └── blink.c             # The main C source code
├── CMakeLists.txt          # The build configuration file
├── pico_sdk_import.cmake   # Copied from the SDK (See Setup below)
├── README.md               # This documentation file
└── .gitignore              # Git configuration (See Reference below)
```

---

## ⚡ Quick Start

**Prerequisites:** You must have the **Pico SDK** and **ARM Toolchain** installed.

### 1. Build the Firmware
Run the following commands in your terminal:

```bash
# Create the build directory
mkdir build
cd build

# Configure the project (generates Makefiles)
cmake ..

# Compile the code
make
```

### 2. Flash the Pico
1.  **Unplug** the Pico from your computer.
2.  Hold down the white **BOOTSEL** button.
3.  **Plug** the Pico in via USB (keep holding until the drive appears).
4.  **Drag and drop** the file `build/blink.uf2` onto the `RPI-RP2` drive.

---

## 🛠 Detailed Setup Guide (Prerequisites)

If you are setting up your environment for the first time (Linux/Raspberry Pi OS), follow these steps.

### Step 1: Install the Toolchain
You need `cmake` to manage the build and `gcc-arm-none-eabi` to compile the code.

```bash
sudo apt update
sudo apt install cmake gcc-arm-none-eabi libnewlib-arm-none-eabi build-essential
```

### Step 2: Download the Pico SDK
We recommend storing the SDK in a hidden folder in your home directory so it stays organized.

```bash
# Create a folder for SDKs
mkdir -p ~/.sdks
cd ~/.sdks

# Clone the SDK repository
git clone [https://github.com/raspberrypi/pico-sdk.git](https://github.com/raspberrypi/pico-sdk.git)

# Enter the folder and initialize submodules (CRITICAL STEP)
cd pico-sdk
git submodule update --init
```

### Step 3: Set the Environment Variable
Your computer needs to know where the SDK is located.

1.  Open your bash configuration: `nano ~/.bashrc`
2.  Add this line to the very bottom:
    ```bash
    export PICO_SDK_PATH=~/.sdks/pico-sdk
    ```
3.  Reload the configuration: `source ~/.bashrc`

### Step 4: Import the CMake Helper
Your project needs the `pico_sdk_import.cmake` file.
1.  Navigate to `~/.sdks/pico-sdk/external/`.
2.  Copy `pico_sdk_import.cmake`.
3.  Paste it into your project root folder (next to `CMakeLists.txt`).

---

## 🚑 Troubleshooting

### "Directory not found" or Cache Errors
If you move your SDK or change your environment variable, CMake might remember the old path and fail.

**The Fix:** Clear the build cache and re-run configuration.

```bash
cd build
rm -rf *
cmake ..
make
```

---

## 📝 Reference: .gitignore Content

To keep your repository clean, your `.gitignore` file should contain the following:

```gitignore
# Build artifacts (do not upload these)
build/
*.uf2
*.elf
*.map
*.hex
*.bin

# CMake generated files
CMakeFiles/
CMakeCache.txt
cmake_install.cmake
Makefile
*.ninja

# IDE settings
.vscode/
.idea/

# Python cache
__pycache__/
*.py[cod]
```