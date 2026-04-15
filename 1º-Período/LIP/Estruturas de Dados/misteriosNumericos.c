/*
Você foi contratado como um detetive de dados para analisar um conjunto de informações misteriosas. Peça ao usuário para determinar quantas pistas (números) ele deseja investigar. Após gerar essas pistas aleatoriamente, descubra quantas delas são mais complexas (maiores) do que a média do conjunto. Ajude a desvendar o mistério!
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numPistas;

    printf("Quantas pistas voce deseja investigar? ");
    scanf("%d", &numPistas);

    int pistas[numPistas];
    int soma = 0;

    srand(time(NULL)); // Inicializa o gerador de numeros aleatorios

    for (int i = 0; i < numPistas; i++) {
        pistas[i] = rand() % 100 + 1; // Pistas entre 1 e 100
        soma += pistas[i];
    }

    float media = (float)soma / numPistas;
    int contagemComplexas = 0;

    for (int i = 0; i < numPistas; i++) {
        if (pistas[i] > media) {
            contagemComplexas++;
        }
    }

    printf("Media das pistas: %.2f\n", media);
    printf("Numero de pistas mais complexas: %d\n", contagemComplexas);

    return 0;
}
