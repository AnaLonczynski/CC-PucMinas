import java.util.Scanner;
public class Main {

  public static void ContMaiu(String palavra){
    int cont = 0;
      for (int i = 0; i < palavra.length(); i++)
      {
        if(palavra.charAt(i)>= 'A' && palavra.charAt(i)<= 'Z')
        {
          cont++;
        }
    } 
    System.out.println(cont);
  }
  
  public static void main(String[] args) {

    Scanner scanner = new Scanner (System.in);
    String palavra;
  
    do {
        palavra = scanner.nextLine();
        if (!palavra.equals("FIM")) {
          ContMaiu(palavra);
        }
    } while (!palavra.equals("FIM"));

    scanner.close();
  }
}