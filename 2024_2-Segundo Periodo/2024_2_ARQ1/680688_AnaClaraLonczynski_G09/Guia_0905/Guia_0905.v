/*
 Guia_0905.v
 0860668 - Ana Clara Lonczynski
 */

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

// -- Pulse generator with width of 4 time units
module pulse ( signal, clk );
input clk;
output signal;
reg signal;

always @ ( posedge clk )
 begin
 signal = 1'b1; // Set the signal high at the rising edge of the clock
 #4 signal = 1'b0; // Set the signal low after 4 time units
 end
endmodule // pulse

// -- Testbench: Guia_0905
module Guia_0905;
wire clk;
clock clk_gen ( clk ); 
wire p;

pulse pulse1 ( p, clk );

initial begin
 $display("Time | Clock | Pulse");
 $monitor("%0t | %b | %b", $time, clk, p);
end

initial begin
 #60 $finish; // Duração total da simulação
end

endmodule // Guia_0905


/*
Resultados Esperados
*/
/*
Time | Clock | Pulse
0 | 0 | x
12 | 1 | 1
16 | 1 | 0
24 | 0 | 0
36 | 1 | 1
40 | 1 | 0
48 | 0 | 0
60 | 1 | 1
*/