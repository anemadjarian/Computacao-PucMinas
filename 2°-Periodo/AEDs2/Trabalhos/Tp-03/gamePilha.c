#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING 100
#define MAX_ARRAY 50
#define MAX_LINE 1000
#define MATRICULA "890191"

// Variáveis globais para contagem
long long numComparacoes = 0;
long long numMovimentacoes = 0;

//---------------------------------------------------------------
// Struct
//---------------------------------------------------------------
typedef struct Game
{
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

    struct Game* prox;
} Game;

typedef struct {
    Game* topo;
    int tamanho;
} Pilha;

void inicializar(Pilha* p) {
    p->topo = NULL;
    p->tamanho = 0;
}

int vazia(Pilha* p) {
    return (p->topo == NULL);
}

void push(Pilha* p, Game* jogo) {
    jogo->prox = p->topo;
    p->topo = jogo;
    p->tamanho++;
}

Game* pop(Pilha* p) {
    if (vazia(p)) return NULL;

    Game* temp = p->topo;
    p->topo = temp->prox;
    p->tamanho--;
    temp->prox = NULL; // evita dangling pointer
    return temp;
}

//---------------------------------------------------------------
// Funções Auxiliares
//---------------------------------------------------------------
char *extrairCampoEntreAspas(char **linha)
{
    char *inicio = strchr(*linha, '\"'); // Procura aspas, anda de caracter de caracter
    if (!inicio)
        return NULL; // Retorna null se não tiver
    inicio++;
    char *fim = strchr(inicio, '\"'); // procura aspas depois de ter achado a primeira
    if (!fim)
        return NULL; // Retorna null se não tiver

    int tamanho = fim - inicio;
    char *campo = (char *)malloc(tamanho + 1); // Aloca tamanho para o tamanho da string
    strncpy(campo, inicio, tamanho);           // Copia os caracteres a partir do ponteiro inicio e coloca dentro de campo
    campo[tamanho] = '\0';
    *linha = fim + 1; // vai pra proxima palavra da linha

    return campo;
}

void cleanString(char *str)
{
    int len = strlen(str); // tamanho
    int start = 0, end = len - 1;

    while (start <= end && (str[start] == '\'' || str[start] == ' '))
        start++; // Pula caracteres não desejados
    while (end >= start && (str[end] == '\'' || str[end] == ' '))
        end--; // Pula caracteres não desejados de tras pra frente

    int j = 0;
    for (int i = start; i <= end; i++)
        str[j++] = str[i]; // Muda a string
    str[j] = '\0';
}

void transformArray(char *token, char arr[MAX_ARRAY][MAX_STRING], int *qtd)
{
    // Para array de strings
    int j = 0;
    char *aux = strtok(token, "[]\","); // Dividir string em partes menores, qualquer caracter dentro de aspas
    while (aux != NULL)
    {
        cleanString(aux); // Limpa a string
        if (strlen(aux) > 0)
            strcpy(arr[j++], aux);    // Se o array não estiver vazio, copia o aux para array original
        aux = strtok(NULL, "[]\","); // Chama strtok novamente para pegar o próximo token
    }
    *qtd = j; // Numeros de strings
}

void lerArray(char **ptr, char arr[MAX_ARRAY][MAX_STRING], int *qtd)
{
    *qtd = 0;
    while (**ptr == ' ')
        (*ptr)++; // Ignora espaços

    if (**ptr == '\"')
    { // Se começar com aspas, chama o remover aspas e depois separa as strings
        char *campoAspa = extrairCampoEntreAspas(ptr);
        transformArray(campoAspa, arr, qtd);
        free(campoAspa);
    }
    else if (**ptr == '[')
    { // Se começar com [
        int k = 0;
        char campoArr[MAX_LINE];   // Buffer
        campoArr[k++] = *(*ptr)++; // Copia [ para o buffer e avança um caracter
        while (**ptr != '\0' && **ptr != ']')
            campoArr[k++] = *(*ptr)++; // Copia todos os caracteres dentro dos colchetes, até encontrar ] ou o fim da string
        if (**ptr == ']')
            campoArr[k++] = *(*ptr)++; // Copia ] para o buffer
        campoArr[k] = '\0';
        transformArray(campoArr, arr, qtd); // Separa strings
    }
    else if (**ptr != ',' && **ptr != '\0')
    { // Se não tiver virgula considera uma string so
        int k = 0;
        char campoSimples[MAX_LINE];
        while (**ptr != ',' && **ptr != '\0')
            campoSimples[k++] = *(*ptr)++;
        campoSimples[k] = '\0';
        cleanString(campoSimples);
        if (strlen(campoSimples) > 0)
        {
            strcpy(arr[0], campoSimples);
            *qtd = 1;
        }
    }
    if (**ptr == ',')
        (*ptr)++; // Pula a virgula do final
}

