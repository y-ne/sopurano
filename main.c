#include "pico/cyw43_arch.h"
#include "pico/stdlib.h"
#include <stdio.h>

int main() {
  stdio_init_all();

  if (cyw43_arch_init()) {
    printf("cyw43 init failed\n");
    return -1;
  }

  while (true) {
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
    sleep_ms(250);
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
    sleep_ms(250);
  }
  return 0;
}
