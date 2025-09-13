/*
 Q_03b
 0860668 - Ana Clara Lonczynski
 */
module expressao_b (
    input x,
    input y,
    output out
);
    //(x'.y)' . (x'.y')'
    assign out = (~(x & y)) & (~((~x) & (~y)));
endmodule

module testbench;
    reg x;
    reg y;
    wire out;
    expressao_b uut (
        .x(x),
        .y(y),
        .out(out)
    );

    initial begin
      $display("Questao 3.) b.)");
        $display("x y | out");
        $display("---------");
        // Gera combinações de 0 a 3
        for (integer i = 0; i < 4; i = i + 1) begin
            {x, y} = i; // Atribui o valor de i às entradas
            #1;
            $display("%b %b | %b", x, y, out);
        end
        $finish; 
    end
endmodule