void transformDate(char *token, int cont, Game *jogo)
{
    char dia[3] = "01", mes[3] = "01", ano[5];
    char *virgula = strchr(token, ','); // Procura virgula

    // DIA
    if (virgula != NULL && (virgula - token) >= 2)
    {
        if (*(virgula - 2) >= '0' && *(virgula - 2) <= '9')
            dia[0] = *(virgula - 2); // Copia o primeiro digito do dia
        if (*(virgula - 1) >= '0' && *(virgula - 1) <= '9')
            dia[1] = *(virgula - 1); // Copia o segundo digito do dia
    }

    // MES
    if (strstr(token, "Jan"))
        strcpy(mes, "01");
    else if (strstr(token, "Feb"))
        strcpy(mes, "02");
    else if (strstr(token, "Mar"))
        strcpy(mes, "03");
    else if (strstr(token, "Apr"))
        strcpy(mes, "04");
    else if (strstr(token, "May"))
        strcpy(mes, "05");
    else if (strstr(token, "Jun"))
        strcpy(mes, "06");
    else if (strstr(token, "Jul"))
        strcpy(mes, "07");
    else if (strstr(token, "Aug"))
        strcpy(mes, "08");
    else if (strstr(token, "Sep"))
        strcpy(mes, "09");
    else if (strstr(token, "Oct"))
        strcpy(mes, "10");
    else if (strstr(token, "Nov"))
        strcpy(mes, "11");
    else if (strstr(token, "Dec"))
        strcpy(mes, "12");

    // ANO
    int len = strlen(token); // Tamanho do token
    if (len >= 4)
        strcpy(ano, token + len - 4); // Copia os quatro ultimos numeros
    else
        strcpy(ano, "0000");

    sprintf(jogo[cont].releaseDate, "%s/%s/%s", dia, mes, ano);
}

void cleanNumber(char *token, char *newStr)
{
    int j = 0;
    for (int i = 0; token[i] != '\0'; i++)
    {
        if ((token[i] >= '0' && token[i] <= '9') || token[i] == '.' || token[i] == ',') // Verifca se é numero
            newStr[j++] = (token[i] == ',') ? '.' : token[i];                           // muda virgula pra ponto
    }
    newStr[j] = '\0';
}

void freeToPlay(char *token, int cont, Game *jogo)
{
    if (token[0] == 'F')
        jogo[cont].price = 0.0;
    else
    {
        char newStr[20];
        cleanNumber(token, newStr);

        // Comparação correta para "0.0"
        if (strcmp(newStr, "0.0") == 0)
            jogo[cont].price = 0.0;
        else
            jogo[cont].price = (strlen(newStr) > 0) ? atof(newStr) : 0.0;
    }
}

