#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

//LEDs
const int PIN = 6;
const int PIN1 = 4;

//Botoes
const int BOT_V = 26;
const int BOT_R = 28;

int main() {
  stdio_init_all();

  // Configuração dos LEDs
  gpio_init(PIN);
  gpio_set_dir(PIN, GPIO_OUT);

  gpio_init(PIN1);
  gpio_set_dir(PIN1, GPIO_OUT);

  // Configuração dos botoes
  gpio_init(BOT_V);
  gpio_set_dir(BOT_V, GPIO_IN);
  gpio_pull_up(BOT_V); // Ativa o botao

  gpio_init(BOT_R);
  gpio_set_dir(BOT_R, GPIO_IN);
  gpio_pull_up(BOT_R); 

  int sinal = 0;
  int sinal2 = 0;

  while (true) {
// Analise primeiro botao
    if (gpio_get(BOT_V) == 0){ //quanto pino do botao mostra 0, significa que alguem pressionou ele
      sinal = 1 - sinal;          //muda o sinal toda vez que entra no if
      gpio_put(PIN, sinal);

      if (sinal == 0){
        printf("A luz foi apagada\n");
      } 
      else{
          printf("A luz foi acesa\n");
        }
      sleep_ms(200); 
      while (gpio_get(BOT_V) == 0); // Espera o botão ser solto
      }
// Analise segundo botao
    if (gpio_get(BOT_R) == 0){
      sinal2 = 1 - sinal2;
      gpio_put(PIN1, sinal2);

      if (sinal2 == 0){
        printf("Luz apagada\n");         
      } 
      else{
        printf("Luz acesa\n");
      }
      sleep_ms(200);
      while(gpio_get(BOT_R) ==0);
      }
    }
  }

