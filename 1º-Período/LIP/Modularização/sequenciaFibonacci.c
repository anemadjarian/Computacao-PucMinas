/*
Você está desenvolvendo um programa para um museu de matemática que deseja mostrar a famosa sequência de Fibonacci. Crie um procedimento em Scratch que permita ao usuário escolher quantos números da sequência deseja ver. O procedimento deve calcular e exibir os números da sequência até o termo solicitado em uma lista de valores. Lembre-se de armazenar e manipular valores adequadamente!
*/
#include <stdio.h>


void mostrarFibonacci(int n) {
    long long fib1 = 0, fib2 = 1, proximo;
    int i;

    printf("Sequencia de Fibonacci:\n");
    for (i = 1; i <= n; i++) {
        printf("%lld ", fib1);
        proximo = fib1 + fib2;
        fib1 = fib2;
        fib2 = proximo;
    }
    printf("\n");
}

int main() {
    int n;

    printf("Quantos termos da sequencia de Fibonacci voce deseja ver? ");
    scanf("%d", &n);

    mostrarFibonacci(n);

    return 0;
}
