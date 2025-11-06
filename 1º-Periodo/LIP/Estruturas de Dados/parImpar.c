/*
Prepare-se para uma jornada através do reino dos números! Crie uma lista de 20 números aleatórios entre 15 e 50, representando as criaturas que habitam este reino. Para cada criatura, determine se ela pertence ao clã dos Pares ou dos Ímpares e registre essa informação em uma segunda lista. Ajude a manter a paz entre os clãs!
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int criaturas[20];
    char clãs[20];

    srand(time(NULL));

    // Gerar criaturas e determinar clã
    for (int i = 0; i < 20; i++) {
        criaturas[i] = rand() % 36 + 15; // Números entre 15 e 50
        if (criaturas[i] % 2 == 0) {
            clãs[i] = 'P'; // Par
        } else {
            clãs[i] = 'I'; // Ímpar
        }
    }

    // Exibir resultados
    printf("Criaturas e seus clãs:\n");
    for (int i = 0; i < 20; i++) {
        printf("Criatura %d: %d (Clã %c)\n", i + 1, criaturas[i], clãs[i]);
    }

    return 0;
}
