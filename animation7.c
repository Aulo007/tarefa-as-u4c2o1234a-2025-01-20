#include "matriz_rgb.h"
#include "pico/stdlib.h"
#include "keypad.h"
#include "animation7.h"

#define ROWS 5
#define COLS 5
#define COLORS 3
#define PERIODO 200 // Isso é o equivalente a 5 frames, uma vez que 1000/200 = 5
#define DESENHOS 9  // Quantidade de desenhos que terá a sua animação

