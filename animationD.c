#include "matriz_rgb.h"
#include "animationD.h"
#include "pico/stdlib.h"
#include "keypad.h"

//Matriz de elementos dispostos similarmente aos LED's e que os configuram
uint8_t matrizD[5][5][3] = 
{
{{0, 127, 0}, {0, 127, 0}, {0, 127, 0}, {0, 127, 0}, {0, 127, 0}}, 
{{0, 127, 0}, {0, 127, 0}, {0, 127, 0}, {0, 127, 0}, {0, 127, 0}},
{{0, 127, 0}, {0, 127, 0}, {0, 127, 0}, {0, 127, 0}, {0, 127, 0}},
{{0, 127, 0}, {0, 127, 0}, {0, 127, 0}, {0, 127, 0}, {0, 127, 0}},
{{0, 127, 0}, {0, 127, 0}, {0, 127, 0}, {0, 127, 0}, {0, 127, 0}}
};

void animar_desenhos_D(void){

  char tecla;

  npWrite2(matrizD); //"Imprime" nos LED's como na 'matrizD'
  while(true){
    tecla = keypad_read(); //Verifica qual tecla é precionada constantemente para poder interromper a função
    if((tecla != 'D')&&(tecla !='X')){
        break;
    }
  }
}
