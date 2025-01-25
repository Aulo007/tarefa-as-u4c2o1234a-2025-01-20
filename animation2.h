#ifndef ANIMATION2_H
#define ANIMATION2_H

#define ROWS 5
#define COLS 5
#define COLORS 3


extern int caixa_de_entrada[15][25];
extern uint8_t matriz[15][5][5][3];


void animar_desenhos_2();
void convertToRGB(int entrada, uint8_t matriz[3]);

#endif