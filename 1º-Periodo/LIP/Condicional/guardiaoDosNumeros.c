/*
Como guardião dos números, sua tarefa é proteger e analisar uma sequência de valores. Construa um programa em Scratch que leia números até encontrar um valor negativo, e então revele o menor, o maior e a média entre eles. Mostre suas habilidades e mantenha o equilíbrio entre os números!
*/
#include <stdio.h>

int main() {
    int numero, menor, maior, soma = 0, contador = 0;
    printf("Digite um número (ou um número negativo para sair): ");
    scanf("%d", &numero);

    if (numero < 0) {
        printf("Nenhum número válido foi digitado.\n");
        return 0;
    }

    menor = numero;
    maior = numero;
    soma = numero;
    contador = 1;

    while (1) {
        printf("Digite um número (ou um número negativo para sair): ");
        scanf("%d", &numero);
        if (numero < 0) {
            break;
        }
        if (numero < menor) {
            menor = numero;
        }
        if (numero > maior) {
            maior = numero;
        }
        soma += numero;
        contador++;
    }

    printf("O menor número digitado foi: %d\n", menor);
    printf("O maior número digitado foi: %d\n", maior);
    printf("A média dos números digitados é: %.2f\n", (float)soma / contador);
    return 0;
}
