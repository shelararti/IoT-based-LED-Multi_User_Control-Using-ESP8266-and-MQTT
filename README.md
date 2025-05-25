# 💡 Voice-Controlled LED System using ESP8266, MQTT, Adafruit IO & Google Assistant

This IoT project allows you to control an LED **with your voice** using **Google Assistant**. It integrates **ESP8266**, **Adafruit IO**, **IFTTT**, and the **MQTT protocol** to build a smart, voice-responsive system.

---

## 🚀 System Architecture

Google Assistant
↓
IFTTT Webhook
↓
Adafruit IO (MQTT Broker)
↓
ESP8266 (MQTT Client)
↓
LED (ON/OFF)

## 🔧 Hardware Requirements

- ESP8266 NodeMCU
- 1× LED
- 1× 220Ω Resistor
- Breadboard + Jumper wires
- Stable Wi-Fi connection

---

## 🔌 Circuit Diagram (Textual Overview)

ESP8266 GPIO (D1) → 220Ω Resistor → LED (Anode)

LED (Cathode) → GND


---

## 🧠 How It Works

1. ESP8266 connects to your Wi-Fi and subscribes to a specific Adafruit IO MQTT feed.
2. Google Assistant listens to your voice commands.
3. IFTTT intercepts these commands and sends a webhook to Adafruit IO.
4. Adafruit IO updates the MQTT feed with a value (`ON` or `OFF`).
5. ESP8266 reads this value and toggles the LED accordingly.

---

## 📄 Arduino Code

Upload the `Main.ino` file using Arduino IDE.

### 🔧 Replace the following in the sketch:

- Your Wi-Fi SSID and Password
- Your Adafruit IO Username
- Your Adafruit IO AIO Key
- Your Feed Name (e.g., `voice-led`)

---

## 🛠 Required Libraries

Install the following via Arduino IDE:

- ESP8266 Board (via Boards Manager)
- `WiFi.h`
- `Adafruit_MQTT.h`
- `Adafruit_MQTT_Client.h`

---

## 🎤 Voice Commands (Via IFTTT)

- “Hey Google, turn on the LED”
- “Hey Google, turn off the LED”

Each command triggers a corresponding IFTTT applet.

---

## ⚙️ IFTTT Configuration

1. **Trigger**  
   - Service: Google Assistant  
   - Event: Say a simple phrase  

2. **Action**  
   - Service: Webhooks  
   - URL: `https://io.adafruit.com/api/v2/<USERNAME>/feeds/<FEED_NAME>/data`  
   - Method: `POST`  
   - Content-Type: `application/x-www-form-urlencoded`  
   - Body: `value=ON` or `value=OFF`  

3. **Authentication**  
   - Add your **Adafruit IO AIO Key** in the webhook header.

---

## 💡 Use Cases

- Smart home lighting control
- Voice-activated gadgets
- IoT learning and prototyping
- Accessible tech solutions

---


## 🤝 Credits

Made with ❤️ by **Arti Shelar and Team**

---

## 📜 License

This project is open-source and free to use under the MIT License.
