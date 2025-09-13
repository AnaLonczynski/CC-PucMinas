import java.io.BufferedReader;
import java.io.FileReader;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Scanner;

class Main extends MyIO{
    public static void main (String [] args){

        Scanner scanProvisorio = new Scanner(System.in);
        int LookingId;
        String entrada;
        List<Pokemon> pokedex = ler.readAllFile("2024_2_AEDS2/TP2/Q9/pokemon.csv");
        //List<Pokemon> pokedex = ler.readAllFile("/tmp/pokemon.csv");

        List<Pokemon> lista = new ArrayList<>();
        //println("Q9");


        // Ler ate FIM, e procurar por ID, e adicionar na List
        while (!(entrada = scanProvisorio.nextLine()).equals("FIM")) {
            LookingId = Integer.parseInt(entrada);
            lista.add(PokemonSearch.searchPokemonId(pokedex, LookingId));
        }

        Q9.HeapSort(lista);

        /* 
        // Imprime a lista de Pokemons selecionados
        for(int i = 0; i < lista.size(); i++)
        {
        Pokemon.imprimir(lista.get(i));
        }*/

        scanProvisorio.close();
    }
}

class Q9{


    public static void swap(List<Pokemon> vetor, int i, int j ){
        Pokemon tmp = vetor.get(i);
        vetor.set(i,vetor.get(j));
        vetor.set(j, tmp);
    }


    public static void InsertionSort(List<Pokemon> vetor) {
        for (int i = 1; i < vetor.size(); i++) {
            Pokemon menor = vetor.get(i);  // Evita o uso de clone
            int j = i;
            boolean test = true;
    
            while (test && j > 0 && vetor.get(j - 1).getCaptureDate().compareTo(menor.getCaptureDate()) >= 0) {
                if (vetor.get(j - 1).getCaptureDate().compareTo(menor.getCaptureDate()) == 0) {
                    if (vetor.get(j - 1).getName().compareTo(menor.getName()) > 0) {
                        vetor.set(j, vetor.get(j - 1));  // Apenas desloca a referência, sem clone
                        j--;
                    } else {
                        test = false;
                    }
                } else {
                    vetor.set(j, vetor.get(j - 1));  // Apenas desloca a referência, sem clone
                    j--;
                }
            }
    
            vetor.set(j, menor);  // Coloca a referência correta sem criar um clone
        }
    }
    
    public static void SelectionSort(List<Pokemon> vetor){
        for(int i = 0; i < vetor.size() && vetor.get(i) != null; i++){
            String menor = new String(vetor.get(i).getName());
            System.out.println(i + " = " + menor);
            int tmp = i;
            for(int j = i + 1; j < vetor.size() ; j++){
                if(vetor.get(i) != null && vetor.get(j).getName().compareTo(menor) < 0){
                    menor = vetor.get(j).getName();
                    tmp = j;
                    System.out.println("Novo menor = "+ j + " = " + menor);
                }
            }
            swap(vetor, i, tmp);
        }
    }

    public static void HeapSort(List<Pokemon> vetor){

        int tam = 0;
        List<Pokemon> heap = new ArrayList<>(contaObjetos(vetor) + 1);
        heap.add(null);

        for(int i = 0; i < contaObjetos(vetor); i++){
            heap.add(vetor.get(i));
            adicionaNoHeap(heap, i+1);
            tam++;
        }


        while(tam > 1){
            swap(heap, 1, tam--);
            reconstroiHeap(heap, tam);
        }

        for(int j = 1; j < heap.size(); j++){
            Pokemon.imprimir(heap.get(j));
        }


    }

    public static int compare(Pokemon a, Pokemon b) {
        
        int heightComparison = Double.compare(a.getHeight(), b.getHeight());
        if (heightComparison != 0) {
            return heightComparison;
        } else {
            return a.getName().compareTo(b.getName());
        }
    }

    public static int getMaiorFilho(List<Pokemon> heap, int i, int tam){
        int maior;
        if(2*i+1 > tam){
            maior = 2*i;
        }
        else{
            if(compare(heap.get(2 * i), heap.get(2 * i + 1)) < 0){
                maior = 2*i+1;
            }
            else{
                maior = 2*i;
            }
        }


        return maior;
    }
    
    public static Boolean hasFilho(List<Pokemon> heap, int i, int tam){
        Boolean test = true;

        if(2*i > tam){
            test = false;
        }

        return test;
    }

