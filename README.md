# Smart Plant

## Descrição

O projeto Smart Plant é um sistema de automação para regar plantas com base na umidade do solo. Ele utiliza um sensor de umidade do solo para monitorar o nível de umidade e uma válvula para controlar a rega. O sistema exibe informações sobre a umidade do solo em um display LCD.

## Componentes

- Arduino
- Sensor de umidade do solo
- Válvula solenoide ou relé
- Display LCD I2C
- Jumpers

## Instalação

1. Conecte o sensor de umidade do solo ao pino analógico do Arduino.
2. Conecte a válvula solenoide ou relé ao pino digital do Arduino.
3. Conecte o display LCD I2C ao Arduino.
4. Carregue o código para o Arduino.

## Uso

O sistema monitora continuamente a umidade do solo. Se a umidade do solo estiver abaixo do definido, o sistema inicia a rega por um período de tempo pré-determinado. Caso contrário, ele mantém a planta hidratada e exibe uma mensagem indicando isso.

![01042022_115559 LMC](https://github.com/user-attachments/assets/a4f6e6aa-f493-4854-9662-57de309730aa)
