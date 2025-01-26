#include "matriz_rgb.h"
#include "animation9.h"
#include "pico/stdlib.h"
#include "keypad.h"

#define ROWS 5
#define COLS 5
#define COLORS 3
#define PERIODO 200 // Isso é o equivalente a 5 frames, uma vez que 1000/200 = 5
#define DESENHOS 1  // Quantidade de desenhos que terá a sua animação

int caixa_de_desenhos_hashtag[1][ROWS][COLS][COLORS] = {
    {{{255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}},
     {{255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}},
     {{255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}},
     {{255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}},
     {{255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}}}};

void animar_desenhos_hashtag(char key_de_ativacao)
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

            setMatrizDeLEDSComIntensidade(caixa_de_desenhos[i], 1, 1, 1);
            npWrite();         // Atualiza a matriz de LEDs
            sleep_ms(PERIODO); // Controla o tempo entre cada quadro
        }
    }
}