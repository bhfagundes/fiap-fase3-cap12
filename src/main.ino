#include <WiFiManager.h>
#include "env.h"

WiFiManager wifiManager;

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  Serial.println("\nCarregando configurações...");
  EnvConfig::init();
  
  Serial.println("\nIniciando conexão WiFi...");
  
  if (!wifiManager.autoConnect(
    EnvConfig::getAPSSID().c_str(), 
    EnvConfig::getAPPassword().c_str()
  )) {
    Serial.println("Falha na conexão, reiniciando...");
    delay(3000);
    ESP.restart();
  }
  
  Serial.println("Conectado ao WiFi com sucesso!");
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi desconectado. Tentando reconectar...");
    WiFi.disconnect();
    WiFi.reconnect();
    delay(5000);
  }
  
  delay(1000);
}