# Configuração do Projeto - Sensor DHT22

## Requisitos de Hardware
- ESP32 DevKit
- Sensor DHT22 (AM2302)
- Jumpers

## Conexões do DHT22
- VCC → 3.3V
- GND → GND
- DATA → GPIO27

## Configuração do Ambiente de Desenvolvimento

### 1. VS Code + PlatformIO
1. Instale o VS Code
2. Instale a extensão PlatformIO
3. Clone o repositório
4. Abra o projeto no VS Code

### 2. Dependências
As seguintes bibliotecas são necessárias:
```ini
lib_deps =
    adafruit/DHT sensor library
    adafruit/Adafruit Unified Sensor
```

### 3. Simulação no Wokwi
1. Instale a extensão Wokwi no VS Code
2. Configure o arquivo diagram.json
3. Execute a simulação

## Testando o Sensor
1. Compile o projeto: `pio run`
2. Faça upload: `pio run --target upload`
3. Monitor serial: `pio device monitor`

O sensor deve mostrar leituras de temperatura e umidade a cada 2 segundos.

## Troubleshooting
- Verifique as conexões físicas
- Confirme se o pino definido em pins_config.h está correto
- Certifique-se que o sensor está alimentado com 3.3V
