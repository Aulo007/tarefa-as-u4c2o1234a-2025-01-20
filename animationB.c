#include "matriz_rgb.h"
#include "animationB.h"
#include "pico/stdlib.h"
#include "keypad.h"

uint8_t matrizB[5][5][3] = 
{
{{0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}}, 
{{0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}},
{{0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}},
{{0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}},
{{0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}}
};

void animar_desenhos_B(void){

  int i=0,j=0,k=0;
  char tecla;

  while(true){
    tecla = keypad_read();
    if((tecla != 'B')&&(tecla !='X')){
        npClear2();
        break;
    }
    for(int i = 0;i<15;i++){
      tecla = keypad_read();
        if((tecla != 'B')&&(tecla !='X')){
          npClear2();
          break;
        }
        npWrite2(matrizB);
        sleep_ms(200);
    }
  }
}