/*
 Guia_0203.v
 680668 - Ana Clara Lonczynski
*/
module Guia_0203;
// define data
  integer q [3:0];
  reg [7:0] a = 8'b0111100, b = 8'b10100100, c = 8'b10011000, d = 8'b111011, e = 8'b10010000 ;// binary
// actions
 initial
 begin : main
   $display ( "\nGuia_0203 - Tests" );
   $display ("\na.) 0,011110(2) = X(4)");
   $display ( "Binário = 0.%8b", a );
   q[3] = a[7:6];
   q[2] = a[5:4];
   q[1] = a[3:2];
   q[0] = a[1:0];
   $display ( "Grupos = 0.%2b %2b %2b %2b (2)", a[7:6],a[5:4],a[3:2],a[1:0] );
   $display ( "Quaternário = 0.%2d %2d %2d %2d (4)", q[3] ,q[2] ,q[1] ,q[0] );

   $display ("\nb.) 0,101001(2) = X(8)");
   $display ( "Binário = 0.%8b", b );
   $display ( "Octal= 0.%o%o%o (8) ", b[7:6],b[5:3],b[2:0] );

   $display ("\nc.) 0,100110(2) = X(16)");
   $display ( "Binário = 0.%8b", c );
   $display ( "Hexadecimal = 0.%x%x (16)", c[7:4], c[3:0] );

   $display ("\nd.) 1,111011(2) = X(8)");
   $display ( "Binário = 1.%8b", d );
   $display ( "Octal= 1.%o%o%o (8) ", d[7:6],d[5:3],d[2:0] );

   $display ("\ne.) 1101,1001(2) = X(16)");
   $display ( "Binário = 1101.%8b", e );
   $display ( "Hexadecimal = D.%x%x (16)", e[7:4], e[3:0] );
 end // main
endmodule // Guia_0203
/*SAIDA:
Guia_0203 - Tests

a.) 0,011110(2) = X(4)
Binário = 0.00111100
Grupos = 0.00 11 11 00 (2)
Quaternário = 0. 0  3  3  0 (4)

b.) 0,101001(2) = X(8)
Binário = 0.10100100
Octal= 0.244 (8) 

c.) 0,100110(2) = X(16)
Binário = 0.10011000
Hexadecimal = 0.98 (16)

d.) 1,111011(2) = X(8)
Binário = 1.00111011
Octal= 1.073 (8) 
*/