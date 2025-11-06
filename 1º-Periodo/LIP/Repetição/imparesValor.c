/*
Desenvolva um programa onde o sprite peça um valor inicial e, a partir desse valor, mostre os próximos 10 números ímpares. Desafie-se a manipular números e controlar a lógica de repetição!
*/
#include <stdio.h>

int main() {
    int valorInicial;
    printf("Digite um valor inicial: ");
    scanf("%d", &valorInicial);

    for (int i = 0; i < 10; i++) {
        if (valorInicial % 2 == 0) {
            valorInicial++;
        }
        printf("%d\n", valorInicial);
        valorInicial += 2;
    }
    return 0;
}
