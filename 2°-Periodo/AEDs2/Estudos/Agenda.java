import java.util.*;

//NÃO FINALIZADO

class Contato{
    public String nome, email, telefone;
    public int cpf;

    public Contato(){
        this("", "", "", 0);
    }

    public Contato(String nome, String email, String telefone, int cpf){
        this.nome=nome;
        this.email=email;
        this.telefone=telefone;
        this.cpf=cpf;
    }
}

class Celula{
    public Contato contato;
    public Celula prox;

    public Celula(){
        this.contato=null;
        this.prox=null;
    }

    public Celula(Contato contato){
        this.contato=contato;
        this.prox=null;
     }

    public Celula(Contato contato, Celula dir, Celula esq){
        this.contato=contato;
        this.prox=null;
    }
}

class No{
    public char letra;
    public No esq, dir;

    public No(char letra){
        this.letra=letra;
        this.esq=this.dir=null;
    }
}

class Agenda{
    No raiz;
    Celula primeiro, ultimo;

    public Agenda(){
        this.primeiro=null;
        this.ultimo=null;
        inserirLetra();
    }

    public void inserirLetra(){
        char[] letras = {'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Y', 'Z'};
        raiz = new No('A');
        for(int i = 0; i < letras.length; i++){
            raiz = inserirLetraRec(raiz, letras[i]);
        }
    }

    private No inserirLetraRec(No no, char letra){
        if(no == null){
            no = new No(letra);
        } else if(letra < no.letra){
            no.esq = inserirLetraRec(no.esq, letra);
        } else if(letra > no.letra){
            no.dir = inserirLetraRec(no.dir, letra);
        }
        return no;
    }
    
    void inserirContato(Contato contato){
        primeiro = inserirContatoRec(primeiro, contato);
    }

    void inserirContatoRec(Celula primeiro, Contato contato){
        if(primeiro==null){
            
        }
    }
}