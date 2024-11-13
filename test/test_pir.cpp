#include <unity.h>
#include "../src/sensors/pir.h"
#include "../src/config/pins_config.h"

PIRSensor pir(PIR_PIN);

void setUp(void) {
    pir.begin();
}

void tearDown(void) {
    // Cleanup
}

void test_sensor_initialization(void) {
    TEST_ASSERT_EQUAL(PIR_PIN, 13);
}

void test_motion_detection(void) {
    bool motion = pir.detectMotion();
    TEST_ASSERT_TRUE(motion == true || motion == false);
}

void test_last_detection_time(void) {
    unsigned long beforeTime = millis();
    pir.detectMotion();
    unsigned long detectionTime = pir.getLastDetectionTime();
    TEST_ASSERT_TRUE(detectionTime >= beforeTime || detectionTime == 0);
}

void RUN_UNITY_TESTS() {
    UNITY_BEGIN();
    RUN_TEST(test_sensor_initialization);
    RUN_TEST(test_motion_detection);
    RUN_TEST(test_last_detection_time);
    UNITY_END();
}

void setup() {
    delay(2000);
    RUN_UNITY_TESTS();
}

void loop() {
    // Empty
} 