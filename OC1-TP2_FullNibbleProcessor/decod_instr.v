module decod_instr(
    input      [23:0] instrucao,
	 output reg [7:0]  addr,
	 output reg [7:0]  y,
    output reg [7:0]  op_code,
    output reg [7:0]  x
    
);
    // Sempre que a instrução mudar, atualizamos nosso op_code, etc.
    always @(instrucao) begin
        op_code <= instrucao[23:21];
        addr    <= instrucao[20:16];
        x       <= instrucao[15:8];
        y       <= instrucao[7:0];
    end
endmodule