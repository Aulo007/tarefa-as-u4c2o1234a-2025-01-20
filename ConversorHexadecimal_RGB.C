// Converte um código hexadecimal gerado no site: https://www.piskelapp.com/
// Para decimal em no padrão RGB.

#include <stdio.h>

#define MATRIX_ROWS 5
#define MATRIX_COLS 5
#define MATRIX_DEPTH 3
#define NUM_FRAMES 50

// Função para converter valores ARGB (0xAARRGGBB) para RGB
void convertToRGB(int argb, int rgb[3])
{
    rgb[2] = (argb >> 16) & 0xFF; // Red
    rgb[1] = (argb >> 8) & 0xFF;  // Green
    rgb[0] = argb & 0xFF;         // Blue
}

