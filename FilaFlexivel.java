import java.util.*;
class Celula{
    int elemento;
    Celula prox;

    public Celula() {
        this(0);
    }
    public Celula(int x){
        this.elemento=x;
        this.prox=null;
    }

}
class FilaFlexivel {
    private Celula primeiro, ultimo;

    public FilaFlexivel(){
        this.primeiro=new Celula();
        this.ultimo=primeiro;
    }

    //Deixa a célula primeiro sempre vazia
    public void inserir(int x){
        ultimo.prox=new Celula(x);
        ultimo=ultimo.prox;
    }

    /*
     * tmp aponta para primeiro
     * primeiro aponta para prox
     * elemento = primeiro (segunda celula)
     * tmp prox e tmp = null (priemira celula não aponta pra ninguem e tmp também não)
     */
    public int remover() throws Exception{
        if(primeiro==ultimo){
            throw new Exception("Erro");
        }
        Celula tmp = primeiro;
        primeiro = primeiro.prox;
        int elemento = primeiro.elemento;
        tmp.prox=null;
        tmp = null;
        return elemento;
    }

    public void mostrar(){
        for(Celula i=primeiro.prox; i!=null; i=i.prox){
            System.out.print(i.elemento + " ");
        }
        System.out.println();
    }

    public int somar(){
        int soma=0;
        for(Celula i=primeiro; i!=null; i=i.prox){
            soma+=i.elemento;
        }
        return soma;
    }

    public int somarRec(){
        return somarRec(primeiro.prox);
    }
    public int somarRec(Celula i){
        if(i==null)
            return 0;
        return i.elemento+somarRec(i.prox);
    }

    public int maiorElementoRec(){
        return 0;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        FilaFlexivel fila = new FilaFlexivel();
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
                        fila.inserir(sc.nextInt());
                        break;
                    case 2:
                        System.out.println("Você removeu o: " + fila.remover());
                        break;
                    case 3:
                        fila.mostrar();
                        break;
                    case 4:
                        System.out.println("Soma dos elementos: " + fila.somar());
                        break;
                    case 5:
                        System.out.println("Soma dos elementos (rec): " + fila.somarRec());
                        break;
                    case 6:
                        System.out.println("Maior elemento (rec): " + fila.maiorElementoRec());
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
