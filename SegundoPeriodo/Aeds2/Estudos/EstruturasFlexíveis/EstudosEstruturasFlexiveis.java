/*
*  Estudos Prova AEDS II 
*/

//---------------------------------------------
//Célula
//---------------------------------------------

class Celula{

    public int elemento;
    public Celula prox;

    public Celula(){
        this.elemento = 0;
        this.prox     = null;
    }
    
    public Celula(int elemento, Celula prox){
        this.elemento = elemento;
        this.prox     = prox;
    }

    
    public Celula(int elemento){
        this.elemento = elemento;
        this.prox = null;
    }
}

//---------------------------------------------
//Célula Dupla
//---------------------------------------------

class CelulaDupla{

    public int elemento;
    public CelulaDupla prox;
    public CelulaDupla ant;

    public CelulaDupla() {
        this.elemento = 0;
        this.ant  = null;
        this.prox = null;
    }

    public CelulaDupla(int elemento, CelulaDupla prox, CelulaDupla ant) {
        this.elemento = elemento;
        this.prox = prox;
        this.ant = ant;
    }
}

//---------------------------------------------
//Pilha
//---------------------------------------------

class Pilha{

    private Celula topo;

    public Pilha(){
        this.topo = null;
    }

    public void inserir(int x){
        Celula tmp = new Celula(x);
        tmp.prox = topo.prox;
    }

    public int remover() throws Exception{

        if (topo == null) {
			throw new Exception("Erro ao remover!");
		}

        int resp = topo.elemento;
        Celula tmp = new Celula();
        tmp = topo;
        topo = topo.prox;
        tmp.prox = null;
        tmp = null;

        return resp;
    }

    public void mostrar(){
        System.out.print("[ ");
        for (Celula i = topo; i != null; i = i.prox) {
            System.out.println( i.elemento + " ");
        }
        System.out.println("]");
    }

    public int getSoma(){
        //chama o metodo com variavel
        return getSoma(topo);
    }

    public int getSoma(Celula topo){
        int resp = 0;

        //entra no while e percorre a pilha
        while(topo != null){
            //adiciona ao resp o elemento da celula atual e entra no metodo de maneira recursiva
            resp += topo.elemento + getSoma(topo.prox);
        }
        return resp;
    }

    public int getMaior(){
        int max = topo.elemento;                 
        for (Celula i = topo; i != null ;i = i.prox){
            if(i.elemento > max){ max = i.elemento;}
        }
        return max;
    }
}

//---------------------------------------------
//Fila
//---------------------------------------------

class Fila{

    private Celula primeiro;
    private Celula ultimo;

    public Fila(){
        primeiro = new Celula();
        ultimo   = primeiro;
    }

    public void inserir(int x){
        ultimo.prox = new Celula(x);
        ultimo = ultimo.prox;
    }

    public int remover() throws Exception{
        if (primeiro == ultimo){
            throw new Exception("Fila Vazia!");
        }
        Celula tmp = primeiro;
        int resp = primeiro.elemento;
        primeiro = primeiro.prox;
        tmp.prox = null;
        tmp = null;

        return resp;
    }

    public void mostrar(){
        System.out.println("[ ");
        for (Celula i = primeiro.prox; i != null; i = i.prox) {
            System.out.println(i.elemento + " ");
        }
        System.out.println("]");
    }
}

//---------------------------------------------
//Lista Duplamente encadeada
//---------------------------------------------

class ListaDupla{
    
	private CelulaDupla primeiro;
	private CelulaDupla ultimo;

    public ListaDupla(){
        primeiro = new CelulaDupla();
        ultimo = primeiro;
    }

    
}

//---------------------------------------------
//No
//---------------------------------------------

class No{
    public int elemento;
    public No esq;
    public No dir;

    public No(int elemento){
        this.elemento = elemento;
        this.esq = null;
        this.dir = null;
    }

    public No(int elemento, No esq, No dir){
        this.elemento = elemento;
        this.esq = esq;
        this.dir = dir;
    }
}

//---------------------------------------------
//Arvore Binária
//---------------------------------------------

class ArvoreBinaria{
    private No raiz;

    public ArvoreBinaria(){
        this.raiz = null;
    }

    public boolean pesquisar(int x) {
        return pesquisar(x, raiz);
    }

    private boolean pesquisar(int x, No i) { //private para ninguem modificar o nó
        boolean resultado = false;
        if(i == null){
            resultado = false;  //se percorrer até o fim da arvore(ponteiro aponta pra null) == não encontrou oque procurava
        }else 
        if(x == i.elemento){
            resultado = true;   // se for igual a x == encontrou
        }else
        if (x < i.elemento) {
            pesquisar(x,i.esq); // se for menor a x == está a esquerda na árvore
        } 
        if(x > i.elemento){
            pesquisar(x, i.dir); // se for maior a x == está a direita na árvore
        }
        return resultado;
    }

    public void caminharCentral (){
        System.out.print("[");
        caminharCentral(raiz);
        System.out.println("]");
    }

    /*
     * Caminhamentos
    */

