module testbench_twos_complement();
	reg  [7:0] a;
	wire [7:0] neg_a;
	
	twos_complement tc(a, neg_a);

	initial begin
		// Printar na tela os valores
		$monitor ("[%0t] a=%b neg_a=%b", $time, a, neg_a);
		
		// Iniciando nossas entradas com valores aleatórios
		#0 a <= $random;
		#5 a <= $random;
		#5 a <= $random;
		
		// Terminando nosso teste
		#5 $finish;
	end
endmodule
