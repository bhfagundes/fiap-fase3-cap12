#include <unity.h>
#include "../src/sensors/ldr.h"
#include "../src/config/pins_config.h"

LDRSensor ldr(LDR_PIN);

void setUp(void) {
    ldr.begin();
}

void tearDown(void) {
    // Cleanup
}

void test_sensor_initialization(void) {
    TEST_ASSERT_EQUAL(LDR_PIN, 35);
}

void test_reading_range(void) {
    int reading = ldr.readLight();
    TEST_ASSERT_TRUE(reading >= 0);
    TEST_ASSERT_TRUE(reading <= 4095);
}

void test_percentage_calculation(void) {
    int percent = ldr.getLightPercent();
    TEST_ASSERT_TRUE(percent >= 0);
    TEST_ASSERT_TRUE(percent <= 100);
}

void test_threshold_check(void) {
    int reading = ldr.readLight();
    bool isLow = ldr.isLowLight();
    TEST_ASSERT_EQUAL(reading > LDR_THRESHOLD, isLow);
}

void RUN_UNITY_TESTS() {
    UNITY_BEGIN();
    RUN_TEST(test_sensor_initialization);
    RUN_TEST(test_reading_range);
    RUN_TEST(test_percentage_calculation);
    RUN_TEST(test_threshold_check);
    UNITY_END();
}

void setup() {
    delay(2000);
    RUN_UNITY_TESTS();
}

void loop() {
    // Empty
} 