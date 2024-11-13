#ifndef DHT_SENSOR_H
#define DHT_SENSOR_H

#include <Arduino.h>
#include <DHT.h>
#include "../config/pins_config.h"

class DHTSensor {
private:
    DHT dht;
    float lastTemperature;
    float lastHumidity;

public:
    DHTSensor(uint8_t pin) : dht(pin, DHTTYPE) {
        lastTemperature = 0.0;
        lastHumidity = 0.0;
    }
    
    void begin() {
        dht.begin();
    }
    
    float readTemperature() {
        lastTemperature = dht.readTemperature();
        return lastTemperature;
    }
    
    float readHumidity() {
        lastHumidity = dht.readHumidity();
        return lastHumidity;
    }
    
    bool isReadingValid() {
        return !isnan(lastTemperature) && !isnan(lastHumidity);
    }
};

#endif
