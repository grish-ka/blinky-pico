#include <stdio.h>
#include <ctype.h>
#include "pico/stdlib.h"

// --- Morse Code Configuration ---
const int DOT_MS = 200; // Speed of the dots (lower = faster)
const uint LED_PIN = PICO_DEFAULT_LED_PIN;

// Morse patterns for A-Z
const char *LETTERS[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", // A-J
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",   // K-T
    "..-", "...-", ".--", "-..-", "-.--", "--.."                            // U-Z
};

// Morse patterns for 0-9
const char *NUMBERS[] = {
    "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."
};

void blink_element(int duration) {
    gpio_put(LED_PIN, 1);
    sleep_ms(duration);
    gpio_put(LED_PIN, 0);
    sleep_ms(DOT_MS); // Gap between parts of the same letter
}

void play_pattern(const char *pattern) {
    while (*pattern) {
        if (*pattern == '.') {
            blink_element(DOT_MS);
        } else if (*pattern == '-') {
            blink_element(DOT_MS * 3);
        }
        pattern++;
    }
    sleep_ms(DOT_MS * 2); // Gap between letters (Total 3 units: 1 from loop + 2 here)
}

int main() {
    stdio_init_all();
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    printf("Morse Translator Ready! Type a message and hit Enter...\n");

    while (true) {
        char c = getchar(); // Blocks until a character is received
        
        // ECHO the character immediately so you see what you typed
        putchar(c); 

        c = toupper(c);     
        
        // FIX 1: Initialize 'a' so it never crashes on Spaces or Newlines
        const char* a = ""; 

        if (c >= 'A' && c <= 'Z') {
            a = LETTERS[c - 'A'];
            play_pattern(a);
        } else if (c >= '0' && c <= '9') {
            a = NUMBERS[c - '0'];
            play_pattern(a);
        } else if (c == ' ') {
            a = " "; // Visual indicator for space
            sleep_ms(DOT_MS * 4); 
        }

        // FIX 2: Use %s for the string 'a', and only print if we actually found Morse
        if (*a != '\0') {
            printf("\n   Morse sequence: %s\n", a);
        }
    }
}