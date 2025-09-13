/*
 Guia_0102.v
 0860668 - Ana Clara Lonczynski
*/
module Guia_0102;
// define data
 integer x = 0, y = 0, z = 0, w = 0, k = 0; // decimal
  reg [7:0] a = 8'b10101, b =  8'b11011, c = 8'b10010, d = 8'b101011, e = 8'b110111; // binary (bits - little endian)
// actions
 initial
 begin : main

   $display ("");
   $display ( "Guia_0102 - Tests" );
   $display ("");
   $display ( "a.) 10101(2) = X(10)" );
   $display ( "Binario = %8b", a );
    x = a;
   $display ( "Decimal = %d", x );

   $display ("");
   $display ( "b.) 11011(2) = X(10)" );
   $display ( "Binario = %8b", b );
   y = b;
   $display ( "Decimal = %d", y );

   $display ("");
   $display ( "c.) 10010(2) = X(10)" );
   $display ( "Binario = %8b", c );
   z = c;
   $display ( "Decimal = %d", x );

   $display ("");
   $display ( "d.) 101011(2) = X(10)" );
   $display ( "Binario = %8b", d );
   w = d;
   $display ( "Decimal = %d", w );

   $display ("");
   $display ( "e.) 110111(2) = X(10)" );
   $display ( "Binario = %8b", e );
   k = e;
   $display ( "Decimal = %d", k );

 end // main
endmodule // Guia_010


/*SAIDAS:
Guia_0102 - Tests

a.) 10101(2) = X(10)
Binario = 00010101
Decimal =          21

b.) 11011(2) = X(10)
Binario = 00011011
Decimal =          27

c.) 10010(2) = X(10)
Binario = 00010010
Decimal =          21

d.) 101011(2) = X(10)
Binario = 00101011
Decimal =          43

e.) 110111(2) = X(10)
Binario = 00110111
Decimal =          55*/