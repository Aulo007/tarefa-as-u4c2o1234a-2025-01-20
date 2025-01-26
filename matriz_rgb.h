#ifndef MATRIZ_RGB_H
#define MATRIZ_RGB_H

#include <stdint.h>

typedef struct {
    uint8_t R;
    uint8_t G;
    uint8_t B;
} npLED_t;

void npInit(uint8_t pin);
void setMatrizDeLEDSComIntensidade(LED matrix[5][5], double intensidadeR, double intensidadeG, double intensidadeB);
void npUpdateMatrix(LED matrix[5][5]);
void npWrite();
void npClear();
int getIndex(int x, int y);

#endif
