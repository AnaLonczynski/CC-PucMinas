import java.util.Scanner;

/*Palındromo - Crie um m´etodo iterativo que recebe uma string como parˆametro e retorna true
se essa ´e um pal´ındromo. Na sa´ıda padr˜ao, para cada linha de entrada, escreva uma linha de
sa´ıda com SIM / NAO indicando se a linha ´e um pal´ındromo. Destaca-se que uma linha de ˜
entrada pode ter caracteres n˜ao letras.
*/

class Main extends MyIO{

    public static boolean isPalindrome(String palavra){
        boolean resp = true;

        for (int i = 0; i < palavra.length(); i++) {
            if(palavra.charAt(i) > 128){
                changeCh(palavra.charAt(i));
            }
            if(palavra.charAt(i) != palavra.charAt(palavra.length()-i-1)){
                resp = false;
            }
        }
        return resp;
    }

    public static char changeCh(char change){
        change = '*';
        return change;
    }

    public static void main (String[] args){

        Scanner scanner = new Scanner (System.in);
        String entrada;
        boolean resp;

        do { 
            entrada = readLine();
            resp = isPalindrome(entrada);
            if (resp){
                System.out.println("SIM");
            }else{
                System.out.println("NAO");
            }
        } while (!entrada.equals("FIM"));

        scanner.close();
    
    }
}