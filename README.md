# 💡 IoT-Based Voice-Controlled LED System using ESP8266, MQTT, Adafruit IO, and Google Assistant

This project lets you control an LED **with your voice** using **Google Assistant**. The system uses **ESP8266** with **MQTT protocol**, and bridges Google Assistant to the ESP8266 via **Adafruit IO** and **IFTTT**. It’s a fun and practical example of IoT + smart home integration.

---

## 🚀 System Architecture

```text
Google Assistant
     ⬇
   IFTTT Webhook
     ⬇
 Adafruit IO Feed (MQTT Broker)
     ⬇
   ESP8266 (Subscribes to Feed)
     ⬇
   LED (ON/OFF)

🔧 Hardware Requirements
ESP8266 NodeMCU

1x LED

1x 220Ω resistor

Jumper wires + breadboard

Wi-Fi connection

🔌 Circuit Diagram (Text Overview)

ESP8266 GPIO (D1) → Resistor (220Ω) → LED (Anode)
LED (Cathode) → GND

🧠 How It Works
ESP8266 connects to Wi-Fi and subscribes to an Adafruit IO feed.

IFTTT listens for voice commands via Google Assistant.

When triggered, IFTTT sends a value (ON or OFF) to Adafruit IO.

The ESP8266 receives that value and turns the LED ON or OFF.

📄 Arduino File
LED_BLINK_USER2.ino: Contains the full implementation.

Replace the following:

Your Wi-Fi SSID and password

Adafruit IO username

Adafruit IO AIO Key

Your feed name (e.g., voice-led)

🛠 Libraries Required
Make sure you install the following in Arduino IDE:

ESP8266 board support (via Boards Manager)

WiFi.h

Adafruit_MQTT.h

Adafruit_MQTT_Client.h

🎤 Sample Voice Commands (via IFTTT)
“Hey Google, turn on the LED”

“Hey Google, turn off the LED”

Each command triggers an IFTTT applet that updates your Adafruit IO feed.

🧪 IFTTT Configuration
Trigger: Google Assistant → Say a phrase

Action: Webhooks → Send data to Adafruit IO

URL: https://io.adafruit.com/api/v2/<USERNAME>/feeds/<FEED_NAME>/data

Method: POST

Body: value=ON or value=OFF

Headers: Content-Type: application/x-www-form-urlencoded

Add your AIO Key in the IFTTT Webhook setup

💡 Real-World Use Cases
Home automation (lights, fans)

Voice-controlled gadgets

IoT learning projects

🤝 Credits
Made with ❤️ by Arti Shelar
