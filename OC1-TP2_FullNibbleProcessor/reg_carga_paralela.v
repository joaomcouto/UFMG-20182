// Usado para instanciar PC, ADDR, X, Y, OP e R
module reg_carga_paralela(
    input       [7:0] data_in,
    input             clk,
    output reg  [7:0] data_out
);
    // Sempre que o clk mudar, em borda de subida, se en = 1, mudamos o output
    always @(posedge clk) begin   
		data_out <= data_in;    
    end
endmodule