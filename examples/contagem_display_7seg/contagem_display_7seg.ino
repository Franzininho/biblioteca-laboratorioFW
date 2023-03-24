/********************************-******************
  Contagem no display de 7 segmentos
  
  Desenvolvido por Letícia P Garcez - 03/2023
 ****************************************************/

#include <laboratorioFW.h>

byte representacaoNumeros[10][8] = {
  { 1, 1, 1, 1, 1, 1, 0 }, //DIGITO 0
  { 0, 1, 1, 0, 0, 0, 0 }, //DIGITO 1
  { 1, 1, 0, 1, 1, 0, 1 }, //DIGITO 2
  { 1, 1, 1, 1, 0, 0, 1 }, //DIGITO 3
  { 0, 1, 1, 0, 0, 1, 1 }, //DIGITO 4
  { 1, 0, 1, 1, 0, 1, 1 }, //DIGITO 5
  { 1, 0, 1, 1, 1, 1, 1 }, //DIGITO 6
  { 1, 1, 1, 0, 0, 0, 0 }, //DIGITO 7
  { 1, 1, 1, 1, 1, 1, 1 }, //DIGITO 8
  { 1, 1, 1, 1, 0, 1, 1 } //DIGITO 9
};

int pinos[8] = {D_0, D_1, D_2, D_3, D_4, D_5, D_6, D_7};
int numero;

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(pinos[i], OUTPUT);
  }

  numero = 0;
}

void loop() {
  if (numero == 10) {
    numero = 0;
  }
  
  ligaSegmentosDisplay(numero);
  delay(1000);
  numero++;
}

void ligaSegmentosDisplay(byte digito) {
  for (byte i = 0; i < 8; i++) {
    digitalWrite(pinos[i], representacaoNumeros[digito][i]);
  }
}
