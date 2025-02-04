#include <stdio.h>
#include <stdint.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED_GPIO 8
#define MARKER_GPIO 9

void app_main(void) {
    gpio_config_t io_conf = {};
    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pin_bit_mask = (1ULL << LED_GPIO) | (1ULL << MARKER_GPIO); // Add MARKER_GPIO
    io_conf.pull_down_en = 0;
    io_conf.pull_up_en = 0;
    gpio_config(&io_conf);
    
    while (1) {
        int counter = 0;
        gpio_set_level(MARKER_GPIO, 1);  

        while (counter < 100000) {
            gpio_set_level(LED_GPIO, 1);
            gpio_set_level(LED_GPIO, 0);
            counter++;
        }

        int count = 0;
        
        while (count < 100) {
        gpio_set_level(MARKER_GPIO, 0);  
        count++;
        }
    }
}