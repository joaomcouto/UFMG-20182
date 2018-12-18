/* Para os demais os testes são similares...
   Então, fizemos apenas para o PC para mostrar que a lógica está funcionando.
*/
module testbench_PC();
    reg  [7:0] data_in;
    reg        clk;
    reg        en;
    wire [7:0] data_out;

    reg_carga_paralela PC(data_in, clk, en, data_out);

    initial begin
        $monitor ("[%0t] data_in=%b clk=%b en=%b data_out=%b", $time, data_in, clk, en, data_out);

        // Inicialmente nosso clk será 0, en será 1, e data_in será 0 para melhor visualização
        clk = 1'b0;
        en  = 1'b0;
        data_in = 00000000;
        
        // Caso onde temos borda de subida e en = 0
        #5 data_in = data_in + 4;

        // Caso onde não temos borda de subida e en = 1
        #5 en <= 1'b1;
        #0 data_in = data_in + 4;

        // Caso onde temos borda de subida e en = 1
        #5 data_in = data_in + 4;

        // Caso onde não temos borda de subida e en = 0
        #5 en <= 1'b0;
        #0 data_in = data_in + 4;

        // Término do teste
        #0 $finish;
    end

    // Gerando nosso clk, com tempo de #5
    always begin
        #5 clk = ~clk;
    end
endmodule

/*
    casos
    1) posedge e en = 0
    2) posedge e en = 1 (v)
    3) 0 e en = 0
    4) 0 e en = 1 (v)
*/