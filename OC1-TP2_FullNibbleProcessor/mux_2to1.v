module mux_2to1(
	input      [7:0] in1, 
	input      [7:0] in2,
	input            sel,
	output reg [7:0] out
);	
	always @(in1 or in2 or sel) begin
		case(sel)
			1'b0 : out <= in1;
			1'b1 : out <= in2;
		endcase
	end
endmodule


       
        