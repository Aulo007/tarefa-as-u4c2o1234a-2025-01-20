#include "matriz_rgb.h"
#include "animation9.h"
#include "pico/stdlib.h"
#include "keypad.h"

#define ROWS 5
#define COLS 5
#define COLORS 3
#define PERIODO 2000 // Isso é o equivalente a 5 frames, uma vez que 1000/200 = 5
#define DESENHOS 9  // Quantidade de desenhos que terá a sua animação

int caixa_de_desenhos[9][ROWS][COLS][COLORS] = {
    {{{7, 13, 4}, {7, 13, 4}, {7, 13, 4}, {255, 0, 0}, {7, 13, 4}},
     {{7, 13, 4}, {7, 13, 4}, {255, 0, 0}, {255, 0, 0}, {7, 13, 4}},
     {{7, 13, 4}, {255, 0, 0}, {7, 13, 4}, {255, 0, 0}, {7, 13, 4}},
     {{7, 13, 4}, {7, 13, 4}, {7, 13, 4}, {255, 0, 0}, {7, 13, 4}},
     {{7, 13, 4}, {7, 13, 4}, {7, 13, 4}, {255, 0, 0}, {7, 13, 4}}},

    {{{0, 0, 0}, {30, 187, 45}, {30, 187, 45}, {30, 187, 45}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {30, 187, 45}, {0, 0, 0}},
     {{0, 0, 0}, {30, 187, 45}, {30, 187, 45}, {30, 187, 45}, {0, 0, 0}},
     {{0, 0, 0}, {30, 187, 45}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {30, 187, 45}, {30, 187, 45}, {30, 187, 45}, {0, 0, 0}}},

    {{{0, 0, 0}, {212, 255, 0}, {212, 255, 0}, {212, 255, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {212, 255, 0}, {0, 0, 0}},
     {{0, 0, 0}, {212, 255, 0}, {212, 255, 0}, {212, 255, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {212, 255, 0}, {0, 0, 0}},
     {{0, 0, 0}, {212, 255, 0}, {212, 255, 0}, {212, 255, 0}, {0, 0, 0}}},

    {{{0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}}},

    {{{0, 0, 0}, {15, 19, 89}, {15, 19, 89}, {15, 19, 89}, {0, 0, 0}},
     {{0, 0, 0}, {15, 19, 89}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {15, 19, 89}, {15, 19, 89}, {15, 19, 89}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {15, 19, 89}, {0, 0, 0}},
     {{0, 0, 0}, {15, 19, 89}, {15, 19, 89}, {15, 19, 89}, {0, 0, 0}}},

    {{{0, 0, 0}, {0, 13, 255}, {0, 13, 255}, {0, 13, 255}, {0, 0, 0}},
     {{0, 0, 0}, {0, 13, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 13, 255}, {0, 13, 255}, {0, 13, 255}, {0, 0, 0}},
     {{0, 0, 0}, {0, 13, 255}, {0, 0, 0}, {0, 13, 255}, {0, 0, 0}},
     {{0, 0, 0}, {0, 13, 255}, {0, 13, 255}, {0, 13, 255}, {0, 0, 0}}},

    {{{0, 0, 0}, {235, 235, 235}, {235, 235, 235}, {235, 235, 235}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {235, 235, 235}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {235, 235, 235}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {235, 235, 235}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {235, 235, 235}, {0, 0, 0}}},

    {{{0, 0, 0}, {31, 209, 174}, {31, 209, 174}, {31, 209, 174}, {0, 0, 0}},
     {{0, 0, 0}, {31, 209, 174}, {0, 0, 0}, {31, 209, 174}, {0, 0, 0}},
     {{0, 0, 0}, {31, 209, 174}, {31, 209, 174}, {31, 209, 174}, {0, 0, 0}},
     {{0, 0, 0}, {31, 209, 174}, {0, 0, 0}, {31, 209, 174}, {0, 0, 0}},
     {{0, 0, 0}, {31, 209, 174}, {31, 209, 174}, {31, 209, 174}, {0, 0, 0}}},

    {{{0, 0, 0}, {243, 250, 162}, {243, 250, 162}, {243, 250, 162}, {0, 0, 0}},
     {{0, 0, 0}, {243, 250, 162}, {0, 0, 0}, {243, 250, 162}, {0, 0, 0}},
     {{0, 0, 0}, {243, 250, 162}, {243, 250, 162}, {243, 250, 162}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {243, 250, 162}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {243, 250, 162}, {0, 0, 0}}},
};

void animar_desenhos_9(void)
{
    while (true)
    {
        // Verifica a tecla antes de cada quadro de animação
        char key_atual = keypad_read();
        if (key_atual != '1' && key_atual != 'X')
        {
            npClear(); // Limpa os LEDs
            return;    // Sai da animação se a tecla for diferente de '1'
        }

        for (int i = 0; i < DESENHOS; i++)
        {
            // Verifica a tecla a cada quadro, antes de mostrar o próximo desenho
            key_atual = keypad_read();
            if (key_atual != '1' && key_atual != 'X')
            {
                npClear(); // Limpa os LEDs
                return;    // Sai da animação se a tecla for diferente de '1'
            }

            setMatrizDeLEDSComIntensidade(caixa_de_desenhos[i], 1, 1, 1);
            npWrite();         // Atualiza a matriz de LEDs
            sleep_ms(PERIODO); // Controla o tempo entre cada quadro
        }
    }
}