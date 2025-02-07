# Projeto interface de comunicação serial com RP2040 e I2C 🚀

Esse projeto faz uso do display que tem quase todos os caracteres incluidos, e faz uso da matriz de led que imprime os numeros de 0 a 9, e também o push button que tem como funcionalidade alternar o estado led RGB e informar o estado do led pelo serial monitor e pelo display.

## Hardware 🛠️

- Microcontrolador RP2040 (Raspberry Pi Pico).
- pushbotton.
- SSD1306 OLED DISPLAY.
- Display NeoPixel RGB 5x5.
- LED RGB.

## Software 💻

* **SDK do Raspberry Pi Pico:** O SDK (Software Development Kit) do Pico, que inclui as bibliotecas e ferramentas necessárias para desenvolver e compilar o código. [Instruções de instalação](https://www.raspberrypi.com/documentation/pico/getting-started/)
* **CMake:** Um sistema de construção multiplataforma usado para gerar os arquivos de construção do projeto.
* **Compilador C/C++:**  Um compilador C/C++ como o GCC (GNU Compiler Collection).
* **Git:** (Opcional) Para clonar o repositório do projeto.


### O código está dividido em vários arquivos para melhor organização:

- **`DisplayC.c`**: Código que tem como função gerar quase todos os caracteres no display, gerar animações dos numeros de 0 a 9 na matriz de Led, e com o uso de interrupção alternar o estado do led RGB com push button.
- **`contador.c/.h`:** Funções de animação para os numeros de 0 a 9.
- **`neopixel.c/.h`:** Controla o display NeoPixel (inicialização e envio de cores).
- - **`ssd1306.c/.h`:** possibilitar o uso de caracteres no SSD1306 OLED DISPLAY.
- **`CMakeLists.txt`:** Define a estrutura do projeto para o CMake.



## Como Compilar e Executar ⚙️

1. **Instale o SDK do Raspberry Pi Pico:** Siga as instruções no site oficial do Raspberry Pi.
2. **Clone este repositório:** https://github.com/LuizEduardo-cyber/CEPEDI-display.git`
3. **Navegue até o diretório do projeto:** `cd CEPEDI-display`
4. **Compile o projeto:** `cmake -B build && cmake --build build`
5. **Copie para o Pico:** Copie o conteúdo da pasta `build` (gerada após a compilação) para o Raspberry Pi Pico. O programa iniciará automaticamente.


## Funcionamento do Loop Principal 🔄 
```
while (true) //loop infinito
  {
    cor = !cor;
    // Atualiza o conteúdo do display com animações
    ssd1306_fill(&ssd, !cor); // Limpa o display
    printf("digite um caratere \n");
    scanf(" %c",&caractere);
   switch(caractere){...     <--- não irei inserir o código completo do switch(caractere) pois é enorme, o código esta disponivel no próprio repósitorio no arquivo DisplayC.c.
    ...}
  sleep_ms(1000);
  }
}
   
  ```
O loop while (true) garante execução contínua. sleep_ms(1000) garante esse loop infinito. a função ssd1306_fill(&ssd,!cor) limpa o display. printf() imprimi uma mensagem. scanf() possibilita a leitura do caractere. switch(caractere) uma codição para cada caractere, faz com que ao digitar um caractere letra, a letra apareçe no display e ao digitar um numero faz com que apareça no display e na matriz de Led.
## Funcionamento da interrupção.
```
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

  ```
A função void gpio_irq_handler tem como objetivo fazer com que ocorra as ações no pushbotton . current_time e last_time tem como função fazer o debounce para controlar a acção do pushbotton e evita alguns problemas. switch(gpio) para dividir ca função de A para alternar o estado do led verde e imprimir a informação do estado do led no display e no serial monitor e B  para alternar o estado do azul e imprimir a informação do estado do led no display e no serial monitor. 
## Diagrama de Conexões 💡:

https://drive.google.com/file/d/1i8oDxxODmszay-6jJolS29nYXLZshbfd/view?usp=drive_link

## Próximos Passos ➡️

- incluir mais caracteres no display.
- gerar mais animações alem dos caracteres de 0 a 9.
- alternar o estado do led vermelho com joystick.
  
 ## 🔗 Link do Vídeo de Funcionamento:
 https://drive.google.com/file/d/1JxK2GQnYCOw1poWcpsvKzCNGIU2aGyAA/view?usp=drivesdk

 ## Contribuições 🤝

Contribuições são bem-vindas! Sinta-se à vontade para abrir issues ou enviar pull requests.

## 📞 Contato

- 👤 **Autor**: Luiz Eduardo Soares Ferreira.
 
- 📧 **E-mail**: luizeduardosoaresferreira942@gmail.com 

--- 

