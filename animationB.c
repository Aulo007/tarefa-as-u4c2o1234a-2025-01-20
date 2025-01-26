#include "matriz_rgb.h"
#include "animationB.h"
#include "pico/stdlib.h"
#include "keypad.h"

//Matriz de elementos dispostos similarmente aos LED's e que os configuram
uint8_t matrizB[5][5][3] = 
{
{{0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}}, 
{{0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}},
{{0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}},
{{0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}},
{{0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}}
};

void animar_desenhos_B(void){

  char tecla;

  npWrite2(matrizB); //"Imprime" nos LED's como na 'matrizB'
  while(true){
    tecla = keypad_read(); //Verifica qual tecla é precionada constantemente para poder interromper a função
    if((tecla != 'B')&&(tecla !='X')){
      break;
    }
  }
}
