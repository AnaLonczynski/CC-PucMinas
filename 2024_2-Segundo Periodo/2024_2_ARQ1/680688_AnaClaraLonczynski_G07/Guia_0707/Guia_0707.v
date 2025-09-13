/*
 Guia_0707.v
 0860668 - Ana Clara Lonczynski
*/

module Guia_0707 (output result, input [2:0] a, input [2:0] b, input select);

// Fios intermediários para os resultados de comparação bit a bit
wire [2:0] greater, less;
wire a_eq_b, a_gt_b, a_lt_b;

// Comparação bit a bit (a > b e a < b)
assign greater[2] = a[2] & ~b[2]; // a2 > b2
assign greater[1] = (~a[2] & ~b[2]) & (a[1] & ~b[1]); // a1 > b1
assign greater[0] = (~a[2] & ~b[2]) & (~a[1] & ~b[1]) & (a[0] & ~b[0]); // a0 > b0

assign less[2] = ~a[2] & b[2]; // a2 < b2
assign less[1] = (~a[2] & ~b[2]) & (~a[1] & b[1]); // a1 < b1
assign less[0] = (~a[2] & ~b[2]) & (~a[1] & ~b[1]) & (~a[0] & b[0]); // a0 < b0

// Resultado final para a > b e a < b
assign a_gt_b = greater[2] | greater[1] | greater[0];
assign a_lt_b = less[2] | less[1] | less[0];

// Seleção: 0 para menor, 1 para maior
assign result = (select) ? a_gt_b : a_lt_b;

endmodule

// Módulo de teste
module test_Guia_0707;

reg [2:0] a, b;
reg select;
wire result;

// Instanciando o módulo principal
Guia_0707 comparator (result, a, b, select);

// Início dos testes
initial begin
    $display("Guia_0707 - Testes da Unidade Lógica Comparadora");
    $display("a   b   select | Result");
    $monitor("%b %b    %b     |   %b", a, b, select, result);

    // Testando menor (select = 0)
    a = 3'b000; b = 3'b001; select = 0; #10; // a < b
    a = 3'b010; b = 3'b100; select = 0; #10; // a < b
    a = 3'b011; b = 3'b011; select = 0; #10; // a = b (resulta falso para a < b)
    a = 3'b111; b = 3'b110; select = 0; #10; // a > b (resulta falso para a < b)

    // Testando maior (select = 1)
    a = 3'b100; b = 3'b010; select = 1; #10; // a > b
    a = 3'b011; b = 3'b001; select = 1; #10; // a > b
    a = 3'b000; b = 3'b000; select = 1; #10; // a = b (resulta falso para a > b)
    a = 3'b101; b = 3'b110; select = 1; #10; // a < b (resulta falso para a > b)
end

endmodule
