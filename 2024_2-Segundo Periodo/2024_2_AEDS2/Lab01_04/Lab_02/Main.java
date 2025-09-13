import java.util.Scanner;
public class Main {

  public static int ContMaiu(String palavra, int pos){
  int resp = 0;
  if (pos < palavra.length()){
    if (palavra.charAt(pos) >= 'A' && palavra.charAt(pos) <= 'Z'){
      resp = ContMaiu (palavra, pos + 1) + 1;
    }else 
      resp = ContMaiu (palavra, pos + 1);
    }    
    return resp;
  }
  
  public static void main(String[] args) {

    Scanner scanner = new Scanner (System.in);
    String palavra;
  
    do {
        palavra = scanner.nextLine();
        if (!palavra.equals("FIM")) {
            int resultado = ContMaiu(palavra, 0);
            System.out.println(resultado);
        }
    } while (!palavra.equals("FIM"));

    scanner.close();
  }
}