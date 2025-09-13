import java.util.Scanner;

class Main extends MyIO {

    // Método recursivo que verifica se a string é um palíndromo
    public static boolean isPalindrome(String palavra, int inicio, int fim) {
        // Caso base: se o início for maior ou igual ao fim, a palavra é um palíndromo
        if (inicio >= fim) {
            return true;
        }
        // Comparar os caracteres nas extremidades
        if (palavra.charAt(inicio) != palavra.charAt(fim)) {
            return false;
        }
        // Chamada recursiva com os índices avançando em direção ao meio da palavra
        return isPalindrome(palavra, inicio + 1, fim - 1);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String entrada;
        boolean resp;

        do {
            entrada = readLine();
            resp = isPalindrome(entrada, 0, entrada.length() - 1);  // Chama a função recursiva
            if (resp) {
                System.out.println("SIM");
            } else {
                System.out.println("NAO");
            }
        } while (!entrada.equals("FIM"));

        scanner.close();
    }
}
