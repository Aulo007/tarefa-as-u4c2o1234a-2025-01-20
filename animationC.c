#include "matriz_rgb.h"
#include "animationC.h"
#include "pico/stdlib.h"
#include "keypad.h"

////Matriz de elementos dispostos similarmente aos LED's e que os configuram
uint8_t matrizC[5][5][3] = 
{
{{204, 0, 0}, {204, 0, 0}, {204, 0, 0}, {204, 0, 0}, {204, 0, 0}}, 
{{204, 0, 0}, {204, 0, 0}, {204, 0, 0}, {204, 0, 0}, {204, 0, 0}},
{{204, 0, 0}, {204, 0, 0}, {204, 0, 0}, {204, 0, 0}, {204, 0, 0}},
{{204, 0, 0}, {204, 0, 0}, {204, 0, 0}, {204, 0, 0}, {204, 0, 0}},
{{204, 0, 0}, {204, 0, 0}, {204, 0, 0}, {204, 0, 0}, {204, 0, 0}}
};

void animar_desenhos_C(void){

  char tecla;

  npWrite2(matrizC); //"Imprime" nos LED's como na 'matrizC'
  while(true){
    tecla = keypad_read(); //Verifica qual tecla é precionada constantemente para poder interromper a função
    if((tecla != 'C')&&(tecla !='X')){
        break;
    }
  }
}
