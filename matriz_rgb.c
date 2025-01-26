#include "matriz_rgb.h"
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2818b.pio.h"

#define LED_COUNT 25

// Buffer de pixels global
static npLED_t leds[LED_COUNT];
static PIO np_pio;
static uint sm;

void npInit(uint8_t pin)
{
    // Cria programa PIO.
    uint offset = pio_add_program(pio0, &ws2818b_program);
    np_pio = pio0;

    // Toma posse de uma máquina PIO.
    sm = pio_claim_unused_sm(np_pio, false);
    if (sm < 0)
    {
        np_pio = pio1;
        sm = pio_claim_unused_sm(np_pio, true);
    }

    // Inicia programa na máquina PIO obtida.
    ws2818b_program_init(np_pio, sm, offset, pin, 800000.f);

    // Limpa buffer de pixels.
    npClear();
}

void setMatrizDeLEDSComIntensidade(int matriz[5][5][3], double intensidadeR, double intensidadeG, double intensidadeB)
{
    // Validação das intensidades
    intensidadeR = (intensidadeR < 0.0 || intensidadeR > 1.0) ? 1.0 : intensidadeR;
    intensidadeG = (intensidadeG < 0.0 || intensidadeG > 1.0) ? 1.0 : intensidadeG;
    intensidadeB = (intensidadeB < 0.0 || intensidadeB > 1.0) ? 1.0 : intensidadeB;

    // Loop para configurar os LEDs
    for (uint8_t linha = 0; linha < 5; linha++)
    {
        for (uint8_t coluna = 0; coluna < 5; coluna++)
        {
            // Calcula os valores RGB ajustados pela intensidade
            uint8_t r = (uint8_t)(matriz[linha][coluna][0] * intensidadeR);
            uint8_t g = (uint8_t)(matriz[linha][coluna][1] * intensidadeG);
            uint8_t b = (uint8_t)(matriz[linha][coluna][2] * intensidadeB);

            // Endereçamento linear para calcular o índice do LED
            uint index = linha * 5 + coluna;

            // Configura o LED diretamente
            leds[index].R = r;
            leds[index].G = g;
            leds[index].B = b;
        }
    }
}
void npWrite()
{
    // Escreve cada dado de 8-bits dos pixels em sequência no buffer da máquina PIO.
    for (uint i = 0; i < LED_COUNT; ++i)
    {
        pio_sm_put_blocking(np_pio, sm, leds[i].G);
        pio_sm_put_blocking(np_pio, sm, leds[i].R);
        pio_sm_put_blocking(np_pio, sm, leds[i].B);
    }
    sleep_us(100); // Espera 100us, sinal de RESET do datasheet.
}
void npClear()
{
    for (uint i = 0; i < LED_COUNT; ++i)
    {
        leds[i].R = 0;
        leds[i].G = 0;
        leds[i].B = 0;
    }

    npWrite();
}

int getIndex(int x, int y)
{
    // Se a linha for par (0, 2, 4), percorremos da esquerda para a direita.
    // Se a linha for ímpar (1, 3), percorremos da direita para a esquerda.
    if (y % 2 == 0)
    {
        return 24 - (y * 5 + x); // Linha par (esquerda para direita).
    }
    else
    {
        return 24 - (y * 5 + (4 - x)); // Linha ímpar (direita para esquerda).
    }
}

void npWrite2(uint8_t matriz[5][5][3]){ // Escreve cada elemento do formato RGB como informação de 8-bit em sequência no buffer da máquina PIO.
    int i=0,j=0;                        // Faz ainda a conversão do formato da matriz para coincidir com a disposição da sequência dos LED's
    for(int i = 4; i>=0; i--){
      for(int j = 4; j>=0; j--){
        if(i%2==0){
          pio_sm_put_blocking(np_pio, sm, matriz[i][j][1]);
          pio_sm_put_blocking(np_pio, sm, matriz[i][j][0]);
          pio_sm_put_blocking(np_pio, sm, matriz[i][j][2]);
        }else{
          pio_sm_put_blocking(np_pio, sm, matriz[i][4-j][1]);
          pio_sm_put_blocking(np_pio, sm, matriz[i][4-j][0]);
          pio_sm_put_blocking(np_pio, sm, matriz[i][4-j][2]);

        }
      }
    }
    sleep_us(100); // Espera 100us, sinal de RESET do datasheet.
}

void npClear2(){ //Faz o mesmo que o npWrite2, porém para desligar os LED's
    uint8_t x=0;
    for(int i = 0; i<25; i++){
        pio_sm_put_blocking(np_pio, sm, x);
        pio_sm_put_blocking(np_pio, sm, x);
        pio_sm_put_blocking(np_pio, sm, x);
    }
    sleep_us(100); // Espera 100us, sinal de RESET do datasheet.

}
