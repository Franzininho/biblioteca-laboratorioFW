/********************************-******************
  Leitura das informações de temperatura e humidade
  e escrita dessas informações no display oled.
  
  Links das bibliotecas externas:
  * DTH -> https://github.com/adafruit/DHT-sensor-library
  * SSD1306Wire -> https://github.com/ThingPulse/esp8266-oled-ssd1306
  
  Desenvolvido por Letícia P Garcez - 03/2023
 ****************************************************/

#include <laboratorioFW.h>
#include <Wire.h>
#include <SSD1306Wire.h>
#include <DHT.h>

SSD1306Wire display(0x3c, C_0, C_1);  // ADDRESS, SDA, SCL
DHT dht(A_9, DHT11);

void setup() {
  display.init();
  display.setContrast(255);
  display.flipScreenVertically();
  dht.begin();
  Serial.begin(19200);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
  } else {
    String textoUm = "Umidade: " + String(h) + " %t";
    String textoTemp = "Temperatura: " + String(t) + " *C";
    display.drawString(0, 20, textoUm );
    display.drawString(0, 30, textoTemp);
    display.display();
  }
  display.clear();
  delay(1000);
}
