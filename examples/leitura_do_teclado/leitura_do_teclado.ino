/********************************-******************
  Leitura do teclado matricial utilizando a biblioteca
  Keypad.
  
  Desenvolvido por Letícia P Garcez - 03/2023
 ****************************************************/

#include <Keypad.h>
#include <laboratorioFW.h>

const int linhas =  4;
const int colunas = 4;

char teclas[linhas][colunas] = { {'1', '4', '7', '*'},
  {'2', '5', '8', '0'},
  {'3', '6', '9', '#'},
  {'A', 'B', 'C', 'D'}
};

byte pinosLinhas[linhas] = {E_6, E_5, E_4, E_3};
byte pinosColunas[colunas] = {D_A, D_B, D_C, D_D};

Keypad teclado = Keypad(makeKeymap(teclas), pinosLinhas, pinosColunas, linhas, colunas);

void setup()
{
  Serial.begin(19200);
}


void loop()
{
  char entrada;
  do {
    entrada = teclado.getKey();
  } while (!entrada);
  Serial.println(entrada);
  delay(500);

}
