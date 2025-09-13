/*
Guia_0104.v
0860668 - Ana Clara Lonczynski
*/
module Guia_0104;
// define data
 integer x = 13; // decimal
 reg [7:0] a = 8'b10100, b = 8'b11010, c = 8'b100111, d = 8'b100101, e = 8'b101101; // binary
// actions
 initial
 begin : main
$display ("");
$display ( "Guia_0104 - Tests" );

$display ("");
$display ( "a.) 10100(2) = X(4)" );
$display ( "a = %B (2) = %o (8) = %x (16) = %X (16)", a, a, a, a );

$display ("");
$display ( "b.) 11010(2) = X(8)" );
$display ( "b = %B (2) = %o (8) = %x (16) = %X (16)", b, b, b, b );

$display ("");
$display ( "c.) 100111(2) = X(16)" );
$display ( "c = %B (2) = %o (8) = %x (16) = %X (16)", c, c, c, c );

$display ("");
$display ( "d.) 100101(2) = X(8)" );
$display ( "d = %B (2) = %o (8) = %x (16) = %X (16)", d, d, d, d );

$display ("");
$display ( "e.) 101101(2) = X(4)" );
$display ( "e = %B (2) = %o (8) = %x (16) = %X (16)", e, e, e, e );

 end // main
endmodule // Guia_0104

/*
Guia_0104 - Tests

a.) 10100(2) = X(4)
a = 00010100 (2) = 024 (8) = 14 (16) = 14 (16)

b.) 11010(2) = X(8)
b = 00011010 (2) = 032 (8) = 1a (16) = 1a (16)

c.) 100111(2) = X(16)
c = 00100111 (2) = 047 (8) = 27 (16) = 27 (16)

d.) 100101(2) = X(8)
d = 00100101 (2) = 045 (8) = 25 (16) = 25 (16)

e.) 101101(2) = X(4)
e = 00101101 (2) = 055 (8) = 2d (16) = 2d (16)
*/




