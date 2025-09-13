import java.util.Scanner;

public class Main{

    public static boolean isAnagrama(String str1, String str2){
        // Se as strings tiverem tamanhos diferentes, não podem ser anagramas
        if (str1.length() != str2.length()) {
            return false;
        }

        // Criar dois arrays para contar as ocorrências de cada caractere (de 'a' a 'z')
        int[] contagem1 = new int[26];
        int[] contagem2 = new int[26];

        // Contar a frequência de caracteres nas duas strings
        for (int i = 0; i < str1.length(); i++) {
            contagem1[str1.charAt(i) - 'a']++;  // Para a string 1
            contagem2[str2.charAt(i) - 'a']++;  // Para a string 2
        }

        // Comparar as frequências
        for (int i = 0; i < 26; i++) {
            if (contagem1[i] != contagem2[i]) {
                return false;  // Se qualquer caractere tem contagens diferentes, não são anagramas
            }
        }

        return true;  // As strings são anagramas
    }

    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        String entrada;
        String parte1 = "";
        String parte2 = "";
        boolean encontrouEspaco  = false;

        do { 
            entrada = sc.nextLine();  

            for (int i = 0; i < entrada.length(); i++) {
                char c = entrada.charAt(i);
    
                if (c != ' ' && !encontrouEspaco && c != '-') {
                    parte1 += c;
                } 
                else if (c == ' ' && !encontrouEspaco) {
                    encontrouEspaco = true;
                } 
                else if (encontrouEspaco && c != ' '&& c != '-') {
                    parte2 += c;
                }
            }

            if (!(entrada.equals("FIM"))){
                if (isAnagrama(parte1, parte2)) {
                    System.out.println("SIM");
                } else {
                    System.out.println("NAO");
                }
            } 

        } while (!(entrada.equals("FIM")));
        sc.close();
    }
}