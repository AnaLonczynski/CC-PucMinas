/*
 Q_02a
 0860668 - Ana Clara Lonczynski
*/
module mux_example(
    input wire a,
    input wire c,
    output wire y
);
    assign y = c ? ~a : a;
endmodule

module tb_mux_example;
    reg a;
    reg c;
    wire y;
    mux_example mux_inst (
        .a(a),
        .c(c),
        .y(y)
    );

    initial begin
      $display("Exercicio 2.) a.)");
        $display("a\tc\ty");
        $display("------------");
        a = 0; c = 0; #1; 
        $display("%b\t%b\t%b", a, c, y);

        a = 0; c = 1; #1; 
        $display("%b\t%b\t%b", a, c, y);

        a = 1; c = 0; #1;
        $display("%b\t%b\t%b", a, c, y);

        a = 1; c = 1; #1; 
        $display("%b\t%b\t%b", a, c, y);
        $finish;
    end
endmodule

