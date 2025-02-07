# Projeto Interrupção com pushbotton e uma matriz de Led 🚀

Este projeto implementa uma interrupção que ao clicar no pushbotton A incrementa um contador e B que decremeta, e que automaticamente aparece na matriz de Led os numeros de 0 a 9, e tudo isso acontece enquanto o led RGB pisca em um loop infinito.

## Hardware 🛠️

- Microcontrolador RP2040 (Raspberry Pi Pico).
- pushbotton.
- Display NeoPixel RGB 5x5.
- LED RGB.

## Software 💻

* **SDK do Raspberry Pi Pico:** O SDK (Software Development Kit) do Pico, que inclui as bibliotecas e ferramentas necessárias para desenvolver e compilar o código. [Instruções de instalação](https://www.raspberrypi.com/documentation/pico/getting-started/)
* **CMake:** Um sistema de construção multiplataforma usado para gerar os arquivos de construção do projeto.
* **Compilador C/C++:**  Um compilador C/C++ como o GCC (GNU Compiler Collection).
* **Git:** (Opcional) Para clonar o repositório do projeto.


### O código está dividido em vários arquivos para melhor organização:

- **`interrupcao_matrixled.C`**: Código com a função de loop principal: gera as animações de 0 a 9 ao clicar nos pushbotton e ao mesmo tempo os Leds cotinuam piscando 5 vezes em 1 segundo.
- **`contador.c/.h`:** Funções de animação para os numeros de 0 a 9.
- **`neopixel.c/.h`:** Controla o display NeoPixel (inicialização e envio de cores).
- **`CMakeLists.txt`:** Define a estrutura do projeto para o CMake.



## Como Compilar e Executar ⚙️

1. **Instale o SDK do Raspberry Pi Pico:** Siga as instruções no site oficial do Raspberry Pi.
2. **Clone este repositório:** `https://github.com/LuizEduardo-cyber/CEPEDI-Interrup-o-matrizLED.git`
3. **Navegue até o diretório do projeto:** `cd CEPEDI-Interrup-o-matrizLED`
4. **Compile o projeto:** `cmake -B build && cmake --build build`
5. **Copie para o Pico:** Copie o conteúdo da pasta `build` (gerada após a compilação) para o Raspberry Pi Pico. O programa iniciará automaticamente.


## Funcionamento do Loop Principal 🔄 
```

    while (true) {
        printf("A= %d \n",a);
        gpio_put(LED_RED,true);
        sleep_ms(200);
        gpio_put(LED_RED,false);
        sleep_ms(200);
    }
  ```
O loop while (true) garante execução contínua. sleep_ms(200) introduz um pequeno atraso para o liga/desliga do LED. a funcão gpio_put(} define se o LED estará ligado ou desligado. printf tem como função exibir contador.

## Funcionamento da interrupção.
```
void gpio_irq_handler(uint gpio, uint32_t events){
   

    uint32_t current_time = to_us_since_boot(get_absolute_time());
  
  if (current_time - last_time > 300000) {
     last_time = current_time;
   switch(gpio){
      case BUTTON_A:
       a++;
       break;
      case BUTTON_B:
       a--;
       break;
      default:
      break;
   }
    switch(a){
    case 0:
        A_0();
        break;
     case 1:
        A_1();
        break;
     case 2:
        A_2();
        break;
     case 3:
        A_3();
        break;
     case 4:
        A_4();
        break;
     case 5:
        A_5();
        break;
     case 6:
        A_6();
        break;
     case 7:
        A_7();
        break;
     case 8:
        A_8();
        break;
     case 9:
        A_9();
        break;
   
    default:
       a=0;
        break;
     
  }
  }
  
}

  ```
A função void gpio_irq_handler tem como objetivo fazer com que ocorra as ações no pushbotton e na matriz de LED enquanto occore o loop principal. current_time e last_time tem como função fazer o debounce para controlar a acção do pushbotton e evita alguns problemas. switch(gpio) para dividir ca função de A para incrementar e B para decrementar. switch(a) para fazer o controle e sizcornizar as animações com o contador "a".
## Diagrama de Conexões 💡:

https://drive.google.com/file/d/1MCG_Vfk13kZax5y6Qc4J7jIw00iS9PUv/view?usp=drive_link

## Próximos Passos ➡️

- Fazer mais numeros além do 0 ao 9.
- implementar teclado matricial e sicronizar teclas com as animações.
  
 ## 🔗 Link do Vídeo de Funcionamento:
 https://drive.google.com/file/d/1JxK2GQnYCOw1poWcpsvKzCNGIU2aGyAA/view?usp=drivesdk

 ## Contribuições 🤝

Contribuições são bem-vindas! Sinta-se à vontade para abrir issues ou enviar pull requests.

## 📞 Contato

- 👤 **Autor**: Luiz Eduardo Soares Ferreira.
 
- 📧 **E-mail**: luizeduardosoaresferreira942@gmail.com 

--- 

