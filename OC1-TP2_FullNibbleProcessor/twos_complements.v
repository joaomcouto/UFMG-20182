module twos_complement(
	input  [7:0] a,
	output [7:0] b
);
	assign b = -a;
endmodule 