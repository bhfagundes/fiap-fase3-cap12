#ifndef ENV_H
#define ENV_H

#include <Arduino.h>
#include <SPIFFS.h>

class EnvConfig {
  private:
    static String ap_ssid;
    static String ap_password;
    
    static void loadEnv() {
      if (!SPIFFS.begin(true)) {
        Serial.println("Erro ao montar SPIFFS");
        return;
      }
      
      File file = SPIFFS.open("/.env", "r");
      if (!file) {
        Serial.println("Falha ao abrir arquivo .env");
        return;
      }
      
      while (file.available()) {
        String line = file.readStringUntil('\n');
        line.trim(); // Remove espaços e quebras de linha
        
        if (line.startsWith("AP_SSID=")) {
          ap_ssid = line.substring(8);
          ap_ssid.trim();
        }
        else if (line.startsWith("AP_PASSWORD=")) {
          ap_password = line.substring(12);
          ap_password.trim();
        }
      }
      file.close();
      
      Serial.println("Configurações carregadas:");
    }
    
  public:
    static void init() {
      loadEnv();
    }
    
    static String getAPSSID() {
      return ap_ssid;
    }
    
    static String getAPPassword() {
      return ap_password;
    }
};

// Inicializa as variáveis estáticas
String EnvConfig::ap_ssid = "ESP32_Config";  // valor padrão
String EnvConfig::ap_password = "12345678";   // valor padrão

#endif 
