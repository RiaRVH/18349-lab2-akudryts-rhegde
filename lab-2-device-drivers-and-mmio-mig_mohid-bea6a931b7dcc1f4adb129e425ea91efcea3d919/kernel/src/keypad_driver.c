#include <unistd.h>

#include <gpio.h>
#include <keypad_driver.h>

#define KEYPAD_COL1_PORT GPIO_B
#define KEYPAD_COL1_PIN  5

#define KEYPAD_COL2_PORT GPIO_B
#define KEYPAD_COL2_PIN  10

#define KEYPAD_COL3_PORT GPIO_A
#define KEYPAD_COL3_PIN  10

#define KEYPAD_ROW1_PORT GPIO_B
#define KEYPAD_ROW1_PIN  4

#define KEYPAD_ROW2_PORT GPIO_A
#define KEYPAD_ROW2_PIN  3

#define KEYPAD_ROW3_PORT GPIO_A
#define KEYPAD_ROW3_PIN  2

#define KEYPAD_ROW4_PORT GPIO_B
#define KEYPAD_ROW4_PIN  3


void keypad_init() {
    gpio_init(KEYPAD_COL1_PORT, KEYPAD_COL1_PIN, MODE_INPUT, OUTPUT_PUSH_PULL, OUTPUT_SPEED_HIGH, PUPD_PULL_UP, ALT0);
    gpio_init(KEYPAD_COL2_PORT, KEYPAD_COL2_PIN, MODE_INPUT, OUTPUT_PUSH_PULL, OUTPUT_SPEED_HIGH, PUPD_PULL_UP, ALT0);
    gpio_init(KEYPAD_COL3_PORT, KEYPAD_COL3_PIN, MODE_INPUT, OUTPUT_PUSH_PULL, OUTPUT_SPEED_HIGH, PUPD_PULL_UP, ALT0);
    gpio_init(KEYPAD_ROW1_PORT, KEYPAD_ROW1_PIN, MODE_INPUT, OUTPUT_PUSH_PULL, OUTPUT_SPEED_HIGH, PUPD_PULL_UP, ALT0);
    gpio_init(KEYPAD_ROW2_PORT, KEYPAD_ROW2_PIN, MODE_INPUT, OUTPUT_PUSH_PULL, OUTPUT_SPEED_HIGH, PUPD_PULL_UP, ALT0);
    gpio_init(KEYPAD_ROW3_PORT, KEYPAD_ROW3_PIN, MODE_INPUT, OUTPUT_PUSH_PULL, OUTPUT_SPEED_HIGH, PUPD_PULL_UP, ALT0);
    gpio_init(KEYPAD_ROW4_PORT, KEYPAD_ROW4_PIN, MODE_INPUT, OUTPUT_PUSH_PULL, OUTPUT_SPEED_HIGH, PUPD_PULL_UP, ALT0);
    return;
}

// returna ascii key corresponding to pressed letter
// if no keys are pressed, return null
// if multiple are pressed, return 1 of the pressed keys
char keypad_read() {
    return '\0';
}