    public static void reconstroiHeap(List<Pokemon> heap, int tam){

        int i = 1;
        while(hasFilho(heap, i, tam) == true){
            int filho = getMaiorFilho(heap, i, tam);

            if(compare(heap.get(i), heap.get(filho)) < 0){

                swap(heap, i, filho);
                i = filho;
            }
            else{
                i = tam;
            }
        }
    }

    public static void adicionaNoHeap(List<Pokemon> heap, int pos) {
        for (; pos > 1 && compare(heap.get(pos), heap.get(pos / 2)) > 0; pos = pos / 2) {
            swap(heap, pos, pos / 2); 
        }
    }
    

    public static int contaObjetos(List<Pokemon> vetor){
        int count = 0;
        for(int i = 0; i < vetor.size(); i++){
            if(vetor.get(i) == null){
                i = vetor.size();
            }
            else{
                count++;
            }
        }

        return count;
    }
    
}

/*
--------------
Classe Pokemon
--------------
*/
class Pokemon{
    private int id;
    private String name;
    private int generation;
    private String description;
    private double weight;
    private int captureRate;
    private boolean isLegendary;
    private Date captureDate;
    private ArrayList<String> types;
    private ArrayList<String> abilities;
    private double height;
    

    public Pokemon(){  
        this.id = 0;
        this.generation = 0;
        this.name = "";
        this.description = "";
        this.types = new ArrayList<>();
        this.abilities = new ArrayList<>();
        this.weight = 0.0;
        this.height = 0.0;
        this.captureRate = 0;
        this.isLegendary = false;
        this.captureDate = new Date();
    }
    
    public Pokemon(int id, int generation, String name, String description, ArrayList<String> types, 
                   ArrayList<String> abilities, double weight, double height, int captureRate, 
                   boolean isLegendary, Date captureDate){
        this.id = id;
        this.generation = generation;
        this.name = name;
        this.description = description;
        this.types = types;
        this.abilities = abilities;
        this.weight = weight;
        this.height = height;
        this.captureRate = captureRate;
        this.isLegendary = isLegendary;
        this.captureDate = captureDate;
    }

    public Pokemon(String[] space) throws Exception {
        
        for (int i = 0; i < space.length; i++) {
            if (space[i].isEmpty()) {
                    space[i] = "0";
            }
        }

        // Atribuir atributos numéricos
        this.id = Integer.parseInt(space[0]);
        this.generation = Integer.parseInt(space[1]);

        // Atribuir atributos de texto
        this.name = space[2];
        this.description = space[3];

        // Tipos (um ou dois tipos)
        this.types = new ArrayList<>();
        this.types.add("'" + space[4].trim() + "'");
        if (!space[5].equals("0")) {
            this.types.add("'" + space[5].trim() + "'");
        }

        // Processar habilidades (remover aspas e colchetes, e dividir por vírgula)
        String abilitiesStr = space[6].replace("\"", "").replace("[", "").replace("]", "");
        String[] abilitiesArray = abilitiesStr.split(",");
        this.abilities = new ArrayList<>();
        for (String ability : abilitiesArray) {
            this.abilities.add(ability.trim());
        }

        // Peso e altura
        this.weight = Double.parseDouble(space[7]);
        this.height = Double.parseDouble(space[8]);

        // Taxa de captura
        this.captureRate = Integer.parseInt(space[9]);

        // Verificar se é lendário
        this.isLegendary = space[10].equals("1");

        // Data de captura (se presente)
        if (space[11].equals("0")) {
            this.captureDate = null;
        } else {
            SimpleDateFormat dateFormat = new SimpleDateFormat("dd/MM/yyyy");
            this.captureDate = dateFormat.parse(space[11]);
        }
    }

    public Pokemon clone (){
        Pokemon tmp = new Pokemon();
        tmp.id = this.id;
        return tmp;
    }

    public Pokemon clone (Pokemon pokemon){
        Pokemon tmp = new Pokemon();
        tmp.id = pokemon.id;
        return tmp;
    }

