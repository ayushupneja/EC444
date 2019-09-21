/* Blink Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"

/* Can use project configuration menu (idf.py menuconfig) to choose the GPIO to blink,
   or you can edit the following line and set a number here.
*/
#define BLINK_GPIO 13
#define BLINK_GPIO2 12
#define BLINK_GPIO3 15
#define BLINK_GPIO4 14
char *decimal_to_binary(int n)
{
   int c, d, count;
   char *pointer;

   count = 0;
   pointer = (char*)malloc(4+1);

   if (pointer == NULL)
      exit(EXIT_FAILURE);

   for (c = 3 ; c >= 0 ; c--)
   {
      d = n >> c;

      if (d & 1)
         *(pointer+count) = 1 + '0';
      else
         *(pointer+count) = 0 + '0';

      count++;
   }
   *(pointer+count) = '\0';

   return pointer;
}
void app_main(void)
{
    /* Configure the IOMUX register for pad BLINK_GPIO (some pads are
       muxed to GPIO on reset already, but some default to other
       functions and need to be switched to GPIO. Consult the
       Technical Reference for a list of pads and their default
       functions.)
    */
    gpio_pad_select_gpio(BLINK_GPIO);
    gpio_pad_select_gpio(BLINK_GPIO2);
    gpio_pad_select_gpio(BLINK_GPIO3);
    gpio_pad_select_gpio(BLINK_GPIO4);
    /* Set the GPIO as a push/pull output */
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
    gpio_set_direction(BLINK_GPIO2, GPIO_MODE_OUTPUT);
    gpio_set_direction(BLINK_GPIO3, GPIO_MODE_OUTPUT);
    gpio_set_direction(BLINK_GPIO4, GPIO_MODE_OUTPUT);
    gpio_set_level(BLINK_GPIO,0);
    gpio_set_level(BLINK_GPIO2,0);
    gpio_set_level(BLINK_GPIO3,0);
    gpio_set_level(BLINK_GPIO4,0);
    //int n, c, k;
    //n = 13;
    //char *pointer;
    //pointer = decimal_to_binary(n);
    //printf("Binary string of %d is: %c\n", n, pointer[0]);

//    free(pointer);
    int i;
    char *binaryNum;
    while(1){
      for (i=0;i<=15;i++){
        binaryNum = decimal_to_binary(i);
        gpio_set_level(BLINK_GPIO, binaryNum[0]-'0');
        gpio_set_level(BLINK_GPIO2, binaryNum[1]-'0');
        gpio_set_level(BLINK_GPIO3, binaryNum[2]-'0');
        gpio_set_level(BLINK_GPIO4, binaryNum[3]-'0');
        free(binaryNum);
        vTaskDelay(1000 / portTICK_RATE_MS);
      }

    }
  }

      //  gpio_set_level(BLINK_GPIO, (int)pointer[32]);
      //  gpio_set_level(BLINK_GPIO2, (int)pointer[31]);
      //  gpio_set_level(BLINK_GPIO3, (int)pointer[30]);
      //  gpio_set_level(BLINK_GPIO4, (int)pointer[29]);
