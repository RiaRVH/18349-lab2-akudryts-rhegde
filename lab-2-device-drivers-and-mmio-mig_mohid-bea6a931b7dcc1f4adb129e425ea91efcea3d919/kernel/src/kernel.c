#include <gpio.h>
#include <i2c.h>
#include <printk.h>
#include <uart_polling.h>
#include <unistd.h>
#include <lcd_driver.h>
#include <keypad_driver.h>

int kernel_main() {
  keypad_init();
  uart_polling_init(139);


  while(1) {
    char x = keypad_read();
    // char y = uart_polling_get_byte();
    // uart_polling_put_byte(y);
    printk("%c", x);
  }
  return 0;
}
