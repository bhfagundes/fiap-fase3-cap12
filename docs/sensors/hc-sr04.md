# Sensor Ultrassônico HC-SR04

## Descrição
O HC-SR04 é um sensor ultrassônico que mede distâncias entre 2cm e 400cm usando ondas sonoras.

## Especificações
- Alimentação: 5V DC
- Corrente: <15mA
- Frequência: 40Hz
- Alcance: 2cm - 400cm
- Precisão: 3mm
- Ângulo de medição: 15°

## Conexões
- VCC → 5V
- GND → GND
- TRIG → GPIO26
- ECHO → GPIO25

## Uso no Projeto
O sensor HC-SR04 é utilizado para:
- Monitorar nível de água em reservatórios
- Controlar sistema de irrigação
- Medir volume de líquidos
- Automação do sistema de irrigação

## Código de Exemplo
```cpp
UltrasonicSensor ultrasonic(TRIGGER_PIN, ECHO_PIN);
float distance = ultrasonic.readDistance();
```

## Troubleshooting
1. Verificar alimentação (5V necessário)
2. Confirmar conexões dos pinos TRIG e ECHO
3. Evitar obstáculos no cone de medição
4. Manter superfície de medição perpendicular
