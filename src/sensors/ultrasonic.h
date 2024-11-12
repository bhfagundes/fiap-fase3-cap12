#ifndef ULTRASONIC_SENSOR_H
#define ULTRASONIC_SENSOR_H

#include <Arduino.h>
#include "../config/pins_config.h"

class UltrasonicSensor {
private:
    uint8_t trigPin;
    uint8_t echoPin;
    float lastDistance;
    unsigned long timeout;
    const float SOUND_SPEED = 0.034;

public:
    UltrasonicSensor(uint8_t trig, uint8_t echo) : 
        trigPin(trig), 
        echoPin(echo),
        lastDistance(0.0),
        timeout(30000) {}
    
    void begin() {
        pinMode(trigPin, OUTPUT);
        pinMode(echoPin, INPUT);
        digitalWrite(trigPin, LOW);
    }
    
    float readDistance() {
        // Garante que o trigger está LOW
        digitalWrite(trigPin, LOW);
        delayMicroseconds(2);
        
        // Envia pulso de 10us
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);
        
        // Lê a duração do pulso ECHO
        unsigned long duration = pulseIn(echoPin, HIGH, timeout);
        
        // Se timeout, retorna -1
        if (duration == 0) {
            lastDistance = -1;
            return lastDistance;
        }
        
        // Calcula a distância
        lastDistance = (duration * SOUND_SPEED) / 2;
        
        return lastDistance;
    }
    
    bool isReadingValid() {
        return (lastDistance >= 2.0 && lastDistance <= 400.0);
    }
    
    float getLastDistance() {
        return lastDistance;
    }
};

#endif
