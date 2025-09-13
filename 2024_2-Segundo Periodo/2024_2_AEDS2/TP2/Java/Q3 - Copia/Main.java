import java.io.BufferedReader;
import java.io.FileReader;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Scanner;

class Main extends MyIO {
    public static void main(String[] args) {

        Scanner scanProvisorio = new Scanner(System.in);
        int LookingId;
        String entrada = new String();
        List<Pokemon> pokedex = ler.readAllFile("/tmp/pokemon.csv");

        // List que iremos adicionar apenas os selecionados da entrada, para trabalhar so com eles
        List<Pokemon> lista = new ArrayList<>();
        List<String> nomesLidos = new ArrayList<>();

        // Ler ate FIM, e procurar por ID, e adicionar na List
        while (scanProvisorio.hasNextLine() && !(entrada = scanProvisorio.nextLine()).equals("FIM")) {
            LookingId = Integer.parseInt(entrada);
            lista.add(PokemonSearch.searchPokemonId(pokedex, LookingId));
            nomesLidos.add(PokemonSearchName.pokemonGetName(pokedex, LookingId));
        }


        Scanner scanSecundario = new Scanner(System.in);
        String segundaEntrada;
        List<String> vetor = new ArrayList<>();
        boolean test;

        // Ler ate FIM, e procurar por Pokemon, e adicionar no vetor
        while (scanSecundario.hasNextLine() && !(segundaEntrada = scanSecundario.nextLine()).equals("FIM")) {
            vetor.add(segundaEntrada);
        }

        for (int i = 0; i < vetor.size(); i++) {
            test = isInVetor(vetor.get(i), nomesLidos);
            if (!test) {
                System.out.println("NAO");
            } else {
                System.out.println("SIM");
            }
        }

        scanProvisorio.close();
        scanSecundario.close();
    }

    public static boolean isInVetor(String vetor, List<String> names) {
        for (String name : names) {
            if (vetor.equals(name)) {
                return true;
            }
        }
        return false;
    }
}

/*
-------------- Classe Pokemon --------------
*/
class Pokemon {
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

    public Pokemon() {
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
                   boolean isLegendary, Date captureDate) {
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

        this.id = Integer.parseInt(space[0]);
        this.generation = Integer.parseInt(space[1]);
        this.name = space[2];
        this.description = space[3];
        this.types = new ArrayList<>();
        this.types.add("'" + space[4].trim() + "'");
        if (!space[5].equals("0")) {
            this.types.add("'" + space[5].trim() + "'");
        }
        String abilitiesStr = space[6].replace("\"", "").replace("[", "").replace("]", "");
        String[] abilitiesArray = abilitiesStr.split(",");
        this.abilities = new ArrayList<>();
        for (String ability : abilitiesArray) {
            this.abilities.add(ability.trim());
        }
        this.weight = Double.parseDouble(space[7]);
        this.height = Double.parseDouble(space[8]);
        this.captureRate = Integer.parseInt(space[9]);
        this.isLegendary = space[10].equals("1");

        if (space[11].equals("0")) {
            this.captureDate = null;
        } else {
            SimpleDateFormat dateFormat = new SimpleDateFormat("dd/MM/yyyy");
            this.captureDate = dateFormat.parse(space[11]);
        }
    }

    public static void imprimir(Pokemon pokemon) {
        SimpleDateFormat formatoSaida = new SimpleDateFormat("dd/MM/yyyy");
        String data = pokemon.captureDate != null ? formatoSaida.format(pokemon.captureDate) : "ERRO na data";
        System.out.println("[#" + pokemon.id + " -> " + pokemon.name + ": " + pokemon.description + " - " + pokemon.types + " - " + pokemon.abilities +
                           " - " + pokemon.weight + "kg - " + pokemon.height + "m - " + pokemon.captureRate + "% - " + pokemon.isLegendary + " - " +
                           pokemon.generation + " gen] - " + data);
    }

    public String getName() {
        return name;
    }

    public int getId() {
        return id;
    }
}

//-------------------------------
// Classe para leitura do arquivo
//-------------------------------
class ler {
    public static List<Pokemon> readAllFile(final String fileName) {
        List<Pokemon> personagens = new ArrayList<>();

        try {
            BufferedReader br = new BufferedReader(new FileReader(fileName));
            br.readLine(); // Pular o cabecalho
            String linha;
            while ((linha = br.readLine()) != null) {
                linha = lineFormat(linha);
                Pokemon pessoa = new Pokemon(linha.split(";"));
                personagens.add(pessoa);
            }
            br.close();
        } catch (Exception e) {
            e.printStackTrace();
            personagens = null;
        }

        return personagens;
    }

    private static String lineFormat(String line) {
        char[] array_aux = line.toCharArray();
        boolean in_list = false;
        for (int i = 0; i < array_aux.length; i++) {
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
    public static Pokemon searchPokemonId(List<Pokemon> pokemons, int id) {
        for (Pokemon pokemon : pokemons) {
            if (pokemon.getId() == id) {
                return pokemon;
            }
        }
        return null;
    }
}

class PokemonSearchName {
    public static String pokemonGetName(List<Pokemon> pokemons, int id) {
        for (Pokemon pokemon : pokemons) {
            if (pokemon.getId() == id) {
                return pokemon.getName();
            }
        }
        return null;
    }
}
