/*
 Guia_0105.v
 999999 - Xxx Yyy Zzz
*/
module Guia_0105;
// define data
 integer x = 0; // decimal
  reg [0:7][7:0] s = "PUC-M.G.";
  reg [0:10][7:0] sb = "“2024-02”";
  reg [0:17][7:0] sc ="“Belo Horizonte”";
  reg [0:18][7:0] sd = "156 157 151 164 145";
  reg [0:13][7:0] se = "4D 61 6E 68 61"; // char array[3] (3x8 bits - little Endian)
// actions
 initial
 begin : main
   $display ("");
   $display ( "Guia_0105 - Tests" );
   $display ("");
   $display ( "a.) “PUC-M.G.” = X(16_ASCII)" );
   $display ( "%s" , s);
   for (x = 0; x < 7; x++)begin
   $display ( "%s = %x (16)" , s[x], s[x] );
   end

  $display ("");
  $display ( "b.) “2024-02” = X(16_ASCII)" );
  $display ( "%s" , sb);
   for (x = 0; x < 9; x++)begin
  $display ( "%s = %x (16)" , sb[x], sb[x] );
  end

   $display ("");
   $display ( "c.) Belo Horizonte = X(2_ASCII)" );
   $display ( "%s" , sc);
   for (x = 0; x < 16; x++)begin
     $display ( "%s = %x (16)" , sc[x], sc[x] );
   end

   $display ("");
    $display ( "d.) 156 157 151 164 145 (8) = X(ASCII)" );
   $display ( "%s" , sd);
   for (x = 0; x < 19; x++)begin
      $display ( "%s = %x (16)" , sd[x], sd[x] );
    end

   $display ("");
     $display ( "e.) 4D 61 6E 68 61 (16) = X(ASCII)" );
   $display ( "%s" , se);
   for (x = 0; x < 14; x++)begin
      $display ( "%s = %x (16)" , se[x], se[x] );
     end
 end // main
endmodule // Guia_0105
/*
Guia_0105 - Tests

a.) “PUC-M.G.” = X(16_ASCII)
PUC-M.G.
P = 50 (16)
U = 55 (16)
C = 43 (16)
- = 2d (16)
M = 4d (16)
. = 2e (16)
G = 47 (16)

b.) “2024-02” = X(16_ASCII)
�2024-02”
� = 9c (16)
2 = 32 (16)
0 = 30 (16)
2 = 32 (16)
4 = 34 (16)
- = 2d (16)
0 = 30 (16)
2 = 32 (16)
� = e2 (16)

c.) Belo Horizonte = X(2_ASCII)
�Belo Horizonte”
� = 9c (16)
B = 42 (16)
e = 65 (16)
l = 6c (16)
o = 6f (16)
  = 20 (16)
H = 48 (16)
o = 6f (16)
r = 72 (16)
i = 69 (16)
z = 7a (16)
o = 6f (16)
n = 6e (16)
t = 74 (16)
e = 65 (16)
� = e2 (16)

d.) 156 157 151 164 145 (8) = X(ASCII)
156 157 151 164 145
1 = 31 (16)
5 = 35 (16)
6 = 36 (16)
  = 20 (16)
1 = 31 (16)
5 = 35 (16)
7 = 37 (16)
  = 20 (16)
1 = 31 (16)
5 = 35 (16)
1 = 31 (16)
  = 20 (16)
1 = 31 (16)
6 = 36 (16)
4 = 34 (16)
  = 20 (16)
1 = 31 (16)
4 = 34 (16)
5 = 35 (16)

e.) 4D 61 6E 68 61 (16) = X(ASCII)
4D 61 6E 68 61
4 = 34 (16)
D = 44 (16)
  = 20 (16)
6 = 36 (16)
1 = 31 (16)
  = 20 (16)
6 = 36 (16)
E = 45 (16)
  = 20 (16)
6 = 36 (16)
8 = 38 (16)
  = 20 (16)
6 = 36 (16)
*/