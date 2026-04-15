/*
Crie um programa onde o sprite leia um número e, em seguida, calcule e imprima o fatorial desse número. Mostre sua habilidade em manipular laços de repetição e operações matemáticas complexas!
*/
#include <stdio.h>

int main() {
    int numero;
    printf("Digite um número: ");
    scanf("%d", &numero);

    int fatorial = 1;
    for (int i = 1; i <= numero; i++) {
        fatorial *= i;
    }

    printf("O fatorial de %d é %d\n", numero, fatorial);
    return 0;
}
