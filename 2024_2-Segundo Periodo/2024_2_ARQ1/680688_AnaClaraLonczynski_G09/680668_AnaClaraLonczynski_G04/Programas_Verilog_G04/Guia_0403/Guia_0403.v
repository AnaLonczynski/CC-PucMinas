/*
Guia_0403.v
Ana Clara Lonczynski - 0680668
*/
/*----------A-----------*/
//x'.y'.z | x.y'.z | x.y.z' | x.y.z
module faxyz (output sa, input  x, y, z);
assign sa = (~x & ~y & z) | (x & ~y & z) | (x & y & ~z) | (x & y & z);
endmodule 

/*----------B-----------*/
//x'.y.z' | x.y'.z | x.y.z' | x.y.z
module fbxyz (output sb, input  x, y, z);
assign sb = (~x & y & ~z) | (x & ~y & z) | (x & y & ~z) | (x & y & z);
endmodule 

/*----------C-----------*/
//w'.x'.y'.z | w'.x'.y.z' | w'.x'.y.z | w'.x.y.z' | w'.x.y.z | w.x'.y.z | w.x.y.z
module fcxyz (output sc, input w, x, y, z);
assign sc = (~w & ~x & ~y & z) | (~w & ~x & y & ~z) | (~w & ~x & y & z) | (~w & x & y & ~z) | (~w & x & y & z) | (w & ~x & y & z) | (w & x & y & z);
endmodule 

/*----------D-----------*/
// w'.x'.y'.z | w'.x'.y.z' | w'.x.y.z' | w.x'.y'.z' | w.x'.y.z' | w.x.y'.z' | w.x.y.z'
module fdxyz (output sd, input w, x, y, z);
assign sd = (~w & ~x & ~y & z) | (~w & ~x & y & ~z) | (~w & x & y & ~z) | (w & ~x & ~y & ~z) | (w & ~x & y & ~z) | (w & x & ~y & ~z) | (w & x & y & ~z);
endmodule 

/*----------E-----------*/
//w'.x'.y'.z' | w'.x'.y.z' | w'.x.y'.z | w'.x.y.z | w.x'.y'.z' | w.x'.y.z
module fexyz (output se, input w, x, y, z);
assign se = (~w & ~x & ~y & ~z) | (~w & ~x & y & ~z) | (~w & x & ~y & z) | (~w & x & y & z) | (w & ~x & ~y & ~z) | (w & ~x & y & z);
endmodule 

module tb_fxyz;
    reg w, x, y, z;
    wire sa, sb, sc, sd, se;

    // Instanciar o módulo

    faxyz uut1 (
        .sa(sa),
        .x(x),
        .y(y),
        .z(z)
    );

    fbxyz uut2 (
        .sb(sb),
        .x(x),
        .y(y),
        .z(z)
    );

    fcxyz uut3 (
        .sc(sc),
        .w(w),
        .x(x),
        .y(y),
        .z(z)
    );

    fdxyz uut4 (
        .sd(sd),
        .w(w),
        .x(x),
        .y(y),
        .z(z)
    );

    fexyz uut5 (
        .se(se),
        .w(w),
        .x(x),
        .y(y),
        .z(z)
    );

    // Testar todos os casos
    initial begin

        $display("Guia_0403 - Tests\n");

        $monitor("w = %b x=%b y=%b z=%b    sa=%b      sb=%b        sc=%b       sd=%b       se=%b", w, x, y, z, sa, sb, sc, sd, se);

        // Testar todas as combinações
        w = 0; x = 0; y = 0; z = 0; #10;
        w = 0; x = 0; y = 0; z = 1; #10;
        w = 0; x = 0; y = 1; z = 0; #10;
        w = 0; x = 0; y = 1; z = 1; #10;
        w = 0; x = 1; y = 0; z = 0; #10;
        w = 0; x = 1; y = 0; z = 1; #10;
        w = 0; x = 1; y = 1; z = 0; #10;
        w = 1; x = 1; y = 1; z = 1; #10;
        w = 1; x = 0; y = 0; z = 0; #10;
        w = 1; x = 0; y = 0; z = 1; #10;
        w = 1; x = 0; y = 1; z = 0; #10;
        w = 1; x = 0; y = 1; z = 1; #10;
        w = 1; x = 1; y = 0; z = 0; #10;
        w = 1; x = 1; y = 0; z = 1; #10;
        w = 1; x = 1; y = 1; z = 0; #10;
        w = 1; x = 1; y = 1; z = 1; #10;

        $finish;
    end
endmodule // tb_fxyz