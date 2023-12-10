#include <Arduino.h>



const int buttonPin = 10;
const int MAXLENGTH = 60;
const uint16_t ADDRESS = 0x0102;
const uint8_t CHANNEL = 0x17;

struct Data {
  uint16_t address;
  uint8_t channel;
  char *data;
};

int state;
int pre_state;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  state = 0;
  pre_state = 0;
}

void loop() {
  state = digitalRead(buttonPin);
  if (state != pre_state) {
    if (state == HIGH) {
      Serial.print("LED_ON#");

    } else if (state == LOW) {
      // Serialize the struct into a byte array
      Serial.print("LED_OFF#");
    }
    pre_state = state;
    delay(5000);
  }
}
