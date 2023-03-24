/********************************-******************
  Teste completo dos periféricos da placa "Laboratório de Sistemas Embarcados e IoT"
  
  Links das bibliotecas externas:
  * DTH -> https://github.com/adafruit/DHT-sensor-library
  * SSD1306Wire -> https://github.com/ThingPulse/esp8266-oled-ssd1306
  * ESP32_S2_ISR_Servo -> https://github.com/khoih-prog/ESP32_S2_ISR_Servo
  
  Desenvolvido por Letícia P Garcez - 03/2023
 ****************************************************/

#include <laboratorioFW.h>
#include <Wire.h>
#include <SSD1306Wire.h>
#include <Adafruit_NeoPixel.h>
#include <DHT.h>
#include <Keypad.h>
#include <ESP32_S2_ISR_Servo.h>

void esperaBotao(int btn);
void esperaContinue(void);
void testeLED(int pino, String nomePino);
void testeJoystick(int pinoX, int pinoY, int btn);
void testePotenciometro(int pino);
void testeTela(void);
void testeBuzzer(int pino);
void testeLEDEnd(int pino);
void testeDTH(int pino);
void testeLDR(int pino);
void testeServo(int pino);
void testeDisplay7Seg(void);
void testeTeclado(void);
void testeTransistor(int pino);
void testeJumpers(int pinoDigital, int pinoAnalogico);
void testeGrove(int pinoGrove);

void setup(void) {
  Serial.begin(19200);
}

void loop(void) {

  Serial.println("Ligue A4,A5,A6,A7,A0,A1,A2,A3,AC,AB,AA,E2 e aperte A4 para começar");
  esperaContinue();

  //Botões
  Serial.println("Teste dos botões");
  Serial.println("Aperte o botao A4");
  esperaBotao(A_4);
  Serial.println("Aperte o botao A5");
  esperaBotao(A_5);
  Serial.println("Aperte o botao A6");
  esperaBotao(A_6);
  Serial.println("Aperte o botao A7");
  esperaBotao(A_7);

  //LEDs
  Serial.println("Teste dos LEDs normais");
  testeLED(A_0, "A0");
  testeLED(A_1, "A1");
  testeLED(A_2, "A2");
  testeLED(A_3, "A3");
  testeLED(A_C, "AC");
  testeLED(A_B, "AB");
  testeLED(A_A, "AA");

  //Buzzer
  Serial.println("Teste do buzzer");
  testeBuzzer(E_2);

  //Potenciômetro
  Serial.println("Teste do potenciômetro");
  testePotenciometro(B_8);

  Serial.println("Desligue tudo menos A4 e aperte A4 para continuar");
  esperaContinue();

  Serial.println("Ligue B1, B0, D8, C0, C1 e aperte A4 para começar");
  esperaContinue();

  //Joystick
  Serial.println("Teste do Joystick");
  testeJoystick(B_1, B_0, D_8);

  //Tela
  Serial.println("Teste da Tela");
  testeTela();

  Serial.println("Desligue tudo menos A4 e aperte A4 para continuar");
  esperaContinue();

  Serial.println("Ligue D9, A9 aperte A4 para começar");
  esperaContinue();

  //LED RGB Endereçável
  Serial.println("Teste do LED RGB Endereçável");
  testeLEDEnd(D_9);

  //DTH
  Serial.println("Teste do DTH");
  testeDTH(A_9);

  Serial.println("Desligue tudo menos A4 e aperte A4 para continuar");
  esperaContinue();

  Serial.println("Ligue A8,B5 aperte A4 para começar");
  esperaContinue();

  //LDR
  Serial.println("Teste do LDR");
  testeLDR(A_8);

  //DTH
  Serial.println("Teste do Servo");
  testeServo(B_5);

  Serial.println("Desligue tudo menos A4 e aperte A4 para continuar");
  esperaContinue();

  Serial.println("Ligue D0, D1, D2, D3, D4, D5, D6, D7 aperte A4 para começar");
  esperaContinue();

  //Teste 7seg
  Serial.println("Teste do display de 7 segmentos");
  testeDisplay7Seg();

  //Teste teclado
  Serial.println("Teste do teclado");
  testeTeclado();

  //Teste transistor
  Serial.println("Teste do transistor");
  testeTransistor(E_9);

  //Teste dos Jumpers 1
  Serial.println("Teste dos jumpers1");
  testeJumpers(B_3, B_2);

  //Teste dos Jumpers 2
  Serial.println("Teste dos jumpers2");
  testeJumpers(B_A, B_B);

  //Teste do Grove 1
  Serial.println("Teste do Grove 1");
  testeGrove(B_6);

  //Teste do Grove 2
  Serial.println("Teste do Grove 2");
  testeGrove(B_7);

  Serial.println("==================================Fim====================================");
  while (true)
    ;
}

void esperaBotao(int btn) {
  pinMode(btn, INPUT);
  while (!digitalRead(btn));
  delay(500);
}

void esperaContinue(void) {
  esperaBotao(A_4);
}

void testeLED(int pino, String nomePino) {
  pinMode(pino, OUTPUT);
  digitalWrite(pino, HIGH);
  Serial.println("LED " + nomePino + " ligou?");
  esperaContinue();
  digitalWrite(pino, LOW);
  delay(500);
}

