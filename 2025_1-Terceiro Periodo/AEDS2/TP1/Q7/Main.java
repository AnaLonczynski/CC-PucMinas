import java.util.Scanner;

public class Main {

    public static String reverse(String str) {
        char[] caracteres = str.toCharArray(); // Converte a string para um array de caracteres
        int esquerda = 0, direita = str.length() - 1;

        // Troca os caracteres de posição
        while (esquerda < direita) {
            char temp = caracteres[esquerda];
            caracteres[esquerda] = caracteres[direita];
            caracteres[direita] = temp;
            esquerda++;
            direita--;
        }
        /* String newStr = str;
        int len = str.length();

        for(int i = 0; i < len; i++){
            newStr.charAt(len - i - 1) = str.charAt(i);
        }
            
        System.out.println(newStr);
 */
       return new String(caracteres); // Retorna a string invertida

    }

    public static void main(String args[]){

        Scanner sc = new Scanner(System.in);
        String str;

        do{
            
            str = sc.nextLine();
            if(!(str.equals("FIM"))){
                String result = reverse(str);
                System.out.println(result);
            }

        }while(!(str.equals("FIM")));
        sc.close();
    }

}

