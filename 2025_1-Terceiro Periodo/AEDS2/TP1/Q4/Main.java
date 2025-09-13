import java.util.*;

public class Main {

    public static String Q4(String p) {
        Random gerador = new Random();
        gerador.setSeed(4);

        char substituir = (char) ('a' + (Math.abs(gerador.nextInt()) % 26));
        char novaLetra = (char) ('a' + (Math.abs(gerador.nextInt()) % 26));

        StringBuilder novaPalavra = new StringBuilder(p);

        for (int i = 0; i < p.length(); i++) {
            if (p.charAt(i) == substituir) {
                novaPalavra.setCharAt(i, novaLetra);
            }
        }

        return novaPalavra.toString();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String palavra;

        do {
            palavra = sc.nextLine();  // Correção na leitura da entrada

            if (!palavra.equals("FIM")) {
                String palavraModificada = Q4(palavra);  // Chamada correta da função
                System.out.println(palavraModificada);
            }

        } while (!palavra.equals("FIM"));

        sc.close();
    }
}
