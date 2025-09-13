class Main{

    public void swap(int i, int j){

        int tmp;
        tmp = i;
        i = j;
        j = tmp;
    
    }

    public void selectionParcial(int array[],int k, int n){

        for(int i = 0; i < k; i++){
            int menor = 0;
            for (int j = 0; j < (i + 1); j++){
                if(array[menor] > array[j]){
                    menor = j;
                }
            }
            swap(menor,i);
        }

    }

    public void insercaoParcial(int array[],int k, int n){


        for (int i = 0; i < n; i++) {
            int tmp = array[i];
            int j = (i < k) ? i-1 : k-1;
            while((j >= 0) && (array[j] > tmp)){
                array[j+1] = array[j];
                j--;
            }
            array[j+1]=tmp;
        }

    }

    public void quickParcial(int array[],int k, int n){


    }

    public void heapParcial(int array[],int k, int n){


    }

        public static void main (String[] args){


    }
}