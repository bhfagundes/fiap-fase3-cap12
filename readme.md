# Sistema de Monitoramento com ESP32 e DHT22

## Descrição
Sistema de monitoramento de temperatura e umidade utilizando ESP32 e sensor DHT22, desenvolvido como parte do projeto da FIAP.

## Sensor Utilizado
### DHT22 (AM2302)
- Sensor digital de temperatura e umidade
- Alta precisão (±0.5°C, ±2-5% RH)
- Leituras a cada 2 segundos
- Interface digital de fácil integração

## Funcionalidades
- Monitoramento contínuo de temperatura
- Medição de umidade relativa do ar
- Exibição de dados via Serial Monitor
- Validação de leituras do sensor

## Configuração do Hardware
1. Conexões do DHT22:
   - VCC → 3.3V
   - GND → GND
   - DATA → GPIO27

## Como Usar
1. Clone o repositório

2. Instale as Dependências
   - Instale o VS Code
   - Instale a extensão PlatformIO
   - Abra o projeto no VS Code

3. Configure o Projeto
   
   a. Configuração do PlatformIO (`platformio.ini`):
   ```ini
   [env:esp32dev]
   platform = espressif32
   board = esp32dev
   framework = arduino
   monitor_speed = 115200
   lib_deps =
       adafruit/DHT sensor library @ ^1.4.4
       adafruit/Adafruit Unified Sensor @ ^1.1.9
   ```

   b. Configuração do Simulador (`wokwi.toml`):
   ```toml
   [wokwi]
   version = 1
   firmware = ".pio/build/esp32dev/firmware.bin"
   ```

   c. Configuração dos Pinos (`src/config/pins_config.h`):
   ```cpp
   #define DHTPIN 27
   #define DHTTYPE DHT22
   ```

4. Compilação e Upload
   ```bash
   # Compilar o projeto
   pio run

   # Fazer upload
   pio run --target upload

   # Monitorar serial
   pio device monitor
   ```

5. Verificação
   - Monitor serial deve mostrar leituras a cada 2 segundos
   - Temperatura em °C
   - Umidade em %

## Estrutura do Projeto

```
projeto/
├── src/                     # Código fonte
│   ├── main.cpp            # Arquivo principal
│   ├── sensors/            # Implementação dos sensores
│   │   └── dht.h          # Classe do sensor DHT22
│   └── config/            # Configurações
│       └── pins_config.h  # Definição dos pinos
│
├── docs/                   # Documentação
│   ├── sensors/           # Docs dos sensores
│   │   └── dht22.md      # Especificações DHT22
│   └── circuit/          # Docs do circuito
│       └── connections.md # Diagrama de conexões
│
├── test/                  # Testes unitários
│   └── test_dht.cpp      # Testes do sensor
│
├── .gitignore            # Arquivos ignorados pelo git
├── platformio.ini        # Configuração do PlatformIO
├── wokwi.toml           # Configuração do simulador
└── README.md            # Este arquivo
```

### Descrição dos Diretórios

#### `/src`
- `main.cpp`: Ponto de entrada do programa
- `sensors/`: Classes e implementações dos sensores
- `config/`: Arquivos de configuração do projeto

#### `/docs`
- `sensors/`: Documentação técnica dos sensores
- `circuit/`: Diagramas e esquemas de conexão

#### `/test`
- Testes unitários e de integração
- Verificações de funcionamento

### Arquivos de Configuração
- `platformio.ini`: Configurações do ambiente PlatformIO
- `wokwi.toml`: Configurações do simulador Wokwi
- `.gitignore`: Lista de arquivos ignorados pelo git

### Documentação
- `README.md`: Documentação principal do projeto
- `docs/*.md`: Documentação específica dos componentes
