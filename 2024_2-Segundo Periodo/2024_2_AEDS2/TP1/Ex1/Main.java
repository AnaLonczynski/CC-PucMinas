import java.io.*;
import java.net.*;
import java.util.Scanner;

/*Pal´ındromo - Crie um m´etodo iterativo que recebe uma string como parˆametro e retorna true
se essa ´e um pal´ındromo. Na sa´ıda padr˜ao, para cada linha de entrada, escreva uma linha de
sa´ıda com SIM / NAO indicando se a linha ´e um pal´ındromo. Destaca-se que uma linha de ˜
entrada pode ter caracteres n˜ao letras.
*/
class Main extends MyIO {

  protected static boolean isPalindrome(String str){
    //cria bool iniciado em falso
    boolean itis = false;
    //percorre a string
    for (int i = 0; i < str.length(); i++){
      //compara se a primeira posicao e' igual a ultima e se for retorna verdadeiro
      if (str.charAt(i) == str.charAt(str.length() - 1 - i)){
        itis = true;
      }else{
        itis = false;
      }
    }
    return (itis);
  }

  public static void main (String[] args){
    Scanner scanner = new Scanner (System.in);
    String palavra;
    boolean resp;

    do {
        palavra = readLine();
        if (!palavra.equals("FIM")) {
          resp = isPalindrome(palavra);
          if (resp){
            System.out.println("SIM");
          }else {
            System.out.println("NAO");
          }
        }
    } while (!palavra.equals("FIM"));

    scanner.close();
    
  }
}