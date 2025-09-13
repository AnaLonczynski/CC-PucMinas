class Main extends MyIO {

    public static String ciframento(String str, int i) {
        if (i < str.length()) {
            char cifrado = (char) (str.charAt(i));
            if ((int) cifrado < 127) {
                cifrado = (char) (str.charAt(i)+3); // Mantém o caractere original se a cifra ultrapassar 127
            }
            return cifrado + ciframento(str, i + 1);
        } else {
            return ""; // Caso base: string vazia quando a posição ultrapassar o comprimento da string
        }
    }

    public static void main(String[] args) {
        MyIO.setCharset("UTF-8");
        String palavra = readLine();
        while (!palavra.equals("FIM")) {
            System.out.println(ciframento(palavra, 0));
            palavra = readLine();
        }
    }
}