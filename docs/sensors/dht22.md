# Sensor DHT22 (AM2302)

## Descrição
O DHT22 é um sensor digital de temperatura e umidade que oferece leituras precisas e confiáveis.

## Especificações
- Alimentação: 3.3V - 5V
- Faixa de temperatura: -40°C a 80°C (±0.5°C)
- Faixa de umidade: 0-100% RH (±2-5% RH)
- Tempo de resposta: 2 segundos
- Interface: Digital (Single-bus)

## Conexões
- VCC → 3.3V
- GND → GND
- DATA → GPIO27

## Uso no Projeto
O sensor DHT22 é utilizado para:
- Monitoramento da temperatura ambiente
- Controle de umidade para irrigação
- Tomada de decisão automatizada

## Código de Exemplo
```cpp
DHTSensor dhtSensor(DHTPIN);
float temperature = dhtSensor.readTemperature();
float humidity = dhtSensor.readHumidity();
