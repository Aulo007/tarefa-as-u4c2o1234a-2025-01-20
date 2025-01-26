#include "matriz_rgb.h"
#include "animacao_6.h"
#include "pico/stdlib.h"
#include "keypad.h"

#define ROWS 5
#define COLS 5
#define COLORS 3
#define PERIODO 200
#define DESENHOS 9 // Quantidade de desenhos que terá a sua animação

// FRASE: EMBARCA TECH:
int caixa_de_desenhos6[10][ROWS][COLS][COLORS] = {
    {{{0, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}}},

    {{{0, 0, 0}, {216, 255, 0}, {216, 255, 0}, {216, 255, 0}, {0, 0, 0}},
     {{0, 0, 0}, {216, 255, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {216, 255, 0}, {216, 255, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {216, 255, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {216, 255, 0}, {216, 255, 0}, {216, 255, 0}, {0, 0, 0}}},

    {{{0, 0, 0}, {0, 0, 0}, {0, 8, 255}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 8, 255}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 8, 255}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 8, 255}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 8, 255}, {0, 0, 0}, {0, 0, 0}}},

    {{{0, 0, 0}, {16, 163, 0}, {16, 163, 0}, {16, 163, 0}, {0, 0, 0}},
     {{0, 0, 0}, {16, 163, 0}, {0, 0, 0}, {16, 163, 0}, {0, 0, 0}},
     {{0, 0, 0}, {16, 163, 0}, {0, 0, 0}, {16, 163, 0}, {0, 0, 0}},
     {{0, 0, 0}, {16, 163, 0}, {0, 0, 0}, {16, 163, 0}, {0, 0, 0}},
     {{0, 0, 0}, {16, 163, 0}, {16, 163, 0}, {16, 163, 0}, {0, 0, 0}}},

    {{{0, 0, 0}, {0, 8, 255}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 8, 255}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 8, 255}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 8, 255}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 8, 255}, {216, 255, 0}, {255, 0, 0}, {0, 0, 0}}},

    {{{216, 255, 0}, {216, 255, 0}, {216, 255, 0}, {216, 255, 0}, {216, 255, 0}},
     {{0, 0, 0}, {0, 0, 0}, {216, 255, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {216, 255, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {216, 255, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {216, 255, 0}, {0, 0, 0}, {0, 0, 0}}},

    {{{0, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {255, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {0, 0, 0}}},

    {{{0, 0, 0}, {3, 0, 255}, {3, 0, 255}, {3, 0, 255}, {0, 0, 0}},
     {{0, 0, 0}, {3, 0, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {3, 0, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {3, 0, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {3, 0, 255}, {3, 0, 255}, {3, 0, 255}, {0, 0, 0}}},

    {{{0, 0, 0}, {16, 163, 0}, {0, 0, 0}, {16, 163, 0}, {0, 0, 0}},
     {{0, 0, 0}, {16, 163, 0}, {0, 0, 0}, {16, 163, 0}, {0, 0, 0}},
     {{0, 0, 0}, {16, 163, 0}, {16, 163, 0}, {16, 163, 0}, {0, 0, 0}},
     {{0, 0, 0}, {16, 163, 0}, {0, 0, 0}, {16, 163, 0}, {0, 0, 0}},
     {{0, 0, 0}, {16, 163, 0}, {0, 0, 0}, {16, 163, 0}, {0, 0, 0}}},

    {{{255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}},
     {{255, 255, 255}, {216, 255, 0}, {0, 8, 255}, {255, 0, 0}, {255, 255, 255}},
     {{255, 255, 255}, {216, 255, 0}, {0, 8, 255}, {255, 0, 0}, {255, 255, 255}},
     {{255, 255, 255}, {216, 255, 0}, {0, 8, 255}, {255, 0, 0}, {255, 255, 255}},
     {{255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}}},
};

void animar_desenhos_6(char key_de_ativacao)
{
    while (true)
    {
        // Verifica a tecla antes de cada quadro de animação
        char key_atual = keypad_read();
        if (key_atual != key_de_ativacao && key_atual != 'X')
        {
            npClear(); // Limpa os LEDs
            return;
        }

        for (int i = 0; i < DESENHOS; i++)
        {
            // Verifica a tecla a cada quadro, antes de mostrar o próximo desenho
            key_atual = keypad_read();
            if (key_atual != key_de_ativacao && key_atual != 'X')
            {
                npClear(); // Limpa os LEDs
                return;
            }

            setMatrizDeLEDSComIntensidade(caixa_de_desenhos6[i], 1, 1, 1);
            npWrite();         // Atualiza a matriz de LEDs
            sleep_ms(PERIODO); // Controla o tempo entre cada quadro
        }
    }
}