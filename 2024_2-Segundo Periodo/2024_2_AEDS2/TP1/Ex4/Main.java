import java.util.Random;
class Main extends MyIO{
  /*Crie um m´etodo iterativo que recebe uma string, sorteia duas letras
min´usculas aleat´orias (c´odigo ASCII ≥ ’a’ e ≤ ’z’), substitui todas as ocorrˆencias da primeira
letra na string pela segunda e retorna a string com as altera¸c˜oes efetuadas. Na sa´ıda padr˜ao,
para cada linha de entrada, execute o m´etodo desenvolvido nesta quest˜ao e mostre a string
retornada como uma linha de sa´ıda.*/
  
  public static void substitui (String str){
    char escolhida, substitui;
    Random gerador = new Random( ) ;
    gerador.setSeed ( 4 );
    escolhida = ((char)('a'+(Math.abs(gerador.nextInt())%26)));
    substitui = ((char)('a'+(Math.abs(gerador.nextInt())%26)));
    for(int i = 0; i < str.length(); i++){
      if (str.charAt(i) == escolhida){
       str = str.replace(str.charAt(i), substitui);
      }
    } 
    println(str);
  }
  
  public static void main (String[] args){
    String palavra;
    palavra = readLine();
    substitui(palavra);
    while(!palavra.equals("FIM")){
      palavra = readLine();
      if(!palavra.equals("FIM")){
        substitui(palavra);}
      }
  }
}