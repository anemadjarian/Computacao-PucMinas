import java.util.Scanner;
public class Main {
 public static void main(String[] args) {
 Scanner scanner = new Scanner(System.in);
 int N = scanner.nextInt();
 int[] estoque = new int[N + 1];
 for (int i = 1; i <= N; i++) {
 estoque[i] = scanner.nextInt();
 }
 int P = scanner.nextInt();
 int vendidos = 0;

 for (int i = 0; i < P; i++) {
 int pedido = scanner.nextInt();
 if (pedido >= 1 && pedido <= N && estoque[pedido] > 0) {
 estoque[pedido]--;
 vendidos++;
 } //se o tamanho do pedido for maior que zero (existir estoque) reduz o
numero do estoque e adiciona 1 ao contador
 }
 System.out.println(vendidos);
 scanner.close();
 }
}