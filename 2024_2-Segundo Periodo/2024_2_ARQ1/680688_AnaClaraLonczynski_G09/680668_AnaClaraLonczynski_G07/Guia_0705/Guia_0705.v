/*
 Guia_0705.v
 0860668 - Ana Clara Lonczynski
*/

module Guia_0705 (output selected_out, input a, input b, input [2:0] select, input neg_b);

// Definindo o valor de 'b' dependendo da chave de negação
wire b_neg;
assign b_neg = neg_b ? ~b : b; // Se neg_b for 1, inverte o valor de b, caso contrário, mantém igual

// Definindo as operações lógicas
wire not_result, and_result, nand_result, or_result, nor_result, xor_result, xnor_result;

// Operações lógicas
assign not_result = ~a;            // Operação NOT (somente com 'a')
assign and_result = a & b_neg;     // Operação AND
assign nand_result = ~(a & b_neg); // Operação NAND
assign or_result = a | b_neg;      // Operação OR
assign nor_result = ~(a | b_neg);  // Operação NOR
assign xor_result = a ^ b_neg;     // Operação XOR
assign xnor_result = ~(a ^ b_neg); // Operação XNOR

// Fios intermediários para cada operação
wire [6:0] results;
assign results[0] = not_result;
assign results[1] = and_result;
assign results[2] = nand_result;
assign results[3] = or_result;
assign results[4] = nor_result;
assign results[5] = xor_result;
assign results[6] = xnor_result;

// Saída selecionada com base na chave de seleção (3 bits para 7 operações)
assign selected_out = results[select];

endmodule

// Módulo de teste
module test_Guia_0705;

reg a, b, neg_b;
reg [2:0] select;
wire selected_out;

// Instanciando o módulo principal
Guia_0705 LU (selected_out, a, b, select, neg_b);

// Início dos testes
initial begin
    $display("Guia_0705 - Testes da Unidade Lógica");
    $display("a b neg_b select | Selected Out");
    $monitor("%b %b   %b    %3b   |     %b", a, b, neg_b, select, selected_out);

    // Testes com combinações de entradas e chaves de seleção
    a = 0; b = 0; neg_b = 0; select = 3'b000; #10; // NOT
    a = 0; b = 1; neg_b = 0; select = 3'b000; #10; // NOT
    a = 1; b = 0; neg_b = 0; select = 3'b000; #10; // NOT
    a = 1; b = 1; neg_b = 0; select = 3'b000; #10; // NOT

    select = 3'b001; // Testando AND
    a = 0; b = 0; neg_b = 0; #10; // AND
    a = 0; b = 1; neg_b = 0; #10; // AND
    a = 1; b = 0; neg_b = 0; #10; // AND
    a = 1; b = 1; neg_b = 0; #10; // AND

    select = 3'b010; // Testando NAND
    a = 0; b = 0; neg_b = 0; #10; // NAND
    a = 0; b = 1; neg_b = 0; #10; // NAND
    a = 1; b = 0; neg_b = 0; #10; // NAND
    a = 1; b = 1; neg_b = 0; #10; // NAND

    select = 3'b011; // Testando OR
    a = 0; b = 0; neg_b = 0; #10; // OR
    a = 0; b = 1; neg_b = 0; #10; // OR
    a = 1; b = 0; neg_b = 0; #10; // OR
    a = 1; b = 1; neg_b = 0; #10; // OR

    select = 3'b100; // Testando NOR
    a = 0; b = 0; neg_b = 0; #10; // NOR
    a = 0; b = 1; neg_b = 0; #10; // NOR
    a = 1; b = 0; neg_b = 0; #10; // NOR
    a = 1; b = 1; neg_b = 0; #10; // NOR

    select = 3'b101; // Testando XOR
    a = 0; b = 0; neg_b = 0; #10; // XOR
    a = 0; b = 1; neg_b = 0; #10; // XOR
    a = 1; b = 0; neg_b = 0; #10; // XOR
    a = 1; b = 1; neg_b = 0; #10; // XOR

    select = 3'b110; // Testando XNOR
    a = 0; b = 0; neg_b = 0; #10; // XNOR
    a = 0; b = 1; neg_b = 0; #10; // XNOR
    a = 1; b = 0; neg_b = 0; #10; // XNOR
    a = 1; b = 1; neg_b = 0; #10; // XNOR

    // Teste com neg_b ativado
    a = 1; b = 1; neg_b = 1; select = 3'b001; #10; // AND com negação de b
    a = 1; b = 0; neg_b = 1; select = 3'b011; #10; // OR com negação de b
end

endmodule
