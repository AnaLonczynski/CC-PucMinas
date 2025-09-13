/*
 Guia_0201.v
 680668 - Ana Clara Lonczynski
*/
module Guia_0201;
// define data
 real x = 0, xb = 0, xc = 0, xd = 0, xe =0 ; // decimal
 real power2 = 1.0, power2b = 1.0, power2c =1.0, power2d = 1.0, power2e = 1.0; // power of 2
 integer y = 7, contb = 7, contc = 7, contd = 7, conte = 7; // counter
  reg [7:0] a = 8'b00001100, b = 8'b01001000, c = 8'b10101000, d = 8'b11101000, e = 8'b11001000; // binary (only fraction part, Big Endian)
// actions
 initial
 begin : main
 $display ( "Guia_0201 - Tests" );
   $display ("");
   $display ("a.) 0,00011(2) = X(10)");
   $display ( "Binário = 0.%8b", a );
   while ( y >= 0 )
 begin
 power2 = power2 / 2.0;
   if ( a[y] == 1 )
 begin
 x = x + power2;
 end
   $display ( "Decimal = %f", x );
 y=y-1;
 end // end while

  $display ("");
  $display ("b.) 0,01001(2) = X(10)");
   $display ( "Binário = 0.%8b", b );
   while ( contb >= 0 )
  begin
  power2b = power2b / 2.0;
    if ( b[contb] == 1 )
  begin
  xb = xb + power2b;
  end
    $display ( "Decimal = %f", xb );
  contb=contb-1;
  end // end while

   $display ("");
   $display ("c.) 0,10101(2) = X(10)");
   $display ( "Binário = 0.%8b", c );
   while ( contc >= 0 )
   begin
   power2c = power2c / 2.0;
     if ( c[contc] == 1 )
   begin
   xc = xc + power2c;
   end
     $display ( "Decimal = %f", xc );
   contc=contc-1;
   end // end while

   $display ("");
    $display ("d.) 1,11101(2) = X(10)");
   $display ( "Binário = 1.%8b", d );
   while ( contd >= 0 )
    begin
    power2d = power2d / 2.0;
      if ( d[contd] == 1 )
    begin
    xd = xd + power2d;
    end
      $display ( "Decimal = %f", xd + 1);
    contd=contd-1;
    end // end while

   $display ("");
   $display ("e.) 11,11001(2) = X(10)");
   $display ( "Binário = 11.%8b", e );
   while ( conte >= 0 )
     begin
     power2e = power2e / 2.0;
       if ( e[conte] == 1 )
     begin
     xe = xe + power2e;
     end
       $display ( "Decimal = %f", xe + 2);
     conte=conte-1;
     end // end while
 end // main
endmodule // Guia_0201
/* SAIDA:
Guia_0201 - Tests

a.) 0,00011(2) = X(10)
Binário = 0.00001100
Decimal = 0.000000
Decimal = 0.000000
Decimal = 0.000000
Decimal = 0.000000
Decimal = 0.031250
Decimal = 0.046875
Decimal = 0.046875
Decimal = 0.046875

b.) 0,01001(2) = X(10)
Binário = 0.01001000
Decimal = 0.000000
Decimal = 0.250000
Decimal = 0.250000
Decimal = 0.250000
Decimal = 0.281250
Decimal = 0.281250
Decimal = 0.281250
Decimal = 0.281250

c.) 0,10101(2) = X(10)
Binário = 0.10101000
Decimal = 0.500000
Decimal = 0.500000
Decimal = 0.625000
Decimal = 0.625000
Decimal = 0.656250
Decimal = 0.656250
Decimal = 0.656250
Decimal = 0.656250

d.) 1,11101(2) = X(10)
Binário = 1.11101000
Decimal = 1.500000
Decimal = 1.750000
Decimal = 1.875000
Decimal = 1.875000
Decimal = 1.906250
Decimal = 1.906250
Decimal = 1.906250
Decimal = 1.906250

e.) 11,11001(2) = X(10)
Binário = 11.11001000
Decimal = 2.500000
Decimal = 2.750000
Decimal = 2.750000
Decimal = 2.750000
Decimal = 2.781250
Decimal = 2.781250
Decimal = 2.781250
Decimal = 2.781250
*/