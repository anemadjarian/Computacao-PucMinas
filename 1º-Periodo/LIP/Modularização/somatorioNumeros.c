/*
Imagine que você está criando um contador mágico que pode somar todos os números de 1 até qualquer número que você escolher. Sua tarefa é programar um procedimento em Scratch que peça ao usuário um número inteiro e positivo e, em seguida, calcule e mostre o somatório de 1 até esse número. Utilize loops para tornar a magia possível!
*/

#include <stdio.h>

int calcularSomatorio(int n) {
    int soma = 0;
    for (int i = 1; i <= n; i++) {
        soma += i;
    }
    return soma;
}

int main() {
    int n, resultado;

    printf("Digite um numero inteiro e positivo: ");
    scanf("%d", &n);

    resultado = calcularSomatorio(n);

    printf("O somatorio de 1 ate %d eh %d\n", n, resultado);

    return 0;
}

