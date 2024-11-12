#ifndef PIR_SENSOR_H
#define PIR_SENSOR_H

#include <Arduino.h>
#include "../config/pins_config.h"

class PIRSensor {
private:
    uint8_t pirPin;
    bool lastMotion;
    unsigned long lastDetectionTime;
    bool isCalibrated;
    const unsigned long CALIBRATION_TIME = 60000; // 60 segundos

public:
    PIRSensor(uint8_t pin) : 
        pirPin(pin), 
        lastMotion(false),
        lastDetectionTime(0),
        isCalibrated(false) {}
    
    void begin() {
        pinMode(pirPin, INPUT);
        Serial.println("Calibrando sensor PIR...");
        
        // Aguarda calibração
        unsigned long startTime = millis();
        while (millis() - startTime < CALIBRATION_TIME) {
            Serial.printf("Calibrando PIR: %lu segundos restantes\n", 
                        (CALIBRATION_TIME - (millis() - startTime)) / 1000);
            delay(1000);
        }
        
        isCalibrated = true;
        Serial.println("Sensor PIR calibrado e pronto!");
    }
    
    bool detectMotion() {
        if (!isCalibrated) return false;
        
        lastMotion = digitalRead(pirPin);
        if (lastMotion) {
            lastDetectionTime = millis();
        }
        return lastMotion;
    }
    
    bool isMotionDetected() {
        return lastMotion;
    }
    
    unsigned long getLastDetectionTime() {
        return lastDetectionTime;
    }
};

#endif
