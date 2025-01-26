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
    {'#', "Ligar todos os LEDs na cor branca na intensidade de 20%"},};

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
    char key_atual = 'O';

    npWrite(); // Escreve os dados nos LEDs.
    do
    {
        key = keypad_read();
        if (key != key_atual && key != 'X')
        {

            if (menu_is_valid_option(main_menu, sizeof(main_menu) / sizeof(MenuOption), key))
            {
                switch (key)
                {
                case '1':

                    mostra_menu = true;
                    key_atual = '1';
                    break;

                case '2':

                    mostra_menu = true;
                    key_atual = '2';
                    break;

                case '3':

                    mostra_menu = true;
                    key_atual = '3';
                    break;
                case '4':

                    mostra_menu = true;
                    key_atual = '4';
                    break;
                case '5':

                    mostra_menu = true;
                    key_atual = '5';

                    break;
                case '6':

                    mostra_menu = true;
                    key_atual = '6';
                    break;

                case '7':

                    mostra_menu = true;
                    key_atual = '7';
                    break;

                case '8':

                    mostra_menu = true;
                    key_atual = '8';
                    break;

                case '9':

                    animar_desenhos_9(key);
                    mostra_menu = true;
                    key_atual = '9';
                    break;
                case 'A':

                    npClear();
                    mostra_menu = true;
                    key_atual = 'A';
                    break;

                case 'B':

                    mostra_menu = true;
                    key_atual = 'B';
                    break;

                case 'C':

                    mostra_menu = true;
                    key_atual = 'C';
                    break;

                case 'D':

                    mostra_menu = true;
                    key_atual = 'D';
                    break;
                case '#':
                    mostra_menu = true;
                    key_atual = '#';
                    break;
                }
                if (mostra_menu)
                {
                    menu_display(main_menu, sizeof(main_menu) / sizeof(MenuOption));
                    mostra_menu = false;
                }
            }
        }

    } while (true);
}
