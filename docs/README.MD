# Sistema Inteligente de Monitoramento Agrícola

## Objetivo do Projeto
O projeto tem como objetivo criar um sistema inteligente de monitoramento agrícola utilizando o microcontrolador ESP32 e quatro sensores: DHT22 (umidade e temperatura), HC-SR04 (ultrassom para medição de distância), PIR (movimento) e LDR (luz). O sistema monitora as condições ambientais e toma decisões automatizadas para otimizar o uso de recursos, como a irrigação.

## Desenho do Circuito
![Esquema do circuito](circuito.png)

## Sensores Utilizados
1. **DHT22**: Medição de temperatura e umidade.
2. **HC-SR04**: Medição de distância de líquidos em reservatórios de água.
3. **PIR**: Detecção de movimento (invasões ou presença de animais).
4. **LDR**: Medição da intensidade de luz solar.

## Como Rodar o Projeto
### Pré-requisitos
- Arduino IDE ou PlatformIO
- Biblioteca DHT: `Adafruit DHT sensor library`

### Passos para configuração:
1. Conectar os sensores aos pinos indicados no código.
2. Carregar o código no ESP32.
3. Monitorar as leituras no Monitor Serial.

## Testes Realizados
- Testes de leitura de cada sensor foram realizados individualmente.
- Prints do Monitor Serial com dados de temperatura, umidade, distância, movimento e luz são gerados a cada ciclo.

## Instalação e Dependências
- DHT sensor library
