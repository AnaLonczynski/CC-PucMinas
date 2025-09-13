import java.util.Random;

public class Selection extends Main {
    protected int[] array;
	protected int n;

	/**
	 * Construtor.
	 */
	public Selection(){
		array = new int[100];
		n = array.length;
	}

    public Selection(int tamanho){
        array = new int[tamanho];
		n = array.length;
    }
    

    public void crescente(){
        for (int i = 0; i < n; i++) {
			array[i] = i;
		}
    }

    //Array Aleatório
    public void aleatorio() {
		Random rand = new Random();
		crescente();	
		for (int i = 0; i < n; i++) {
			swap(i, Math.abs(rand.nextInt()) % n);
		}
	}

    public void swap (int a, int b){
        int tmp = array[a];
        array [a] = array [b];
        array [b] = tmp;
    }

    public void mostrar (){

        System.out.print("[");

        for (int i = 0; i < n; i++) {
            System.out.print(" ["+i+"] : " + array[i]);
        }

        System.out.println("]");
    }

    public void SelectionSort(){
        int movimentacao = 0;
        for (int i = 0; i < n-1; i++) {
            int menor = array [i];
            for (int j = (i + 1); j < n; j++) {
                if(array[menor] > array[j]){
                    menor = j;
                }
            }
            swap(menor, i);
            movimentacao = movimentacao +3;
        }
        System.out.println("movimentacoes = " + movimentacao);
        System.out.println("Teoria : " + (3*n - 3));
    }
}

class Main {
    public static void main(String[] args) {
    
        Selection Array = new Selection(10);
        Array.aleatorio();
        Array.mostrar();
        System.out.println("Após ordenação:");
        Array.SelectionSort();
        Array.mostrar();
    }
}
