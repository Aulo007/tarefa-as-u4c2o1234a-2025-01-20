#include <stdio.h>
#include "pico/stdlib.h"
#include "keypad.h"
#include "matriz_rgb.h"
#include "animation2.h"
#include "animation9.h"
#include "animationC.h"

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
        case '2':
            printf("Botão 2 apertado\n");
            animar_desenhos_2();
            break;
        case '9':
            printf("Botão 9 apertado\n");
            animar_desenhos_9();
            break;
        case 'A':
            printf("Botão A apertado\n");
            npClear();
            break;
        case 'C':
            printf("Botão C apertado\n");
            animar_desenhos_C();
            break;
        }
    }
}
