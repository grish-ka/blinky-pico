#include "pico/stdlib.h"
#include <stdio.h>

int main() {

    stdio_init_all(); // Initialize USB Serial!

    // Initialize the standard IO and the onboard LED
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    // Loop forever
    while (true) {
        printf("Blinking LED!\n"); // Send text to computer
        gpio_put(LED_PIN, 1);
        sleep_ms(1000);
        
        printf("LED is off.\n");
        gpio_put(LED_PIN, 0);
        sleep_ms(1000);
    }
}