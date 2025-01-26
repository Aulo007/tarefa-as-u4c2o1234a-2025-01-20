#include "matriz_rgb.h"
#include "animation9.h"
#include "pico/stdlib.h"
#include "keypad.h"

#define ROWS 5
#define COLS 5
#define COLORS 3
#define PERIODO 200 // Isso é o equivalente a 5 frames, uma vez que 1000/200 = 5
#define DESENHOS 1  // Quantidade de desenhos que terá a sua animação

uint8_t matrizhashtag[5][5][3] = {
    {{51, 51, 51}, {51, 51, 51}, {51, 51, 51}, {51, 51, 51}, {51, 51, 51}},
    {{51, 51, 51}, {51, 51, 51}, {51, 51, 51}, {51, 51, 51}, {51, 51, 51}},
    {{51, 51, 51}, {51, 51, 51}, {51, 51, 51}, {51, 51, 51}, {51, 51, 51}},
    {{51, 51, 51}, {51, 51, 51}, {51, 51, 51}, {51, 51, 51}, {51, 51, 51}},
    {{51, 51, 51}, {51, 51, 51}, {51, 51, 51}, {51, 51, 51}, {51, 51, 51}}};

void animar_desenhos_hashtag(void)
{

    char tecla;

    npWrite2(matrizhashtag); //"Imprime" nos LED's como na 'matrizhashtag'
    while (true)
    {
        tecla = keypad_read(); // Verifica qual tecla é precionada constantemente para poder interromper a função
        if ((tecla != '#') && (tecla != 'X'))
        {
            break;
        }
    }
}