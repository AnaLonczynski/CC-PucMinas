import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.RandomAccessFile;

class Main extends MyIO{
    public static void main(String[] args) {
        int n = readInt();

        PrintWriter writer = null;
        RandomAccessFile raf = null;

        try {
            // Escrever os valores no arquivo
            writer = new PrintWriter(new File("valores.txt"));
            for (int i = 0; i < n; i++) {
                double valor = readDouble();
                writer.println(valor);
            }
        } catch (IOException e) {
            System.err.println("Erro ao escrever no arquivo: " + e.getMessage());
        } finally {
            if (writer != null) {
                writer.close();
            }
        }

        try {
            // Ler os valores de trás para frente
            raf = new RandomAccessFile("valores.txt", "r");
            long pointer = raf.length(); // Tamanho total do arquivo

            for (int i = 0; i < n; i++) {
                pointer = seekPreviousLine(raf, pointer);
                String line = raf.readLine();
                if (line != null) {
                    double numero = Double.parseDouble(line); // Converte a linha para double
                    if (numero == (int) numero) {
                        println((int) numero); // Imprime como inteiro se terminar em .0
                    } else {
                        println(numero); 
                    }
                }
            }
        } catch (IOException e) {
            System.err.println("Erro ao ler do arquivo: " + e.getMessage());
        } finally {
            if (raf != null) {
                try {
                    raf.close();
                } catch (IOException e) {
                    System.err.println("Erro ao fechar o arquivo: " + e.getMessage());
                }
            }
        }
    }

    // Método auxiliar para posicionar o ponteiro no início da linha anterior
    private static long seekPreviousLine(RandomAccessFile raf, long pointer) throws IOException {
        pointer--; // Move o ponteiro um byte para trás
        raf.seek(pointer);

        while (pointer > 0) {
            char c = (char) raf.readByte();
            if (c == '\n') {
                break;
            }
            pointer--;
            raf.seek(pointer);
        }

        return pointer;
    }
}