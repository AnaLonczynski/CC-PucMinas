/*
Guia_0401.v
Ana Clara Lonczynski - 0680668
*/
//x' . ( y'+z )'
//x' . ( y'+z )'
module faxyz (output sa, input x, y, z);
assign sa = ~x & ~(~y | z);
endmodule 

//( x' +y' )' . z
module fbxyz (output sb, input x, y, z);
assign sb = ~(~x | ~y) & z;
endmodule 

//( x . y' )' . z'
module fcxyz (output sc, input x, y, z);
assign sc = ~(x & ~y) & ~z;
endmodule 

//( x' . y )' . z
module fdxyz (output sd, input x, y, z);
assign sd = ~(~x & y) & z;
endmodule 

//( x' + y ) . ( y' + z)'
module fexyz (output se, input x, y, z);
assign se = (~x | y) & ~(~y | z);
endmodule 

module tb_fxyz;
    reg x, y, z;
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
        .x(x),
        .y(y),
        .z(z)
    );

    fdxyz uut4 (
        .sd(sd),
        .x(x),
        .y(y),
        .z(z)
    );

    fexyz uut5 (
        .se(se),
        .x(x),
        .y(y),
        .z(z)
    );

    // Testar todos os casos
    initial begin

        $display("Guia_0401 - Tests\n");

        $monitor("x=%b y=%b z=%b    sa=%b      sb=%b        sc=%b       sd=%b       se=%b", x, y, z, sa, sb, sc, sd, se);

        // Testar todas as combinações
        x = 0; y = 0; z = 0; #10;
        x = 0; y = 0; z = 1; #10;
        x = 0; y = 1; z = 0; #10;
        x = 0; y = 1; z = 1; #10;
        x = 1; y = 0; z = 0; #10;
        x = 1; y = 0; z = 1; #10;
        x = 1; y = 1; z = 0; #10;
        x = 1; y = 1; z = 1; #10;

        $finish;
    end
endmodule // tb_fxyz