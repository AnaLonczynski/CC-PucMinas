import java.sql.ResultSet;

class Main extends MyIO {
/*Crie um m´etodo iterativo que recebe uma string e retorna true se a mesma ´e composta
  somente por vogais. Crie outro m´etodo iterativo que recebe uma string e retorna true se a
  mesma ´e composta somente por consoantes. Crie um terceiro m´etodo iterativo que recebe uma
  string e retorna true se a mesma corresponde a um n´umero inteiro. Crie um quarto m´etodo
  iterativo que recebe uma string e retorna true se a mesma corresponde a um n´umero real. Na
  sa´ıda padr˜ao, para cada linha de entrada, escreva outra de sa´ıda da seguinte forma X1 X2 X3
  X4 onde cada Xi ´e um booleano indicando se a ´e entrada ´e: composta somente por vogais (X1);
  composta somente somente por consoantes (X2); um n´umero inteiro (X3); um n´umero real (X4).
  Se Xi for verdadeiro, seu valor ser´a SIM, caso contr´ario, NAO*/

  protected static boolean isint (String str){
    /*
    try {
      Integer.parseInt(str);
      return true;
    } catch (NumberFormatException e) {
      return false;
    }*/
    for (int i = 0; i < str.length(); i++) {
      // Se qualquer caractere não for um dígito, retorna false
      if (!Character.isDigit(str.charAt(i))) {
          return false;
      }
    }
    // Se todos os caracteres forem dígitos, retorna true
    return true;
  }

  protected static boolean isreal (String str){
    boolean foundDecimalPoint = false;
    for (int i = 0; i < str.length(); i++) {
      char c = str.charAt(i);

      // Verifica se o caractere é um ponto decimal
      if (c == '.' || c == ',') {
          if (foundDecimalPoint) {
              return false; // Se já encontrou um ponto, não pode haver outro
          }
          foundDecimalPoint = true; // Marca que encontrou um ponto decimal
      } else if (!Character.isDigit(c)) {
          return false; // Se não é um dígito nem um ponto, retorna falso
      }
    }

    // Se todos os caracteres forem válidos, retorna true
    return true;
  }
  
  protected static boolean isvogal (String str){
    //compara a letra na posição i com as vogais e retorna true se for igual a alguma delas
    boolean itis = false;
    int cont = 0;
      for (int i = 0; i < str.length(); i++){
        char c = str.charAt(i);
        if ((c == 'a')||(c == 'e')||(c == 'i')||(c == 'o')||(c == 'u')||(c == 'A')||(c == 'E')||(c == 'I')||(c == 'O')||(c == 'U')){
          cont ++;
        }
        if ( cont == str.length()){
          itis = true;
        }else{itis=false;}
      }
      return (itis);
    }

  protected static void resultado ( boolean x1, boolean x2, boolean x3, boolean x4){
    //printar os resultados
    if(x1){
      print("SIM ");
    }else{
      print("NAO ");
    }
    if(x2){
      print("SIM ");
    }else{
      print("NAO ");
    }
    if(x3){
      print("SIM ");
    }else{
      print("NAO ");
    }
    if(x4){
      println("SIM");
    }else{
      println("NAO");
    }
  }
  
  protected static boolean isConsoante(String str) {
    //compara a letra na posição i com as consoantes e retorna true se for igual a alguma delas
    boolean cons = false;
    int n = 0;
     for (int i = 0; i < str.length(); i++){
       char c = str.charAt(i);
        if ((c >= 'b' && c <= 'z' && c != 'e' && c != 'i' && c != 'o' && c != 'u')||(c >= 'B' && c <= 'Z' && c != 'E' && c != 'I' && c != 'O' && c != 'U')){
           n++;
          }
       if(n == str.length()){
         cons = true;
       }else{
         cons = false;
       }
     }
    return (cons);
  }

   public static void main(String[] args){
      String palavra;
      palavra = readLine();
      boolean X1 = isvogal(palavra);
      boolean X2 = isConsoante(palavra);
      boolean X3 = isint(palavra);
      boolean X4 = isreal(palavra);
      resultado(X1, X2, X3, X4);
        while(!palavra.equals("FIM")){
          palavra = readLine();
          X1 = isvogal(palavra);
          X2 = isConsoante(palavra);
          X3 = isint(palavra);
          X4 = isreal(palavra);
            if(!palavra.equals("FIM")){
              resultado(X1, X2, X3, X4);
          }
      }
    
  }
}