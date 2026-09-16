#include <unistd.h>

#include <gpio.h>
#include <keypad_driver.h>

void keypad_init() {
    gpio_init(GPIO_B, 10, MODE_INPUT, OUTPUT_PUSH_PULL, OUTPUT_SPEED_HIGH, PUPD_PULL_UP, ALT0);
    gpio_init(GPIO_B, 4, MODE_INPUT, OUTPUT_PUSH_PULL, OUTPUT_SPEED_HIGH, PUPD_PULL_UP, ALT0);
    gpio_init(GPIO_B, 5, MODE_INPUT, OUTPUT_PUSH_PULL, OUTPUT_SPEED_HIGH, PUPD_PULL_UP, ALT0);
    gpio_init(GPIO_B, 3, MODE_INPUT, OUTPUT_PUSH_PULL, OUTPUT_SPEED_HIGH, PUPD_PULL_UP, ALT0);
    gpio_init(GPIO_A, 10, MODE_INPUT, OUTPUT_PUSH_PULL, OUTPUT_SPEED_HIGH, PUPD_PULL_UP, ALT0);
    gpio_init(GPIO_A, 2, MODE_INPUT, OUTPUT_PUSH_PULL, OUTPUT_SPEED_HIGH, PUPD_PULL_UP, ALT0);
    gpio_init(GPIO_A, 3, MODE_INPUT, OUTPUT_PUSH_PULL, OUTPUT_SPEED_HIGH, PUPD_PULL_UP, ALT0);
    return;
}

char keypad_read() {
    return '\0';
}
