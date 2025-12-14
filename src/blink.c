#include "pico/stdlib.h"

int main() {
    // Initialize the standard IO and the onboard LED
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    // Loop forever
    while (true) {
        gpio_put(LED_PIN, 1); // Turn LED ON
        sleep_ms(250);        // Wait 250ms
        gpio_put(LED_PIN, 0); // Turn LED OFF
        sleep_ms(250);        // Wait 250ms
    }
}