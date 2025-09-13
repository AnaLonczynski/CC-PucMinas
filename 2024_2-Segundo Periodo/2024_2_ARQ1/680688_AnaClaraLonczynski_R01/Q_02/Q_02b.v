/*
 Q_02b
 0860668 - Ana Clara Lonczynski
 */
module mux_example(
    input wire a,
    input wire b,
    input wire c,
    output wire y
);
    // MUX interno
    wire mux_ab;
    assign mux_ab = a ? ~a : b; // MUX(a, not(a), b)

    // MUX principal
    assign y = c ? ~c : mux_ab; // MUX(c, not(c), mux(a, not(a), b))
endmodule
module tb_mux_example;
    reg a;
    reg b;
    reg c;
    wire y;
    mux_example mux_inst (
        .a(a),
        .b(b),
        .c(c),
        .y(y)
    );

    initial begin
      $display("Exercicio 2.) b.)");
        $display("a\tb\tc\ty");
        $display("---------------");

        a = 0; b = 0; c = 0; #1;
        $display("%b\t%b\t%b\t%b", a, b, c, y);
        a = 0; b = 0; c = 1; #1;
        $display("%b\t%b\t%b\t%b", a, b, c, y);
        a = 0; b = 1; c = 0; #1;
        $display("%b\t%b\t%b\t%b", a, b, c, y);
        a = 0; b = 1; c = 1; #1;
        $display("%b\t%b\t%b\t%b", a, b, c, y);
        a = 1; b = 0; c = 0; #1;
        $display("%b\t%b\t%b\t%b", a, b, c, y);
        a = 1; b = 0; c = 1; #1;
        $display("%b\t%b\t%b\t%b", a, b, c, y);
        a = 1; b = 1; c = 0; #1;
        $display("%b\t%b\t%b\t%b", a, b, c, y);
        a = 1; b = 1; c = 1; #1;
      $display("%b\t%b\t%b\t%b", a, b, c, y);
        $finish;
    end
endmodule
