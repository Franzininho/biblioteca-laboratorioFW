/********************************-******************
  Controle o caractere . no display oled utilizando
  o módulo joystick.
  
  Links das bibliotecas externas:
  * SSD1306Wire -> https://github.com/ThingPulse/esp8266-oled-ssd1306
  
  Desenvolvido por Letícia P Garcez - 03/2023
 ****************************************************/

#include <laboratorioFW.h>
#include <Wire.h>
#include <SSD1306Wire.h>

#define x B_1
#define y B_0
#define btn D_8

SSD1306Wire display(0x3c, C_0, C_1);  // ADDRESS, SDA, SCL

void setup() {
  display.init();
  display.flipScreenVertically();
  display.mirrorScreen();
  display.setContrast(255);
  pinMode(x, INPUT);
  pinMode(y, INPUT);
  pinMode(btn, INPUT);
}

bool normal = true;

void loop() {
  if (digitalRead(btn)) {
    normal ? display.invertDisplay() : display.normalDisplay();
    normal = !normal;
  }
  
  int xMapeado = map(analogRead(x), 0, 8191, 0, 124);
  int yMapeado = map(analogRead(y), 0, 8191, 0, 60);

  display.drawString(xMapeado, yMapeado, "*" );
  display.display();
  delay(300);
  display.clear();
}
