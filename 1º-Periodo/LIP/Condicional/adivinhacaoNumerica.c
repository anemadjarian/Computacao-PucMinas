/*
Bem-vindo ao desafio final: o jogo da adivinhação numérica! Crie um programa em Scratch que desafie o usuário a pensar em um número entre 1 e 1023. Seu programa deve adivinhar o número escolhido em no máximo 10 tentativas, usando a técnica do valor intermediário - (também conhecida como busca binária). Conte quantas tentativas foram necessárias para alcançar a vitória. Mostre seu talento em adivinhação e conquiste o título de Mestre dos Números!
*/

#include <stdio.h>

int main() {
    int inicio = 1, fim = 1023, meio;
    int resposta;
    int tentativas = 0;

    printf("Pense em um numero entre 1 e 1023.\n");
    printf("Eu vou tentar adivinhar!\n");
    printf("Responda: 1 - muito pequeno, 2 - muito grande, 3 - acertei\n\n");

    do {
        meio = (inicio + fim) / 2;
        tentativas++;

        printf("Tentativa %d: O numero eh %d?\n", tentativas, meio);
        printf("Sua resposta: ");
        scanf("%d", &resposta);

        if (resposta == 1) {
            inicio = meio + 1;
        } else if (resposta == 2) {
            fim = meio - 1;
        } else if (resposta == 3) {
            printf("Acertei em %d tentativas!\n", tentativas);
        } else {
            printf("Resposta invalida! Use 1, 2 ou 3.\n");
        }

    } while (resposta != 3 && tentativas < 10);

    if (resposta != 3) {
        printf("Nao consegui adivinhar em 10 tentativas.\n");
    }

    return 0;
}
