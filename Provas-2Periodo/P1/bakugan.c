/*
Mark e Leti adoram brincar com suas bolas Bakugan.
Essas bolas são pequenas esferas de plástico com um pequeno brinquedo-monstro dentro.
Quando jogada ao chão, a bola Bakugan se abre, fazendo um som incrível e liberando um monstro Bakugan assustador.
Mark e Leti adoram brincar com seus monstros, mas abrir as bolas Bakugan também é bem divertido.

Cada um deles recebeu uma bolsa com bolas Bakugan e eles inventaram um jogo para abrir as bolas.
Existem 10 monstros diferentes, e para o jogo Mark e Leti associaram cada monstro a um inteiro diferente de 1 a 10,
de acordo com o nível de feiura do monstro. O jogo é composto de R rodadas. A cada rodada:

Os dois jogadores jogam suas bolas ao chão simultaneamente;
Cada jogador acumula um número de pontos coincidente com o número associado ao monstro liberado por sua bola;
O primeiro (e apenas o primeiro) jogador que liberar o mesmo monstro em três rodadas consecutivas ganha 30 pontos adicionais;
se essa condição acontecer na mesma rodada para ambos os jogadores então ninguém ganha pontos extras. 

O vencedor do jogo é o jogador que acumular mais pontos. Por favor ajude Mark e Leti anunciar o vencedor do jogo!

Entrada
Cada caso de testo é descrito por três linhas. 
A primeira linha contém um inteiro R indicando o número de rodadas do jogo (1 ≤ R ≤ 10). 
A segunda linha contém R inteiros Mi indicando os monstros liberados por Mark a cada rodada (1 ≤ Mi ≤ 10, para 1 ≤ i ≤ R). A terceira linha contém R inteiros Li indicando os monstros liberados por Leti a cada rodada (1 ≤ Li ≤ 10, para 1 ≤ i ≤ R).

O último caso de teste é composto por uma linha contendo zero.

Saída
Para cada caso de teste imprima uma linha com um caractere representando o resultado do jogo: 
"M" caso o vencedor seja Mark, "L" caso o vencedor seja Leti, ou "T" caso haja um empate (tie).
*/

#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    while(n!=0){
        int vetMark[n];
        int vetLeti[n];
        for(int i=0; i<n; i++){
            scanf("%d", &vetMark[i]);
        }
        for(int i=0; i<n; i++){
            scanf("%d", &vetLeti[i]);
        }
        int somaMark=0, somaLeti=0, contMark=0, contLeti=0;
        for(int i=0; i<n; i++){
            somaMark+=vetMark[i];
            somaLeti+=vetLeti[i];
            if(contMark!=2 && contLeti!=2){
                if(vetMark[i]==vetMark[i+1]){
                    contMark++;
                }
                if(vetLeti[i]==vetLeti[i+1]){
                    contLeti++;
                }
            }
        }
        if(contMark==2 || contLeti==2){
            if(contMark==2){
                somaMark+=30;
            } else{
                somaLeti+=30;
            }
        }
        int maior;
        if(somaMark>somaLeti){
            maior=somaMark;
        } else{
            maior=somaLeti;
        }
        if(somaMark>somaLeti){
            printf("M\n");
        } else if(somaLeti>somaMark){
            printf("L\n");
        } else{
            printf("T\n");
        }
        scanf("%d", &n);
    }
}