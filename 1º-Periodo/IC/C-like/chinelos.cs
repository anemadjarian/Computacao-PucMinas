using System;
class ProgramaChinelos
{
 static void Main()
 {
 int N = int.Parse(Console.ReadLine());
 int[] estoque = new int[N + 1];
 for (int i = 1; i <= N; i++)
 {
 estoque[i] = int.Parse(Console.ReadLine());
 }
 int P = int.Parse(Console.ReadLine());
 int vendidos = 0;
 for (int i = 0; i < P; i++)
 {
 int pedido = int.Parse(Console.ReadLine());
 if (pedido >= 1 && pedido <= N && estoque[pedido] > 0)
 {
 estoque[pedido]--;
 vendidos++;
 } //se o tamanho do pedido for maior que zero (existir estoque) reduz o
numero do estoque e adiciona 1 ao contador
 }
 Console.WriteLine(vendidos);
 }
}