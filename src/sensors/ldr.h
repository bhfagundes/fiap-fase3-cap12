#ifndef LDR_SENSOR_H
#define LDR_SENSOR_H

#include <Arduino.h>
#include "../config/pins_config.h"

class LDRSensor {
private:
    uint8_t ldrPin;
    int lastReading;
    int threshold;
    const int MAX_ANALOG = 4095;  // ESP32 ADC resolution (12-bit)

public:
    LDRSensor(uint8_t pin, int thresh = LDR_THRESHOLD) : 
        ldrPin(pin), 
        lastReading(0),
        threshold(thresh) {}
    
    void begin() {
        pinMode(ldrPin, INPUT);
        Serial.println("Sensor LDR iniciado");
    }
    
    int readLight() {
        lastReading = analogRead(ldrPin);
        return lastReading;
    }
    
    bool isLowLight() {
        return lastReading > threshold;
    }
    
    int getLastReading() {
        return lastReading;
    }
    
    // Retorna percentual de luz (0-100%)
    int getLightPercent() {
        return map(lastReading, 0, MAX_ANALOG, 100, 0);
    }
};

#endif
