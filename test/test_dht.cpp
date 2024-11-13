#include <unity.h>
#include "../src/sensors/dht.h"
#include "../src/config/pins_config.h"

DHTSensor dht(DHTPIN);

void setUp(void) {
    dht.begin();
    delay(2000); // Aguarda estabilização do sensor
}

void tearDown(void) {
    // Cleanup
}

void test_sensor_initialization(void) {
    TEST_ASSERT_EQUAL(DHTPIN, 27);
    TEST_ASSERT_EQUAL(DHTTYPE, DHT22);
}

void test_temperature_range(void) {
    float temp = dht.readTemperature();
    TEST_ASSERT_TRUE(temp >= -40.0 || temp == -999);
    TEST_ASSERT_TRUE(temp <= 80.0 || temp == -999);
}

void test_humidity_range(void) {
    float humidity = dht.readHumidity();
    TEST_ASSERT_TRUE(humidity >= 0.0 || humidity == -999);
    TEST_ASSERT_TRUE(humidity <= 100.0 || humidity == -999);
}

void test_reading_validation(void) {
    float temp = dht.readTemperature();
    float humidity = dht.readHumidity();
    
    if (temp != -999 && humidity != -999) {
        TEST_ASSERT_TRUE(dht.isReadingValid());
    } else {
        TEST_ASSERT_FALSE(dht.isReadingValid());
    }
}

void test_consecutive_readings(void) {
    float temp1 = dht.readTemperature();
    delay(2000);
    float temp2 = dht.readTemperature();
    
    if (temp1 != -999 && temp2 != -999) {
        // Variação máxima esperada entre leituras
        TEST_ASSERT_FLOAT_WITHIN(2.0, temp1, temp2);
    }
}

void test_temperature_storage(void) {
    float temp = dht.readTemperature();
    float stored = dht.getLastTemperature();
    TEST_ASSERT_EQUAL_FLOAT(temp, stored);
}

void test_humidity_storage(void) {
    float humidity = dht.readHumidity();
    float stored = dht.getLastHumidity();
    TEST_ASSERT_EQUAL_FLOAT(humidity, stored);
} 