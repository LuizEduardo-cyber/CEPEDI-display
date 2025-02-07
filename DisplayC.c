#include <stdlib.h>
#include<stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "inc/ssd1306.h"
#include "inc/font.h"
#include "hardware/timer.h"
#include "DisplayC.h"
#define I2C_PORT i2c1
#define I2C_SDA 14
#define I2C_SCL 15
#define BUTTON_A 5
#define BUTTON_B 6
#define LED_RED 13
#define LED_BLUE 12
#define LED_GREEN 11
#define endereco 0x3C
static volatile char caractere;
static volatile uint32_t last_time = 0; //para fazer o debounce
bool est_led=0; //para alternar led verde
bool est_led2=0; //para alternar led blue
static ssd1306_t ssd; // Inicializa a estrutura do display
static bool cor;

void gpio_irq_handler(); //função para interrupçao
void init_gpio(); //inicia botoes e leds

int main()
{
  // I2C Initialisation. Using it at 400Khz.
  i2c_init(I2C_PORT, 400 * 1000);
  stdio_init_all(); 
  initNeoPixel(); //inicializa ws28122
  init_gpio();
 
  gpio_set_function(I2C_SDA, GPIO_FUNC_I2C); // Set the GPIO pin function to I2C
  gpio_set_function(I2C_SCL, GPIO_FUNC_I2C); // Set the GPIO pin function to I2C
  gpio_pull_up(I2C_SDA); // Pull up the data line
  gpio_pull_up(I2C_SCL); // Pull up the clock line
  ssd1306_init(&ssd, WIDTH, HEIGHT, false, endereco, I2C_PORT); // Inicializa o display
  ssd1306_config(&ssd); // Configura o display
  ssd1306_send_data(&ssd); // Envia os dados para o display
  gpio_set_irq_enabled_with_callback(BUTTON_A, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler); // configura a interrupção e exuta a interrupção.
    gpio_set_irq_enabled_with_callback(BUTTON_B, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler); // configura a interrupção e exuta a interrupção.


  // Limpa o display. O display inicia com todos os pixels apagados.
  ssd1306_fill(&ssd, false);
  ssd1306_send_data(&ssd);
  bool cor = true;
  while (true) //loop infinito
  {
    cor = !cor;
    // Atualiza o conteúdo do display com animações
    ssd1306_fill(&ssd, !cor); // Limpa o display
    printf("digite um caratere \n");
    scanf(" %c",&caractere);
    
    switch(caractere){ //um switch para caractere, cada caractere que digitar aparece no display e numero na matriz de led.
      
      //letras minusculas
    case 'a':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor , !cor);
    ssd1306_draw_string(&ssd, "a", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'b':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "b", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'c':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "c", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'd':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "d", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'e':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "e", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'f':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "f", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'g':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "g", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'h':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "h", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'i':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "i", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'j':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "j", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'k':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "k", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'l':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "l", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'm':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "m", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'n':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "n", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'o':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "o", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'p':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "p", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'q':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "q", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'r':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "r", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 's':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "s", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 't':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "t", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'u':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "u", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'v':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "v", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'w':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "w", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'x':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "x", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'y':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "y", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'z':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "z", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;

     // LETRAS MAIUSCULAS

    case 'A':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "A", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'B':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "B", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'C':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "C", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'D':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "D", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'E':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "E", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'F':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "F", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'G':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "G", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'H':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "H", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'I':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "I", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'J':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "J", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'K':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "K", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'L':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "L", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'M':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "M", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'N':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "N", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'O':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "O", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'P':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "P", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'Q':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "Q", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'R':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "R", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'S':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "S", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'T':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "T", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'U':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "U", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'V':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "V", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'W':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "W", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'X':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "X", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'Y':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "Y", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case 'Z':
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "Z", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;

    //numeros

    case '0':
    A_0();
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "0", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display

    break;
    case '1':
     A_1();
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "1", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
     
    break;
    case '2':
    A_2();
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "2", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    
    break;
    case '3':
    A_3();
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "3", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case '4':
    A_4();
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "4", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case '5':
    A_5();
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "5", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case '6':
    A_6();
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "6", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case '7':
    A_7();
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "7", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
    case '8':
    A_8();
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "8", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
     case '9':
    A_9();
    ssd1306_rect(&ssd, 20, 50, 30, 30, cor, !cor);
    ssd1306_draw_string(&ssd, "9", 61, 29);
    ssd1306_send_data(&ssd); // Atualiza o display
    break;
     case '-':
     default_();
     printf("limpa matriz de led \n");
     ssd1306_fill(&ssd, cor); // Limpa o display
     ssd1306_draw_string(&ssd, "ws28122 desl", 3, 29);
     ssd1306_send_data(&ssd); // Atualiza o display
    break;
     default:
     printf("caractere invalido \n");
     ssd1306_fill(&ssd, cor); // Limpa o display
     ssd1306_draw_string(&ssd, "invalido", 3, 29);
     ssd1306_send_data(&ssd); // Atualiza o display
     break;
    }
    sleep_ms(1000);
  }
}

