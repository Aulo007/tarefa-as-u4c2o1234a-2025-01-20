#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2818b.pio.h"
#include "animation5.h"
#include "matriz2.c"

#define ROW1 6
#define ROW2 7
#define ROW3 8
#define ROW4 9
#define COL1 10
#define COL2 11
#define COL3 12
#define COL4 13

#define LED_COUNT 25
#define LED_PIN 15

static uint colunas[4] = {COL1, COL2, COL3, COL4};
static uint linhas[4] = {ROW1, ROW2, ROW3, ROW4};

PIO np_pio;
uint sm;

struct pixel_t
{
    uint8_t G, R, B;
};
typedef struct pixel_t pixel_t;
typedef pixel_t npLED_t;

npLED_t leds[LED_COUNT];

/**
 * Inicializa a máquina PIO para controle da matriz de LEDs.
 */
void npInit(uint pin)
{
    uint offset = pio_add_program(pio0, &ws2818b_program);
    np_pio = pio0;

    sm = pio_claim_unused_sm(np_pio, false);
    if (sm < 0)
    {
        np_pio = pio1;
        sm = pio_claim_unused_sm(np_pio, true);
    }

    ws2818b_program_init(np_pio, sm, offset, pin, 800000.f);

    for (uint i = 0; i < LED_COUNT; ++i)
    {
        leds[i].R = 0;
        leds[i].G = 0;
        leds[i].B = 0;
    }
}

/**
 * Atribui uma cor RGB a um LED.
 */
void npSetLED(const uint index, const uint8_t r, const uint8_t g, const uint8_t b)
{
    leds[index].R = r;
    leds[index].G = g;
    leds[index].B = b;
}

/**
 * Limpa o buffer de pixels.
 */
void npClear()
{
    for (uint i = 0; i < LED_COUNT; ++i)
        npSetLED(i, 0, 0, 0);
}

/**
 * Escreve os dados do buffer nos LEDs.
 */
void npWrite()
{
    for (uint i = 0; i < LED_COUNT; ++i)
    {
        pio_sm_put_blocking(np_pio, sm, leds[i].G);
        pio_sm_put_blocking(np_pio, sm, leds[i].R);
        pio_sm_put_blocking(np_pio, sm, leds[i].B);
    }
    sleep_us(100); 
}

// Função para inicializar o teclado matricial
void keypad_init(void)
{
    // Inicializar colunas como entrada com pull-up
    for (int i = 0; i < 4; i++)
    {
        gpio_init(colunas[i]);
        gpio_set_dir(colunas[i], GPIO_IN);
        gpio_pull_up(colunas[i]);
    }

    // Inicializar linhas como saída
    for (int i = 0; i < 4; i++)
    {
        gpio_init(linhas[i]);
        gpio_set_dir(linhas[i], GPIO_OUT);
        gpio_put(linhas[i], 1);
    }
}

// Função para ler as teclas do teclado matricial
char keypad_read(void)
{
    char teclado[4][4] = {
        {'1', '2', '3', 'A'},
        {'4', '5', '6', 'B'},
        {'7', '8', '9', 'C'},
        {'*', '0', '#', 'D'}};

    for (int i = 0; i < 4; i++)
    {
        gpio_put(linhas[i], 0);
        sleep_ms(1);  // Atraso para estabilizar a leitura

        for (int j = 0; j < 4; j++)
        {
           if (gpio_get(colunas[j]) == 0)  // Detecta se há uma tecla pressionada
            {
              sleep_ms(50);

            if (gpio_get(colunas[j]) == 0)
            {
                gpio_put(linhas[i], 1);
                return teclado[i][j];
            }
         }
      }
      gpio_put(linhas[i], 1);
   }

    return 'X';  
}

// Função para calcular o índice linear do LED
int getIndex(int linha, int coluna)
{
    return linha * 5 + coluna; // Calcula o índice linear para a matriz de 5x5
}

extern uint8_t matriz2[15][5][5][3];  // Define matriz de sprites

void animar_desenhos_2()
{
    for (int i = 0; i < 15; i++)  
    {
        npClear();
        for (int linha = 0; linha < 5; linha++)
        {
            for (int coluna = 0; coluna < 5; coluna++)
            {
                int posicao = getIndex(linha, coluna);
                npSetLED(posicao, matriz2[i][linha][coluna][0], matriz2[i][linha][coluna][1], matriz2[i][linha][coluna][2]);
            }
        }
        npWrite();
        sleep_ms(500);  
    }
}

int main()
{
    stdio_init_all();

    npInit(LED_PIN);
    npClear();

    keypad_init();

    while (true)
    {
        char key = keypad_read();  

        if (key == '9')  
        {
            animar_desenhos_2(); 
        }
    }
}
