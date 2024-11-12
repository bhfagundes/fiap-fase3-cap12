#include <unity.h>
#include "../src/sensors/ultrasonic.h"
#include "../src/config/pins_config.h"

UltrasonicSensor ultrasonic(TRIGGER_PIN, ECHO_PIN);

void setUp(void) {
    ultrasonic.begin();
}

void tearDown(void) {
    // Cleanup
}

void test_sensor_initialization(void) {
    TEST_ASSERT_EQUAL(TRIGGER_PIN, 26);
    TEST_ASSERT_EQUAL(ECHO_PIN, 25);
}

void test_distance_range(void) {
    float distance = ultrasonic.readDistance();
    TEST_ASSERT_TRUE(distance >= 2.0 || distance == -1);
    TEST_ASSERT_TRUE(distance <= 400.0 || distance == -1);
}

void test_reading_validation(void) {
    float distance = ultrasonic.readDistance();
    if (distance >= 2.0 && distance <= 400.0) {
        TEST_ASSERT_TRUE(ultrasonic.isReadingValid());
    } else {
        TEST_ASSERT_FALSE(ultrasonic.isReadingValid());
    }
}

void test_timeout_handling(void) {
    // Simula uma situação de timeout
    // Em hardware real, isso seria testado desconectando o sensor
    float distance = ultrasonic.readDistance();
    if (distance == -1) {
        TEST_ASSERT_FALSE(ultrasonic.isReadingValid());
    }
}

void test_last_reading_storage(void) {
    float firstReading = ultrasonic.readDistance();
    float storedReading = ultrasonic.getLastDistance();
    TEST_ASSERT_EQUAL_FLOAT(firstReading, storedReading);
}

void RUN_UNITY_TESTS() {
    UNITY_BEGIN();
    
    RUN_TEST(test_sensor_initialization);
    RUN_TEST(test_distance_range);
    RUN_TEST(test_reading_validation);
    RUN_TEST(test_timeout_handling);
    RUN_TEST(test_last_reading_storage);
    
    UNITY_END();
}

void setup() {
    delay(2000);
    RUN_UNITY_TESTS();
}

void loop() {
    // Empty
} 