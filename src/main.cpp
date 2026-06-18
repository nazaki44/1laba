#include <Arduino.h>

// разные платы
#if defined(BOARD_UNO_R4)
  #define BUTTON_PIN 2
  #define LED_PIN LED_BUILTIN
#elif defined(BOARD_ESP32)
  #define BUTTON_PIN 0
  #define LED_PIN 2
#else
  #define BUTTON_PIN 2
  #define LED_PIN LED_BUILTIN
#endif

bool ledState = false;
bool lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
    Serial.begin(115200);
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(LED_PIN, OUTPUT);
    Serial.println("System started. Press button to toggle LED.");
}

void loop() {
    bool currentButtonState = digitalRead(BUTTON_PIN);

    if (currentButtonState != lastButtonState) {
        lastDebounceTime = millis();
    }

    if ((millis() - lastDebounceTime) > debounceDelay) {
        if (currentButtonState == LOW && lastButtonState == HIGH) {
            ledState = !ledState;
            digitalWrite(LED_PIN, ledState);
            Serial.println(ledState ? "LED ON" : "LED OFF");
        }
    }

    lastButtonState = currentButtonState;
}