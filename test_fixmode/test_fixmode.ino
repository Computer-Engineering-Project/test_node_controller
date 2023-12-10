#include <Arduino.h>

const int buttonPin = 10;
const uint16_t ADDRESS = 0x0102;
const uint8_t CHANNEL = 0x17;
const char led_on[] = "LED_ON#";
const char led_off[] = "LED_OFF#";

struct Data {
  uint16_t address;
  uint8_t channel;
  char data[]; // Flexible array member
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
      // Send LED ON command
      size_t dataSize = strlen(led_on); // Include null terminator
      Data* data = (Data*)malloc(sizeof(Data) + dataSize);
      data->address = ADDRESS;
      data->channel = CHANNEL;
      strcpy(data->data, led_on);

      // Serialize the struct into a byte array
      Serial.write((uint8_t*)data, sizeof(Data) + dataSize);

      // Free dynamically allocated memory
      free(data);

    } else if (state == LOW) {
      // Send LED OFF command
      size_t dataSize = strlen(led_off); // Include null terminator
      Data* data = (Data*)malloc(sizeof(Data) + dataSize);
      data->address = ADDRESS;
      data->channel = CHANNEL;
      strcpy(data->data, led_off);

      // Serialize the struct into a byte array
      Serial.write((uint8_t*)data, sizeof(Data) + dataSize);

      // Free dynamically allocated memory
      free(data);
    }
    pre_state = state;
    delay(10000);
  }
}
