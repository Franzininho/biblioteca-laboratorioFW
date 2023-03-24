/********************************-******************
  Altere a luminosidade de um LED utilizando o sensor 
  LDR. Um botão pode ser apertado para inverter a 
  lógica de escrita no LED. 
  
  Desenvolvido por Letícia P Garcez - 03/2023
 ****************************************************/

#include <laboratorioFW.h>

#define ldr A_8
#define led A_0
#define btn A_7

void setup() {
  pinMode(ldr, INPUT);
  pinMode(btn, INPUT);
  pinMode(led, OUTPUT);
}

bool crescente = true;

void loop() {

  int leituraMapeada = map(analogRead(ldr), 0, 8191, 0, 255);

  if (digitalRead(btn)) {
    crescente = !crescente;
  }

  if (crescente) {
    analogWrite(led, leituraMapeada);
  } else {
    analogWrite(led, 255 - leituraMapeada);
  }

  delay(300);
}