void testeJoystick(int pinoX, int pinoY, int btn) {
  pinMode(pinoX, INPUT);
  pinMode(pinoY, INPUT);
  pinMode(btn, INPUT);
  do {
    Serial.println("X: " + String(analogRead(pinoX)) + " Y: " + String(analogRead(pinoY)) + "   btn:: " + String(digitalRead(btn)));
    delay(500);
  } while (!digitalRead(A_4));
}

void testePotenciometro(int pino) {
  pinMode(pino, INPUT);
  pinMode(A_4, INPUT);
  do {
    Serial.print("Potenciometro: ");
    Serial.println(analogRead(pino));
    delay(500);
  } while (!digitalRead(A_4));
  delay(500);
}

void testeTela(void) {
  SSD1306Wire display(0x3c, C_0, C_1);  // ADDRESS, SDA, SCL
  display.init();
  display.setContrast(255);
  for (int16_t i = 0; i < display.getHeight() / 2; i += 2) {
    display.drawRect(i, i, display.getWidth() - 2 * i, display.getHeight() - 2 * i);
    display.display();
    delay(10);
  }
  delay(1000);
  display.clear();
}

void testeBuzzer(int pino) {
  pinMode(pino, OUTPUT);
  tone(pino, 1800);
  Serial.println("Buzzer funcionou?");
  esperaContinue();
  noTone(pino);
  delay(500);
}

void testeLEDEnd(int pino) {
  Adafruit_NeoPixel pixels(1, pino, NEO_GRB + NEO_KHZ800);
  pixels.begin();
  pixels.clear();
  pixels.setPixelColor(0, pixels.Color(154, 200, 100));
  pixels.show();

  Serial.println("LED RGB Endereçável ligou?");
  esperaContinue();
  pixels.setPixelColor(0, pixels.Color(0, 0, 0));
  pixels.show();
  delay(500);
}

void testeDTH(int pino) {
  DHT dht(pino, DHT11);
  dht.begin();
  do {
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    if (isnan(t) || isnan(h)) {
      Serial.println("Failed to read from DHT");
    } else {
      Serial.print("DTH: Umidade: ");
      Serial.print(h);
      Serial.print(" %t");
      Serial.print("Temperatura: ");
      Serial.print(t);
      Serial.println(" *C");
    }
    delay(500);
  } while (!digitalRead(A_4));
  delay(500);
}

void testeLDR(int pino) {
  pinMode(pino, INPUT);
  do {
    Serial.print("LDR: ");
    Serial.println(analogRead(pino));
    delay(500);
  } while (!digitalRead(A_4));
  delay(500);
}

void testeServo(int pino) {
  int MIN_MICROS = 800;  //544
  int MAX_MICROS = 2450;
  int servo = ESP32_ISR_Servos.setupServo(B_5, MIN_MICROS, MAX_MICROS);

  ESP32_ISR_Servos.setPosition(servo, 180);
  delay(100);
  ESP32_ISR_Servos.setPosition(servo, 0);
  delay(100);

  Serial.println("Servo mexeu?");
  esperaContinue();
  delay(500);
}

void testeDisplay7Seg(void) {
  testeLED(D_1, "D1");
  testeLED(D_2, "D2");
  testeLED(D_3, "D3");
  testeLED(D_4, "D4");
  testeLED(D_5, "D5");
  testeLED(D_6, "D6");
  testeLED(D_7, "D7");
  delay(500);
}

void testeTeclado(void) {
  char teclas[4][4] = { { '1', '2', '3', 'A' },
                        { '4', '5', '6', 'B' },
                        { '7', '8', '9', 'C' },
                        { '*', '0', '#', 'D' } };
  byte pinosL[4] = { D_A, D_B, D_C, D_D };
  byte pinosC[4] = { D_3, D_4, D_5, D_6 };

  Keypad teclado = Keypad(makeKeymap(teclas), pinosL, pinosC, 4, 4);

  char entrada;
  do {
    do {
      entrada = teclado.getKey();
    } while (!entrada);
    Serial.println(entrada);

    delay(300);
  } while (entrada != 'D');
  delay(500);
}

void testeTransistor(int pino) {
  pinMode(pino, OUTPUT);
  digitalWrite(pino, HIGH);
  Serial.println("Transistor  ativou?");
  esperaContinue();
  digitalWrite(pino, LOW);
  delay(500);
}

void testeJumpers(int pinoDigital, int pinoAnalogico) {
  pinMode(pinoDigital, INPUT);
  pinMode(pinoAnalogico, INPUT);
  do {
    Serial.print("Digital - ");
    Serial.print(digitalRead(pinoDigital));
    Serial.print(" Analogico - ");
    Serial.println(analogRead(pinoAnalogico));
    delay(500);
  } while (!digitalRead(A_4));
  delay(500);
}

void testeGrove(int pinoGrove) {
  pinMode(pinoGrove, INPUT);
  do {
    Serial.print("Digital - ");
    Serial.print(digitalRead(pinoGrove));
    Serial.print(" Analogico - ");
    Serial.println(analogRead(pinoGrove));
    delay(500);
  } while (!digitalRead(A_4));
  delay(500);
}
