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
    int counter = 0;

    print_debug("loop starting");
    gpio_set_level(MARKER_GPIO, 1);

    while (counter < 1000000) {
        print_debug("Turning LED ON");
        gpio_set_level(LED_GPIO, 1);  


        print_debug("Turning LED OFF");
        gpio_set_level(LED_GPIO, 0);  
    }
    print_debug("loop done");
    gpio_set_level(MARKER_GPIO, 0);
}
