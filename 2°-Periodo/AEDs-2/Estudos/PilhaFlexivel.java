import java.util.*;

class Celula {
    int elemento;
    Celula prox;

    public Celula() {
        this(0);
    }

    public Celula(int x) {
        this.elemento = x;
        this.prox = null;
    }
}

class PilhaFlexivel {
    private Celula topo;

    public PilhaFlexivel() {
        topo = null;
    }

    public void inserir(int x) {
        Celula tmp = new Celula(x);
        tmp.prox = topo;
        topo = tmp;
    }

    public int remover() throws Exception {
        if (topo == null) {
            throw new Exception("Erro: pilha vazia!");
        }
        int elemento = topo.elemento;
        topo = topo.prox;
        return elemento;
    }

    public void mostrar() {
        System.out.print("Pilha: ");
        for (Celula i = topo; i != null; i = i.prox) {
            System.out.print(i.elemento + " ");
        }
        System.out.println();
    }

    public int somar() {
        int soma = 0;
        for (Celula i = topo; i != null; i = i.prox) {
            soma += i.elemento;
        }
        return soma;
    }

    public int somarRec() {
        return somarRec(topo);
    }

    private int somarRec(Celula i) {
        if (i == null)
            return 0;
        return i.elemento + somarRec(i.prox);
    }

    public int maiorElemento() {
        int maior = 0;
        for (Celula i = topo; i != null; i = i.prox) {
            if (maior < i.elemento) {
                maior = i.elemento;
            }
        }
        return maior;
    }

    public int maiorElementoRec() {
        return maiorElementoRec(topo);
    }

    private int maiorElementoRec(Celula i) {
        if (i == null)
            return 0;
        int maior = maiorElementoRec(i.prox);
        return (i.elemento > maior) ? i.elemento : maior;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PilhaFlexivel pilha = new PilhaFlexivel();
        int n = 0;

        while (n != 7) {
            System.out.println("\n1- Inserir");
            System.out.println("2- Remover");
            System.out.println("3- Mostrar");
            System.out.println("4- Somar");
            System.out.println("5- Somar Recursivo");
            System.out.println("6- Maior Elemento");
            System.out.println("7- Sair");
            n = sc.nextInt();

            try {
                switch (n) {
                    case 1:
                        System.out.print("Qual número deseja inserir? ");
                        pilha.inserir(sc.nextInt());
                        break;
                    case 2:
                        System.out.println("Você removeu o: " + pilha.remover());
                        break;
                    case 3:
                        pilha.mostrar();
                        break;
                    case 4:
                        System.out.println("Soma dos elementos: " + pilha.somar());
                        break;
                    case 5:
                        System.out.println("Soma dos elementos (rec): " + pilha.somarRec());
                        break;
                    case 6:
                        System.out.println("Maior elemento (rec): " + pilha.maiorElementoRec());
                        break;
                    case 7:
                        System.out.println("Programa encerrado!");
                        break;
                    default:
                        System.out.println("Opção inválida!");
                }
            } catch (Exception e) {
                System.out.println(e.getMessage());
            }
        }

        System.out.println("Programa encerrado!");
        sc.close();
    }
}