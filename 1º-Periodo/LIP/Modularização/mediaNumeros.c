/*
Ajude um cientista de dados a calcular a média de um conjunto de números que ele coleta diariamente. Desenvolva um procedimento em Scratch que receba um conjunto indeterminado de valores (FLAG valor negativo), receba esses números, calcule a média NO procedimento e exiba o resultado NO programa principal. Use sua habilidade com loops e variáveis para facilitar o trabalho do cientista!
*/

#include <stdio.h>

float calcularMedia() {
    float num, soma = 0;
    int cont = 0;

    printf("Digite os numeros (negativo para encerrar):\n");

    while (1) {
        scanf("%f", &num);
        if (num < 0)
            break;
        soma += num;
        cont++;
    }

    if (cont == 0)
        return 0;
    else
        return soma / cont;
}

int main() {
    float media;

    media = calcularMedia(); 

    printf("A media dos valores digitados eh: %.2f\n", media);

    return 0;
}
