#include <stdint.h>

__attribute__((import_module("env"), import_name("gpio_set_level")))
void gpio_set_level(int pin, int level);


__attribute__((import_module("env"), import_name("sleep_ms")))
void sleep_ms(int milliseconds);


__attribute__((import_module("env"), import_name("print_debug")))
void print_debug(const char *message);


#define LED_GPIO 8 
#define MARKER_GPIO 9


void main() {
    while(1) {
        int counter = 0;
        gpio_set_level(MARKER_GPIO, 1);

        while (counter < 100000) {
            gpio_set_level(LED_GPIO, 1);  
            gpio_set_level(LED_GPIO, 0);
            counter++;
        }

        int count = 0;

        
        while (count < 100){
            gpio_set_level(MARKER_GPIO, 0);
            count++;    
        }
    }
}