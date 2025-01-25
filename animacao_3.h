#ifndef ANIMATION3_H
#define ANIMATION3_H

#include <stdint.h>

// Define a estrutura para controlar a matriz de LEDs
typedef struct {
    uint8_t red;     // Valor do componente vermelho (0-255)
    uint8_t green;   // Valor do componente verde (0-255)
    uint8_t blue;    // Valor do componente azul (0-255)
} LED;

// Função para executar a animação 3
void animation3(LED matrix[5][5]);

#endif // ANIMATION3_H
