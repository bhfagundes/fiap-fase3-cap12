# Conexões do Circuito

## ESP32 DevKit

### Sensor DHT22
| Sensor Pin | ESP32 Pin | Descrição    |
|------------|-----------|--------------|
| VCC        | 3.3V      | Alimentação  |
| GND        | GND       | Terra        |
| DATA       | GPIO27    | Dados        |

## Notas de Montagem
1. Resistor pull-up de 10kΩ entre VCC e DATA
2. Manter cabos curtos para evitar interferência
3. Distância mínima de 20cm de fontes de calor

## Diagrama
[Ver diagram.json para detalhes da conexão]

## Considerações
- Usar alimentação estável 3.3V
- Evitar interferência eletromagnética
- Manter distância de outros componentes
