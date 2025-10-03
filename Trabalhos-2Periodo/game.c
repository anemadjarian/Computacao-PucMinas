#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STRING 100
#define MAX_ARRAY 50
#define MAX_LINE 1000

typedef struct Game {
    int id;  
    char name[MAX_STRING];
    char releaseDate[11];
    int estimatedOwners;
    float price;

    char supportedLanguages[MAX_ARRAY][MAX_STRING];
    int qtdLanguages;

    int metacriticScore;
    float userScore;
    int achievements;

    char publishers[MAX_ARRAY][MAX_STRING];
    int qtdPublishers;

    char developers[MAX_ARRAY][MAX_STRING];
    int qtdDevelopers;

    char categories[MAX_ARRAY][MAX_STRING];
    int qtdCategories;

    char genres[MAX_ARRAY][MAX_STRING];
    int qtdGenres;

    char tags[MAX_ARRAY][MAX_STRING];
    int qtdTags;

} Game;

void transformaData(char *token, int cont, Game *jogo){
    char dia[3], mes[3], ano[5];

    if(token[7]!=','){
        dia[0] = token[6];
        dia[1] = token[7];
        dia[2] = '\0';
    } else{
        dia[0] = '0';
        dia[1] = token[6];
        dia[2] = '\0';
    }

    if(token[1]=='J'){
        if(token[2]=='a'){
            mes[0]='0';
            mes[1]='1';
            mes[2] = '\0';
        }
        else if(token[3]=='n'){
            mes[0]='0';
            mes[1]='6';
            mes[2] = '\0';
        }
        else if(token[3]=='l'){
            mes[0]='0';
            mes[1]='7';
            mes[2] = '\0';
        }
    }
    if(token[1]=='F'){
        mes[0]='0';
        mes[1]='2';
        mes[2] = '\0';
    }
    if(token[1]=='M'){
        if(token[3]=='r'){
            mes[0]='0';
            mes[1]='3';
            mes[2] = '\0';
        }
        else if(token[3]=='y'){
            mes[0]='0';
            mes[1]='5';
            mes[2] = '\0';
        }
    }
    if(token[1]=='A'){
        if(token[2]=='p'){
            mes[0]='0';
            mes[1]='4';
            mes[2] = '\0';
        }
        else if(token[2]=='u'){
            mes[0]='0';
            mes[1]='8';
            mes[2] = '\0';
        }
    }
    if(token[1]=='S'){
        mes[0]='0';
        mes[1]='9';
        mes[2] = '\0';
    }
    if(token[1]=='O'){
        mes[0]='1';
        mes[1]='0';
        mes[2] = '\0';
    }
    if(token[1]=='N'){
        mes[0]='1';
        mes[1]='1';
        mes[2] = '\0';
    }
    if(token[1]=='D'){
        mes[0]='1';
        mes[1]='2';
        mes[2] = '\0';
    }

    int j=0;
    for(int i=8; i<12; i++){
        ano[j]=token[i];
        j++;
    }
    ano[4]='\0';

    char data[11];
    data[0]=dia[0];
    data[1]=dia[1];
    data[2]='/';
    data[3]=mes[0];
    data[4]=mes[1];
    data[5]='/';
    data[6]=ano[0];
    data[7]=ano[1];
    data[8]=ano[2];
    data[9]=ano[3];
    data[10]='\0';

    strcpy(jogo[cont].releaseDate, data);
}

void preencheVetor(Game jogo[], char line[], int cont){

    line[strcspn(line, "\n")]='\0'; //Remove o \n e muda para \0

    char *token = strtok(line, ","); //Separa a virgula e pega cada valor separadamente
    if (token != NULL){ 
        jogo[cont].id = atoi(token); 
    } 
    
    token = strtok(NULL, ","); 
    if (token != NULL){ 
        strcpy(jogo[cont].name, token); 
    } 
    
    token = strtok(NULL, ","); 
    if(token != NULL){ 
        transformaData(token, cont, jogo);
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
        jogo[cont].metacriticScore = atoi(token); 
    } 

    token = strtok(NULL, ","); 
    if (token != NULL){ 
        jogo[cont].userScore = atof(token); 
    }

    token = strtok(NULL, ","); 
    if (token != NULL){ 
        jogo[cont].achievements = atoi(token); 
    }
}

int main() {
    FILE *arq = fopen("games.csv", "r");
    if (arq==NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    char line[MAX_LINE];
    int cont=0;
    Game jogo[1851];

    // Ignorar cabeçalho
    fgets(line, sizeof(line), arq);

    while(fgets(line, sizeof(line), arq)!=NULL){
        preencheVetor(jogo, line, cont);
        cont++;
    }
    fclose(arq);
    return 0;
}