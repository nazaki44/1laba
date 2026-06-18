#include <Arduino.h>#include <Arduino.h>

// LED_BUILTIN - константа встроенного светодиода
#define LED_PIN LED_BUILTIN

void setup() {
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(115200); // Используем высокую скорость передачи
}

void loop() {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("LED ON");
    delay(1000);

    digitalWrite(LED_PIN, LOW);
    Serial.println("LED OFF");
    delay(1000);
}