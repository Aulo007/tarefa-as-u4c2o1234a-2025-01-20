#include "matriz_rgb.h"
#include "animationC.h"
#include "pico/stdlib.h"
#include "keypad.h"

uint8_t matrizC[5][5][3] = 
{
{{204, 0, 0}, {204, 0, 0}, {204, 0, 0}, {204, 0, 0}, {204, 0, 0}}, 
{{204, 0, 0}, {204, 0, 0}, {204, 0, 0}, {204, 0, 0}, {204, 0, 0}},
{{204, 0, 0}, {204, 0, 0}, {204, 0, 0}, {204, 0, 0}, {204, 0, 0}},
{{204, 0, 0}, {204, 0, 0}, {204, 0, 0}, {204, 0, 0}, {204, 0, 0}},
{{204, 0, 0}, {204, 0, 0}, {204, 0, 0}, {204, 0, 0}, {204, 0, 0}}
};

void animar_desenhos_C(void){

  int i=0,j=0,k=0;
  char tecla;

  while(true){
    tecla = keypad_read();
    if((tecla != 'C')&&(tecla !='X')){
        break;
    }
    for(int i = 0;i<15;i++){
      tecla = keypad_read();
        if((tecla != 'C')&&(tecla !='X')){
          break;
        }
        npWrite2(matrizC);
    }
  }
}
