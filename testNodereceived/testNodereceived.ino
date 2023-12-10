
////////////////////////////////////////////////////////////
// receiver module
const int ledPin = 13;
String data = "";

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {

}

void serialEvent() {
  if (Serial.available()) 
  {
    char receivedChar = Serial.read();   // Đọc một byte dữ liệu từ cổng nối tiếp
    if (receivedChar != '#') 
    {          // Kiểm tra nếu chưa gặp ký tự kết thúc chuỗi
      data += receivedChar;  // Thêm ký tự vào bộ đệm
    } 
    else 
    {
      data += receivedChar;
      // Ký tự kết thúc chuỗi được nhận
      // Xử lý bộ đệm (ví dụ: in ra dữ liệu)
      // Reset bộ đệm
      data.trim();
      if (data == "LED_ON#") 
      {
        digitalWrite(ledPin, HIGH);
      } 
      else if (data == "LED_OFF#") 
      {
        digitalWrite(ledPin, LOW);
      }
      data = "";
    }
  }
}

