#include "matriz_rgb.h"
#include "animation9.h"
#include "pico/stdlib.h"
#include "keypad.h"

#define ROWS 5
#define COLS 5
#define COLORS 3
#define PERIODO 200 // Isso é o equivalente a 5 frames, uma vez que 1000/200 = 5
#define DESENHOS 5  // Quantidade de desenhos que terá a sua animação

int caixa_de_desenhos[2][ROWS][COLS][COLORS] = {

    {{{255, 255, 255}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 255, 255}},
     {{255, 0, 0}, {0, 255, 0}, {255, 0, 0}, {0, 255, 0}, {255, 0, 0}},
     {{255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}},
     {{255, 0, 0}, {255, 0, 0}, {255, 255, 255}, {255, 0, 0}, {255, 0, 0}},
     {{255, 0, 0}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 0, 0}}},

    // Segunda matriz (matriz2) - pode ser diferente ou similar
    {
        {{255, 255, 255}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 255, 255}},
        {{255, 0, 0}, {0, 255, 0}, {255, 0, 0}, {0, 255, 0}, {255, 0, 0}},
        {{255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}},
        {{255, 0, 0}, {255, 0, 0}, {255, 255, 255}, {255, 0, 0}, {255, 0, 0}},
        {{255, 0, 0}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 0, 0}}}};

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

            setMatrizDeLEDSComIntensidade(caixa_de_desenhos[i], 1, 1, 1.0);
            npWrite();         // Atualiza a matriz de LEDs
            sleep_ms(PERIODO); // Controla o tempo entre cada quadro
        }
    }
}