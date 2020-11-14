# smart-garden-mini

Smart Garden Mini is a project that aims to build an auto watering system for home plants.

# Arduino Setup

## Setup

1. Download and install the Arduino IDE from the Arduino Home Page
2. Open Arduino IDE, go to File > Preferences
3. Enter https://dl.espressif.com/dl/package_esp32_index.json into the “Additional Board Manager URLs” field as shown in the figure below. Then, click the “OK” button:
4. Open the Boards Manager. Go to Tools > Board > Boards Manager…
5. Search for ESP32 and press install button for the “ESP32 by Espressif Systems“

## Testing the Installations

1. Select your Board in Tools > Choose ESP32 DEV
2. Select the Port in Tools (Please make sure you connected the ESP32 first)
3. Open any example under File > Examples > ESP32
4. Press the Upload button in the Arduino IDE. Wait and see whether it success
5. If everything went as expected, you should see a “Done uploading.” message.

# Project Setup

1. Find the Arduino Library folder, it usually located at the Document folder in your user folder
2. Copy all the libraries folder inside sg-mini-firmware-library
3. Paste all the libraries inside the Arduino Library folder
4. Then try to Verify the sg-mini-firmware.ino script
5. If no error related to the library dependencies, and it should be okay
