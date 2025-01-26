#include "matriz_rgb.h"
#include "pico/stdlib.h"
#include "keypad.h"
#include "animation7.h"

#define ROWS 5
#define COLS 5
#define COLORS 3
#define PERIODO 200 // Isso é o equivalente a 5 frames, uma vez que 1000/200 = 5
#define DESENHOS 9  // Quantidade de desenhos que terá a sua animação

int caixa_de_desenhos7[9][ROWS][COLS][COLORS] = {
    {{{255, 255, 255}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {255, 255, 255}},
     {{0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}},
     {{255, 255, 255}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {255, 255, 255}},
     {{0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}},
     {{255, 255, 255}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {255, 255, 255}}},

    {{{0, 0, 255}, {0, 255, 0}, {255, 0, 0}, {0, 255, 0}, {0, 0, 255}},
     {{0, 255, 0}, {255, 0, 0}, {0, 0, 255}, {255, 0, 0}, {0, 255, 0}},
     {{255, 0, 0}, {0, 0, 255}, {0, 255, 0}, {0, 0, 255}, {255, 0, 0}},
     {{0, 255, 0}, {255, 0, 0}, {0, 0, 255}, {255, 0, 0}, {0, 255, 0}},
     {{0, 0, 255}, {0, 255, 0}, {255, 0, 0}, {0, 255, 0}, {0, 0, 255}}},

    {{{255, 0, 255}, {255, 255, 0}, {0, 255, 255}, {255, 255, 0}, {255, 0, 255}},
     {{255, 255, 0}, {0, 255, 255}, {255, 0, 255}, {0, 255, 255}, {255, 255, 0}},
     {{0, 255, 255}, {255, 0, 255}, {255, 255, 0}, {255, 0, 255}, {0, 255, 255}},
     {{255, 255, 0}, {0, 255, 255}, {255, 0, 255}, {0, 255, 255}, {255, 255, 0}},
     {{255, 0, 255}, {255, 255, 0}, {0, 255, 255}, {255, 255, 0}, {255, 0, 255}}},

    {{{128, 0, 128}, {128, 128, 128}, {0, 128, 128}, {128, 128, 128}, {128, 0, 128}},
     {{128, 128, 128}, {0, 128, 128}, {128, 0, 128}, {0, 128, 128}, {128, 128, 128}},
     {{0, 128, 128}, {128, 0, 128}, {128, 128, 128}, {128, 0, 128}, {0, 128, 128}},
     {{128, 128, 128}, {0, 128, 128}, {128, 0, 128}, {0, 128, 128}, {128, 128, 128}},
     {{128, 0, 128}, {128, 128, 128}, {0, 128, 128}, {128, 128, 128}, {128, 0, 128}}},

    {{{0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}},
     {{255, 255, 255}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {255, 255, 255}},
     {{0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}},
     {{255, 255, 255}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {255, 255, 255}},
     {{0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}}},

    {{{255, 128, 0}, {0, 255, 128}, {255, 0, 128}, {0, 255, 128}, {255, 128, 0}},
     {{0, 255, 128}, {255, 0, 128}, {255, 128, 0}, {255, 0, 128}, {0, 255, 128}},
     {{255, 0, 128}, {255, 128, 0}, {0, 255, 128}, {255, 128, 0}, {255, 0, 128}},
     {{0, 255, 128}, {255, 0, 128}, {255, 128, 0}, {255, 0, 128}, {0, 255, 128}},
     {{255, 128, 0}, {0, 255, 128}, {255, 0, 128}, {0, 255, 128}, {255, 128, 0}}},

    {{{128, 64, 0}, {64, 128, 0}, {128, 0, 64}, {64, 128, 0}, {128, 64, 0}},
     {{64, 128, 0}, {128, 0, 64}, {128, 64, 0}, {128, 0, 64}, {64, 128, 0}},
     {{128, 0, 64}, {128, 64, 0}, {64, 128, 0}, {128, 64, 0}, {128, 0, 64}},
     {{64, 128, 0}, {128, 0, 64}, {128, 64, 0}, {128, 0, 64}, {64, 128, 0}},
     {{128, 64, 0}, {64, 128, 0}, {128, 0, 64}, {64, 128, 0}, {128, 64, 0}}},

    {{{0, 255, 255}, {255, 0, 255}, {255, 255, 0}, {255, 0, 255}, {0, 255, 255}},
     {{255, 0, 255}, {255, 255, 0}, {0, 255, 255}, {255, 255, 0}, {255, 0, 255}},
     {{255, 255, 0}, {0, 255, 255}, {255, 0, 255}, {0, 255, 255}, {255, 255, 0}},
     {{255, 0, 255}, {255, 255, 0}, {0, 255, 255}, {255, 255, 0}, {255, 0, 255}},
     {{0, 255, 255}, {255, 0, 255}, {255, 255, 0}, {255, 0, 255}, {0, 255, 255}}},

    {{{192, 192, 192}, {64, 64, 64}, {192, 192, 192}, {64, 64, 64}, {192, 192, 192}},
     {{64, 64, 64}, {192, 192, 192}, {64, 64, 64}, {192, 192, 192}, {64, 64, 64}},
     {{192, 192, 192}, {64, 64, 64}, {192, 192, 192}, {64, 64, 64}, {192, 192, 192}},
     {{64, 64, 64}, {192, 192, 192}, {64, 64, 64}, {192, 192, 192}, {64, 64, 64}},
     {{192, 192, 192}, {64, 64, 64}, {192, 192, 192}, {64, 64, 64}, {192, 192, 192}}}
};

void animar_desenhos_7(char key_de_ativacao)
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

            setMatrizDeLEDSComIntensidade(caixa_de_desenhos7[i], 1, 1, 1);
            npWrite();         // Atualiza a matriz de LEDs
            sleep_ms(PERIODO); // Controla o tempo entre cada quadro
        }
    }
}
