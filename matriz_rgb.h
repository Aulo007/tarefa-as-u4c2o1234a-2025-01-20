#ifndef MATRIZ_RGB_H
#define MATRIZ_RGB_H

#include <stdint.h>

// Definição do pixel/LED
typedef struct
{
    uint8_t G, R, B;
} npLED_t;

//Declaraão de funções
void npInit(uint8_t pin);
void npClear();
void npWrite();
void setMatrizDeLEDSComIntensidade(int matriz[5][5][3], double intensidadeR, double intensidadeG, double intensidadeB);
int getIndex(int x, int y);
void npWrite2(uint8_t matriz[5][5][3]);

#endif // MATRIZ_RGB_H
