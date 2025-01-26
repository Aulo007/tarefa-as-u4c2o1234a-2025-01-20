#include "matriz_rgb.h"
#include "animationD.h"
#include "pico/stdlib.h"
#include "keypad.h"

uint8_t matrizD[5][5][3] = 
{
{{0, 127, 0}, {0, 127, 0}, {0, 127, 0}, {0, 127, 0}, {0, 127, 0}}, 
{{0, 127, 0}, {0, 127, 0}, {0, 127, 0}, {0, 127, 0}, {0, 127, 0}},
{{0, 127, 0}, {0, 127, 0}, {0, 127, 0}, {0, 127, 0}, {0, 127, 0}},
{{0, 127, 0}, {0, 127, 0}, {0, 127, 0}, {0, 127, 0}, {0, 127, 0}},
{{0, 127, 0}, {0, 127, 0}, {0, 127, 0}, {0, 127, 0}, {0, 127, 0}}
};

void animar_desenhos_D(void){

  int i=0,j=0,k=0;
  char tecla;

  while(true){
    tecla = keypad_read();
    if((tecla != 'D')&&(tecla !='X')){
        break;
    }
    for(int i = 0;i<15;i++){
      tecla = keypad_read();
        if((tecla != 'D')&&(tecla !='X')){
          break;
        }
        npWrite2(matrizD);
    }
  }
}
