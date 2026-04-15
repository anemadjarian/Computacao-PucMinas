import java.util.*;
import java.io.*;

class Programa{

    public static String Transforma(int x, int y, char opCode){ // função que transforma para Hexa, para a impressão no arquivo de saida
        char xx;
        if(x==10){ xx='A'; } // conferimos a partir do 10 pois é onde os números se diferem na base decimal e hexadecimal
        else if(x==11){ xx='B'; }
        else if(x==12){ xx='C'; }
        else if(x==13){ xx='D'; }
        else if(x==14){ xx='E'; }
        else if(x==15){ xx='F'; }
        else{
            xx = (char)('0' + x);
        }

        char yy;
        if(y==10){ yy='A'; }
        else if(y==11){ yy='B'; }
        else if(y==12){ yy='C'; }
        else if(y==13){ yy='D'; }
        else if(y==14){ yy='E'; }
        else if(y==15){ yy='F'; }
        else{
            yy = (char)('0' + y);
        }

        String resultado = "" + xx + yy + opCode; // cria a string no formato necessário para o arquivo de saída
        return resultado;
    }

    public static String Conferir(String w, int x, int y){ // Função que confere os diferentes OPCODES
        char opCode = '0';
        //comparação e distinção entre os diferentes OPCODES
        if(w.equals("W=CopiaA;")){
            opCode='0';
        } else if(w.equals("W=CopiaB;")){
            opCode='1';
        } else if(w.equals("W=AxB;")){
            opCode='2';
        } else if(w.equals("W=nAxnB;")){
            opCode='3';
        } else if(w.equals("W=AeBn;")){
            opCode='4';
        } else if(w.equals("W=nB;")){
            opCode='5';
        } else if(w.equals("W=nAonB;")){
            opCode='6';
        } else if(w.equals("W=nA;")){
            opCode='7';
        } else if(w.equals("AonB;")){
            opCode='8';
        } else if(w.equals("W=UmL;")){
            opCode='9';
        } else if(w.equals("W=ZeroL;")){
            opCode='A';
        } else if(w.equals("W=AeB;")){
            opCode='B';
        } else if(w.equals("W=nAeB;")){
            opCode='C';
        } else if(w.equals("W=AenB;")){
            opCode='D';
        } else if(w.equals("W=AoB;")){
            opCode='E';
        } else if(w.equals("W=nAenB;")){
            opCode='F';
        } else{
            System.out.println("Operação inválida.");
        }

        return Transforma(x, y, opCode); // chamamos a função de transformação para hexa
    }

    public static void main (String[] args){
        try{
            File arquivo = new File("testeula.ula"); // cria abre o arquivo
            Scanner sc = new Scanner(arquivo); // declara o scanner para o arquivo

            PrintWriter writer = new PrintWriter("testeula.hex"); // cria o arquivo de saída

            String linha = sc.nextLine();

            if(linha.equals("inicio:")){

                int x = 0; // declarando as variaveis 
                int y = 0;
                String w;

                while(!(linha.equals("fim."))){ // codigo roda até a entrada do arquivo ser "fim."

                    linha = sc.nextLine(); // escaneia as entradas
                 
                    if (linha == null || linha.trim().isEmpty()) {
                        System.out.println("Programa Inválido"); // pula linha vazia
                        return;
                    }
                    char c = linha.charAt(0); // declaração de uma variavel do tipo char para comparar o inicio das strings escaneadas
                    if(!linha.equals("fim.") && linha.charAt(linha.length()-1)!=';') { // trata a falta de ;
                        System.out.println("Operação Inválida: falta ';'");
                        sc.close();
                        linha="fim.";
                        break;
                    }

                    if(c == 'X'){
                        x = Integer.parseInt(linha.substring(2, linha.length()-1)); // transforma o x e o y pra inteiros para melhor manipulação
                    }
                    else if(c == 'Y'){
                        y = Integer.parseInt(linha.substring(2, linha.length()-1));
                    }
                    else if(c == 'W'){
                        w = linha; // deixa o W como string pois é a operação
                        String imprimir = Conferir(w, x, y); // chama a função que confere os comandos
                        writer.println(imprimir); // imprime no arquivo
                    }
                }
            }
         
            writer.println("GGG"); // printando caracteres que não são OPCODE para parar o código
            sc.close();
            writer.close();

        }catch(FileNotFoundException e){ //trata o erro caso o arquivo de entrada não exista
            System.out.println("Arquivo não encontrado.");
        }
    }
}