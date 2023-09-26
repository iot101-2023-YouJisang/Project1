#include <Arduino.h>
#include <SSD1306.h>
SSD1306         display(0x3c, 4, 5, GEOMETRY_128_32);

float y = 0;
int alpha = 0.5;
int val = 0; // AD 변환값을 저장할 변수
void setup() {
 Serial.begin(115200);
 display.init();
 display.flipScreenVertically();
 display.setFont(ArialMT_Plain_16);
 //display.drawString(1, 1, "Hello World"); (좌우 위치, 위아래 위치, 넣을 문장)
 //display.display();
}
void loop()
{
 val = analogRead(0); // 아날로그 0번 핀 (VR) 값을 입력
 Serial.println(val);
 y = val*0.5+(1-0.5)*y;  // alpha = 0.5, x = 현재값)
 display.drawString(1, 1, "Brightness :");
 display.drawString(1, 14, "y :");
 display.drawString(85, 1, (String)val); 
 display.drawString(20, 15, (String)y);
 display.display();
 delay(1000);
 display.clear();

}