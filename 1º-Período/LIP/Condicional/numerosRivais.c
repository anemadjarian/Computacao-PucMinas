/*
Imagine que você é um juiz em uma competição de números. Sua missão é criar um programa em Scratch que receba dois números competidores e determine qual deles é o vencedor, ou se eles são igualmente poderosos. Construa um programa que leia dois números e anuncie o maior deles ou declare que são iguais, se for o caso. Que comece a competição!
*/
#include <stdio.h>

int main() {
    int num1, num2;
    printf("Digite o primeiro número: ");
    scanf("%d", &num1);
    printf("Digite o segundo número: ");
    scanf("%d", &num2);

    if (num1 > num2) {
        printf("O número %d é o vencedor!\n", num1);
    } else if (num2 > num1) {
        printf("O número %d é o vencedor!\n", num2);
    } else {
        printf("Os números são iguais!\n");
    }

    return 0;
}
