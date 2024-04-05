/*
 * PROJETO SMART PLANT
 * Autor: Rodrigo Martins da Silva
 * Data: 17/03/2022
 * Versão: 2.0
 */

// Bibliotecas:
#include <LiquidCrystal_I2C.h>
//#include <Wire.h>

// Variáveis do programa
const int pinoSensor = A0;
const int pinoValvula = 13;
const int limiarSeco = 40; // Estipula até que porcentagem deve-se molhar a planta.
const int tempoRega = 10; // Tempo de rega em segundos.
int umidadeSolo = 0;

// Definições
#define endereco  0x27 
#define colunas   16
#define linhas    2

LiquidCrystal_I2C lcd(endereco, colunas, linhas);

void setup() {
  lcd.backlight(); // Liga a iluminação do display.
  pinMode(pinoValvula, OUTPUT); 
  digitalWrite(pinoValvula, HIGH); 
  lcd.begin(16, 2);  
  lcd.print("  SMART PLANT"); // Exibe a mensagem no Display LCD.
  Serial.begin(9600);
}

void loop() {
  for(int i = 0; i < 5; i++) {
    lcd.setCursor(0, 1);    
    lcd.print("Umidade: "); // Exibe a mensagem no Display LCD.    
    umidadeSolo = analogRead(pinoSensor); // Faz a leitura do sensor de umidade do solo.    
    umidadeSolo = map(umidadeSolo, 1023, 45, 0, 100); // Converte a variação do sensor de 0 a 1023 para 0 a 100.   
    lcd.print(umidadeSolo); // Exibe a mensagem no Display LCD.    
    lcd.print(" %    ");
    delay(1000); // Espera um segundo.
  }

  if(umidadeSolo < limiarSeco) {
    lcd.setCursor(0, 1); 
    lcd.print("  **Regando** "); // Exibe a mensagem no Display LCD.   
    digitalWrite(pinoValvula, HIGH); // Liga a válvula ou desliga algum relé.
    delay(tempoRega * 1000); // Espera o tempo estipulado.
    digitalWrite(pinoValvula, LOW); 
  } else {
    lcd.setCursor(0, 1);  
    lcd.print("**Hidratada :)**"); // Exibe a mensagem no Display LCD.  
    delay(2500); // Espera o tempo estipulado.
  }
}
