/*
 Guia_0901.v
 0860668 - Ana Clara Lonczynski
 *

// -- test clock generator (2)
module clock ( output clk );
reg clk;
initial
 begin
 clk = 1'b0;
 end
always
 begin
 #12 clk = ~clk;
 end
endmodule

// -- pulse generator
module pulse ( signal, clock );
input clock;
output signal;
reg signal;
always @ ( clock )
 begin
 signal = 1'b1;
 #3 signal = 1'b0;
 #3 signal = 1'b1;
 #3 signal = 1'b0;
 end
endmodule // pulse

module trigger ( signal, on, clock );
input on, clock;
output signal;
reg signal;
always @ ( posedge clock & on )
 begin
 #60 signal = 1'b1;
 #60 signal = 1'b0;
 end
endmodule // trigger

// -- Testbench: Guia_0901
module Guia_0901;
wire clock;
clock clk ( clock );
reg p;
wire p1, t1;

// Instanciando os módulos pulse e trigger
pulse pulse1 ( p1, clock );
trigger trigger1 ( t1, p, clock );

initial begin
 p = 1'b0;
end

  initial begin
   // Exibindo os resultados no terminal
   $display("Guia_0901 - Testes ");
   $display("Time: %0d | Clock: %b | Pulse: %b | Trigger: %b | p: %b", 
            $time, clock, p1, t1, p);

   // Teste do gatilho com ativação/desativação de 'p'
   #060 p = 1'b1;
   #120 $finish;
  end

  // Exibindo os resultados no terminal em cada borda de subida do clock
  always @ (posedge clock) begin
      $display("Time: %0d | Clock: %b | Pulse: %b | Trigger: %b | p: %b", 
                $time, clock, p1, t1, p);
  end

endmodule // Guia_0901

/*
Resultados Esperados
*/
/*
Guia_0901 - Testes 
Time: 0 | Clock: 0 | Pulse: x | Trigger: x | p: 0
Time: 12 | Clock: 1 | Pulse: 0 | Trigger: x | p: 0
Time: 36 | Clock: 1 | Pulse: 0 | Trigger: x | p: 0
Time: 60 | Clock: 1 | Pulse: 0 | Trigger: x | p: 1
Time: 84 | Clock: 1 | Pulse: 0 | Trigger: x | p: 1
Time: 108 | Clock: 1 | Pulse: 0 | Trigger: x | p: 1
Time: 132 | Clock: 1 | Pulse: 0 | Trigger: 1 | p: 1
Time: 156 | Clock: 1 | Pulse: 0 | Trigger: 1 | p: 1
Time: 180 | Clock: 1 | Pulse: 0 | Trigger: 0 | p: 1
*/