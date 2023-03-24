/********************************-******************
  Leitura dos sensores externos conectados através
  dos conectores Grove.
  
  Desenvolvido por Letícia P Garcez - 03/2023
 ****************************************************/

#include <laboratorioFW.h>

#define grove B_6


void setup() {
  pinMode(grove, INPUT);
  Serial.begin(19200);
}


void loop() {
  Serial.println(analogRead(grove));
  delay(1000);
}
