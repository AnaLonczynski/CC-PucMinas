/*
 Guia_0706.v
 0860668 - Ana Clara Lonczynski
*/

module Guia_0706 (output result, input [2:0] a, input [2:0] b, input select);

// Fios intermediários para as operações XOR (diferente) e XNOR (igual)
wire [2:0] xor_result;
wire [2:0] xnor_result;

// Operações XOR e XNOR
assign xor_result = a ^ b;    // Diferença (diferente)
assign xnor_result = ~(a ^ b); // Igualdade (igual)

// Comparação final - XOR (1) ou XNOR (0), baseado na seleção
assign result = (select) ? |xor_result : &xnor_result;

endmodule

// Módulo de teste
module test_Guia_0706;

reg [2:0] a, b;
reg select;
wire result;

// Instanciando o módulo principal
Guia_0706 comparator (result, a, b, select);

// Início dos testes
initial begin
    $display("Guia_0706 - Testes da Unidade Lógica Comparadora");
    $display("a   b   select | Result");
    $monitor("%b %b    %b     |   %b", a, b, select, result);

    // Testando igualdade (select = 0, usando XNOR)
    a = 3'b000; b = 3'b000; select = 0; #10; // Igual
    a = 3'b101; b = 3'b101; select = 0; #10; // Igual
    a = 3'b111; b = 3'b111; select = 0; #10; // Igual
    a = 3'b110; b = 3'b011; select = 0; #10; // Diferente

    // Testando desigualdade (select = 1, usando XOR)
    a = 3'b000; b = 3'b000; select = 1; #10; // Igual
    a = 3'b101; b = 3'b111; select = 1; #10; // Diferente
    a = 3'b001; b = 3'b001; select = 1; #10; // Igual
    a = 3'b011; b = 3'b100; select = 1; #10; // Diferente
end

endmodule
