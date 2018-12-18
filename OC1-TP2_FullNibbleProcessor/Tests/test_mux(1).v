module testbench_mux_2to1();
	reg  [7:0] in1;
	reg  [7:0] in2;
    reg  [7:0] in3;
	reg  [1:0] sel;
	wire [7:0] out;
	
	mux_3to1 mux(.in1(in1), .in2(in2), .in3(in3), .sel(sel), .out(out));
	
	initial begin
		// Printar na tela os valores
		$monitor ("[%0t] sel=%b in1=%b in2=%b in3=%b out=%b", $time, sel, in1, in2, in3, out);
		
		// Iniciando nossas entradas com valores aleatórios
		in1 <= $random;
		in2 <= $random;
        in3 <= $random;
		
		#0 sel <= 2'b00;
		#5 sel <= 2'b01;
        #5 sel <= 2'b10;
        
		#5 $finish;
	end
endmodule 