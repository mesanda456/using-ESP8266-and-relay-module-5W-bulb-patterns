#include <ESP8266WiFi.h>

// Wi-Fi credentials
const char* ssid = "youer wifi name ";
const char* password = "youer wifi password";

// Relay pins connected to D4, D5, D6, D7
const int pins[] = {2, 14, 12, 13};  // GPIO2 (D4), GPIO14 (D5), GPIO12 (D6), GPIO13 (D7)
const int pinCount = sizeof(pins) / sizeof(pins[0]);

#define on LOW   // Active-low relay modules
#define off HIGH

int delayTime = 100; // Delay in milliseconds

void setup() {
  Serial.begin(115200);

  // Wi-Fi connection
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Setup relay pins
  for (int i = 0; i < pinCount; i++) {
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i], off);  // Turn all off at start
  }
}

void loop() {
  P1(1); delay(500);
  P2(1); delay(500);
  P3(1); delay(500);
  P4(1); delay(500);
  P5(1); delay(500);
  P6(1); delay(500);
  color(3); delay(500);
}

void color(int loopCount) {
  for (int j = 0; j < loopCount; j++) {
    for (int i = 0; i < pinCount; i++) {
      digitalWrite(pins[i], on);
      delay(delayTime);
      digitalWrite(pins[i], off);
    }
  }
}

void P1(int loopCount) {
  for (int j = 0; j < loopCount; j++) {
    digitalWrite(pins[0], on);
    digitalWrite(pins[pinCount - 1], on);
    delay(delayTime);
    digitalWrite(pins[0], off);
    digitalWrite(pins[pinCount - 1], off);
    delay(delayTime);
  }
}

void P2(int loopCount) {
  for (int j = 0; j < loopCount; j++) {
    for (int i = 0; i < pinCount; i++) {
      digitalWrite(pins[i], on);
      delay(delayTime);
      digitalWrite(pins[i], off);
    }
  }
}

void P3(int loopCount) {
  for (int j = 0; j < loopCount; j++) {
    for (int i = pinCount - 1; i >= 0; i--) {
      digitalWrite(pins[i], on);
      delay(delayTime);
      digitalWrite(pins[i], off);
    }
  }
}

void P4(int loopCount) {
  for (int j = 0; j < loopCount; j++) {
    for (int i = 0; i < pinCount; i++) {
      digitalWrite(pins[i], on);
      delay(delayTime);
    }
    for (int i = 0; i < pinCount; i++) {
      digitalWrite(pins[i], off);
      delay(delayTime);
    }
  }
}

void P5(int loopCount) {
  for (int j = 0; j < loopCount; j++) {
    for (int i = pinCount - 1; i >= 0; i--) {
      digitalWrite(pins[i], on);
      delay(delayTime);
    }
    for (int i = pinCount - 1; i >= 0; i--) {
      digitalWrite(pins[i], off);
      delay(delayTime);
    }
  }
}

void P6(int loopCount) {
  for (int j = 0; j < loopCount; j++) {
    for (int i = 0; i < pinCount; i++) {
      digitalWrite(pins[i], on);
    }
    delay(delayTime);
    for (int i = 0; i < pinCount; i++) {
      digitalWrite(pins[i], off);
    }
    delay(delayTime);
  }
}