//---------------------------------------------------------------
// Preencher
//---------------------------------------------------------------
void preencheVetor(Game jogo[], char line[])
{
    // Supondo CSV simples: id,name,releaseDate,price
    char* ptr = line;
    char campo[MAX_LINE];

    // ID
    sscanf(ptr, "%d,", &jogo->id);
    ptr = strchr(ptr, ',') + 1;

    // Name
    int i = 0;
    while (*ptr != ',' && *ptr != '\0') campo[i++] = *ptr++;
    campo[i] = '\0';
    strcpy(jogo->name, campo);
    if (*ptr == ',') ptr++;

    // ReleaseDate
    i = 0;
    while (*ptr != ',' && *ptr != '\0') campo[i++] = *ptr++;
    campo[i] = '\0';
    strcpy(jogo->releaseDate, campo);
    if (*ptr == ',') ptr++;

    // Price
    jogo->price = atof(ptr);
    jogo->prox = NULL;
}


//---------------------------------------------------------------
// Mostrar
//---------------------------------------------------------------
void printar(Game *topo)
{
    Game *current = topo;
    while(current != NULL){
        if (jogo[resp].price == 0 || ((int)(jogo[resp].price * 10)) % 10 == 0)
        {
            printf("=> %d ## %s ## %s ## %d ## %.1f ## [",
                jogo[resp].id, jogo[resp].name, jogo[resp].releaseDate,
                jogo[resp].estimatedOwners, jogo[resp].price);
        }
        else
        {
            printf("=> %d ## %s ## %s ## %d ## %.2f ## [",
                jogo[resp].id, jogo[resp].name, jogo[resp].releaseDate,
                jogo[resp].estimatedOwners, jogo[resp].price);
        }

        for (int i = 0; i < jogo[resp].qtdLanguages; i++)
            printf("%s%s", jogo[resp].supportedLanguages[i],
                (i < jogo[resp].qtdLanguages - 1) ? ", " : "");
        printf("] ## %d ## %.1f ## %d ## [",
            jogo[resp].metacriticScore, jogo[resp].userScore, jogo[resp].achievements);

        for (int i = 0; i < jogo[resp].qtdPublishers; i++)
            printf("%s%s", jogo[resp].publishers[i],
                (i < jogo[resp].qtdPublishers - 1) ? ", " : "");
        printf("] ## [");

        for (int i = 0; i < jogo[resp].qtdDevelopers; i++)
            printf("%s%s", jogo[resp].developers[i],
                (i < jogo[resp].qtdDevelopers - 1) ? ", " : "");
        printf("] ## [");

        for (int i = 0; i < jogo[resp].qtdCategories; i++)
            printf("%s%s", jogo[resp].categories[i],
                (i < jogo[resp].qtdCategories - 1) ? ", " : "");
        printf("] ## [");

        for (int i = 0; i < jogo[resp].qtdGenres; i++)
            printf("%s%s", jogo[resp].genres[i],
                (i < jogo[resp].qtdGenres - 1) ? ", " : "");
        printf("] ## [");

        for (int i = 0; i < jogo[resp].qtdTags; i++)
            printf("%s%s", jogo[resp].tags[i],
                (i < jogo[resp].qtdTags - 1) ? ", " : "");
        printf("] ##\n");
        current = current->prox;
    }
    
}


//---------------------------------------------------------------
// Main
//---------------------------------------------------------------
int main() {
    Pilha p;
    inicializar(&p);

    FILE* arq = fopen("/tmp/games.csv", "r");
    if (!arq) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    char line[MAX_LINE];
    fgets(line, sizeof(line), arq); // ignora cabeçalho

    // Lê CSV direto para a pilha
    while (fgets(line, sizeof(line), arq) != NULL) {
        Game* novoJogo = (Game*)malloc(sizeof(Game));
        if (!novoJogo) {
            printf("Erro de memória!\n");
            exit(1);
        }
        preencheVetor(novoJogo, line);
        push(&p, novoJogo);
    }

    fclose(arq);

    // Exemplo: pop de 2 jogos
    for (int i = 0; i < 2; i++) {
        Game* r = pop(&p);
        if (r != NULL) {
            printf("(R) %s\n", r->name);
            free(r);
        }
    }

    // Imprime pilha restante
    printf("Pilha final:\n");
    imprimirPilha(p.topo);

    // Libera memória restante
    while (!vazia(&p)) {
        Game* r = pop(&p);
        free(r);
    }

    return 0;
}
