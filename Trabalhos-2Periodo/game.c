#include<stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Game{
    int id;
    char name[50];
    char releaseDate[11];
    int estimatedOwners;
    float price;
    char supportedLanguage[50][100];
    int metacriticScore;
    float userScore;
    int achievements;
    char publishers[50][100];
    char developers[50][100];
    char categories[50][100];
    char genres[50][100];
    char tags[50][100];
} Game;

int main(){
    FILE *arq = fopen("games.csv", "r");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    Game jogo[100];
    int cont=0;
    char linha[100];
     while (fgets(linha, 100, arq) != NULL && cont<100) {

        linha[strcspn(linha, "\n")]='\0'; //Remove o \n e muda para \0

        char *token = strtok(linha, ","); //Separa a virgula e pega cada valor separadamente
        if (token != NULL){
            jogo[cont].id = atoi(token);
        }

        token = strtok(NULL, ",");
        if (token != NULL){
            strcpy(jogo[cont].name, token);
        }

        token = strtok(NULL, ",");
        if(token != NULL){
            strcpy(jogo[cont].releaseDate, token);
        }

        token = strtok(NULL, ",");
        if (token != NULL){
            jogo[cont].estimatedOwners = atoi(token);
        }

        token = strtok(NULL, ",");
        if (token != NULL){
            jogo[cont].price = atof(token);
        }

        token = strtok(NULL, ",");
        if (token != NULL){
            jogo[cont].price = atof(token);
        }
     }
    fclose(arq);
    return 0;
}