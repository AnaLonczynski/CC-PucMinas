/*
 Guia_0202.v
 680668 - Ana Clara Lonczynski
*/
module Guia_0202;
// define data
 real xa = 0.375, xb = 0.125, xc = 0.625, xd = 0.03125, xe = 0.75; // decimal
 integer ya = 7 , yb = 7, yc = 7, yd = 7, ye = 7; // counter
  reg [7:0] ba = 0;
  reg [7:0] b = 0;
  reg [7:0] bc = 0;
  reg [7:0] bd = 0;
  reg [7:0] be = 0; // binary
// actions
 initial
 begin : main
   $display ( "\nGuia_0202 - Tests" );
   $display ( "\na.) 0,375000(10) = X(2)");
   while ( xa > 0 && ya >= 0 )
 begin
   if ( xa*2 >= 1 )
 begin
   ba[ya] = 1;
 xa = xa*2.0 - 1.0;
 end
 else
 begin
   ba[ya] = 0;
 xa = xa*2.0;
 end // end if
   $display ( "Binário = 0.%8b", ba  );
 ya=ya-1;
 end // end while

 $display ( "\nb.) 2,125000 (10) = X(2)");
   while ( xb > 0 && yb >= 0 )
  begin
    if ( xb*2 >= 1 )
  begin
    b[yb] = 1;
  xb = xb*2.0 - 1.0;
  end
  else
  begin
    b[yb] = 0;
  xb= xb*2.0;
  end // end if
    $display ( "Binário = 10.%8b", b );
  yb=yb-1;
  end // end while

   $display ( "\nc.) 3,625000 (10) = X(2)");
   while ( xc > 0 && yc >= 0 )
   begin
     if ( xc*2 >= 1 )
   begin
     bc[yc] = 1;
   xc = xc*2.0 - 1.0;
   end
   else
   begin
     bc[yc] = 0;
   xc= xc*2.0;
   end // end if
     $display ( "Binário = 11.%8b", bc );
   yc=yc-1;
   end // end while

  $display ( "\nd.) 5,03125 (10) = X(2)");
   while ( xd > 0 && yd >= 0 )
  begin
    if ( xd*2 >= 1 )
  begin
    bd[yd] = 1;
  xd = xd*2.0 - 1.0;
  end
  else
  begin
    bd[yd] = 0;
  xd= xd*2.0;
  end // end if
    $display ( "Binário = 101.%8b", bd );
  yd=yd-1;
  end // end while

   $display ( "\ne.) 6,750000 (10) = X(2)");
   while ( xe > 0 && ye >= 0 )
   begin
     if ( xe*2 >= 1 )
   begin
     be[ye] = 1;
   xe = xe*2.0 - 1.0;
   end
   else
   begin
     be[ye] = 0;
   xe= xe*2.0;
   end // end if
     $display ( "Binário = 110.%8b", be );
   ye=ye-1;
   end // end while
 end // main
endmodule // Guia_0202
/*SAIDA:
Guia_0202 - Tests

a.) 0,375000(10) = X(2)
Binário = 0.00000000
Binário = 0.01000000
Binário = 0.01100000

b.) 2,125000 (10) = X(2)
Binário = 10.00000000
Binário = 10.00000000
Binário = 10.00100000

c.) 3,625000 (10) = X(2)
Binário = 11.10000000
Binário = 11.10000000
Binário = 11.10100000

d.) 5,03125 (10) = X(2)
Binário = 101.00000000
Binário = 101.00000000
Binário = 101.00000000
Binário = 101.00000000
Binário = 101.00001000

e.) 6,750000 (10) = X(2)
Binário = 110.10000000
Binário = 110.11000000
*/