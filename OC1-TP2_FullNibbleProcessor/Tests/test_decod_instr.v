module testbench_decod_instr();
	reg  [23:0] instrucao;
	wire [2:0] op_code;
	wire [4:0] addr;
    wire [7:0] x;
    wire [7:0] y;

	decod_instr decoder(instrucao, op_code, addr, x, y);
	
	initial begin
		// Printar na tela os valores
		$monitor ("[%0t] instrucao=%b op_code=%b addr=%b x=%b y=%b", $time, instrucao, op_code, addr, x, y);
		
		// Iniciando nossas entradas com valores aleatórios
		#0 instrucao <= $random;
		#5 instrucao <= $random;
		#5 instrucao <= $random;

		#5 $finish;
	end
endmodule 