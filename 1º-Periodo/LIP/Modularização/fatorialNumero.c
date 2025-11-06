/*
Você foi contratado para ajudar um alquimista a calcular o fatorial de números inteiros positivos, uma operação essencial para suas poções. Crie um procedimento em Scratch que receba um número lido no programa principal, calcule o fatorial multiplicando todos os inteiros de 1 até esse número, e exiba o resultado no programa principal. Utilize loops para realizar essa tarefa de forma eficiente.
*/
#include <stdio.h>

long long calcularFatorial(int n) {
    long long fatorial = 1;
    int i;

    for (i = 1; i <= n; i++) {
        fatorial *= i;
    }

    return fatorial;
}

int main() {
    int n;
    long long resultado;

    printf("Digite um numero inteiro e positivo: ");
    scanf("%d", &n);

    resultado = calcularFatorial(n); 

    printf("O fatorial de %d eh %lld\n", n, resultado);

    return 0;
}