void gpio_irq_handler(uint gpio, uint32_t events){ //definido manualmente para tratar eventos de interrupção.
 uint32_t current_time = to_us_since_boot(get_absolute_time());
 est_led=!est_led;
 est_led2=!est_led2;
  if (current_time - last_time > 200000) { //debounce
     last_time = current_time;
     switch(gpio){
      case BUTTON_A: //caso for botao A ele entra nessa condição
       gpio_put(LED_GREEN,est_led);
      if(gpio_get(LED_GREEN)==1){
      printf("led verde foi aceso e display gerando informacao \n");
      ssd1306_fill(&ssd, cor); // Limpa o display
      ssd1306_draw_string(&ssd, "Led 11 aceso", 3, 29);
      ssd1306_send_data(&ssd); // Atualiza o display
      }else{
      printf("led verde foi apagado e display gerando informacao \n");
      ssd1306_draw_string(&ssd, "Led 11 apagado", 3, 29);
      ssd1306_send_data(&ssd); // Atualiza o display
      ssd1306_fill(&ssd, cor); // Limpa o display
      }
      break;
      case BUTTON_B: //caso for botao B ele entra nessa condição
      gpio_put(LED_BLUE,est_led2);
      if(gpio_get(LED_BLUE)==1){ //se led blue estiver aceso gera essas informações
      printf("led azul foi aceso e display gerando informacao \n");
      ssd1306_fill(&ssd, cor); // Limpa o display
      ssd1306_draw_string(&ssd, "Led 12 aceso", 3, 29);
      ssd1306_send_data(&ssd); // Atualiza o display
      }else{ //se estiver apagado gera essas informações
      printf("led azul foi apagado e display gerando informacao \n");
      ssd1306_draw_string(&ssd, "Led 12 apagado", 3, 29);
      ssd1306_send_data(&ssd); // Atualiza o display
      ssd1306_fill(&ssd, cor); // Limpa o display
      }
      break;
      default:
      printf("pushbotton invalido \n"); //caso nao seja nem botao a e nem b.
      break;

     }
  }
}

void init_gpio(){ //função de inicialização
  gpio_init(BUTTON_A);
  gpio_set_dir(BUTTON_A,GPIO_IN);
  gpio_pull_up(BUTTON_A);
  gpio_init(BUTTON_B);
  gpio_set_dir(BUTTON_B,GPIO_IN);
  gpio_pull_up(BUTTON_B);
  gpio_init(LED_RED);
  gpio_set_dir(LED_RED,GPIO_OUT);
  gpio_init(LED_BLUE);
  gpio_set_dir(LED_BLUE,GPIO_OUT);
  gpio_init(LED_GREEN);
  gpio_set_dir(LED_GREEN,GPIO_OUT);
}