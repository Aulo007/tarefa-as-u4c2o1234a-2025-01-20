#ifndef ANIMATION9_H
#define ANIMATION9_H

#define ROWS 5
#define COLS 5
#define COLORS 3

// Definição da caixa de desenhos
extern int caixa_de_desenhos[9][ROWS][COLS][COLORS];
// Definição da função de animar desenhos
void animar_desenhos_9(char key_de_ativacao);

#endif // ANIMATION9_H