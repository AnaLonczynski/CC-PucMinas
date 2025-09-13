/*
 Guia_0704.v
 0860668 - Ana Clara Lonczynski
*/

module Guia_0704 (output selected_out, input a, input b, input [1:0] select);

// Definindo as operações lógicas
wire or_result, nor_result, xor_result, xnor_result;

// Operações lógicas
assign or_result = a | b;     // Operação OR
assign nor_result = ~(a | b); // Operação NOR
assign xor_result = a ^ b;    // Operação XOR
assign xnor_result = ~(a ^ b); // Operação XNOR

// Fios intermediários para seleção de operações
wire sel_or_nor, sel_xor_xnor;

// Seleção entre OR e NOR (selecão bit mais baixo)
assign sel_or_nor = (select[0] & or_result) | (~select[0] & nor_result);

// Seleção entre XOR e XNOR (selecão bit mais baixo)
assign sel_xor_xnor = (select[0] & xor_result) | (~select[0] & xnor_result);

// Seleção final entre os grupos OR/NOR e XOR/XNOR (seleção bit mais alto)
assign selected_out = (select[1] & sel_xor_xnor) | (~select[1] & sel_or_nor);

endmodule

// Módulo de teste
module test_Guia_0704;

reg a, b;
reg [1:0] select;
wire selected_out;

// Instanciando o módulo principal
Guia_0704 LU (selected_out, a, b, select);

// Início dos testes
initial begin
    $display("Guia_0704 - Testes da Unidade Lógica");
    $display("a b select | Selected Out");
    $monitor("%b %b   %2b     |     %b", a, b, select, selected_out);

    // Testes com combinações de entradas e chaves de seleção
    a = 0; b = 0; select = 2'b00; #10; // NOR
    a = 0; b = 1; select = 2'b00; #10; // NOR
    a = 1; b = 0; select = 2'b00; #10; // NOR
    a = 1; b = 1; select = 2'b00; #10; // NOR

    select = 2'b01; // Testando OR
    a = 0; b = 0; #10; // OR
    a = 0; b = 1; #10; // OR
    a = 1; b = 0; #10; // OR
    a = 1; b = 1; #10; // OR

    select = 2'b10; // Testando XOR
    a = 0; b = 0; #10; // XOR
    a = 0; b = 1; #10; // XOR
    a = 1; b = 0; #10; // XOR
    a = 1; b = 1; #10; // XOR

    select = 2'b11; // Testando XNOR
    a = 0; b = 0; #10; // XNOR
    a = 0; b = 1; #10; // XNOR
    a = 1; b = 0; #10; // XNOR
    a = 1; b = 1; #10; // XNOR
end

endmodule
