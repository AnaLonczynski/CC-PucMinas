/*
 Q_03a
 0860668 - Ana Clara Lonczynski
 */

module expressao_a (
  input a,
  input b,
  input c,
  output out
);
  // (~a | b) & (b | ~c)
  assign out = (~a | b) & (b | ~c);
endmodule

module testbench;
  reg a; 
  reg b;
  reg c;
  wire out;

  expressao_a uut (
      .a(a),
      .b(b),
      .c(c),
      .out(out)
  );

  initial begin
    $display("Questao 3.) a.)");
      $display("a b c | out");
      $display("-----------");
      // Gera combinações de 0 a 7
      for (integer i = 0; i < 8; i = i + 1) begin
          {a, b, c} = i; // Atribui o valor de i às entradas
          #1;
          $display("%b %b %b | %b", a, b, c, out);
      end
      $finish; 
  end
endmodule
