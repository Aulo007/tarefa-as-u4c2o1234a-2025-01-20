#include <stdio.h>
#include "pico/stdlib.h"
#include "keypad.h"
#include "matriz_rgb.h"
#include "animation9.h"
#include "menu.h"

MenuOption main_menu[] = {
    {'1', "Primeira animação"},
    {'2', "Segunda animação"},
    {'3', "Terceira animação"},
    {'4', "Quarta animação"},
    {'5', "Quinta animação"},
    {'6', "Sexta animação"},
    {'7', "Sétima animação"},
    {'8', "Oitava animação"},
    {'9', "Nona animação"},
    {'A', "Desligar todos os leds"},
    {'B', "Ligar todos os LEDs na cor azul na intensidade máxima"},
    {'C', "Ligar todos os LEDs na cor vermelha na intensidade de 80%"},
    {'D', "Ligar todos os LEDs na cor verde na intensidade de 50%"},
    {'#', "Ligar todos os LEDs na cor branca na intensidade de 20%"}};

int main()
{
    // Inicializa entradas e saídas.
    stdio_init_all();

    // Inicializa matriz de LEDs NeoPixel.
    npInit(15); // Usar a constante LED_PIN definida anteriormente
    keypad_init();
    npClear();

    menu_display(main_menu, sizeof(main_menu) / sizeof(MenuOption));
    bool mostra_menu = true;

    char key = 'X';

    npWrite(); // Escreve os dados nos LEDs.
    do
    {
        key = keypad_read();
        switch (key)
        {
        case '1':
            printf("Tocando primeira animação... \n");
            break;

        case '2':
            printf("Tocando segunda animação... \n");
            break;

        case '3':
            printf("Tocando terceira animação... \n");
            break;
        case '4':
            printf("Tocando quarta animação... \n");
            break;
        case '5':
            printf("Tocando quinta animação... \n");
            break;
        case '6':
            printf("Tocando sexta animação... \n");
            break;

        case '7':
            printf("Tocanodo sétima animação... \n");
            break;

        case '8':
            printf("Tocando oitava animação... \n");
            break;

        case '9':
            printf("Tocanodi nona animação... \n");
            animar_desenhos_9(key);
            break;
        case 'A':
            printf("Desliganod os leds... n");
            npClear();
            break;

        case 'B':
            printf("Ligando todos os leds na cor azul na intensidade máxima... \n");
            break;

        case 'C':
            printf("Ligando todos os leds na cor vermelha na intensidade de 80%... \n");
            break;

        case 'D':
            printf("Ligando todos os leds na cor verde na intensidade de 50%... \n");
            break;
        case '#':
            printf("Ligando todos os leds na cor branca na intensidade de 20%... \n");
            break;
        }

    } while (true);
}
