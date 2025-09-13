/*
 Guia_0906.v
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

// -- Pulse generator with width of 5 time units
module pulse ( signal, clk );
input clk;
output signal;
reg signal;

always @ ( negedge clk ) 
 begin
 signal = 1'b1; 
 #5 signal = 1'b0; 
 end
endmodule // pulse

module Guia_0906;
wire clk;
clock clk_gen ( clk ); 
wire p;

pulse pulse1 ( p, clk );

initial begin
 $display("Time | Clock | Pulse");
 $monitor("%0t | %b | %b", $time, clk, p);
end

initial begin
 #60 $finish; // Total simulation time
end

endmodule // Guia_0906

/*
Resultados Esperados
*/
/*
Time | Clock | Pulse
0 | 0 | x
12 | 1 | x
24 | 0 | 1
29 | 0 | 0
36 | 1 | 0
48 | 0 | 1
53 | 0 | 0
60 | 1 | 0
*/