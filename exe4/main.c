#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int botao = 28;
const int Lvermelha = 5;
const int Lroxa = 8;
const int Lazul = 11;
const int Lamarela = 15;

int main() {
  stdio_init_all();
  //--------------------------
  gpio_init(botao);
  gpio_init(Lvermelha);
  gpio_init(Lroxa);
  gpio_init(Lazul);
  gpio_init(Lamarela);
  //--------------------------
  gpio_set_dir(botao, GPIO_IN);
  gpio_set_dir(Lvermelha, GPIO_OUT);
  gpio_set_dir(Lroxa, GPIO_OUT);
  gpio_set_dir(Lazul, GPIO_OUT);
  gpio_set_dir(Lamarela, GPIO_OUT);
  //--------------------------
  gpio_pull_up(botao);

  
  while (true) {
    if (gpio_get(botao) == 0){
      gpio_put(Lvermelha, 1);
      sleep_ms(300);
      gpio_put(Lvermelha, 0);

      gpio_put(Lroxa, 1);
      sleep_ms(300);
      gpio_put(Lroxa, 0);

      gpio_put(Lazul, 1);
      sleep_ms(300);
      gpio_put(Lazul, 0);

      gpio_put(Lamarela, 1);
      sleep_ms(300);
      gpio_put(Lamarela, 0);

      while(gpio_get(botao) ==0);
    }
  }
}
