// Copyright (C) 2018  Intel Corporation. All rights reserved.
// Your use of Intel Corporation's design tools, logic functions 
// and other software and tools, and its AMPP partner logic 
// functions, and any output files from any of the foregoing 
// (including device programming or simulation files), and any 
// associated documentation or information are expressly subject 
// to the terms and conditions of the Intel Program License 
// Subscription Agreement, the Intel Quartus Prime License Agreement,
// the Intel FPGA IP License Agreement, or other applicable license
// agreement, including, without limitation, that your use is for
// the sole purpose of programming logic devices manufactured by
// Intel and sold by Intel or its authorized distributors.  Please
// refer to the applicable agreement for further details.

// PROGRAM		"Quartus Prime"
// VERSION		"Version 18.1.0 Build 625 09/12/2018 SJ Lite Edition"
// CREATED		"Sat Dec 01 23:26:58 2018"

module nibble_diagram(
);



wire	SYNTHESIZED_WIRE_0;
wire	[7:0] SYNTHESIZED_WIRE_1;
wire	SYNTHESIZED_WIRE_2;
wire	[7:0] SYNTHESIZED_WIRE_3;
wire	[7:0] SYNTHESIZED_WIRE_4;
wire	SYNTHESIZED_WIRE_5;
wire	[7:0] SYNTHESIZED_WIRE_6;
wire	[0:7] SYNTHESIZED_WIRE_7;
wire	SYNTHESIZED_WIRE_8;
wire	SYNTHESIZED_WIRE_34;
wire	[7:0] SYNTHESIZED_WIRE_10;
wire	[7:0] SYNTHESIZED_WIRE_11;
wire	SYNTHESIZED_WIRE_12;
wire	[7:0] SYNTHESIZED_WIRE_35;
wire	[0:7] SYNTHESIZED_WIRE_14;
wire	[7:0] SYNTHESIZED_WIRE_18;
wire	SYNTHESIZED_WIRE_19;
wire	[7:0] SYNTHESIZED_WIRE_20;
wire	[7:0] SYNTHESIZED_WIRE_21;
wire	[7:0] SYNTHESIZED_WIRE_36;
wire	[7:0] SYNTHESIZED_WIRE_23;
wire	[0:7] SYNTHESIZED_WIRE_24;
wire	[1:0] SYNTHESIZED_WIRE_25;
wire	[23:0] SYNTHESIZED_WIRE_26;
wire	[7:0] SYNTHESIZED_WIRE_29;
wire	[7:0] SYNTHESIZED_WIRE_31;
wire	[7:0] SYNTHESIZED_WIRE_33;

assign	SYNTHESIZED_WIRE_2 = 0;
assign	SYNTHESIZED_WIRE_7 = 0;
assign	SYNTHESIZED_WIRE_12 = 0;
assign	SYNTHESIZED_WIRE_14 = 1;
assign	SYNTHESIZED_WIRE_24 = 1;




controle_central	b2v_inst(
	.ovf(SYNTHESIZED_WIRE_0),
	.op(SYNTHESIZED_WIRE_1),
	
	.DUMP(SYNTHESIZED_WIRE_8),
	.sel_mux2(SYNTHESIZED_WIRE_19),
	.sel_mux3(SYNTHESIZED_WIRE_5),
	.sel_mux1(SYNTHESIZED_WIRE_25));


clock	b2v_inst10(
	.clock(SYNTHESIZED_WIRE_34));


adder_8bit	b2v_inst16(
	.cin(SYNTHESIZED_WIRE_2),
	.a(SYNTHESIZED_WIRE_3),
	.b(SYNTHESIZED_WIRE_4),
	
	.ovf(SYNTHESIZED_WIRE_0),
	.soma(SYNTHESIZED_WIRE_18));



mux_2to1	b2v_inst18(
	.sel(SYNTHESIZED_WIRE_5),
	.in1(SYNTHESIZED_WIRE_6),
	.in2(SYNTHESIZED_WIRE_7),
	.out(SYNTHESIZED_WIRE_10));



single_port_ram	b2v_inst2(
	.we(SYNTHESIZED_WIRE_8),
	.clk(SYNTHESIZED_WIRE_34),
	.addr(SYNTHESIZED_WIRE_10),
	.data(SYNTHESIZED_WIRE_11),
	.q(SYNTHESIZED_WIRE_20));


adder_8bit	b2v_inst20(
	.cin(SYNTHESIZED_WIRE_12),
	.a(SYNTHESIZED_WIRE_35),
	.b(SYNTHESIZED_WIRE_14),
	
	
	.soma(SYNTHESIZED_WIRE_29));





single_port_rom	b2v_inst3(
	.clk(SYNTHESIZED_WIRE_34),
	.addr(SYNTHESIZED_WIRE_35),
	.q(SYNTHESIZED_WIRE_26));


reg_carga_paralela	b2v_inst31(
	.clk(SYNTHESIZED_WIRE_34),
	.data_in(SYNTHESIZED_WIRE_18),
	.data_out(SYNTHESIZED_WIRE_11));


mux_2to1	b2v_inst4(
	.sel(SYNTHESIZED_WIRE_19),
	.in1(SYNTHESIZED_WIRE_20),
	.in2(SYNTHESIZED_WIRE_21),
	.out(SYNTHESIZED_WIRE_4));


mux_3to1	b2v_inst5(
	.in1(SYNTHESIZED_WIRE_36),
	.in2(SYNTHESIZED_WIRE_23),
	.in3(SYNTHESIZED_WIRE_24),
	.sel(SYNTHESIZED_WIRE_25),
	.out(SYNTHESIZED_WIRE_3));


decod_instr	b2v_inst8(
	.instrucao(SYNTHESIZED_WIRE_26),
	.addr(SYNTHESIZED_WIRE_6),
	.op_code(SYNTHESIZED_WIRE_1),
	.x(SYNTHESIZED_WIRE_31),
	.y(SYNTHESIZED_WIRE_33));


twos_complement	b2v_inst9(
	.a(SYNTHESIZED_WIRE_36),
	.b(SYNTHESIZED_WIRE_23));


reg_carga_paralela	b2v_PC(
	.clk(SYNTHESIZED_WIRE_34),
	.data_in(SYNTHESIZED_WIRE_29),
	.data_out(SYNTHESIZED_WIRE_35));


reg_carga_paralela	b2v_X(
	.clk(SYNTHESIZED_WIRE_34),
	.data_in(SYNTHESIZED_WIRE_31),
	.data_out(SYNTHESIZED_WIRE_36));


reg_carga_paralela	b2v_Y(
	.clk(SYNTHESIZED_WIRE_34),
	.data_in(SYNTHESIZED_WIRE_33),
	.data_out(SYNTHESIZED_WIRE_21));


endmodule