    /*
    Método para imprimir o resultado da pokedex
    */
    public static void imprimir(Pokemon pokemon){
        //definir formato da saida da data
            SimpleDateFormat formatoSaida = new SimpleDateFormat("dd/MM/yyyy");
            String data = "";
            //verificar se é válida
            if(pokemon.captureDate != null){
                data = formatoSaida.format(pokemon.captureDate);
            }
            else{data = "ERRO na data";}
            //printar dados
            System.out.println( "[#" + pokemon.id + " -> " + pokemon.name + ": " + pokemon.description + " - " + pokemon.types + " - " + pokemon.abilities + 
            " - " + pokemon.weight + "kg - " + pokemon.height + "m - " + pokemon.captureRate + "% - " + pokemon.isLegendary + " - " + pokemon.generation + 
            " gen] - " + data);
        }

    /*
    Definindo metodos getters e setters para cada atributo.
    */
    public ArrayList<String> getAbilities() {
        return abilities;
    }
    public void setCaptureRate(int captureRate) {
        this.captureRate = captureRate;
    }
    public void setGeneration(int generation) {
        this.generation = generation;
    }
    public void setCaptureDate(Date captureDate) {
        this.captureDate = captureDate;
    }
    public void setDescription(String description) {
        this.description = description;
    }
    public void setId(int id) {
        this.id = id;
    }
    public void setLegendary(boolean isLegendary) {
        this.isLegendary = isLegendary;
    }
    public void setName(String name) {
        this.name = name;
    }
    public void setWeight(double weight) {
        this.weight = weight;
    }
    public void setHeigh(double height) {
        this.height = height;
    }
    public void setTypes(ArrayList<String> types) {
        this.types = types;
    }
    public Date getCaptureDate() {
        return captureDate;
    }
    public int getCaptureRate() {
        return captureRate;
    }
    public String getDescription() {
        return description;
    }
    public int getGeneration() {
        return generation;
    }
    public int getId() {
        return id;
    }
    public String getName() {
        return name;
    }
    public double getWeight() {
        return weight;
    }
    public ArrayList<String> getTypes() {
        return types;
    }
    public double getHeight() {
        return height;
    }
    /*
    Fim da definição dos métodos
    */
}

//-------------------------------
// Classe para leitura do arquivo
//-------------------------------

class ler{
    public static List<Pokemon> readAllFile(final String fileName)
    {
        List<Pokemon> personagens = new ArrayList<>();

        try
        {
            BufferedReader br = new BufferedReader(new FileReader(fileName));

            // Pular o cabecalho
            br.readLine();

            // Ler linha por linha
            String linha = new String();
            while((linha = br.readLine()) != null)
            {
                // Tratar a linha, para conseguir fazer o plit em ; sem atrapalhar a lista
                    linha = lineFormat(linha);

                // Para cada linha, damos split e jogamos para o construtor, e adicionamos a instancia toda preenchida no nosso array
                Pokemon pessoa = new Pokemon(linha.split(";"));
                personagens.add(pessoa);
            }

            br.close();
        }
        catch (Exception e)
        {
            e.printStackTrace();
            personagens = null;
        }

        return personagens;
    }

    // Subistituir todas as , por ; para dar split (menos as , dentro de [])
    private static String lineFormat(String line)
    {
        char[] array_aux = line.toCharArray();
        boolean in_list = false;
        for (int i = 0; i < array_aux.length; i++)
        {
            if (!in_list && array_aux[i] == ',') array_aux[i] = ';'; 
            else if (array_aux[i] == '"') in_list = !in_list;
        }

        return new String(array_aux);
    }

}

//---------------------------------------------
// Função estática que busca um Pokémon pelo ID
//---------------------------------------------

class PokemonSearch {
    public static Pokemon searchPokemonId(List<Pokemon> pokemons, int id)
    {
        for (Pokemon pokemon : pokemons)
        {
            if (pokemon.getId() == id)
            {
                return pokemon;
            }
        }
        return null;
    }
}

class PokemonSearchName {
    public static Pokemon pokemonSearchName(List<Pokemon> pokemons, String name)
    {
        for (Pokemon pokemon : pokemons)
        {
            if (pokemon.getName() == null ? name == null : pokemon.getName().equals(name))
            {
                return pokemon;
            }
            else{
                System.out.println("NAO");
            }
        }
        
        return null;
    }

    public static String pokemonGetName(List<Pokemon> pokemons, int id)
    {
        
        for (Pokemon pokemon : pokemons)
        {
             if (pokemon.getId() == id)
             {
                 return pokemon.getName();
            }
        }
        return null;
    }
}
