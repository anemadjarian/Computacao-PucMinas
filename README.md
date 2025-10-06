# 🧠 Exercícios Reaizados

Este repositório reúne os materiais, exercícios e projetos desenvolvidos durante a graduação.

---

## 📘 Sobre

💻 **Exercícios**  
📚 **Trabalhos**  
📝 **Provas**  

---

## 🛠️ Tecnologias Utilizadas

- Linguagem: Java, C
- IDE: VSCode



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

void transformDate(char *token, int cont, Game *jogo){
    char dia[3]="01", mes[3]="01", ano[5];

    char *virgula = strchr(token, ',');
    if (virgula != NULL && (virgula - token) >= 3) {
        // pega dois dígitos antes da vírgula
        if (*(virgula-2) >= '0' && *(virgula-2) <= '9')
            dia[0] = *(virgula-2);
        if (*(virgula-1) >= '0' && *(virgula-1) <= '9')
            dia[1] = *(virgula-1);
    }

        if (strstr(token, "Jan")) strcpy(mes,"01");
        else if (strstr(token,"Feb")) strcpy(mes,"02");
        else if (strstr(token,"Mar")) strcpy(mes,"03");
        else if (strstr(token,"Apr")) strcpy(mes,"04");
        else if (strstr(token,"May")) strcpy(mes,"05");
        else if (strstr(token,"Jun")) strcpy(mes,"06");
        else if (strstr(token,"Jul")) strcpy(mes,"07");
        else if (strstr(token,"Aug")) strcpy(mes,"08");
        else if (strstr(token,"Sep")) strcpy(mes,"09");
        else if (strstr(token,"Oct")) strcpy(mes,"10");
        else if (strstr(token,"Nov")) strcpy(mes,"11");
        else if (strstr(token,"Dec")) strcpy(mes,"12");

    int j=0;
    for(int i=8; i<12; i++){
        ano[j]=token[i];
        j++;
    }
    ano[4]='\0';

    sprintf(jogo[cont].releaseDate, "%s/%s/%s", dia, mes, ano);

}

void transformLanguage(char *token, int cont, Game *jogo){
    int j = 0;
    char *aux = strtok(token, "[]',"); // separa por [, ], ', ou ,
    while (aux != NULL) {
        if (strlen(aux) > 1) { // ignora vazio
            strcpy(jogo[cont].supportedLanguages[j], aux);
            j++;
        }
        aux = strtok(NULL, "[]',");
    }
    jogo[cont].qtdLanguages = j;
}

void transformPublichers(char *token, int cont, Game *jogo){
    int j = 0;
    char *aux = strtok(token, "[]\","); // separa por aspas, vírgula, []
    while (aux != NULL) {
        if (strlen(aux) > 1) { 
            strcpy(jogo[cont].publishers[j], aux);
            j++;
        }
        aux = strtok(NULL, "[]\",");
    }
    jogo[cont].qtdPublishers = j;
}

void transformDevelopers(char *token, int cont, Game *jogo) {
    int j = 0;
    char *aux = strtok(token, "[]\","); 
    while (aux != NULL) {
        if (strlen(aux) > 1) { 
            strcpy(jogo[cont].developers[j], aux);
            j++;
        }
        aux = strtok(NULL, "[]\",");
    }
    jogo[cont].qtdDevelopers = j;
}

void transformCategories(char *token, int cont, Game *jogo) {
    int j = 0;
    char *aux = strtok(token, "[]\","); 
    while (aux != NULL) {
        if (strlen(aux) > 1) { 
            strcpy(jogo[cont].categories[j], aux);
            j++;
        }
        aux = strtok(NULL, "[]\",");
    }
    jogo[cont].qtdCategories = j;
}

void transformGenres(char *token, int cont, Game *jogo) {
    int j = 0;
    char *aux = strtok(token, "[]\","); 
    while (aux != NULL) {
        if (strlen(aux) > 1) { 
            strcpy(jogo[cont].genres[j], aux);
            j++;
        }
        aux = strtok(NULL, "[]\",");
    }
    jogo[cont].qtdGenres = j;
}

void transformTags(char *token, int cont, Game *jogo) {
    int j = 0;
    char *aux = strtok(token, "[]\","); 
    while (aux != NULL) {
        if (strlen(aux) > 1) { 
            strcpy(jogo[cont].tags[j], aux);
            j++;
        }
        aux = strtok(NULL, "[]\",");
    }
    jogo[cont].qtdTags = j;
}

void cleanNumber(char *token, char *new) {
    int j = 0;
    for (int i = 0; token[i] != '\0'; i++) {
        if ((token[i] >= '0' && token[i] <= '9') || token[i] == '.' || token[i] == ',') {
            if (token[i] == ',') // troca vírgula por ponto
                new[j++] = '.';
            else
                new[j++] = token[i];
        }
    }
    new[j] = '\0';
}

void freeToPlay(char *token, int cont, Game *jogo){
    if (token[0] == 'F') {
        jogo[cont].price = 0.0; 
    } else {
        char new[20];
        cleanNumber(token, new);
        if (strlen(new) > 0)
            jogo[cont].price = atof(new); 
        else
            jogo[cont].price = 0.0;
    }
}

