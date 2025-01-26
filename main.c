#include <stdio.h>
#include "pico/stdlib.h"
#include "keypad.h"
#include "matriz_rgb.h"
#include "animacao_6.h"

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
        case 'A':
            printf("Botão A apertado\n");
            break;

        case '6':
            printf("Botão 6 apertado\n");
            animar_desenhos_6();
            break;
        }
    }
}
