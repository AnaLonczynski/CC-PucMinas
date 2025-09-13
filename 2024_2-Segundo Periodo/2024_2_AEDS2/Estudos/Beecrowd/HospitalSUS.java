import java.util.ArrayList;
import java.util.Scanner;

class Usuario{
    private int H, M, C;

    public Usuario() {
        this.H = 0;
        this.M = 0;
        this.C = 0;
    }

    public Usuario(int h, int m, int c){

        if(7 <= h && h <= 19) {this.H = h;}
        if(0 <= m && m <= 60) {this.M = m;}
        if(0 <= c && c <= 720){this.C = c;}

    }

    public int tempoDeChegada(){
        return (H - 7) * 60 + M;
    }

    public int tempoPossivelParaAtendimento(){
        return C + tempoDeChegada();
    }

    public static int Atendimento(ArrayList<Usuario> ordemDeChegada) {
        int tempoAtual = 0; //hora que começou o atendimento
        int horarioProxAtendimento = 0;
        int resultado = 0;

        for (int i = 0; i < ordemDeChegada.size(); i++) {

             // Atualiza o tempo atual se o paciente chegou após o último atendimento
             if (tempoAtual < ordemDeChegada.get(i).tempoDeChegada()) {
                tempoAtual = ordemDeChegada.get(i).tempoDeChegada();
            }

            horarioProxAtendimento = tempoAtual + 30;
            if(ordemDeChegada.get(i).tempoPossivelParaAtendimento() < horarioProxAtendimento){
                resultado++;
            }

            tempoAtual +=30 ;
        }

        return resultado;
    }
    
}

class HospitalSUS {

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);


        while (sc.hasNextInt()) {
            int linhas = sc.nextInt();

            ArrayList<Usuario> ordemDeChegada = new ArrayList<>();

            for (int i = 0; i < linhas; i++) {
            int H = sc.nextInt();
            int M = sc.nextInt();
            int C = sc.nextInt();

            Usuario user = new Usuario(H,M,C);
            ordemDeChegada.add(user);
            }

            System.out.println(Usuario.Atendimento(ordemDeChegada));
        }

        sc.close();
    }
}