import java.util.Scanner;

public class Main {

    public static int soma (String str){
        int r, soma = 0;
        for (int i = 0; i < str.length(); i++) {
            r = str.charAt(i) - '0';
            soma += r;
        }
        
        return soma;
    }

    public static void main(String[] args) {
            
        Scanner sc = new Scanner(System.in);
        String str;

        do{
            str = sc.nextLine();
            if(!(str.equals("FIM"))){
                int r = soma(str);
                System.out.println(r);
            }

        }while(!(str.equals("FIM")));
        sc.close();
    
    }
}

