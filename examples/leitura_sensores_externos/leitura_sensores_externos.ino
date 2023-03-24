/********************************-******************
  Leitura dos sensores externos conectados através
  dos headers.
  
  Desenvolvido por Letícia P Garcez - 03/2023
 ****************************************************/

#include <laboratorioFW.h>

#define analogico B_B
#define digital B_A


void setup() {
  pinMode(analogico, INPUT);
  pinMode(digital, INPUT);
  Serial.begin(19200);
}


void loop() {
  Serial.print("Digital - ");
  Serial.print(digitalRead(digital));
  Serial.print(" Analogico - ");
  Serial.println(analogRead(analogico));
  delay(1000);
}
