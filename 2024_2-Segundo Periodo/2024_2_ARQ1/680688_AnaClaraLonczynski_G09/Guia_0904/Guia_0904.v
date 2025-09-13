/*
 Guia_0904.v
 0860668 - Ana Clara Lonczynski
 *

// -- Clock generator module
module clock ( output clk );
reg clk;
initial
 begin
 clk = 1'b0;
 end
always
 begin
 #12 clk = ~clk; // Clock period of 24 time units
 end
endmodule // clock

// -- Pulse generator
module pulse ( signal, clock );
input clock;
output signal;
reg signal;
always @ ( posedge clock )
 begin
 signal = 1'b1;
 #3 signal = 1'b0; // Pulse duration: 3 time units (1/4 of the clock period)
 #3 signal = 1'b1; // Pulse duration: 3 time units (1/4 of the clock period)
 #3 signal = 1'b0; // Another pulse duration: 3 time units
 #3 signal = 1'b1; // Another pulse duration: 3 time units
 end
endmodule // pulse

// -- Testbench: Guia_0904
module Guia_0904;
wire clock;
clock clk ( clock ); 
wire p;

// Instanciando o módulo de pulso
pulse pulse1 ( p, clock );

initial begin
 $display("Time | Clock | Pulse");
 $monitor("%0t | %b | %b", $time, clock, p);
end

initial begin
 #60 $finish; // Duração total da simulação
end

endmodule // Guia_0904

/*
Resultados Esperados
*/
/*
Time | Clock | Pulse
0 | 0 | x
12 | 1 | 1
15 | 1 | 0
18 | 1 | 1
21 | 1 | 0
24 | 0 | 1
36 | 1 | 1
39 | 1 | 0
42 | 1 | 1
45 | 1 | 0
48 | 0 | 1
60 | 1 | 1
/*