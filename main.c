#include "hardware/i2c.h"
#include "pico/cyw43_arch.h"
#include "pico/stdlib.h"

#define SSD1306_I2C_ADDR 0x3C
#define I2C_SDA 4
#define I2C_SCL 5

#define SSD1306_WIDTH 128
#define SSD1306_HEIGHT 64

#define SSD1306_SET_MEM_MODE 0x20
#define SSD1306_SET_COL_ADDR 0x21
#define SSD1306_SET_PAGE_ADDR 0x22
#define SSD1306_SET_MUX_RATIO 0xA8
#define SSD1306_SET_DISPLAY 0xAE
#define SSD1306_SET_CHARGE_PUMP 0x8D
#define SSD1306_SET_COM_PIN_CFG 0xDA

void ssd1306_send_command(uint8_t cmd) {
  uint8_t buf[2] = {0x80, cmd};
  i2c_write_blocking(i2c_default, SSD1306_I2C_ADDR, buf, 2, false);
}

void ssd1306_init() {
  sleep_ms(100);
  ssd1306_send_command(SSD1306_SET_DISPLAY);
  ssd1306_send_command(SSD1306_SET_MEM_MODE);
  ssd1306_send_command(0x00);
  ssd1306_send_command(SSD1306_SET_MUX_RATIO);
  ssd1306_send_command(0x3F);
  ssd1306_send_command(SSD1306_SET_COM_PIN_CFG);
  ssd1306_send_command(0x12);
  ssd1306_send_command(SSD1306_SET_CHARGE_PUMP);
  ssd1306_send_command(0x14);
  ssd1306_send_command(SSD1306_SET_DISPLAY | 0x01);
}

int main() {
  if (cyw43_arch_init())
    return -1;

  i2c_init(i2c_default, 400000);
  gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
  gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
  gpio_pull_up(I2C_SDA);
  gpio_pull_up(I2C_SCL);

  ssd1306_init();

  for (;;) {
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
    sleep_ms(250);
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
    sleep_ms(250);
  }
}
