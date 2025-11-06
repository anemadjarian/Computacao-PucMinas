/*
Imagine que você está criando um jogo em que o jogador deve enfrentar uma série de desafios numéricos. Primeiro, peça ao jogador para definir o número de desafios que ele deseja enfrentar. Em seguida, gere uma lista de valores aleatórios representando a dificuldade de cada desafio. Ao final, mostre ao jogador qual foi o desafio mais fácil e qual foi o mais difícil!
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numDesafios;

    printf("Digite o numero de desafios: ");
    scanf("%d", &numDesafios);

    int dificuldades[numDesafios];

    srand(time(NULL)); // Inicializa o gerador de numeros aleatorios

    for (int i = 0; i < numDesafios; i++) {
        dificuldades[i] = rand() % 100 + 1; // Dificuldade entre 1 e 100
    }

    int maisFacil = dificuldades[0];
    int maisDificil = dificuldades[0];

    for (int i = 1; i < numDesafios; i++) {
        if (dificuldades[i] < maisFacil) {
            maisFacil = dificuldades[i];
        }
        if (dificuldades[i] > maisDificil) {
            maisDificil = dificuldades[i];
        }
    }

    printf("Desafio mais facil: %d\n", maisFacil);
    printf("Desafio mais dificil: %d\n", maisDificil);

    return 0;
}
