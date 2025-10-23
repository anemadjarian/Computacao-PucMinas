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