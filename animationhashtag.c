#include "matriz_rgb.h"
#include "animationhashtag.h"
#include "pico/stdlib.h"
#include "keypad.h"

#define ROWS 5
#define COLS 5
#define COLORS 3

int caixa_de_desenhos_hashtag[1][ROWS][COLS][COLORS] = {

    {{{255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}},
     {{255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}},
     {{255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}},
     {{255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}},
     {{255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}}}};
