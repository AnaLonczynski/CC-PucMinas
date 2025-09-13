/*
 Guia_0903.v
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
 #12 signal = 1'b0; // Pulse duration: 12 time units (1/3 of the clock period)
 #12 signal = 1'b1; // Pulse duration: 12 time units (1/3 of the clock period)
 end
endmodule // pulse

// -- Testbench: Guia_0903
module Guia_0903;
wire clock;
clock clk ( clock ); 
wire p;

pulse pulse1 ( p, clock );

initial begin
 $display("Time | Clock | Pulse");
 $monitor("%0t | %b | %b", $time, clock, p);
end

initial begin
 #60 $finish; // Duração total da simulação
end

endmodule // Guia_0903

/*
Resultados Esperados
*/
/*
Time | Clock | Pulse
0 | 0 | x
12 | 1 | 1
24 | 0 | 0
36 | 1 | 1
48 | 0 | 1
60 | 1 | 1
/*