# Sensor de Luz LDR

## Descrição
O LDR (Light Dependent Resistor) é um sensor que varia sua resistência de acordo com a intensidade de luz. Quanto mais luz, menor a resistência.

## Especificações Técnicas
- Tipo: Fotoresistor
- Tensão de Operação: 3.3V/5V
- Interface: Analógica
- Resolução: 12-bit (0-4095)
- Tempo de Resposta: ~20ms
- Resistência na Luz: ~5kΩ
- Resistência no Escuro: ~200kΩ

## Conexões
- VCC → 3.3V
- GND → GND
- OUT → GPIO35 (ADC1_7)

## Funcionamento
1. Leitura Analógica
   - Valor alto = Pouca luz
   - Valor baixo = Muita luz
   - Range: 0-4095

2. Interpretação
   - 0-1000: Luz intensa
   - 1000-2000: Luz moderada
   - 2000-4095: Luz baixa

## Uso no Projeto
- Monitoramento de luminosidade
- Controle de iluminação
- Detecção de período diurno/noturno
- Economia de energia

## Código de Exemplo
```cpp
LDRSensor ldr(LDR_PIN);

void setup() {
    ldr.begin();
}

void loop() {
    int light = ldr.readLight();
    int percent = ldr.getLightPercent();
    Serial.printf("Luz: %d (%.2f%%)\n", light, percent);
}
```

## Troubleshooting
1. Leituras Inconsistentes
   - Verificar conexões
   - Verificar tensão de referência
   - Limpar superfície do sensor
   - Evitar luz direta

2. Valores Sempre Altos/Baixos
   - Verificar divisor de tensão
   - Ajustar threshold
   - Verificar polaridade
   - Testar em diferentes condições

## Manutenção
- Limpeza periódica
- Verificação de conexões
- Calibração do threshold
- Proteção contra umidade
