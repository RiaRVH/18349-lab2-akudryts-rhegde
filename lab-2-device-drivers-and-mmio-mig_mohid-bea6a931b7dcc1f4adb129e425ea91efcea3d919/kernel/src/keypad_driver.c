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




int read_row(int row) {
  if (row == 1) {
    return gpio_read(KEYPAD_ROW1_PORT, KEYPAD_ROW1_PIN);
  } else if (row == 2) {
    return gpio_read(KEYPAD_ROW2_PORT, KEYPAD_ROW2_PIN);
  } else if (row == 3) {
    return gpio_read(KEYPAD_ROW3_PORT, KEYPAD_ROW3_PIN);
  } else {
    return gpio_read(KEYPAD_ROW4_PORT, KEYPAD_ROW4_PIN);
  }
}

int read_col(int col) {
  if (col == 1) {
    return gpio_read(KEYPAD_COL1_PORT, KEYPAD_COL1_PIN);
  } else if (col == 2) {
    return gpio_read(KEYPAD_COL2_PORT, KEYPAD_COL2_PIN);
  } else {
    return gpio_read(KEYPAD_COL3_PORT, KEYPAD_COL3_PIN);
  }
}

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

int find_num(int col, int row) {
  switch (col) {
    case 1: {
      switch (row) {
          case 1:
            return '1';
            break;
          case 2:
            return '4';
            break;
          case 3:
            return '7';
            break; 
          default:
            return '*';
            break;
        }
      }
      break;
    case 2: {
      switch (row) {
          case 1:
            return '2';
            break;
          case 2:
            return '5';
            break;
          case 3:
            return '8';
            break; 
          default:
            return '0';
            break;
        }
      break;
      }
    default: {
      switch (row) {
          case 1:
            return '3';
            break;
          case 2:
            return '6';
            break;
          case 3:
            return '9';
            break; 
          default:
            return '#';
            break;
        }
      break; 
    }
  }
}


// returna ascii key corresponding to pressed letter
// if no keys are pressed, return null
// if multiple are pressed, return 1 of the pressed keys
char keypad_read() {
    for (int i = 1; i < 4; i++) {
      if (read_col(i)) {
        for (int j = 1; j < 5; j++) {
          if (read_row(j)) {
            return find_num(i, j);
          }
        }
      }
    }
    return '\0';
}
