/*
 Guia_0703.v
 0860668 - Ana Clara Lonczynski
*/

module Guia_0703 (output selected_out, input a, input b, input sel_group, input sel_gate);

// Definindo as operações lógicas
wire and_result, nand_result, or_result, nor_result;

// Operações lógicas para cada grupo
assign and_result = a & b;    // Operação AND
assign nand_result = ~(a & b); // Operação NAND
assign or_result = a | b;     // Operação OR
assign nor_result = ~(a | b);  // Operação NOR

// Fios intermediários para as seleções de portas
wire selected_and_nand, selected_or_nor;

// Seleção entre AND e NAND
assign selected_and_nand = (sel_gate & and_result) | (~sel_gate & nand_result);

// Seleção entre OR e NOR
assign selected_or_nor = (sel_gate & or_result) | (~sel_gate & nor_result);

// Seleção final entre os grupos AND/NAND ou OR/NOR
assign selected_out = (sel_group & selected_or_nor) | (~sel_group & selected_and_nand);

endmodule

// Módulo de teste
module test_Guia_0703;

reg a, b, sel_group, sel_gate;
wire selected_out;

// Instanciando o módulo principal
Guia_0703 LU (selected_out, a, b, sel_group, sel_gate);

// Início dos testes
initial begin
    $display("Guia_0703 - Testes da Unidade Lógica");
    $display("a b sel_group sel_gate | Selected Out");
    $monitor("%b %b      %b        %b      |    %b", a, b, sel_group, sel_gate, selected_out);

    // Testes com combinações de entradas e chaves de seleção
    a = 0; b = 0; sel_group = 0; sel_gate = 0; #10; // NAND
    a = 0; b = 1; sel_group = 0; sel_gate = 0; #10; // NAND
    a = 1; b = 0; sel_group = 0; sel_gate = 0; #10; // NAND
    a = 1; b = 1; sel_group = 0; sel_gate = 0; #10; // NAND

    sel_gate = 1; // Testando AND
    a = 0; b = 0; sel_group = 0; #10; // AND
    a = 0; b = 1; sel_group = 0; #10; // AND
    a = 1; b = 0; sel_group = 0; #10; // AND
    a = 1; b = 1; sel_group = 0; #10; // AND

    sel_group = 1; sel_gate = 0; // Testando NOR
    a = 0; b = 0; #10; // NOR
    a = 0; b = 1; #10; // NOR
    a = 1; b = 0; #10; // NOR
    a = 1; b = 1; #10; // NOR

    sel_gate = 1; // Testando OR
    a = 0; b = 0; #10; // OR
    a = 0; b = 1; #10; // OR
    a = 1; b = 0; #10; // OR
    a = 1; b = 1; #10; // OR
end

endmodule
