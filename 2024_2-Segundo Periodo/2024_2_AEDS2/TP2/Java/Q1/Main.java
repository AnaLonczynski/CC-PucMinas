import java.util.Date;
import java.util.ArrayList;
import java.util.List;
import java.io.BufferedReader;
import java.io.FileReader;
import java.text.SimpleDateFormat;
import java.util.Scanner;
import java.io.*;
import java.nio.charset.*;

class Main extends MyIO{
    public static void main (String [] args){

        Scanner scanProvisorio = new Scanner(System.in);
        int LookingId = 0;
        String entrada = new String();
        List<Pokemon> pokedex = ler.readAllFile("/tmp/pokemon.csv");

        // List que iremos adicionar apenas os selecionados da entrada, para trabalhar so com eles
        List<Pokemon> lista = new ArrayList<Pokemon>();

        // Ler ate FIM, e procurar por ID, e adicionar na List
        while (!(entrada = scanProvisorio.nextLine()).equals("FIM")) {
                    LookingId = Integer.parseInt(entrada);
            lista.add(PokemonSearch.searchPokemonId(pokedex, LookingId));
        }

        // Imprime a lista de Pokemons selecionados
        for(int i = 0; i < lista.size(); i++)
        {
        Pokemon.imprimir(lista.get(i));
        }

        scanProvisorio.close();
        /*
        //Percorre Pokedex imprimindo
        for (Pokemon p : lista) {
            System.out.println(p);
        }
        
        Scanner scanProvisorio = new Scanner(System.in);
        List<Pokemon> pokedex = ler.readAllFile("pokemon.csv");
        List<Pokemon> lista = new ArrayList<Pokemon>(); // Lista para os Pokemons selecionados

        String entrada = new String();
        while (!(entrada = scanProvisorio.nextLine()).equals("FIM")) {
            try {
                int lookingId = Integer.parseInt(entrada); // Converte a entrada para ID
                Pokemon pokemon = PokemonSearch.searchPokemonId(pokedex, lookingId);
                if (pokemon != null) {
                    lista.add(pokemon); // Adiciona apenas se o Pokemon for encontrado
                }
            } catch (NumberFormatException e) {
                MyIO.println("Error// entrada");
            }
        }
        */

        
        /*
        --------------------------------
        Ideia Descartada. Avaliar depois
        --------------------------------
        
        String idPoke = MyIO.readLine();
        while (idPoke != "FIM"){
            //Procurar o id "idPoke" no arquivo Pokemon. e quando na string linha
            pokedex[cont] = new Pokemon();
            pokedex[cont].ler(linha);
            cont++;
            idPoke = MyIO.readLine();
        }
        */
    }
}

/*
Sua classe terá os atributos privado id int, generation int, name String, description String, 
types Lista, abilities Lista, weight double, height double, captureRate int, isLegendary boolean, 
captureDate Date. Sua classe também terá pelo menos dois construtores, e os métodos gets, sets, 
clone, imprimir e ler.
*/

