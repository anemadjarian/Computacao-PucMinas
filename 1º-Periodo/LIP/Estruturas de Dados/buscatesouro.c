/*
Você está no meio de uma emocionante caça ao tesouro numérico! Primeiro, peça ao explorador para indicar quantos tesouros ele quer descobrir. Crie uma lista de valores aleatórios representando a localização dos tesouros. Em seguida, permita que o explorador insira quantas coordenadas quiser para tentar encontrar os tesouros. Para cada tentativa, revele se o tesouro está na lista ou não.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numTesouros;

    printf("Quantos tesouros voce deseja descobrir? ");
    scanf("%d", &numTesouros);

    int tesouros[numTesouros];
    srand(time(NULL));

    for (int i = 0; i < numTesouros; i++) {
        tesouros[i] = rand() % 100 + 1;
    }

    int tentativa;
    char continuar;

    do {
        printf("Digite uma coordenada para procurar um tesouro (1-100): ");
        scanf("%d", &tentativa);

        int encontrado = 0;
        for (int i = 0; i < numTesouros; i++) {
            if (tesouros[i] == tentativa) {
                encontrado = 1;
                break;
            }
        }

        if (encontrado) {
            printf("Parabens! Voce encontrou um tesouro na coordenada %d.\n", tentativa);
        } else {
            printf("Que pena! Nao ha tesouro na coordenada %d.\n", tentativa);
        }

        printf("Deseja tentar novamente? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's');

    printf("Obrigado por jogar!\n");
    return 0;
}
