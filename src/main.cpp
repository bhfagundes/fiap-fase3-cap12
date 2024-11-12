#include <Arduino.h>
#include "sensors/dht.h"
#include "sensors/ultrasonic.h"

// Instanciação dos sensores
DHTSensor dhtSensor(DHTPIN);
UltrasonicSensor ultrasonicSensor(TRIGGER_PIN, ECHO_PIN);

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
}

void loop() {
  // Leitura do DHT22
  float humidity = dhtSensor.readHumidity();
  float temperature = dhtSensor.readTemperature();

  // Leitura do HC-SR04
  float distance = ultrasonicSensor.readDistance();

  // Exibe leituras do DHT22
  if (!dhtSensor.isReadingValid()) {
    Serial.println("Falha ao ler do sensor DHT22!");
  } else {
    Serial.printf("Temperatura: %.2f°C, Umidade: %.2f%%\n", temperature, humidity);
  }

  // Exibe leituras do HC-SR04
  if (!ultrasonicSensor.isReadingValid()) {
    Serial.println("Falha ao ler do sensor HC-SR04 ou fora do range (2-400cm)");
  } else {
    Serial.printf("Distância: %.1f cm\n", distance);
    
    // Lógica de controle do reservatório
    if (distance < 10) {
      Serial.println("ALERTA: Nível baixo no reservatório!");
    }
  }

  delay(2000);
}