//[#id -> name: description - [types] - [abilities] - weight - height - captureRate - isLegendary - 
//generation] - captureDate]

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
        this.types = new ArrayList<String>();
        this.abilities = new ArrayList<String>();
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
        this.types = new ArrayList<String>();
        this.types.add("'" + space[4].trim() + "'");
        if (!space[5].equals("0")) {
            this.types.add("'" + space[5].trim() + "'");
        }

        // Processar habilidades (remover aspas e colchetes, e dividir por vírgula)
        String abilitiesStr = space[6].replace("\"", "").replace("[", "").replace("]", "");
        String[] abilitiesArray = abilitiesStr.split(",");
        this.abilities = new ArrayList<String>();
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

    /*
    Método para imprimir o resultado da pokedex
    */
    public static void imprimir(Pokemon pokemon){
        //definir formato da saida da data
            SimpleDateFormat formatoSaida = new SimpleDateFormat("dd/MM/yyyy");
            String data = " ";
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

class ler{
    public static List<Pokemon> readAllFile(final String fileName)
    {
        List<Pokemon> personagens = new ArrayList<Pokemon>();

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

class PokemonSearch {
    // Função estática que busca um Pokémon pelo ID
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

/*
-----------------------------------------------------------
Por erro de import vou adicionar a MyIO ao final do arquivo
-----------------------------------------------------------
*/
class MyIO {

   private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in, Charset.forName("ISO-8859-1")));
   private static String charset = "ISO-8859-1";

   public static void setCharset(String charset_){
      charset = charset_;
      in = new BufferedReader(new InputStreamReader(System.in, Charset.forName(charset)));
   }

   public static void print(){
   }

   public static void print(int x){
      try {
         PrintStream out = new PrintStream(System.out, true, charset);
         out.print(x);
      }catch(UnsupportedEncodingException e){ System.out.println("Erro: charset invalido"); }
   }

   public static void print(float x){
      try {
         PrintStream out = new PrintStream(System.out, true, charset);
         out.print(x);
      }catch(UnsupportedEncodingException e){ System.out.println("Erro: charset invalido"); }
   }

   public static void print(double x){
      try {
         PrintStream out = new PrintStream(System.out, true, charset);
         out.print(x);
      }catch(UnsupportedEncodingException e){ System.out.println("Erro: charset invalido"); }
   }

   public static void print(String x){
      try {
         PrintStream out = new PrintStream(System.out, true, charset);
         out.print(x);
      }catch(UnsupportedEncodingException e){ System.out.println("Erro: charset invalido"); }
   }

   public static void print(boolean x){
      try {
         PrintStream out = new PrintStream(System.out, true, charset);
         out.print(x);
      }catch(UnsupportedEncodingException e){ System.out.println("Erro: charset invalido"); }
   }

   public static void print(char x){
      try {
         PrintStream out = new PrintStream(System.out, true, charset);
         out.print(x);
      }catch(UnsupportedEncodingException e){ System.out.println("Erro: charset invalido"); }
   }

   public static void println(){
   }

   public static void println(int x){
      try {
         PrintStream out = new PrintStream(System.out, true, charset);
         out.println(x);
      }catch(UnsupportedEncodingException e){ System.out.println("Erro: charset invalido"); }
   }

   public static void println(float x){
      try {
         PrintStream out = new PrintStream(System.out, true, charset);
         out.println(x);
      }catch(UnsupportedEncodingException e){ System.out.println("Erro: charset invalido"); }
   }

   public static void println(double x){
      try {
         PrintStream out = new PrintStream(System.out, true, charset);
         out.println(x);
      }catch(UnsupportedEncodingException e){ System.out.println("Erro: charset invalido"); }
   }

   public static void println(String x){
      try {
         PrintStream out = new PrintStream(System.out, true, charset);
         out.println(x);
      }catch(UnsupportedEncodingException e){ System.out.println("Erro: charset invalido"); }
   }

   public static void println(boolean x){
      try {
         PrintStream out = new PrintStream(System.out, true, charset);
         out.println(x);
      }catch(UnsupportedEncodingException e){ System.out.println("Erro: charset invalido"); }
   }

   public static void println(char x){
      try {
         PrintStream out = new PrintStream(System.out, true, charset);
         out.println(x);
      }catch(UnsupportedEncodingException e){ System.out.println("Erro: charset invalido"); }
   }

   public static void printf(String formato, double x){
      try {
         PrintStream out = new PrintStream(System.out, true, charset);
         out.printf(formato, x);// "%.2f"
      }catch(UnsupportedEncodingException e){ System.out.println("Erro: charset invalido"); }
   }

   public static double readDouble(){
      double d = -1;
      try{
         d = Double.parseDouble(readString().trim().replace(",","."));
      }catch(Exception e){}
      return d;
   }

   public static double readDouble(String str){
      try {
         PrintStream out = new PrintStream(System.out, true, charset);
         out.print(str);
      }catch(UnsupportedEncodingException e){ System.out.println("Erro: charset invalido"); }
      return readDouble();
   }

   public static float readFloat(){
      return (float) readDouble();
   }

   public static float readFloat(String str){
      return (float) readDouble(str);
   }

   public static int readInt(){
      int i = -1;
      try{
         i = Integer.parseInt(readString().trim());
      }catch(Exception e){}
      return i;
   }

   public static int readInt(String str){
      try {
         PrintStream out = new PrintStream(System.out, true, charset);
         out.print(str);
      }catch(UnsupportedEncodingException e){ System.out.println("Erro: charset invalido"); }
      return readInt();
   }

   public static String readString(){
      String s = "";
      char tmp;
      try{
         do{
            tmp = (char)in.read();
            if(tmp != '\n' && tmp != ' ' && tmp != 13){
               s += tmp;
            }
         }while(tmp != '\n' && tmp != ' ');
      }catch(IOException ioe){
         System.out.println("lerPalavra: " + ioe.getMessage());
      }
      return s;
   }

   public static String readString(String str){
      try {
         PrintStream out = new PrintStream(System.out, true, charset);
         out.print(str);
      }catch(UnsupportedEncodingException e){ System.out.println("Erro: charset invalido"); }
      return readString();
   }

   public static String readLine(){
      String s = "";
      char tmp;
      try{
         do{
            tmp = (char)in.read();
            if(tmp != '\n' && tmp != 13){
               s += tmp;
            }
         }while(tmp != '\n');
      }catch(IOException ioe){
         System.out.println("lerPalavra: " + ioe.getMessage());
      }
      return s;
   }

   public static String readLine(String str){
      try {
         PrintStream out = new PrintStream(System.out, true, charset);
         out.print(str);
      }catch(UnsupportedEncodingException e){ System.out.println("Erro: charset invalido"); }
      return readLine();
   }

   public static char readChar(){
      char resp = ' ';
      try{
         resp  = (char)in.read();
      }catch(Exception e){}
      return resp;
   }

   public static char readChar(String str){
      try {
         PrintStream out = new PrintStream(System.out, true, charset);
         out.print(str);
      }catch(UnsupportedEncodingException e){ System.out.println("Erro: charset invalido"); }
      return readChar();
   }

   public static boolean readBoolean(){
      boolean resp = false;
      String str = "";

      try{
         str = readString();
      }catch(Exception e){}

      if(str.equals("true") || str.equals("TRUE") || str.equals("t") || str.equals("1") || 
            str.equals("verdadeiro") || str.equals("VERDADEIRO") || str.equals("V")){
         resp = true;
            }

      return resp;
   }

   public static boolean readBoolean(String str){
      try {
         PrintStream out = new PrintStream(System.out, true, charset);
         out.print(str);
      }catch(UnsupportedEncodingException e){ System.out.println("Erro: charset invalido"); }
      return readBoolean();
   }

   public static void pause(){
      try{
         in.read();
      }catch(Exception e){}
   }

   public static void pause(String str){
      try {
         PrintStream out = new PrintStream(System.out, true, charset);
         out.print(str);
      }catch(UnsupportedEncodingException e){ System.out.println("Erro: charset invalido"); }
      pause();
   }
}
