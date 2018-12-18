module testbench_adder_8bit();
	reg  [7:0] a;
	reg  [7:0] b;
	reg        cin;
	wire       cout;
	wire [7:0] soma;
	wire       ovf;
	
	full_adder_8bit adder(.a(a), .b(b), .cin(cin), .cout(cout), .soma(soma), .ovf(ovf));
	
	initial begin
		// Printar na tela os valores
		$monitor ("[%0t] a=%b b=%b soma=%b cin=%b cout=%b ovf=%b", $time, a, b, soma, cin, cout, ovf);

		// Caso onde cin = 0 e cout = 0
		#0 a   <= 8'b10010001;
		#0 b   <= 8'b01000010;
		#0 cin <= 1'b0;

		// Caso onde cin = 0 e cout = 1 (deve ocorrer overflow!)
		#5 a   <= 8'b11111111;
		#0 b   <= 8'b00000001;
		#0 cin <= 1'b0;

		// Caso onde cin = 1 e cout = 0
		#5 a   <= 8'b00011011;
		#0 b   <= 8'b00100101;
		#0 cin <= 1'b1;

		// Caso onde cin = 1 e cout = 1
		#5 a   <= 8'b11111110;
		#0 b   <= 8'b00000001;
		#0 cin <= 1'b1;

		#5 $finish;
	end
endmodule 