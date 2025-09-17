public class ciframentodecesar {
    public static String codigoString(String str){
    String str2 = "";
    for(int i=0; i<str.length(); i++){
        str2 += (char) (str.charAt(i)+3); //Pula para a terceira proxima letra da tabela ASCII e força a ser char
    }
    return str2;
}
    public static void main(String[] args){
        String str = MyIO.readLine();
        while(!(str.length()==3 && str.charAt(0)=='F' && str.charAt(1)=='I' && str.charAt(2)=='M')){
            String str2 = codigoString(str); //While repete até scanear a palavra FIM
            MyIO.println(str2);
            str = MyIO.readLine(); //Scaneia a proxima palavra até o loop acabar
        }
    }
}