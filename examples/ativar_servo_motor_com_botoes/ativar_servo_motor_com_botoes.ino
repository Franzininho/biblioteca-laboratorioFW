/********************************-******************
  Aperte os botões para ver o servo motor se mover em
  direções diferentes.
  
  Desenvolvido por Letícia P Garcez - 03/2023
 ****************************************************/

#include <ESP32_S2_ISR_Servo.h>
#include <laboratorioFW.h>

#define motor B_5
#define btnEsquerda A_4
#define btnDireita A_7

#define MIN_MICROS 800  //544
#define MAX_MICROS 2450

int meuServo = ESP32_ISR_Servos.setupServo(motor, MIN_MICROS, MAX_MICROS);

int angulo = 0;

void setup() {
  pinMode(btnEsquerda, INPUT);
  pinMode(btnDireita, INPUT);
}

void loop() {

  if (digitalRead(btnEsquerda)) {
    angulo += 10;
  }
  else if (digitalRead(btnDireita)) {
    angulo -= 10;
  }

  angulo = angulo % 180;

  ESP32_ISR_Servos.setPosition(meuServo, angulo);
  delay(25);//delay
}
