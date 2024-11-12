# Sensor de Movimento PIR

## Descrição
O sensor PIR (Passive Infrared) detecta movimento através de variações na radiação infravermelha do ambiente.

## Especificações
- Tensão de Operação: 5V DC
- Corrente: <50mA
- Delay ajustável: 0.3s ~ 18s
- Distância de Detecção: 3-7m
- Ângulo de Detecção: 120°

## Conexões
- VCC → 5V
- GND → GND
- OUT → GPIO13

## Uso no Projeto
O sensor PIR é utilizado para:
- Detectar presença em áreas monitoradas
- Ativar sistemas de segurança
- Monitorar movimentação de animais
- Controlar sistemas baseados em presença

## Código de Exemplo
```cpp
PIRSensor pir(PIR_PIN);
if (pir.detectMotion()) {
    Serial.println("Movimento detectado!");
}
```

## Troubleshooting
1. Falsos positivos
   - Verificar interferências IR
   - Ajustar sensibilidade
   - Verificar temperatura ambiente

2. Não detecta movimento
   - Verificar alimentação
   - Aguardar calibração (60s)
   - Verificar conexões
