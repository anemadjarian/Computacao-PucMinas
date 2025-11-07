#include <stdio.h>
#include <stdlib.h>
int main() {
 int n;
 scanf("%d", &n); //numero de tamanhos
 int *estoque = (int *)malloc(n * sizeof(int));
 if (estoque == NULL) {
 printf("Erro ao alocar memória\n");
 return 1;
 } //aloca dinamicamente a quantidade de cada tamanho
 for (int i = 0; i < n; i++) {
 scanf("%d", &estoque[i]);
 }
 int p;
 scanf("%d", &p);
 int cont=0, pedido;
 for (int i = 0; i < p; i++) {
 scanf("%d", &pedido);
 if (estoque[pedido - 1] > 0) {
 estoque[pedido - 1]--;
 cont++;
 } //se o tamanho do pedido for maior que zero (existir estoque) reduz o numero
do estoque e adiciona 1 ao contador
 }
 printf("%d", cont);
 free(estoque);
 return 0;
}