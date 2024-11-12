# Conexões do Circuito

## ESP32 DevKit

### 1. Sensor DHT22
| Sensor Pin | ESP32 Pin | Descrição    |
|------------|-----------|--------------|
| VCC        | 3.3V      | Alimentação  |
| GND        | GND       | Terra        |
| DATA       | GPIO27    | Dados        |

### 2. Sensor HC-SR04
| Sensor Pin | ESP32 Pin | Descrição    |
|------------|-----------|--------------|
| VCC        | 5V        | Alimentação  |
| GND        | GND       | Terra        |
| TRIG       | GPIO26    | Trigger      |
| ECHO       | GPIO25    | Echo         |

## Diagrama de Conexões
```
[ESP32] -------- [DHT22]          [HC-SR04]
3.3V    -------- VCC
5V      -------------------------- VCC
GND     -------- GND      ------- GND
GPIO27  -------- DATA
GPIO26  -------------------------- TRIG
GPIO25  -------------------------- ECHO
```

## Componentes Necessários
1. ESP32 DevKit
2. Sensor DHT22 (AM2302)
3. Sensor HC-SR04
4. Resistor pull-up 10kΩ (para DHT22)
5. Jumpers/fios para conexão
6. Protoboard

## Notas de Montagem

### DHT22
1. **Resistor Pull-up**
   - Conectar resistor 10kΩ entre VCC e DATA
   - Necessário para comunicação estável

### HC-SR04
1. **Alimentação**
   - Usar 5V para funcionamento correto
   - Não usar 3.3V (pode causar leituras instáveis)

2. **Considerações de Montagem**
   - Manter sensor perpendicular à superfície medida
   - Evitar obstáculos no cone de medição (15°)
   - Distância mínima: 2cm
   - Distância máxima: 400cm

## Verificação de Conexões
1. Verificar polaridade (VCC/GND)
2. Confirmar GPIOs corretos
   - DHT22: GPIO27
   - HC-SR04: GPIO26 (TRIG) e GPIO25 (ECHO)
3. Testar continuidade das conexões
4. Medir tensões de alimentação
   - DHT22: 3.3V
   - HC-SR04: 5V

## Troubleshooting

### DHT22
1. **Sem Leitura**
   - Verificar alimentação 3.3V
   - Testar continuidade
   - Confirmar resistor pull-up

### HC-SR04
1. **Leituras Incorretas**
   - Verificar alimentação 5V
   - Confirmar conexões TRIG/ECHO
   - Checar obstáculos
   - Verificar ângulo de medição

2. **Sem Resposta**
   - Testar alimentação
   - Verificar continuidade
   - Confirmar GPIOs

## Simulação
O circuito pode ser testado no Wokwi usando o arquivo `diagram.json` fornecido.

## Referências
- [Datasheet DHT22](link-para-datasheet)
- [Datasheet HC-SR04](link-para-datasheet)
- [ESP32 Pinout](link-para-pinout)
