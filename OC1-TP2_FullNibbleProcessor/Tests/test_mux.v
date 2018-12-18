module testbench_mux_2to1();
	reg  [7:0] in1;
	reg  [7:0] in2;
	reg        sel;
	wire [7:0] out;
	
	mux_2to1 mux(.in1(in1), .in2(in2), .sel(sel), .out(out));
	
	initial begin
		// Printar na tela os valores
		$monitor ("[%0t] sel=0x%0h in1=0x%0h in2=0x%0h out=0x%0h", $time, sel, in1, in2, out);
		
		// Iniciando nossas entradas com valores aleatórios
		in1 <= $random;
		in2 <= $random;
		
		#0 sel <= 1'b0;
		#5 sel <= 1'b1;
		
		#5 $finish;
	end
endmodule 