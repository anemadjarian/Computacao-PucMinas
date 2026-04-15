/*
Escreva um programa onde o sprite leia um conjunto de números e, ao encontrar a flag -1, calcule e imprima a média desses números. Desafie-se a manipular conjuntos de dados e realizar cálculos precisos!
*/
#include <stdio.h>

int main() {
    int numero, soma = 0, contador = 0;
    printf("Digite um conjunto de números (digite -1 para finalizar):\n");

    while (1) {
        scanf("%d", &numero);
        if (numero == -1) {
            break;
        }
        soma += numero;
        contador++;
    }

    if (contador > 0) {
        float media = (float)soma / contador;
        printf("A média dos números digitados é: %.2f\n", media);
    } else {
        printf("Nenhum número válido foi digitado.\n");
    }

    return 0;
}
