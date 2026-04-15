/*
Você é um explorador em busca do menor número em uma sequência misteriosa de valores. Usando o Scratch, desenvolva um programa que leia uma série de números e identifique o menor deles. A jornada termina quando um número negativo é encontrado, marcando o fim da busca. Prepare-se para encontrar o tesouro escondido!
*/
#include <stdio.h>

int main() {
    int numero, menor;
    printf("Digite um número (ou um número negativo para sair): ");
    scanf("%d", &numero);

    if (numero < 0) {
        printf("Nenhum número válido foi digitado.\n");
        return 0;
    }

    menor = numero;

    while (1) {
        printf("Digite um número (ou um número negativo para sair): ");
        scanf("%d", &numero);
        if (numero < 0) {
            break;
        }
        if (numero < menor) {
            menor = numero;
        }
    }

    printf("O menor número digitado foi: %d\n", menor);
    return 0;
}
