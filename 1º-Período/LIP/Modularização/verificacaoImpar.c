/*
Você está criando um programa para um festival de números, onde os participantes podem verificar se seus números favoritos são primos. Desenvolva um procedimento em Scratch que receba um número do usuário lido NO programa principal, verifique se ele é primo e exiba NO procedimento uma mensagem informando o resultado. Utilize sua lógica para identificar os divisores corretamente!
*/
#include <stdio.h>
#include <stdbool.h>

// Procedimento que verifica e mostra se o número é primo
void verificarPrimo(int n) {
    if (n <= 1) {
        printf("%d nao eh primo.\n", n);
        return;
    }

    bool primo = true;
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            primo = false;
            break;
        }
    }

    if (primo)
        printf("%d eh primo.\n", n);
    else
        printf("%d nao eh primo.\n", n);
}

int main() {
    int numero;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    verificarPrimo(numero); // chamada do procedimento

    return 0;
}
