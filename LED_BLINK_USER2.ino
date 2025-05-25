#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

// LED Pin
#define led1 D1

// Wi-Fi Credentials
const char* wifiSSIDs[] = {"ssid1","ssid2"}; // List of SSIDs
const char* wifiPasswords[] = {"shraddha","canva$12"}; // Corresponding passwords
const int wifiCount = 2; // Number of Wi-Fi networks

// Adafruit IO Configuration
#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883
#define AIO_USERNAME    "naosano"            // Adafruit Username
#define AIO_KEY         "key" // Adafruit IO Key

// WiFi Client
WiFiClient client;

// MQTT Client
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

// Subscription for LED feed
Adafruit_MQTT_Subscribe Light1 = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/led01");

void connectWiFi();
void MQTT_connect();

void setup() {
  Serial.begin(115200);

  // Initialize LED
  pinMode(led1, OUTPUT);

  // Connect to Wi-Fi
  connectWiFi();

  // Subscribe to the LED feed
  mqtt.subscribe(&Light1);
}

void loop() {
  // Ensure MQTT connection
  MQTT_connect();

  // Check for updates
  Adafruit_MQTT_Subscribe *subscription;
  while ((subscription = mqtt.readSubscription(20000))) {
    if (subscription == &Light1) {
      Serial.print(F("Feed Update: "));
      Serial.println((char *)Light1.lastread);
      int Light1_State = atoi((char *)Light1.lastread);
      digitalWrite(led1, Light1_State); // Update LED based on input
    }
  }
}

void connectWiFi() {
  Serial.println("\nConnecting to WiFi...");
  for (int i = 0; i < wifiCount; i++) {
    Serial.print("Trying to connect to: ");
    Serial.println(wifiSSIDs[i]);
    WiFi.begin(wifiSSIDs[i], wifiPasswords[i]);

    // Wait for connection
    int attempts = 0;
    while (WiFi.status() != WL_CONNECTED && attempts < 20) { // Retry 20 times
      delay(500);
      Serial.print(".");
      attempts++;
    }

    if (WiFi.status() == WL_CONNECTED) {
      Serial.println("\nWiFi connected!");
      Serial.print("Connected to: ");
      Serial.println(wifiSSIDs[i]);
      Serial.print("IP address: ");
      Serial.println(WiFi.localIP());
      return;
    }
    Serial.println("\nFailed to connect to WiFi.");
  }

  Serial.println("No available WiFi networks. Restarting...");
  ESP.restart(); // Restart if no Wi-Fi connection is successful
}

void MQTT_connect() {
  int8_t ret;

  // Skip if already connected
  if (mqtt.connected()) {
    return;
  }

  Serial.print("Connecting to MQTT... ");
  uint8_t retries = 3;

  // Attempt to connect
  while ((ret = mqtt.connect()) != 0) {
    Serial.println(mqtt.connectErrorString(ret));
    Serial.println("Retrying MQTT connection in 5 seconds...");
    mqtt.disconnect();
    delay(5000);
    retries--;
    if (retries == 0) {
      while (1); // Halt on failure
    }
  }
  Serial.println("MQTT Connected!");
}