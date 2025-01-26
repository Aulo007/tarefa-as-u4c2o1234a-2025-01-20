#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"

// Biblioteca gerada pelo arquivo .pio durante compilação.
#include "ws2818b.pio.h"

#define ROW1 6
#define ROW2 7
#define ROW3 8
#define ROW4 9
#define COL1 10
#define COL2 11
#define COL3 12
#define COL4 13

// Definição do número de LEDs e pino.
#define LED_COUNT 25
#define LED_PIN 15

// Definição de pixel GRB
struct pixel_t
{
  uint8_t G, R, B; // Três valores de 8-bits compõem um pixel.
};
typedef struct pixel_t pixel_t;
typedef pixel_t npLED_t; // Mudança de nome de "struct pixel_t" para "npLED_t" por clareza.

// Declaração do buffer de pixels que formam a matriz.
npLED_t leds[LED_COUNT];

// Variáveis para uso da máquina PIO.
PIO np_pio;
uint sm;

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
  sleep_us(100); // Espera 100us, sinal de RESET do datasheet.
}

// Função para converter a posição do matriz para uma posição do vetor.
int getIndex(int x, int y)
{
  if (y % 2 == 0)
  {
    return 24 - (y * 5 + x); // Linha par (esquerda para direita).
  }
  else
  {
    return 24 - (y * 5 + (4 - x)); // Linha ímpar (direita para esquerda).
  }
}

// Função para configurar os pinos do teclado matricial.
void setupKeypad()
{
  // Configura pinos das linhas (6-9) como saída
  gpio_init(ROW1);
  gpio_set_dir(ROW1, GPIO_OUT);
  gpio_init(ROW2);
  gpio_set_dir(ROW2, GPIO_OUT);
  gpio_init(ROW3);
  gpio_set_dir(ROW3, GPIO_OUT);
  gpio_init(ROW4);
  gpio_set_dir(ROW4, GPIO_OUT);

  // Configura pinos das colunas (10-13) como entrada com pull-up
  gpio_init(COL1);
  gpio_set_dir(COL1, GPIO_IN);
  gpio_pull_up(COL1);
  gpio_init(COL2);
  gpio_set_dir(COL2, GPIO_IN);
  gpio_pull_up(COL2);
  gpio_init(COL3);
  gpio_set_dir(COL3, GPIO_IN);
  gpio_pull_up(COL3);
  gpio_init(COL4);
  gpio_set_dir(COL4, GPIO_IN);
  gpio_pull_up(COL4);
}

// Função para ler as teclas do teclado matricial.
int readKeypad()
{
  for (int i = 0; i < 4; i++)
  {
    // Desativa todas as linhas e ativa apenas a linha atual
    gpio_put(ROW1, i == 0);
    gpio_put(ROW2, i == 1);
    gpio_put(ROW3, i == 2);
    gpio_put(ROW4, i == 3);

    // Verifica se alguma coluna foi pressionada
    if (gpio_get(COL1) == 0)
      return 1 + i * 4;
    if (gpio_get(COL2) == 0)
      return 2 + i * 4;
    if (gpio_get(COL3) == 0)
      return 3 + i * 4;
    if (gpio_get(COL4) == 0)
      return 4 + i * 4;
  }
  return 0; // Nenhuma tecla pressionada
}

int main()
{
  stdio_init_all();

  // Inicializa matriz de LEDs NeoPixel.
  npInit(LED_PIN);
  npClear();

  // Define as 5 imagens como matrizes 5x5x3 (RGB)
  int imagens[5][5][5][3] = {
      {// Primeira imagem
       {{255, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}},
       {{0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}},
       {{255, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {255, 0, 0}},
       {{0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}},
       {{255, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}}},

      {// Segunda imagem
       {{58, 149, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {58, 149, 0}},
       {{0, 0, 0}, {0, 0, 0}, {58, 149, 0}, {0, 0, 0}, {0, 0, 0}},
       {{0, 0, 0}, {58, 149, 0}, {58, 149, 0}, {58, 149, 0}, {0, 0, 0}},
       {{0, 0, 0}, {0, 0, 0}, {58, 149, 0}, {0, 0, 0}, {0, 0, 0}},
       {{58, 149, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {58, 149, 0}}},

      {// Terceira imagem
       {{255, 0, 0}, {0, 0, 0}, {196, 195, 14}, {0, 0, 0}, {255, 0, 0}},
       {{0, 0, 0}, {196, 195, 14}, {196, 195, 14}, {196, 195, 14}, {0, 0, 0}},
       {{58, 149, 0}, {196, 195, 14}, {255, 0, 0}, {196, 195, 14}, {58, 149, 0}},
       {{0, 0, 0}, {196, 195, 14}, {196, 195, 14}, {196, 195, 14}, {0, 0, 0}},
       {{255, 0, 0}, {0, 0, 0}, {196, 195, 14}, {0, 0, 0}, {255, 0, 0}}},

      {// Quarta imagem
       {{0, 14, 149}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 14, 149}},
       {{0, 0, 0}, {0, 0, 0}, {0, 14, 149}, {0, 0, 0}, {0, 0, 0}},
       {{0, 14, 149}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 14, 149}},
       {{0, 0, 0}, {0, 0, 0}, {0, 14, 149}, {0, 0, 0}, {0, 0, 0}},
       {{0, 14, 149}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 14, 149}}},

      {// Quinta imagem
       {{196, 195, 14}, {0, 0, 0}, {58, 149, 0}, {0, 0, 0}, {255, 0, 0}},
       {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
       {{0, 0, 0}, {58, 149, 0}, {196, 195, 14}, {58, 149, 0}, {0, 0, 0}},
       {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
       {{255, 0, 0}, {0, 0, 0}, {58, 149, 0}, {0, 0, 0}, {196, 195, 14}}}};

  // Configura o teclado matricial
  setupKeypad();

  while (true)
  {
    int key = readKeypad();

    if (key == 5)
    { // Quando a tecla 5 for pressionada
      // Exibe as 5 imagens sequencialmente
      for (int i = 0; i < 5; i++)
      {
        npClear(); // Limpa o buffer de pixels antes de desenhar a nova imagem.

        // Desenha cada imagem no buffer.
        for (int linha = 0; linha < 5; linha++)
        {
          for (int coluna = 0; coluna < 5; coluna++)
          {
            int posicao = getIndex(linha, coluna);
            npSetLED(posicao, imagens[i][linha][coluna][0], imagens[i][linha][coluna][1], imagens[i][linha][coluna][2]);
          }
        }

        npWrite(); 
        sleep_ms(2000); 
      }
    }
  }
}
