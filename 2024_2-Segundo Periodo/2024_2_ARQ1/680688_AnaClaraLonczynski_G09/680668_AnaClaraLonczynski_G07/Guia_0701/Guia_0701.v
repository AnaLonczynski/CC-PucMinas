/*
 Guia_0701.v
 0860668 - Ana Clara Lonczynski
*/

module Guia_0701 (output and_out, output nand_out, output selected_out, input a, input b, input select);

// Definindo as operações lógicas
wire and_result;
wire nand_result;

assign and_result = a & b;    // Operação AND
assign nand_result = ~(a & b); // Operação NAND

// Atribuindo saídas independentes
assign and_out = and_result;
assign nand_out = nand_result;

// Saída selecionável pela chave de seleção (0 -> NAND, 1 -> AND)
assign selected_out = (select) ? and_result : nand_result;

endmodule

// Módulo de teste
module test_Guia_0701;

reg a, b, select;
wire and_out, nand_out, selected_out;

// Instanciando o módulo principal
Guia_0701 LU (and_out, nand_out, selected_out, a, b, select);

// Início dos testes
initial begin
    $display("Guia_0701 - Testes da Unidade Lógica");
    $display("a b select | AND  NAND  Selected");
    $monitor("%b %b   %b    |  %b     %b     %b", a, b, select, and_out, nand_out, selected_out);

    // Testes com combinações de entradas e chaves de seleção
    a = 0; b = 0; select = 0; #10;
    a = 0; b = 1; select = 0; #10;
    a = 1; b = 0; select = 0; #10;
    a = 1; b = 1; select = 0; #10;

    select = 1; // Mudando a chave de seleção para testar a operação AND
    a = 0; b = 0; #10;
    a = 0; b = 1; #10;
    a = 1; b = 0; #10;
    a = 1; b = 1; #10;
end

endmodule
