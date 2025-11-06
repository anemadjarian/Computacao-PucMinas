/*
A série de Fibonacci é formada pela sequência: 1, 1, 2, 3, 5, 8, 13, 21, 34, ... Crie um programa que peça um número N maior que 2 e gere a série até o N-ésimo termo. Mostre sua habilidade em implementar algoritmos clássicos e manipular sequências!
*/
#include <stdio.h>

int main() {
    int n;
    printf("Digite um número maior que 2: ");
    scanf("%d", &n);

    if (n <= 2) {
        printf("Número inválido. Por favor, digite um número maior que 2.\n");
        return 1;
    }

    int a = 1, b = 1, c;
    printf("Sequência de Fibonacci até o %d-ésimo termo:\n", n);
    printf("%d\n%d\n", a, b);

    for (int i = 3; i <= n; i++) {
        c = a + b;
        printf("%d\n", c);
        a = b;
        b = c;
    }

    return 0;
}
