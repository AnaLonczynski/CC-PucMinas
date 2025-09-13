import java.util.Scanner;

class Main extends MyIO {
  /*Pal´ındromo - Crie um m´etodo iterativo que recebe uma string como parˆametro e retorna true
  se essa ´e um pal´ındromo. Na sa´ıda padr˜ao, para cada linha de entrada, escreva uma linha de
  sa´ıda com SIM / NAO indicando se a linha ´e um pal´ındromo. Destaca-se que uma linha de ˜
  entrada pode ter caracteres n˜ao letras.
  */

    // Método recursivo para verificar se uma string é um palíndromo
    protected static boolean isPalindrome(String str, int left, int right) {
        // Ignorar caracteres não letras ou fora do intervalo ASCII (menor que 127 e diferente de 32)
        while (left < right && !(str.charAt(left) < 127 && str.charAt(left) != 32)) {
            left++;
        }
        while (left < right && !(str.charAt(right) < 127 && str.charAt(right) != 32)) {
            right--;
        }

        // Condição base: se os ponteiros se cruzarem ou se encontrarem, é um palíndromo
        if (left >= right) {
            return true;
        }

        // Verificar se os caracteres nas posições atuais são iguais
        if (Character.toLowerCase(str.charAt(left)) != Character.toLowerCase(str.charAt(right))) {
            return false;
        }

        // Chamada recursiva para os próximos caracteres
        return isPalindrome(str, left + 1, right - 1);
    }

    // Método principal
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String palavra;

        do {
            palavra = scanner.nextLine();
            if (!palavra.equals("FIM")) {
                boolean resp = isPalindrome(palavra, 0, palavra.length() - 1);
                if (resp) {
                    System.out.println("SIM");
                } else {
                    System.out.println("NAO");
                }
            }
        } while (!palavra.equals("FIM"));

        scanner.close();
    }
}