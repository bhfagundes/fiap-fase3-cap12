#ifndef PINS_CONFIG_H
#define PINS_CONFIG_H

// DHT22 - Temperatura e Umidade
#define DHTPIN 27
#define DHTTYPE DHT22

// HC-SR04 - Sensor Ultrassônico
#define TRIGGER_PIN 26
#define ECHO_PIN 25

// PIR Motion Sensor
#define PIR_PIN 13

// LDR - Light Sensor
#define LDR_PIN 35  // ADC1_CHANNEL_7
#define LDR_THRESHOLD 2000  // Valor de referência para luz baixa

#endif
