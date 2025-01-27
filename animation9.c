#include "matriz_rgb.h"
#include "animation9.h"
#include "pico/stdlib.h"

#define ROWS 5
#define COLS 5
#define COLORS 3

int caixa_de_desenhos[23][ROWS][COLS][COLORS] = {

    {{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 255, 2}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 255, 2}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 255, 2}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 255, 2}}},

    {{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 255, 2}, {0, 255, 2}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 255, 2}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 255, 2}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}},

    {{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {255, 0, 0}, {0, 255, 2}, {0, 255, 2}, {0, 255, 2}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 255, 2}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}},

    {{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 255, 2}, {0, 255, 2}, {0, 255, 2}, {0, 255, 2}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 255, 2}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}}},

    {{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 255, 2}, {0, 255, 2}, {0, 255, 2}, {0, 255, 2}},
     {{0, 0, 0}, {0, 255, 2}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}}},

    {{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 255, 2}, {0, 255, 2}, {0, 255, 2}, {0, 0, 0}},
     {{0, 0, 0}, {0, 255, 2}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 255, 2}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}}},

    {{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 255, 2}, {0, 255, 2}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 255, 2}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 255, 2}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 255, 2}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}}},

    {{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 255, 2}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 255, 2}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 255, 2}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 255, 2}, {0, 255, 2}, {255, 0, 0}, {0, 0, 0}}},

    {{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 255, 2}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 255, 2}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 255, 2}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 255, 2}, {0, 255, 2}, {0, 255, 2}, {0, 0, 0}}},

    {{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 255, 2}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 255, 2}, {0, 0, 0}, {0, 255, 2}, {0, 0, 0}},
     {{0, 0, 0}, {0, 255, 2}, {0, 255, 2}, {0, 255, 2}, {0, 0, 0}}},

    {{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 255, 2}, {0, 0, 0}},
     {{0, 0, 0}, {0, 255, 2}, {0, 0, 0}, {0, 255, 2}, {0, 0, 0}},
     {{0, 0, 0}, {0, 255, 2}, {0, 255, 2}, {0, 255, 2}, {0, 0, 0}}},

    {{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 255, 2}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 255, 2}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 255, 2}, {0, 0, 0}},
     {{0, 0, 0}, {0, 255, 2}, {0, 255, 2}, {0, 255, 2}, {0, 0, 0}}},

    {{{0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 255, 2}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 255, 2}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 255, 2}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 255, 2}, {0, 0, 0}},
     {{0, 0, 0}, {0, 255, 2}, {0, 255, 2}, {0, 255, 2}, {0, 0, 0}}},

    {{{0, 0, 0}, {255, 0, 0}, {0, 255, 2}, {0, 255, 2}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 255, 2}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 255, 2}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 255, 2}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 255, 2}, {0, 255, 2}, {0, 0, 0}}},

    {{{0, 0, 0}, {0, 255, 2}, {0, 255, 2}, {0, 255, 2}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 255, 2}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 255, 2}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 255, 2}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 255, 2}, {0, 255, 2}, {255, 0, 0}}},

    {{{0, 0, 0}, {0, 255, 2}, {0, 255, 2}, {0, 255, 2}, {0, 0, 0}},
     {{0, 0, 0}, {0, 255, 2}, {0, 0, 0}, {0, 255, 2}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 255, 2}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 255, 2}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 255, 2}, {255, 0, 0}}},

    {{{0, 0, 0}, {0, 255, 2}, {0, 255, 2}, {0, 255, 2}, {0, 0, 0}},
     {{0, 0, 0}, {0, 255, 2}, {0, 0, 0}, {0, 255, 2}, {0, 0, 0}},
     {{0, 0, 0}, {0, 255, 2}, {0, 0, 0}, {0, 255, 2}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 255, 2}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}}},

    {{{0, 0, 0}, {0, 255, 2}, {0, 255, 2}, {0, 255, 2}, {0, 0, 0}},
     {{0, 0, 0}, {0, 255, 2}, {0, 0, 0}, {0, 255, 2}, {0, 0, 0}},
     {{0, 0, 0}, {0, 255, 2}, {0, 255, 2}, {0, 255, 2}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}}},

    {{{0, 0, 0}, {0, 255, 2}, {0, 255, 2}, {0, 255, 2}, {0, 0, 0}},
     {{0, 0, 0}, {0, 255, 2}, {0, 0, 0}, {0, 255, 2}, {0, 0, 0}},
     {{0, 0, 0}, {0, 255, 2}, {0, 255, 2}, {0, 58, 255}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}}},

    {{{0, 2, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 2, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 2, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 2, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
     {{0, 2, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}},

    {{{0, 2, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 2, 255}},
     {{0, 2, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 2, 255}},
     {{0, 2, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 2, 255}},
     {{0, 2, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 2, 255}},
     {{0, 2, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 2, 255}}},

    {{{0, 2, 255}, {0, 2, 255}, {0, 0, 0}, {0, 2, 255}, {0, 2, 255}},
     {{0, 2, 255}, {0, 2, 255}, {0, 0, 0}, {0, 2, 255}, {0, 2, 255}},
     {{0, 2, 255}, {0, 2, 255}, {0, 0, 0}, {0, 2, 255}, {0, 2, 255}},
     {{0, 2, 255}, {0, 2, 255}, {0, 0, 0}, {0, 2, 255}, {0, 2, 255}},
     {{0, 2, 255}, {0, 2, 255}, {0, 0, 0}, {0, 2, 255}, {0, 2, 255}}},

    {{{0, 2, 255}, {0, 2, 255}, {0, 2, 255}, {0, 2, 255}, {0, 2, 255}},
     {{0, 2, 255}, {0, 2, 255}, {0, 2, 255}, {0, 2, 255}, {0, 2, 255}},
     {{0, 2, 255}, {0, 2, 255}, {0, 2, 255}, {0, 2, 255}, {0, 2, 255}},
     {{0, 2, 255}, {0, 2, 255}, {0, 2, 255}, {0, 2, 255}, {0, 2, 255}},
     {{0, 2, 255}, {0, 2, 255}, {0, 2, 255}, {0, 2, 255}, {0, 2, 255}}},
};
