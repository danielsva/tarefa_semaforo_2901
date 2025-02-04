#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

// pinos GPIO correspondentes aos LEDs do semáforo
#define LED_verde 11   // LED Verde - Seguir
#define LED_amarelo 12 // LED Amarelo - Atenção
#define LED_vermelho 13 // LED Vermelho - Parar

// espera troca de sinais (em milissegundos)
#define ESPERA_TROCA 3000 

void configurar_gpio() {
    // inicializando os pinos dos LEDs
    gpio_init(LED_amarelo);
    gpio_init(LED_verde);
    gpio_init(LED_vermelho);

    //definindo os pinos como saída
    gpio_set_dir(LED_amarelo, GPIO_OUT);
    gpio_set_dir(LED_verde, GPIO_OUT);
    gpio_set_dir(LED_vermelho, GPIO_OUT);

    //inicializando o semáforo na cor vermelha
    gpio_put(LED_vermelho, 1); //ligado
    gpio_put(LED_verde, 0); //desligado
    gpio_put(LED_amarelo, 0); //desligado
}

// funcao callback do timer que controla o semaforo
bool mudar_sinal(struct repeating_timer *timer) {
    static int sinal_estado = 1; // comeca no vermelho (1)

    // alterna o estado: 1 -> 2 -> 3 -> 1
    sinal_estado = (sinal_estado % 3) + 1;

    // atualiza os leds conforme o estado
    gpio_put(LED_verde, sinal_estado == 3);
    gpio_put(LED_amarelo, sinal_estado == 2);
    gpio_put(LED_vermelho, sinal_estado == 1);

    // mostra o estado no serial
    switch (sinal_estado) {
        case 1:
            printf("🚦 pare! vermelho.\n");
            break;
        case 2:
            printf("⚠️  atencao! amarelo.\n");
            break;
        case 3:
            printf("✅ siga! verde.\n");
            break;
    }

    return true; // continua o timer
}


int main(){

    stdio_init_all(); 
    configurar_gpio(); 

    struct repeating_timer temporizador;
    add_repeating_timer_ms(ESPERA_TROCA, mudar_sinal, NULL, &temporizador);


    while (true) {
        printf("Não ultrapasse o sinal vermelho! Aguarde a sua vez!\n");
        sleep_ms(1000); // espera 1s
    }

    return 0;
}
