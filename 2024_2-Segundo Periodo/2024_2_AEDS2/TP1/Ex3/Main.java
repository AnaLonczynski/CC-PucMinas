class Main extends MyIO{
  /*Crie um m´etodo iterativo que recebe uma string como parˆametro e retorna
  outra contendo a entrada de forma cifrada. Neste exerc´ıcio, suponha a chave de ciframento trˆes.
  Na sa´ıda padr˜ao, para cada linha de entrada, escreva uma linha com a mensagem criptografada*/
  
  public static void ciframento (String str){
      //Le a string na posição desejada e soma tres numeros para a letra indicada, mudando o valor do algorismo e, consequentemente, mudando o que sera mostrado após a conversão para char
      String cifra = "";
      for (int i = 0; i < str.length(); i++){
        char cifrado = (char)((int)str.charAt(i));
        if (cifrado < 127) {
            cifra +=(char)((int)str.charAt(i)+3);
        }else {
            cifra += cifrado;
        }

      }
      System.out.println(cifra);  
    }

    public static void main (String[] args){

      MyIO.setCharset("UTF-8");
      String palavra;
      palavra = readLine();
        ciframento(palavra);

        while(!palavra.equals("FIM")){
          palavra = readLine();
            if(!palavra.equals("FIM")){
          ciframento(palavra);}
      }
    }
  }

