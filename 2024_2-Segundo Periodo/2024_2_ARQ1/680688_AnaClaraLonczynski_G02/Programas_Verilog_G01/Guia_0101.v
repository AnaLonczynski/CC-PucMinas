/*
 Guia_0101.v
 0860668 - Ana Clara Lonczynski
*/
module Guia_0101;
// define data
 integer x = 26, y = 53, z = 713, w = 213, k = 365; // decimal
  reg [7:0] a = 0, b = 0, c = 0, d = 0, e = 0; // binary (bits - little endian)
// actions
 initial
 begin : main
 $display ( "Guia_0101 - Tests" );
 $display ("");
 $display ( "a.) 26(10) = X(2)" );
 $display ( "x = %d" , x );
 $display ( "a = %8b", a );
 a = x;
 $display ( "a = %8b", a );

 $display ("");
 $display ( "b.) 53(10) = X(2)" );
 $display ( "y = %d" , y );
 $display ( "b = %8b", b );
 b = y;
 $display ( "b = %8b", b );

   $display ("");
 $display ( "c.) 713(10) = X(2)" );
 $display ( "z = %d" , z );
 $display ( "c = %8b", c );
 c = z;
 $display ( "c = %8b", c );

   $display ("");
 $display ( "d.) 213(10) = X(2)" );
 $display ( "w = %d" , w );
 $display ( "d = %8b", d );
 d = w;
 $display ( "d = %8b", d );

   $display ("");
 $display ( "e.) 365(10) = X(2)" );
 $display ( "k = %d" , k );
 $display ( "e = %8b", e );
 e = k;
 $display ( "e = %8b", e );
 end // main
endmodule // Guia_0101

/* SAIDA: 
Guia_0101 - Tests

a.) 26(10) = X(2)
x =          26
a = 00000000
a = 00011010

b.) 53(10) = X(2)
y =          53
b = 00000000
b = 00110101

c.) 713(10) = X(2)
z =         713
c = 00000000
c = 11001001

d.) 213(10) = X(2)
w =         213
d = 00000000
d = 11010101

e.) 365(10) = X(2)
k =         365
e = 00000000
e = 01101101
/*