#include <WiFiManager.h>

WiFiManager wifiManager;

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  Serial.println("\nIniciando conexão WiFi...");
  
  // Configura o portal de WiFi
  // Nome do ponto de acesso: "ESP32_Config"
  // Senha: "12345678"
  if (!wifiManager.autoConnect("ESP32_Config", "12345678")) {
    Serial.println("Falha na conexão, reiniciando...");
    delay(3000);
    ESP.restart();
  }
  
  Serial.println("Conectado ao WiFi com sucesso!");
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Monitora o status da conexão WiFi
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi desconectado. Tentando reconectar...");
    WiFi.disconnect();
    WiFi.reconnect();
    delay(5000);
  }
  
  delay(1000);
}