#include "matriz_rgb.h"
#include "pico/stdlib.h"
#include "animation7.h"

#define ROWS 5
#define COLS 5
#define COLORS 3

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
     {{192, 192, 192}, {64, 64, 64}, {192, 192, 192}, {64, 64, 64}, {192, 192, 192}}}};
