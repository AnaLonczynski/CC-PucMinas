/*
* Ana Clara Lonczynski
* 0680668
*/
module MintermSystem();
    // Definição das entradas
    reg a, b, c, d;
    wire result;

    // Definição dos mintermos
    assign result = (~c & d) | 
                    (a & b & c & d);

    initial begin
        // Testes - todos os valores possíveis de entrada
        $display("a b c d | result");
        $display("-----------------");
        for (integer i = 0; i < 16; i = i + 1) begin
            {a, b, c, d} = i; // Atribuir valores às entradas
            #1; // Aguardar propagação
            $display("%b %b %b %b | %b", a, b, c, d, result);
        end
        $finish;
    end
endmodule
