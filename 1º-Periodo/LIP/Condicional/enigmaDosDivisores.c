/*
Você é um decifrador de enigmas numéricos. Crie um programa em Scratch que peça um número ao usuário e determine seu status de divisibilidade. O número pode ser um mestre dos divisores, sendo divisível por 5 e 3, ou pode ter outras combinações. Desvende o enigma e mostre a verdade sobre cada número!
*/
#include <stdio.h>

int main() {
    int numero;
    printf("Digite um número: ");
    scanf("%d", &numero);

    if (numero % 5 == 0 && numero % 3 == 0) {
        printf("O número %d é um mestre dos divisores!\n", numero);
    } else if (numero % 5 == 0) {
        printf("O número %d é divisível por 5.\n", numero);
    } else if (numero % 3 == 0) {
        printf("O número %d é divisível por 3.\n", numero);
    } else {
        printf("O número %d não é divisível nem por 5 nem por 3.\n", numero);
    }

    return 0;
}
