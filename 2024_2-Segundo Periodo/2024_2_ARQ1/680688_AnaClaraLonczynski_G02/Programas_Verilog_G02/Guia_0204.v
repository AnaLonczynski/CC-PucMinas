/*
 Guia_0204.v
 680668 - Ana Clara Lonczynski
*/
module Guia_0204;
// define data
  real xa = 57, xb = 978, xc = 489, xd = 229, xe = 2654, xee=15; // decimal
  reg [7:0] b = 8'b1010_0000, ba = 0, bb = 0, bd = 0; // binary
  reg [8:0] bc = 0 ; //binario com um bit a mais
  reg [11:0] be = 0;
  integer q [3:0];
  integer p [5:0];
// actions
 initial
 begin : main
  $display ( "\nGuia_0204 - Tests" );
  $display ("\na.) 0,321(4) = X(2)");
   ba = xa;
   q[2] = ba[5:4];
   q[1] = ba[3:2];
   
   q[0] = ba[1:0];
   $display ( "Quaternario = 0. %2d %2d %2d (4)",q[2] ,q[1] ,q[0]);
   $display ( "Binário = 0. %2b %2b %2b (2)",ba[5:4],ba[3:2],ba[1:0]);
   
  $display ("\nb.) 0,3D2(16) = X(4)");
  $display ( "Hexadecimal = 0.%x", xb );
   bb = xb;
   q[3] = bb[7:6];
   q[2] = bb[5:4];
   q[1] = bb[3:2];
   q[0] = bb[1:0];
   $display ( "Quaternario = 0.%2d%2d%2d%2d (4)",q[3], q[2] ,q[1] ,q[0]);

   $display ("\nc.) 0,751(8) = X(2)");
   bc = xc;
   $display ( "Octal= 0.%o%o%o (8) ", bc[8:6],bc[5:3],bc[2:0] );
   $display ( "Binário = 0.%8b", bc );
   
   $display ("\nd.) 7,345(8) = X(4)");
   bd = xd;
   $display ( "Octal= 7.%o%o%o (8) ", bd[7:6],bd[5:3],bd[2:0] );
   q[3] = bd[7:6];
   q[2] = bd[5:4];
   q[1] = bd[3:2];
   q[0] = bd[1:0];
   $display ( "Quaternario = 13.%2d%2d%2d%2d (4)",q[3], q[2] ,q[1] ,q[0]);
   
   $display ("\ne.) F,A5E(16) = X(4)"); 
   $display ( "Hexadecimal = %x.%x", xee, xe );
   be = xe;
   $display ( "b = 0.%8b", be );
   p[5] = be[11:10];
   p[4] = be[9:8];
   p[3] = be[7:6];
   p[2] = be[5:4];
   p[1] = be[3:2];
   p[0] = be[1:0];
   $display ( "Quaternario = 33.%2d %2d %2d %2d %2d %2d (4)", p[5], p[4], p[3], p[2], p[1], p[0]);
 end // main
endmodule // Guia_0204

/* OBS: Nao consegui resolver sem começar com o valor decimal

SAÍDA: 
Guia_0204 - Tests

a.) 0,321(4) = X(2)
Quaternario = 0.  3  2  1 (4)
Binário = 0. 11 10 01 (2)

b.) 0,3D2(16) = X(4)
Hexadecimal = 0.3d2
Quaternario = 0. 3 1 0 2 (4)

c.) 0,751(8) = X(2)
Octal= 0.751 (8) 
Binário = 0.111101001

d.) 7,345(8) = X(4)
Octal= 7.345 (8) 
Quaternario = 13. 3 2 1 1 (4)

e.) F,A5E(16) = X(4)
Hexadecimal = f.a5e
b = 0.101001011110
Quaternario = 33. 2  2  1  1  3  2 (4)
*/