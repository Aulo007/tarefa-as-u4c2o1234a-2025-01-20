#include <stdio.h>
#include "pico/stdlib.h"
#include "keypad.h"
#include "matriz_rgb.h"
#include "animacao_3.h" // Incluindo o cabeçalho da animação 3

#define MATRIX_SIZE 5

 npLED_t led_matrix[5][5]; // Matriz de LEDs do tipo correto

int main()
{
    // Inicializa entradas e saídas.
    stdio_init_all();

    // Inicializa matriz de LEDs NeoPixel.
    npInit(15); // Usar a constante LED_PIN definida anteriormente
    keypad_init();
    npClear();

    // Atualiza a matriz na faixa de LEDs
    npUpdateMatrix(led_matrix);
    char key = '0';

    npWrite(); // Escreve os dados nos LEDs.
    while (true)
    {
        key = keypad_read(); // Lê a tecla pressionada.
        switch (key)
        {
        case '1':
            printf("Botão 1 apertado\n");
            break;
        case 'A':
            printf("Botão A apertado\n");
            break;
        case 'C': // Caso o botão 'C' seja pressionado.
            printf("Botão C apertado\n");
            animacao_3(led_matrix); // Aplica a animação 3.
            npUpdateMatrix(led_matrix); // Atualiza os LEDs com a matriz.
            npWrite(); // Escreve os dados nos LEDs.
            break;
        }
    }
}
