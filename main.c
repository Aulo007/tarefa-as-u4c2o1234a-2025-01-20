#include <stdio.h>
#include "pico/stdlib.h"
#include "keypad.h"
#include "matriz_rgb.h"
#include "animation_3.h"

int main()
{
    // Inicializa entradas e saídas.
    stdio_init_all();

    // Inicializa matriz de LEDs NeoPixel.
    npInit(15); // Usar a constante LED_PIN definida anteriormente
    keypad_init();
    npClear();

    char key = '0';

    npWrite(); // Escreve os dados nos LEDs.
    while (true)
    {
        key = keypad_read();
        switch (key)
        {
        case '1':
            printf("Botão 1 apertado\n");
            break;

        case '3':
            printf("Botão 3 apertado\n");
            animar_desenhos_1();
            break;
        case 'A':
            printf("Botão A apertado\n");
            npClear();
            break;
        }
    }
}