/*
 Guia_0702.v
 0860668 - Ana Clara Lonczynski
*/

module Guia_0702 (output selected_out, input a, input b, input select);

// Definindo as operações lógicas
wire or_result;
wire nor_result;

assign or_result = a | b;    // Operação OR
assign nor_result = ~(a | b); // Operação NOR

// Saída selecionável pela chave de seleção (0 -> NOR, 1 -> OR)
assign selected_out = (select & or_result) | (~select & nor_result);

endmodule

// Módulo de teste
module test_Guia_0702;

reg a, b, select;
wire selected_out;

// Instanciando o módulo principal
Guia_0702 LU (selected_out, a, b, select);

// Início dos testes
initial begin
    $display("Guia_0702 - Testes da Unidade Lógica");
    $display("a b select | Selected");
    $monitor("%b %b   %b    |   %b", a, b, select, selected_out);

    // Testes com combinações de entradas e chave de seleção
    a = 0; b = 0; select = 0; #10;
    a = 0; b = 1; select = 0; #10;
    a = 1; b = 0; select = 0; #10;
    a = 1; b = 1; select = 0; #10;

    select = 1; // Mudando a chave de seleção para testar a operação OR
    a = 0; b = 0; #10;
    a = 0; b = 1; #10;
    a = 1; b = 0; #10;
    a = 1; b = 1; #10;
end

endmodule
