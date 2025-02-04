# Projeto: Semáforo com Temporizador Periódico no Raspberry Pi Pico W

## Descrição
Este projeto implementa um semáforo utilizando o microcontrolador Raspberry Pi Pico W e a função `add_repeating_timer_ms()` da ferramenta Pico SDK. O semáforo alterna entre as luzes vermelha, amarela e verde com um intervalo de 3 segundos para cada sinal. O controle dos LEDs é feito através de um temporizador periódico, e informações sobre o estado atual do semáforo são impressas na porta serial a cada segundo.

## Componentes Utilizados
1. **Microcontrolador:** Raspberry Pi Pico W  
2. **LEDs:** 3 LEDs (vermelho, amarelo e verde)  
3. **Resistores:** 3 resistores de 330 Ω  

## Configuração do Hardware
Os LEDs estão conectados às seguintes GPIOs do Pico W:
- **LED Vermelho:** GPIO 2
- **LED Amarelo:** GPIO 3
- **LED Verde:** GPIO 4

Cada LED está em série com um resistor de 330 Ω conectado ao GND.

## Instruções de Uso

### 1. Configuração do Ambiente
1. Certifique-se de ter o **Pico SDK** instalado e configurado.
2. Clone ou baixe este repositório no seu computador.
3. Abra o projeto no **VS Code** com a extensão **Wokwi** instalada.

### 2. Compilando o Projeto
1. No **VS Code**, vá até a parte da extensão da **Raspberry**;
2. Clique em **compilar projeto**;

### 3. Simulação no Wokwi
1. Abra o arquivo `diagram.json` no VS Code.
2. Clique no botão de **play** no canto superior direito para iniciar a simulação.
3. Observe o funcionamento do semáforo, com os LEDs alternando a cada 3 segundos.

### 4. Saída Serial
Durante a execução do programa, mensagens indicando o estado atual do semáforo serão exibidas na porta serial a cada segundo. Exemplo:
```
🚦 pare! vermelho.
⚠️  atencao! amarelo.
✅ siga! verde.
```
## Autor
Projeto desenvolvido para a atividade de temporizador periódico utilizando o Raspberry Pi Pico W, conforme orientação do curso.