void preencheVetor(Game jogo[], char line[], int cont){

    line[strcspn(line, "\n")]='\0'; //Remove o \n e muda para \0

    char *token = strtok(line, ","); //Separa a virgula e pega cada valor separadamente
    if(token[0])
    if (token != NULL){ 
        jogo[cont].id = atoi(token); 
    } 
    
    token = strtok(NULL, ","); 
    if (token != NULL){ 
        strcpy(jogo[cont].name, token); 
    } 
    
    token = strtok(NULL, ","); 
    if(token != NULL){ 
        transformDate(token, cont, jogo);
    } 
    
    token = strtok(NULL, ","); 
    if (token != NULL){ 
        char new[20];
        cleanNumber(token, new);
        jogo[cont].estimatedOwners = atoi(new);
    } 

    token = strtok(NULL, ","); 
    if (token != NULL){ 
        freeToPlay(token, cont, jogo);
    }

    token = strtok(NULL, ","); 
    if (token != NULL){ 
        transformLanguage(token, cont, jogo);
    }

    token = strtok(NULL, ","); 
    if (token != NULL){ 
        jogo[cont].metacriticScore = atoi(token);
    } else{
        jogo[cont].metacriticScore = -1;
    }

    token = strtok(NULL, ","); 
    if (token != NULL){ 
        jogo[cont].userScore = atof(token); 
    } else{
        jogo[cont].userScore = -1.0; 
    }

    token = strtok(NULL, ","); 
    if (token != NULL){ 
        jogo[cont].achievements = atoi(token); 
    } else{
        jogo[cont].achievements = 0;
    }

    token = strtok(NULL, ","); 
    if(token != NULL){ 
        transformPublichers(token, cont, jogo);
    }

    token = strtok(NULL, ","); 
    if (token != NULL){ 
        transformDevelopers(token, cont, jogo);
    }

    token = strtok(NULL, ","); 
    if (token != NULL){ 
        transformCategories(token, cont, jogo);
    }

    token = strtok(NULL, ","); 
    if (token != NULL){ 
        transformGenres(token, cont, jogo);
    }

    token = strtok(NULL, ","); 
    if (token != NULL){ 
        transformTags(token, cont, jogo);
    }
}

int pesquisaSequencial(Game *jogo, int n, int idPesquisa) {
    for (int i = 0; i < n; i++) {
        if (jogo[i].id == idPesquisa) {
            return i;
        }
    }
    return -1; // não encontrado
}

void printar(Game *jogo, int resp){
    printf("=> %d ## ", jogo[resp].id);
    printf("%s ## ", jogo[resp].name);
    printf("%s ## ", jogo[resp].releaseDate);
    printf("%d ## ", jogo[resp].estimatedOwners);
    printf("%f ## ", jogo[resp].price);
    
    printf("[");
    for(int i = 0; i < jogo[resp].qtdLanguages-1; i++){
        printf("%s, ", jogo[resp].supportedLanguages[i]);
    }
    printf("%s] ## ", jogo[resp].supportedLanguages[jogo[resp].qtdLanguages-1]);

    printf("%d ## ", jogo[resp].metacriticScore);
    printf("%f ## ", jogo[resp].userScore);
    printf("%d ## ", jogo[resp].achievements);

    printf("[");
    for(int i = 0; i < jogo[resp].qtdPublishers-1; i++){
        printf("%s, ", jogo[resp].publishers[i]);
    }
    printf("%s] ## ", jogo[resp].publishers[jogo[resp].qtdPublishers-1]);

    printf("[");
    for(int i = 0; i < jogo[resp].qtdDevelopers-1; i++){
        printf("%s, ", jogo[resp].developers[i]);
    }
    printf("%s] ## ", jogo[resp].developers[jogo[resp].qtdDevelopers-1]);

    printf("[");
    for(int i = 0; i < jogo[resp].qtdCategories-1; i++){
        printf("%s, ", jogo[resp].categories[i]);
    }
    printf("%s] ## ", jogo[resp].categories[jogo[resp].qtdCategories-1]);

    printf("[");
    for(int i = 0; i < jogo[resp].qtdGenres-1; i++){
        printf("%s, ", jogo[resp].genres[i]);
    }
    printf("%s] ## ", jogo[resp].genres[jogo[resp].qtdGenres-1]);

    printf("[");
    for(int i = 0; i < jogo[resp].qtdTags-1; i++){
        printf("%s, ", jogo[resp].tags[i]);
    }
    printf("%s] ## ", jogo[resp].tags[jogo[resp].qtdTags-1]);
}

int main() {
    FILE *arq = fopen("games.csv", "r");
    if (arq==NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    char line[MAX_LINE];
    int cont=0;
    Game *jogo = (Game *)malloc(2000 * sizeof(Game));

    // Ignorar cabeçalho
    fgets(line, sizeof(line), arq);

    while(fgets(line, sizeof(line), arq)!=NULL){
        preencheVetor(jogo, line, cont);
        cont++;
    }

    char idInput[50];
    int resp;
    scanf("%s", &idInput);
    idInput[strcspn(idInput, "\n")] = '\0'; // remove \n, muda para /0

    while(strcmp(idInput, "FIM") != 0){
        int idPesquisa = atoi(idInput);
        resp = pesquisaSequencial(jogo, cont, idPesquisa);

        if(resp != -1){
            printar(jogo, resp);
        } else{
            printf("Jogo com ID %d nao encontrado.\n", idPesquisa);
        }

        fgets(idInput, sizeof(idInput), stdin);
        idInput[strcspn(idInput, "\n")] = '\0';
    }

    fclose(arq);
    free(jogo);
    return 0;
}
