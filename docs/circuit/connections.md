# Conexões do Sistema de Monitoramento

## Visão Geral
Sistema completo utilizando ESP32 com três sensores:
- DHT22 (Temperatura/Umidade)
- HC-SR04 (Ultrassônico)
- PIR HC-SR501 (Movimento)

## Tabela de Conexões

### ESP32 DevKit C
| Sensor    | Pino ESP32 | Tipo  | Descrição        |
|-----------|------------|-------|------------------|
| DHT22     | GPIO27     | Data  | Dados           |
|           | 3.3V       | Power | Alimentação      |
|           | GND        | GND   | Terra           |
| HC-SR04   | GPIO26     | Trig  | Trigger         |
|           | GPIO25     | Echo  | Echo            |
|           | 5V         | Power | Alimentação      |
|           | GND        | GND   | Terra           |
| PIR       | GPIO13     | Data  | Saída Digital   |
|           | 5V         | Power | Alimentação      |
|           | GND        | GND   | Terra           |

## Requisitos de Energia
- DHT22: 3.3V (baixo consumo)
- HC-SR04: 5V (~15mA)
- PIR: 5V (~50mA)
- Consumo total estimado: ~65mA + ESP32

## Diagrama de Conexões
```
ESP32           DHT22
GPIO27    <-->  DATA
3.3V      <-->  VCC
GND       <-->  GND

ESP32           HC-SR04
GPIO26    <-->  TRIG
GPIO25    <-->  ECHO
5V        <-->  VCC
GND       <-->  GND

ESP32           PIR
GPIO13    <-->  OUT
5V        <-->  VCC
GND       <-->  GND
```

## Verificação de Conexões
1. Alimentação
   - Verificar 3.3V para DHT22
   - Verificar 5V para HC-SR04 e PIR
   - Confirmar GND comum

2. Sinais
   - DHT22: Pino de dados (GPIO27)
   - HC-SR04: TRIG (GPIO26) e ECHO (GPIO25)
   - PIR: Saída (GPIO13)

## Troubleshooting

### DHT22
- Verificar resistor pull-up (já integrado)
- Distância máxima recomendada: 20m
- Evitar interferência eletromagnética

### HC-SR04
- Verificar polaridade VCC/GND
- Manter TRIG/ECHO separados
- Distância máxima: 4m

### PIR
- Aguardar calibração (60s)
- Verificar jumpers de configuração
- Ajustar sensibilidade se necessário

## Notas de Montagem
1. Usar cabos de qualidade
2. Manter conexões curtas
3. Evitar cruzamento de sinais
4. Proteger contra curto-circuito
5. Considerar caixa de proteção

## Manutenção
1. Verificação periódica das conexões
2. Limpeza dos sensores
3. Teste de continuidade
4. Calibração quando necessário
