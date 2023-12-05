#include <iostream>
#include "lx16a-servo.h"
#include <stdio.h>
#include "pico/stdlib.h"

LX16ABus servoBus;
LX16AServo servo(&servoBus, 3);
LX16AServo servoOr(&servoBus, 4);
const uint LED_PIN = 25;

int main()
{
  stdio_init_all();
  sleep_ms(100);
  for (auto i = 0; i < 3; i++)
  {
    printf("%i\n", i);
    sleep_ms(1000);
  }
  servoBus.begin(uart1, 4,5);
  servoBus.debug(true);
  servoBus.retry = 0;
  gpio_init(LED_PIN);
  gpio_set_dir(LED_PIN, GPIO_OUT);
  gpio_put(LED_PIN, 0);

  while (1)
  {
    gpio_put(LED_PIN, 0);
    sleep_ms(250);
    gpio_put(LED_PIN, 1);

    sleep_ms(250);
    // printf("id %i %i %i\n", servoOr.id_read(), servoOr.pos_read(), servo.isCommandOk());

    servo.move_time(9000, 1000);

    servoOr.move_time(2000, 1000);
    sleep_ms(1000);
    servo.move_time(13000, 1000);

    servoOr.move_time(6000, 1000);
    sleep_ms(1000);
    // std::cout << "id" << servo.id_read() << " " << servo.pos_read() << " - " << servo.isCommandOk() << std::endl;
  }
}
