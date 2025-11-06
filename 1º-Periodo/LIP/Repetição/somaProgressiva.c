/*
Escreva um programa onde o sprite leia um número e, em seguida, calcule e imprima a soma de todos os números de 1 até esse número. Utilize laços de repetição e operações aritméticas para resolver este desafio!
*/
#include <stdio.h>

int main() {
    int numero, soma = 0;
    printf("Digite um número: ");
    scanf("%d", &numero);

    for (int i = 1; i <= numero; i++) {
        soma += i;
    }

    printf("A soma de todos os números de 1 até %d é %d\n", numero, soma);
    return 0;
}
