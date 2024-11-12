#include <Arduino.h>
#include "sensors/dht.h"
#include "sensors/ultrasonic.h"
#include "sensors/pir.h"

// Instanciação dos sensores
DHTSensor dhtSensor(DHTPIN);
UltrasonicSensor ultrasonicSensor(TRIGGER_PIN, ECHO_PIN);
PIRSensor pirSensor(PIR_PIN);

void setup() {
    Serial.begin(115200);
    delay(1000);
    
    Serial.println("\nIniciando sensores...");
    
    // Inicializa DHT22
    dhtSensor.begin();
    Serial.println("Sensor DHT22 iniciado");
    
    // Inicializa HC-SR04
    ultrasonicSensor.begin();
    Serial.println("Sensor HC-SR04 iniciado");
    
    // Inicializa PIR com feedback de calibração
    Serial.println("Iniciando calibração do sensor PIR...");
    Serial.println("Aguarde 60 segundos...");
    
    // Contador visual durante calibração
    for(int i = 0; i < 60; i++) {
        Serial.printf("Calibrando PIR: %d segundos restantes\n", 60-i);
        delay(1000);
    }
    
    pirSensor.begin();
    Serial.println("Sensor PIR calibrado e pronto!");
}

void loop() {
    // Leitura do DHT22
    float humidity = dhtSensor.readHumidity();
    float temperature = dhtSensor.readTemperature();

    // Leitura do HC-SR04
    float distance = ultrasonicSensor.readDistance();

    // Leitura do PIR
    bool motion = pirSensor.detectMotion();

    // Exibe leituras do DHT22
    if (!dhtSensor.isReadingValid()) {
        Serial.println("Falha ao ler do sensor DHT22!");
    } else {
        Serial.printf("Temperatura: %.2f°C, Umidade: %.2f%%\n", temperature, humidity);
    }

    // Exibe leituras do HC-SR04
    if (!ultrasonicSensor.isReadingValid()) {
        Serial.println("Falha ao ler do sensor HC-SR04!");
    } else {
        Serial.printf("Distância: %.2f cm\n", distance);
    }

    // Exibe status do PIR
    if (motion) {
        Serial.println("ALERTA: Movimento detectado!");
        Serial.printf("Tempo desde última detecção: %lu ms\n", 
                     millis() - pirSensor.getLastDetectionTime());
    }

    // Lógica de controle e alertas
    if (distance < 10) {
        Serial.println("ALERTA: Nível baixo no reservatório!");
    }

    // Verifica condições críticas
    if (temperature > 30) {
        Serial.println("ALERTA: Temperatura elevada!");
    }
    
    if (humidity < 40) {
        Serial.println("ALERTA: Umidade baixa!");
    }

    // Aguarda antes da próxima leitura
    delay(2000);
}