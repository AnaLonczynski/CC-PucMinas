class Main extends MyIO {

    protected static boolean isInt(String str, int index) {
        if (index == str.length()) {
            return true;
        } else if (!Character.isDigit(str.charAt(index))) {
            return false;
        }
        return isInt(str, index + 1);
    }

    protected static boolean isReal(String str, int index, boolean foundDecimalPoint) {
        if (index == str.length()) {
            // Se encontramos pelo menos um ponto decimal ou vírgula, retorna verdadeiro
            return true;
        }

        char c = str.charAt(index);

        if (c == '.' || c == ',') {
            if (foundDecimalPoint) {
                return false; // Se já encontrou um ponto ou vírgula, não pode haver outro
            }
            foundDecimalPoint = true; // Marca que encontrou um ponto decimal ou vírgula
        } else if (!Character.isDigit(c)) {
            return false; // Se não é um dígito nem um ponto, retorna falso
        }

        return isReal(str, index + 1, foundDecimalPoint);
    }

    protected static boolean isReal(String str) {
        // Chama o método recursivo com o índice inicial 0 e sem ponto decimal encontrado
        return isReal(str, 0, false);
    }

    protected static boolean isVogal(String str, int index) {
        if (index == str.length()) {
            return true;
        }

        char c = str.charAt(index);
        if (!(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
              c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')) {
            return false;
        }

        return isVogal(str, index + 1);
    }

    protected static boolean isConsoante(String str, int index) {
        if (index == str.length()) {
            return true;
        }

        char c = str.charAt(index);
        if (!(c >= 'b' && c <= 'z' && c != 'e' && c != 'i' && c != 'o' && c != 'u') &&
            !(c >= 'B' && c <= 'Z' && c != 'E' && c != 'I' && c != 'O' && c != 'U')) {
            return false;
        }

        return isConsoante(str, index + 1);
    }

    protected static void resultado(boolean x1, boolean x2, boolean x3, boolean x4) {
        // Imprime os resultados
        if (x1) {
            print("SIM ");
        } else {
            print("NAO ");
        }
        if (x2) {
            print("SIM ");
        } else {
            print("NAO ");
        }
        if (x3) {
            print("SIM ");
        } else {
            print("NAO ");
        }
        if (x4) {
            println("SIM");
        } else {
            println("NAO");
        }
    }

    public static void main(String[] args) {
        String palavra;
        palavra = readLine();
        boolean X1 = isVogal(palavra, 0);
        boolean X2 = isConsoante(palavra, 0);
        boolean X3 = isInt(palavra, 0);
        boolean X4 = isReal(palavra, 0, false);
        resultado(X1, X2, X3, X4);

        while (!palavra.equals("FIM")) {
            palavra = readLine();
            if (!palavra.equals("FIM")) {
                X1 = isVogal(palavra, 0);
                X2 = isConsoante(palavra, 0);
                X3 = isInt(palavra, 0);
                X4 = isReal(palavra, 0, false);
                resultado(X1, X2, X3, X4);
            }
        }
    }
}