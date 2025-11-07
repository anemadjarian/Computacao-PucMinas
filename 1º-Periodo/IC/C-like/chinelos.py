def main():
 N = int(input())
 # lê o estoque para cada tamanho (de 1 a N)
 estoque = [0] * (N + 1)
 for i in range(1, N + 1):
 estoque[i] = int(input())
 P = int(input())
 vendidos = 0
 for _ in range(P):
 pedido = int(input())
 if 1 <= pedido <= N and estoque[pedido] > 0:
 estoque[pedido] -= 1
 vendidos += 1
# se o tamanho do pedido for maior que zero (existir estoque) reduz o numero do
estoque e adiciona 1 ao contador
 print(vendidos)
if __name__ == "__main__":
 main()