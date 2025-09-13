/*
 Guia_0103.v
 0860668 - Ana Clara Lonczynski
*/
module Guia_0103;
// define data
  integer x = 61, y = 53, z = 77, w = 153, k = 753; // decimal
  reg [7:0] a = 0, b = 0, c = 0, d = 0, e =0; // binary
// actions
 initial
 begin : main
 $display ("");
 $display ( "Guia_0103 - Tests" );
 $display ("");
 $display ( "a.) 61(10) = X(4)" );
 $display ( "Decimal = %d" , x );
 a = x;
 $display ( "a = %B (2) = %o (8) = %x (16) = %X (16)", a, a, a, a );

$display ("");
$display ( "b.) 53(10) = X(8)" );
$display ( "Decimal = %d" , y );
b = y;
 $display ( "b = %B (2) = %o (8) = %x (16) = %X (16)", b, b, b, b );

$display ("");
$display ( "c.) 77(10) = X(16)" );
$display ( "Decimal = %d" , z );
c = z;
 $display ( "c = %B (2) = %o (8) = %x (16) = %X (16)", c, c, c, c );

$display ("");
$display ( "d.) 153(10) = X(16)" );
$display ( "Decimal = %d" , w );
d = w;
   $display ( "d = %B (2) = %o (8) = %x (16) = %X (16)", d, d, d, d );

$display ("");
$display ( "e.) 753(10) = X(16)" );
$display ( "Decimal = %d" , k );
e = k;
   $display ( "e = %B (2) = %o (8) = %x (16) = %X (16)", e, e, e, e );
 end // main
endmodule // Guia_0103

/*Guia_0103 - Tests
a.) 61(10) = X(4)
Decimal =          61
a = 00111101 (2) = 075 (8) = 3d (16) = 3d (16)

b.) 53(10) = X(8)
Decimal =          53
b = 00110101 (2) = 065 (8) = 35 (16) = 35 (16)

c.) 77(10) = X(16)
Decimal =          77
c = 01001101 (2) = 115 (8) = 4d (16) = 4d (16)

d.) 153(10) = X(16)
Decimal =         153
d = 10011001 (2) = 231 (8) = 99 (16) = 99 (16)

e.) 753(10) = X(16)
Decimal =         753
e = 11110001 (2) = 361 (8) = f1 (16) = f1 (16)*/