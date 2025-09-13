/*
Guia_0402.v
Ana Clara Lonczynski - 0680668
*/
/*----------A-----------*/
//x . ( x' + y )'
module faxy (output sa, input x, y);
assign sa = x & ~(~x | y);
endmodule 

//x . y'
module fraxy (output rsa, input x, y);
assign rsa = x & ~y;
endmodule 

/*----------B-----------*/
//( x' + y ) + ( x' . y )
module fbxy (output sb, input x, y);
assign sb = (~x | y) | (~x & y);
endmodule 

//x' + y
module frbxy (output rsb, input x, y);
assign rsb = ~x | y;
endmodule 

/*----------C-----------*/
//( x' . y' )' . ( x + y )
module fcxy (output sc, input x, y);
assign sc = ~(~x & ~y) & (x | y);
endmodule 

//x + y
module frcxy (output rsc, input x, y);
assign rsc = x | y;
endmodule 

/*----------D-----------*/
//( x' . y )' + ( x' + y )'
module fdxy (output sd, input x, y);
assign sd = ~(~x & y) | ~(~x | y);
endmodule 

//x + ~y
module frdxy (output rsd, input x, y);
assign rsd = x | ~y;
endmodule 

/*----------E-----------*/
//( y + x' ) . ( y' + x)'
module fexy (output se, input x, y);
assign se = (y | ~x) & ~(~y | x);
endmodule 

//y . x'
module frexy (output rse, input x, y);
assign rse = y & ~x;
endmodule 

module tb_fxyz;
    reg x, y, z;
    wire sa, sb, sc, sd, se;

    // Instanciar o módulo

    //Questão a)

    faxy uut1 (
        .sa(sa),
        .x(x),
        .y(y)
    );

    fraxy uut2 (
        .rsa(rsa),
        .x(x),
        .y(y)
    );

    //Questão b)

    fbxy uut3 (
        .sb(sb),
        .x(x),
        .y(y)
    );

    frbxy uut4 (
        .rsb(rsb),
        .x(x),
        .y(y)
    );

    //Questão c)

    fcxy uut5 (
        .sc(sc),
        .x(x),
        .y(y)
    );

    frcxy uut6 (
        .rsc(rsc),
        .x(x),
        .y(y)
    );

    //Questão d)

    fdxy uut7 (
        .sd(sd),
        .x(x),
        .y(y)
    );

    frdxy uut8 (
        .rsd(rsd),
        .x(x),
        .y(y)
    );

    //Questão e)

    fexy uut9 (
        .se(se),
        .x(x),
        .y(y)
    );

    frexy uut10 (
        .rse(rse),
        .x(x),
        .y(y)
    );

    // Testar todos os casos
    initial begin

        $display("Guia_0402 - Tests\n");

        $monitor("x=%b y=%b     sa=%b === rsa=%b   sb=%b === rsa=%b     sc=%b === rsc=%b    sd=%b === rsd=%b    se=%b === rse=%b", x, y, sa, rsa, sb, rsb, sc, rsc, sd, rsd, se, rse);

        // Testar todas as combinações
        x = 0; y = 0; #10;
        x = 0; y = 1; #10;
        x = 1; y = 0; #10;
        x = 1; y = 1; #10;

        $finish;
    end
endmodule // tb_fxyz