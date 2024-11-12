#include <Arduino.h>
#include "sensors/dht.h"

DHTSensor dhtSensor(DHTPIN);

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  Serial.println("\nIniciando...");
  dhtSensor.begin();
  Serial.println("Sensor DHT iniciado");
}

void loop() {
  float humidity = dhtSensor.readHumidity();
  float temperature = dhtSensor.readTemperature();

  if (!dhtSensor.isReadingValid()) {
    Serial.println("Falha ao ler do sensor DHT!");
  } else {
    Serial.printf("Temperatura: %.2f°C, Umidade: %.2f%%\n", temperature, humidity);
  }

  delay(2000);
}