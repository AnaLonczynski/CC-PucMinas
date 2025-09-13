import java.io.BufferedReader;
import java.io.FileReader;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Scanner;

class Main extends MyIO{
    public static void main (String [] args){

        Scanner scan = new Scanner(System.in);
        int LookingId;
        String entrada;
        //List<Pokemon> pokedex = ler.readAllFile("pokemon.csv");
        List<Pokemon> pokedex = ler.readAllFile("/tmp/pokemon.csv");

        Lista lista = new Lista();

        // Ler ate FIM, e procurar por ID, e adicionar na List
        while (!(entrada = scan.nextLine()).equals("FIM")) 
        {
            LookingId = Integer.parseInt(entrada);
            Pokemon pokemonEncontrado = PokemonSearch.searchPokemonId(pokedex, LookingId);

            if (pokemonEncontrado != null) {
                lista.inserirFim(pokemonEncontrado); // Adiciona ao fim da lista encadeada
            } else {
                System.out.println("Pokémon com ID " + LookingId + " não encontrado.");
            }
        }
        
        // Imprime a lista de Pokemons selecionados
        //System.out.println("Pokemons na lista: ");
        //lista.imprimirLista();

        int numEntradas = scan.nextInt();
        scan.nextLine();

        for(int i = 0; i < numEntradas; i++)
        {
            String entrada2 = scan.nextLine();   
            
            switch (Q1.getOperacao(entrada2)) 
            {
                case 0:
                    lista.inserirInicio(ler.getPokemon(pokedex, Integer.parseInt(entrada2.substring(3, entrada2.length()))));
                    break;
                case 1:
                    lista.inserirFim(ler.getPokemon(pokedex, Integer.parseInt(entrada2.substring(3, entrada2.length()))));
                    break;
                case 2:
                    String[] partes = entrada2.substring(3).trim().split(" ");
                    if (partes.length == 2) {
                        int posicao = Integer.parseInt(partes[0]);
                        int id = Integer.parseInt(partes[1]);
                        lista.inserir(ler.getPokemon(pokedex, id), posicao);
                    } else {
                        System.out.println("ERRO: Entrada inválida para operação de inserção em posição específica.");
                    }
                    break;
                case 3:
                    System.out.println("(R) " + lista.removerInicio().getName());  
                    break;
                case 4:
                    System.out.println("(R) " + lista.removerFim().getName());  
                    break;
                case 5:
                    System.out.println("(R) " + lista.remover(Integer.parseInt(entrada2.substring(3).trim())).getName());   
                    break;
            }
        }
        
        lista.imprimirLista2();

        scan.close();
    }
}

class Q1{

    public static int getOperacao(String entrada){
        int resp;
        if(entrada.charAt(0) == 'I'){
            if(entrada.charAt(1) == 'I'){
                resp = 0;
            }else if(entrada.charAt(1) == 'F'){
                resp = 1;
            }else{
                resp = 2;
            }
        }else{
            if(entrada.charAt(1) == 'I'){
                resp = 3;
            }else if(entrada.charAt(1) == 'F'){
                resp = 4;
            }else{
                resp = 5;
            }
        }
        return resp;
    }

}

/*
-------------
Classe Lista
-------------
*/
class Lista {
    private ArrayList<Pokemon> pokemons;

    // Construtor inicializando a lista vazia
    public Lista() {
        this.pokemons = new ArrayList<>();
    }

    public void inserirInicio(Pokemon pokemon) {
        this.pokemons.add(0, pokemon);
    }

    public void inserirFim(Pokemon pokemon) {
        this.pokemons.add(pokemon);
    }

    public void inserir(Pokemon pokemon, int posicao) {
        if (posicao >= 0 && posicao <= this.pokemons.size()) {
            this.pokemons.add(posicao, pokemon);
        } else {
            System.out.println("ERRO: Posição inválida.");
        }
    }

    public Pokemon removerInicio() {
        if (!this.pokemons.isEmpty()) {
            return this.pokemons.remove(0);
        }
        return null;
    }

    public Pokemon removerFim() {
        if (!this.pokemons.isEmpty()) {
            return this.pokemons.remove(this.pokemons.size() - 1);
        }
        return null;
    }

    public Pokemon remover(int posicao) {
        if (posicao >= 0 && posicao < this.pokemons.size()) {
            return this.pokemons.remove(posicao);
        }
        System.out.println("ERRO: Posição inválida.");
        return null;
    }

    // Obter um Pokémon de uma posição específica
    public Pokemon getPokemon(int posicao) {
        if (posicao >= 0 && posicao < this.pokemons.size()) {
            return this.pokemons.get(posicao);
        }
        return null;
    }

    // Obter o tamanho atual da lista
    public int tamanho() {
        return this.pokemons.size();
    }

    // Imprimir todos os Pokémons da lista
    public void imprimirLista2() {
        int[] num = new int[tamanho()];
        for (int i = 0; i < this.pokemons.size(); i++) {
            Pokemon pokemon = this.pokemons.get(i);
            Pokemon.imprimir2(pokemon, i);
        }
    }

    //imprimir todos Pokémons sem o contador
    public void imprimirLista() {
        for (Pokemon pokemon : this.pokemons) {
            Pokemon.imprimir(pokemon);
        }
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

    public static void imprimir2(Pokemon pokemon, int num){
            //definir formato da saida da data
            SimpleDateFormat formatoSaida = new SimpleDateFormat("dd/MM/yyyy");
            String data = "";

            //verificar se é válida
            if(pokemon.captureDate != null){
                data = formatoSaida.format(pokemon.captureDate);
            }
            else{data = "ERRO na data";}

            //printar dados
            System.out.println( "[" + num + "] " + "[#" + pokemon.id + " -> " + pokemon.name + ": " + pokemon.description + " - " + pokemon.types + " - " + pokemon.abilities + 
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

    public static Pokemon getPokemon ( List<Pokemon> pokedex, int id ){   
        for (Pokemon pokemon : pokedex) {
            if (pokemon.getId() == id) {
                return pokemon;
            }
        }
        return null;

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
