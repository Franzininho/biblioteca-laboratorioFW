/********************************-******************
  Insira uma senha no teclado matricial e verifique 
  se esta senha está correta.
    
  Desenvolvido por Letícia P Garcez - 03/2023
 ****************************************************/

#include <Keypad.h>
#include <laboratorioFW.h>

#define ledCerto A_2
#define ledErrado A_3

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

const char senha[5] = {'1', '2', '3', '4', '5'};

char leTeclado(void);
void verificaSenha(char* s);

void setup()
{
  Serial.begin(19200);
  pinMode(ledCerto, OUTPUT);
  pinMode(ledErrado, OUTPUT);
  Serial.println();
  Serial.println("Digite a senha e aperte '*' ou '#' para confirmar");
}

char leitura;
char senhaInput[5];

void loop()
{
  int contador = 0;
  
  do {
    leitura = leTeclado();
    senhaInput[contador] = leitura;
    contador++;
  } while (leitura != '*' && leitura != '#');

  Serial.println("Senha digitada com sucesso");
  delay(1000);
  verificaSenha(senhaInput);
  delay(1000);
  digitalWrite(ledCerto, LOW);
  digitalWrite(ledErrado, LOW);

}


char leTeclado(void) {
  char entrada;
  do {
    entrada = teclado.getKey();
  } while (!entrada);
  return entrada;
}

void verificaSenha(char* s) {
  for (int c = 0; c < 5; c++) {
    if (s[c] != senha[c]) {
      digitalWrite(ledErrado, HIGH);
      Serial.println("SENHA INCORRETA");
      delay(1000);
      return;
    }
  }
  digitalWrite(ledCerto, HIGH);
  Serial.println("SENHA CORRETA");
  delay(1000);
  return;
}
