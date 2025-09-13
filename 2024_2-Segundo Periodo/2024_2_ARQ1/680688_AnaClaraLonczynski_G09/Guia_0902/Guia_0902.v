/*
 Guia_0902.v
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
endmodule 

// -- Pulse generator 1
module pulse1 ( signal, clock );
input clock;
output signal;
reg signal;
always @ ( posedge clock )
 begin
 signal = 1'b1;
 #4 signal = 1'b0; // Pulse duration: 4 time units
 #4 signal = 1'b1;
 #4 signal = 1'b0;
 #4 signal = 1'b1;
 #4 signal = 1'b0;
 end
endmodule // pulse1

// -- Pulse generator 2
module pulse2 ( signal, clock );
input clock;
output signal;
reg signal;
always @ ( posedge clock )
 begin
 signal = 1'b1;
 #5 signal = 1'b0; // Pulse duration: 5 time units
 end
endmodule // pulse2

// -- Pulse generator 3
module pulse3 ( signal, clock );
input clock;
output signal;
reg signal;
always @ ( negedge clock )
 begin
 signal = 1'b1;
 #15 signal = 1'b0; // Pulse duration: 15 time units
 #15 signal = 1'b1;
 end
endmodule // pulse3

// -- Pulse generator 4
module pulse4 ( signal, clock );
input clock;
output signal;
reg signal;
always @ ( negedge clock )
 begin
 signal = 1'b1;
 #20 signal = 1'b0; // Pulse duration: 20 time units
 #20 signal = 1'b1;
 #20 signal = 1'b0;
 end
endmodule // pulse4

// -- Testbench: Guia_0902
module Guia_0902;
wire clock;
clock clk ( clock );
wire p1, p2, p3, p4;
pulse1 pls1 ( p1, clock );
pulse2 pls2 ( p2, clock );
pulse3 pls3 ( p3, clock );
pulse4 pls4 ( p4, clock );

initial begin
 $display("Time | Clock | Pulse1 | Pulse2 | Pulse3 | Pulse4");
 $monitor("%0t | %b | %b | %b | %b | %b", $time, clock, p1, p2, p3, p4);
end

initial begin
 #60 $finish; // Duração total da simulação
end

endmodule // Guia_0902

/*
Resultados Esperados
*/
/*
Time | Clock | Pulse1 | Pulse2 | Pulse3 | Pulse4
0 | 0 | x | x | x | x
12 | 1 | 1 | 1 | x | x
16 | 1 | 0 | 1 | x | x
17 | 1 | 0 | 0 | x | x
20 | 1 | 1 | 0 | x | x
24 | 0 | 0 | 0 | 1 | 1
28 | 0 | 1 | 0 | 1 | 1
32 | 0 | 0 | 0 | 1 | 1
36 | 1 | 1 | 1 | 1 | 1
39 | 1 | 1 | 1 | 0 | 1
40 | 1 | 0 | 1 | 0 | 1
41 | 1 | 0 | 0 | 0 | 1
44 | 1 | 1 | 0 | 0 | 0
48 | 0 | 0 | 0 | 0 | 0
52 | 0 | 1 | 0 | 0 | 0
54 | 0 | 1 | 0 | 1 | 0
56 | 0 | 0 | 0 | 1 | 0
60 | 1 | 1 | 1 | 1 | 0
/*