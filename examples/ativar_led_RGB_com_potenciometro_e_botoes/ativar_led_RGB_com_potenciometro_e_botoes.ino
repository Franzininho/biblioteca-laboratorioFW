/********************************-******************
  Controle a cor de um LED RGB através de botões e
  um potenciômetro. 
  
  Desenvolvido por Letícia P Garcez - 03/2023
 ****************************************************/

#include <laboratorioFW.h>

#define btn1 A_4
#define btn2 A_5
#define btn3 A_6
#define pot B_8
#define r A_A
#define g A_B
#define b A_C

void setup() {
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  pinMode(pot, INPUT);
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
  analogWrite(g, 0);
  analogWrite(b, 0);
  analogWrite(r, 0);
}

void loop() {
  int leitura = analogRead(pot);

  int leituraMapeada = map(leitura, 0, 8191, 0, 255);

  if (digitalRead(btn1)) {
    analogWrite(r, leituraMapeada);
  } else if (digitalRead(btn2)) {
    analogWrite(g, leituraMapeada);
  } else  if (digitalRead(btn3)) {
    analogWrite(b, leituraMapeada);
  }


  delay(300);
}
