#include "matriz_rgb.h"
#include "animation2.h"
#include "pico/stdlib.h"
#include "keypad.h"

/*
Mensagem para o leitor: 
A função abaixo converte cada vetor de elementos hexadecimais em 
matrizes no padrão RGB que é utilizado para configurar cada LED. 
Inicialmente o objetivo era fazer uso desse conversor facilitando
o trabalho do programador, que fez os sprites num editor externo
e copiava as cores de todos os pixels do sprite no formato hexadecimal
e colava no "caixa_de_entrada" sem precisar fazer a conversão 
manualmente. Porém, uma vez que o objetivo de realizar a animação
foi cumprido, o programador escolheu preencher "matriz2" já com 
os valores convertidos em RGB para diminuir esforço desnecessário
para o micro-controlador que teria que fazer a conversão toda vez
que o programa fosse inicializado.



void convertToRGB(int entrada, uint8_t matriz[3]) {
    matriz[0] = entrada & 0xFF;          // Red
    matriz[1] = (entrada >> 8) & 0xFF;   // Green
    matriz[2] = (entrada >> 16) & 0xFF;  // Blue
}

int caixa_de_entrada[15][25] = {{
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff0000ff, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
},{
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff0000ff, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff0000ff, 0x00000000, 0x00000000
},{
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff0000ff, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
},{
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff0000ff, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff0000ff, 0x00000000, 0x00000000
},{
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff0000ff, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
},{
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff0000ff, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff0000ff, 0x00000000, 0x00000000
},{
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff0000ff, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff0000ff, 0x00000000, 0x00000000
},{
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff0000ff, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff0000ff, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000    
},{
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff0000ff, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff0000ff, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
},{
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff0000ff, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
},{
0x00000000, 0xff0000ff, 0xff0000ff, 0xff0000ff, 0x00000000, 
0x00000000, 0xff0000ff, 0xff0070ff, 0xff0000ff, 0x00000000, 
0x00000000, 0xff0000ff, 0xff0000ff, 0xff0000ff, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
},{
0xff0000ff, 0xff0070ff, 0xff0070ff, 0xff0070ff, 0xff0000ff, 
0xff0000ff, 0xff0070ff, 0xff00fffb, 0xff0070ff, 0xff0000ff, 
0xff0000ff, 0xff0070ff, 0xff0070ff, 0xff0070ff, 0xff0000ff, 
0xff0000ff, 0xff0000ff, 0xff0000ff, 0xff0000ff, 0xff0000ff, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
},{
0xff0070ff, 0xff00fffb, 0xff00fffb, 0xff00fffb, 0xff0070ff, 
0xff0070ff, 0xff00fffb, 0x00000000, 0xff00fffb, 0xff0070ff, 
0xff0070ff, 0xff00fffb, 0xff00fffb, 0xff00fffb, 0xff0070ff, 
0xff0070ff, 0xff0070ff, 0xff0070ff, 0xff0070ff, 0xff0070ff, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
},{
0xff00fffb, 0x00000000, 0x00000000, 0x00000000, 0xff00fffb, 
0xff00fffb, 0x00000000, 0x00000000, 0x00000000, 0xff00fffb, 
0xff00fffb, 0x00000000, 0x00000000, 0x00000000, 0xff00fffb, 
0xff00fffb, 0xff00fffb, 0xff00fffb, 0xff00fffb, 0xff00fffb, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
},{
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
}};*/

//Matriz de 15 sprites dispostos similarmente aos LED's
uint8_t matriz2[15][5][5][3] = {
{
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},  
{{0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}},
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},  
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
},{
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},  
{{0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}},
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},  
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
{{0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}}  
},{
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},  
{{0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}},
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},  
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
},{
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},  
{{0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}},
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},  
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
{{0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}}
},{
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},  
{{0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}},
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},  
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
},{
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},  
{{0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}},
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},  
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
{{0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}}   
},{
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},  
{{0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}},
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},  
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
{{0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}}
},{
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},  
{{0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}},
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},  
{{0, 0, 0}, {0, 0, 0},  {255, 0, 0}, {0, 0, 0}, {0, 0, 0}},
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
},{
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},  
{{0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}},
{{0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}},  
{{0, 0, 0}, {0, 0, 0},  {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
},{
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},  
{{0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}},
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
},{
{{0, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {0, 0, 0}},
{{0, 0, 0}, {255, 0, 0}, {255, 112, 0}, {255, 0, 0}, {0, 0, 0}},
{{0, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {0, 0, 0}},
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
},{
{{255, 0, 0}, {255, 112, 0}, {255, 112, 0}, {255, 112, 0}, {255, 0, 0}},
{{255, 0, 0}, {255, 112, 0}, {251, 255, 0}, {255, 112, 0}, {255, 0, 0}},
{{255, 0, 0}, {255, 112, 0}, {255, 112, 0}, {255, 112, 0}, {255, 0, 0}},
{{255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}},
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
},{
{{255, 112, 0}, {251, 255, 0}, {251, 255, 0}, {251, 255, 0}, {255, 112, 0}},
{{255, 112, 0}, {251, 255, 0}, {0, 0, 0}, {251, 255, 0}, {255, 112, 0}},
{{255, 112, 0}, {251, 255, 0}, {251, 255, 0}, {251, 255, 0}, {255, 112, 0}},
{{255, 112, 0}, {255, 112, 0}, {255, 112, 0}, {255, 112, 0}, {255, 112, 0}},
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
},{
{{251, 255, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {251, 255, 0}},
{{251, 255, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {251, 255, 0}},
{{251, 255, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {251, 255, 0}},
{{251, 255, 0}, {251, 255, 0}, {251, 255, 0}, {251, 255, 0}, {251, 255, 0}},
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
},{
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},  
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},  
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
}};

void animar_desenhos_2(void){

  char tecla;

  /*Conjunto de linhas que permitem a conversão dos index de vetores para a disposição matrical como acima
  int i=0,j=0,k=0;
  for(int i=0;i<15;i++){
    for(int j = 0;j<5;j++){
      for(int k = 0;k<5;k++){
        convertToRGB(caixa_de_entrada[i][((j*5)+k)], matriz2[i][j][k]);
      }
    }
  }*/

  while(true){
    for(int i = 0;i<15;i++){
      tecla = keypad_read(); //Verifica qual tecla é precionada constantemente para poder interromper a animação
        if((tecla != '2')&&(tecla !='X')){
          break;
        }
        npWrite2(matriz2[i]); //A cada ciclo do laço de repetição "imprime" um sprite
        sleep_ms(200); //Espera de 200ms para que o FPS seja 5
    }
  }
}
