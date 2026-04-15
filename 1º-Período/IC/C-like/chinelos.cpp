#include <iostream>
#include <vector>
using namespace std;
int main() {
 int n;
 cin >> n;
 vector<int> estoque(n);
 for (int i = 0; i < n; i++) {
 cin >> estoque[i];
 }
 int p;
 cin >> p;
 int cont= 0, pedido;
 for (int i = 0; i < p; i++) {
 cin >> pedido;
 if ((pedido-1) >= 0 && indice < n && estoque[pedido-1] > 0) {
 estoque[pedido-1]--;
 cont++;
 } //se o tamanho do pedido for maior que zero (existir estoque) reduz o numero
do estoque e adiciona 1 ao contador
 }
 cout << cont;
 return 0;
}