    private void caminharCentral(No i) {
        if(i !=null ){
            caminharCentral(i.esq); // Elementos da esquerda.
            System.out.print(i.elemento + " ");
            caminharCentral(i.dir); // Elementos da direita.
        }
    }

    public void caminharPre(){
        System.out.print("[");
        caminharPre(raiz);
        System.out.println("]");
    }

    private void caminharPre(No i){
        if( i != null){
            System.out.print(i.elemento + " ");
            caminharPre(i.esq); // Elementos da esquerda.
			caminharPre(i.dir); // Elementos da direita.
        }
    }

    public void caminharPos(){
        System.out.print("[");
        caminharPos(raiz);
        System.out.println("]");
    }

    private void caminharPos(No i){
        if(i!=null){
            caminharPos(i.esq); // Elementos da esquerda.
            caminharPos(i.dir); // Elementos da direita.
            System.out.print(i.elemento + " ");
        }
    }
    
    /*
     * Inserir
    */

    public void inserir(int x) throws Exception{
        raiz = inserir(x, raiz);
    }

    private No inserir(int x, No i) throws Exception{
        if(i != null){
            i = new No(x);
        }else
        if(x < i.elemento){
            inserir(x, i.esq);
        }else
        if(x > i.elemento){
            inserir(x, i.dir);
        }else {
            throw new Exception("Erro ao inserir!");
        }

        return i;
    }

    public void inserirPai(int x) throws Exception{
        if(raiz == null){
            raiz = new No(x);
        }else
        if(x < raiz.elemento){
            inserirPai(x, raiz.esq, raiz);
        }else
        if(x > raiz.elemento){
            inserirPai(x, raiz.dir, raiz);
        }else{
            throw new Exception ("Erro ao inserirPai!");
        }
    }

    private void inserirPai(int x, No i, No pai) throws Exception{
        if(i == null){ //se encontrar folha vazia
            if(x < pai.elemento){
                pai.esq = new No(x); //se x menor, construir novo nó a esquerda
            }else{
                pai.dir = new No(x); //se x maior, construir novo nó a direita
            }
        }else{ //se não encontrar folha vazia, continuar a percorrer a árvore
            if(x < i.elemento){
                inserirPai(x, i.esq, i);
            }else
            if(x > i.elemento){
                inserirPai(x, i.dir, i);
            } else {
                throw new Exception("Erro ao inserirPai!");
            }
        }
    }

    /*
     * Remover
    */

    public void remover(int x) throws Exception {
		raiz = remover(x, raiz);
	}

    private No remover (int x, No i) throws Exception{
        if( i == null){
            throw new Exception("Erro ao remover!");
        }else
        if( x < i.elemento){
            i.esq = remover(x, i.esq); 
        }else
        if( x > i.elemento){
            i.dir = remover(x,i.dir);
        }else  
        if(i.dir == null){ // Sem no a direita.
            i = i.esq; // volta
        }else
        if(i.esq == null){ // Sem no a esquerda.
            i = i.dir; // volta
        } else 
        {  
            i.esq = maiorEsq(i, i.esq); // se chegao ao final e houver No a esquerda e no a direita, pegar o a esquerda
        }
        return i;
    }

    private No maiorEsq(No i, No j){
        // Encontrou o maximo da subarvore esquerda.
        if(j.dir == null){
            i.elemento = j.elemento; // Substitui i por j.
			j = j.esq;               // Substitui j por j.ESQ.
        } 
        // Existe no a direita.
        else
        {
            j.dir = maiorEsq(i, j.dir); // Caminha para direita até chegar ao extremo da árvore.
        }
        return j;
    }

    /*
     * Pegar o menor e o maior elemento e a altura da árvore
    */

    public int getMenor(){ 
        int resp = -1;
        if(raiz != null){
           for(No i = raiz; i.esq != null; i = i.esq) // como é uma árvore binária, o menor elemento estará na extremidade a esquerda
           {resp = i.elemento;}
        }
        return resp;
    }

    public int getMaior(){
        int resp = -1;
        if(raiz != null){
            for(No i = raiz; i.dir !=null; i = i.dir) // como é uma árvore binária, o maior elemento estará na extremidade a direita
            {resp = i.elemento;}
        }
        return resp;
    }

    public int getAltura(){
        return getAltura(raiz, 0);
    }

    private int getAltura(No i, int altura){
        if(i == null){
            altura--; // ao terminar é preciso diminuir um algorismo, tal qual a posição final de um array
        }else{
            int alturaDir = getAltura(i.dir, altura + 1);
            int alturaEsq = getAltura(i.esq, altura + 1);
            altura = (alturaDir < alturaEsq) ? alturaEsq : alturaDir; // descobrir qual lado teve maior altura para contabilizar ao final
        }
        return altura;
    }
}


/*
 * Dicas:
 * -DECORAR VERIFICAÇÕES:
 *      -Verificar se pilha esta vazia
 *      -Verificar se ponterio esta nulo
 *      -Quando remover celula, como é em C, dê free
 */
