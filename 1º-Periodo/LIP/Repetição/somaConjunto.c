/*
Desenvolva um programa onde o sprite leia um conjunto de números e, ao encontrar a flag -1, imprima a soma desses números. Teste sua capacidade de trabalhar com conjuntos de dados e controle de fluxo!
*/
#include <stdio.h>

int main() {
    int numero, soma = 0;
    printf("Digite um conjunto de números (digite -1 para finalizar):\n");

    while (1) {
        scanf("%d", &numero);
        if (numero == -1) {
            break;
        }
        soma += numero;
    }

    printf("A soma dos números digitados é: %d\n", soma);
    return 0;
}
