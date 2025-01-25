#include "animation3.h"

// Definição do nível de intensidade (80% da luminosidade máxima)
#define INTENSITY 204  // 80% de 255

void animation3(LED matrix[5][5]) {
    // Itera sobre toda a matriz 5x5
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {
            matrix[row][col].red = INTENSITY;   // 80% de vermelho
            matrix[row][col].green = 0;        // Sem verde
            matrix[row][col].blue = 0;         // Sem azul
        }
    }

    // Aqui você pode adicionar comandos adicionais para atualizar a matriz
    // dependendo da biblioteca utilizada para controlar os LEDs.
}
