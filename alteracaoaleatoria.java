import java.util.*;
public class alteracaoaleatoria{
    public static String alteracao(String str, char a, char b){
        String str2 = "";
        for(int i=0; i<str.length(); i++){
            char letra = str.charAt(i);
            if(letra==a){
                str2+=b; //Se a letra for igual a primeira letra randomica, ela modifica para a segunda
            } else{
                str2+=letra; //Se não for, ela continua com a string normal
            }
        }
        return str2;

    }
    public static void main(String[] args){
        String str = MyIO.readLine();
        Random gerador = new Random();
        gerador.setSeed(4);
        while(!(str.length()==3 && str.charAt(0)=='F' && str.charAt(1)=='I' && str.charAt(2)=='M')){
            char a = (char)('a' + (Math.abs(gerador.nextInt()) % 26)); //Gera as duas letras randomicas
            char b = (char)('a' + (Math.abs(gerador.nextInt()) % 26));
            String str2 = alteracao(str, a, b);
            MyIO.println(str2);
            str = MyIO.readLine();
        }
    }
}