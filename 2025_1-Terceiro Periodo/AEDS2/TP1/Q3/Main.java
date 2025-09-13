import java.util.Scanner;

public class Main extends MyIO {

    public static void CifraCesar(String palavra){
        String cifra = "";
        for (int i = 0; i < palavra.length(); i++) {
            char cifrado = (char)((int)palavra.charAt(i));
            if (cifrado < 127) {
                cifra +=(char)((int)palavra.charAt(i)+3);; 
            }else {
                cifra += cifrado;
            }
        }
        System.err.println(cifra);
    }

    public static void main(String[] args) {
 
        MyIO.setCharset("UTF-8");
        Scanner sc = new Scanner(System.in);
        String entrada;

        do{
            entrada = readLine();
            if(!entrada.equals("FIM")){CifraCesar(entrada);}
        } while (!entrada.equals("FIM"));

        sc.close();
    }
}
