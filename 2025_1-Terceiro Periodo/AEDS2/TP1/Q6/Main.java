import java.util.Scanner;

public class Main {

    public static void init (String p){
        boolean a = vogal(p);
        boolean b = consoante(p);
        boolean c = ehint(p);
        boolean d = ehDouble(p);

        System.out.println(
            (a ? "SIM" : "NAO") + " " +
            (b ? "SIM" : "NAO") + " " +
            (c ? "SIM" : "NAO") + " " +
            (d ? "SIM" : "NAO")
        );
    }

    /*public static boolean vogal(String p){
        for (int i = 0; i < p.length(); i++) {
            if (!(p.charAt(i) == 'a' ||p.charAt(i) == 'e' ||p.charAt(i) == 'i' ||p.charAt(i) == 'o' ||p.charAt(i) == 'u' 
             || p.charAt(i) == 'A' ||p.charAt(i) == 'E' ||p.charAt(i) == 'I' ||p.charAt(i) == 'O' ||p.charAt(i) == 'U' )){
                return false;
            }
        }
        return result;
    }
        
    public static boolean consoante(String p){
        boolean result = false;
        for (int i = 0; i < p.length(); i++) {
            if (!(p.charAt(i) == 'a' ||p.charAt(i) == 'e' ||p.charAt(i) == 'i' ||p.charAt(i) == 'o' ||p.charAt(i) == 'u' 
               || p.charAt(i) == 'A' ||p.charAt(i) == 'E' ||p.charAt(i) == 'I' ||p.charAt(i) == 'O' ||p.charAt(i) == 'U')){
                result = true;
            } else {result = false;}
        }
        return result;
    }*/

    public static boolean vogal(String p) {
        for (int i = 0; i < p.length(); i++) {
            char c = Character.toLowerCase(p.charAt(i));
            if (!(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')) {
                return false; 
            }
        }
        return p.length() > 0; 
    }
    public static boolean consoante(String p) {
        for (int i = 0; i < p.length(); i++) {
            char c = Character.toLowerCase(p.charAt(i));
            if (!Character.isLetter(c) || "aeiou".indexOf(c) != -1) {
                return false; 
            }
        }
        return p.length() > 0; 
    }
    


    public static boolean ehint(String p){
        return p != null && p.matches("-?\\d+");
    }

    public static boolean ehDouble(String p){
        return p != null && (p.matches("-?\\d+(\\.\\d+)?") || p.matches("-?\\d+(\\,\\d+)?") || p.matches("-?\\d+\\,") || p.matches("-?\\d+\\.") || p.matches("-?(\\.\\d+)?") || p.matches("-?(\\,\\d+)?")) ;
    }

    public static void main (String args[]){

        Scanner sc = new Scanner(System.in);
        String entrada;

        do { 
            entrada = sc.nextLine(); 
            if (!(entrada.equals("FIM"))){init(entrada);} 

        } while (!(entrada.equals("FIM")));

        sc.close();
    }
    
}
