#include "keypad.h"

static uint colunas[4] = {COL1, COL2, COL3, COL4};
static uint linhas[4] = {ROW1, ROW2, ROW3, ROW4};

void keypad_init(void)
{
    // Inicializar colunas como entrada com pull-up
    for (int i = 0; i < 4; i++)
    {
        gpio_init(colunas[i]);
        gpio_set_dir(colunas[i], GPIO_IN);
        gpio_pull_up(colunas[i]);
    }

    // Inicializar linhas como saída
    for (int i = 0; i < 4; i++)
    {
        gpio_init(linhas[i]);
        gpio_set_dir(linhas[i], GPIO_OUT);
        gpio_put(linhas[i], 1);
    }
}
