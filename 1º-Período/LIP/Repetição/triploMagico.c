/*
Crie um programa onde o sprite interaja com o usuário pedindo um número e, em seguida, imprimindo o triplo desse número. Repita essa interação 5 vezes. Vamos ver como você lida com a repetição(iteração) e a interação dinâmica!
*/
#include <stdio.h>

int main() {
    int numero;
    for (int i = 0; i < 5; i++) {
        printf("Digite um número: ");
        scanf("%d", &numero);
        printf("O triplo de %d é %d\n", numero, numero * 3);
    }
    return 0;
}