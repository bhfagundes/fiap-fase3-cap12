# Sistema de Monitoramento com ESP32, DHT22, HC-SR04 e PIR

## Demonstração
Projeto em funcionamento no simulador Wokwi: [ESP32 Monitoring System](https://wokwi.com/projects/414347450896821249)

## Versão mais recente
A branch `feat/ldr` contém a versão mais atualizada do projeto, incluindo o sensor LDR (fotoresistor) e todas as melhorias recentes. Um Pull Request está aberto com estas alterações e pode ser encontrado [aqui](https://github.com/bhfagundes/fiap-fase3-cap12/pull/5).

## Descrição
Sistema de monitoramento agrícola utilizando ESP32, sensor DHT22 para temperatura/umidade, HC-SR04 para nível de água e PIR para detecção de movimento.

## Sensores Utilizados
### DHT22 (AM2302)
- Sensor digital de temperatura e umidade
- Alta precisão (±0.5°C, ±2-5% RH)
- Leituras a cada 2 segundos

### HC-SR04
- Sensor ultrassônico de distância
- Range: 2cm a 400cm
- Precisão: 3mm
- Ângulo de medição: 15°

### PIR (HC-SR501)
- Sensor de movimento infravermelho
- Alcance: 3-7 metros
- Ângulo de detecção: 120°
- Tempo de calibração: 60s

## Funcionalidades
- Monitoramento de temperatura e umidade
- Medição de nível de água
- Detecção de movimento
- Sistema de alertas
- Exibição de dados via Serial

## Configuração do Hardware
1. Conexões do DHT22:
   - VCC → 3.3V
   - GND → GND
   - DATA → GPIO27

2. Conexões do HC-SR04:
   - VCC → 5V
   - GND → GND
   - TRIG → GPIO26
   - ECHO → GPIO25

3. Conexões do PIR:
   - VCC → 5V
   - GND → GND
   - OUT → GPIO13

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
   // DHT22
   #define DHTPIN 27
   #define DHTTYPE DHT22

   // HC-SR04
   #define TRIGGER_PIN 26
   #define ECHO_PIN 25

   // PIR
   #define PIR_PIN 13
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
   - Monitor serial mostra leituras a cada 2 segundos
   - Temperatura em °C
   - Umidade em %
   - Distância em cm
   - Alertas de nível baixo de água

## Estrutura do Projeto
```
projeto/
├── src/                     # Código fonte
│   ├── main.cpp            # Arquivo principal
│   ├── sensors/            # Implementação dos sensores
│   │   ├── dht.h          # Classe do sensor DHT22
│   │   ├── ultrasonic.h   # Classe do sensor HC-SR04
│   │   └── pir.h         # Classe do sensor PIR
│   └── config/            # Configurações
│       └── pins_config.h  # Definição dos pinos
│
├── docs/                   # Documentação
│   ├── sensors/           # Docs dos sensores
│   │   ├── dht22.md      # Especificações DHT22
│   │   ├── hc-sr04.md    # Especificações HC-SR04
│   │   └── pir.md        # Especificações PIR
│   └── circuit/          # Docs do circuito
│       └── connections.md # Diagrama de conexões
│
├── test/                  # Testes unitários
│   ├── test_dht.cpp      # Testes do DHT22
│   ├── test_ultrasonic.cpp # Testes do HC-SR04
│   └── test_pir.cpp     # Testes do PIR
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

## Como Testar
### Configuração dos Testes
1. Verifique se o `platformio.ini` inclui as configurações de teste:
   ```ini
   [env:esp32dev]
   platform = espressif32
   board = esp32dev
   framework = arduino
   monitor_speed = 115200
   lib_deps =
       adafruit/DHT sensor library @ ^1.4.4
       adafruit/Adafruit Unified Sensor @ ^1.1.9
   
   test_framework = unity
   test_build_src = yes
   test_filter = test_*
   ```

### Executando os Testes
1. Via Linha de Comando:
   ```bash
   # Executar todos os testes
   pio test

   # Executar teste específico do ultrassônico
   pio test -f test_ultrasonic

   # Executar teste específico do DHT22
   pio test -f test_dht

   # Executar teste específico do PIR
   pio test -f test_pir

   # Executar com saída detalhada
   pio test -v
   ```

2. Via VS Code:
   - Abra a extensão PlatformIO
   - Navegue até a seção "Testing"
   - Clique em "Test" ou selecione o teste específico

### Verificando Resultados
- Os resultados são exibidos no terminal
- Relatório detalhado disponível em `.pio/test/esp32dev/output.txt`
- Logs de erro em caso de falha

### Testes Implementados
1. Sensor DHT22:
   - Inicialização
   - Leitura de temperatura
   - Leitura de umidade
   - Validação de dados

2. Sensor HC-SR04:
   - Inicialização
   - Medição de distância
   - Validação de range (2-400cm)
   - Tratamento de timeout
   - Armazenamento de última leitura

3. Sensor PIR:
   - Inicialização
   - Detecção de movimento
   - Sistema de alertas
