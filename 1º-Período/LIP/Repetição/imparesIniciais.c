/*
Crie um programa que faça o sprite escrever os 10 primeiros números ímpares. Utilize laços de repetição e condições para identificar e imprimir os números corretos. Teste sua lógica e habilidades de programação!
*/
#include <stdio.h>

int main() {
    for (int i = 1; i <= 20; i++) {
        if (i % 2 != 0) {
            printf("%d\n", i);
        }
    }
    return 0;
}