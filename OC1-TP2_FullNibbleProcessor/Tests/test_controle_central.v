module testbench_controle_central();
  reg  [2:0] op;
  reg        ovf;
  wire       ended;
  wire       DUMP;
  wire [1:0] sel_mux1; // Mux com 3 entradas (X, -X ou 1)
  wire       sel_mux2; // Mux com 2 entradas (Y ou Q)
  wire       sel_mux3; // Mux com 2 entradas (ADDR ou 0xF)

  controle_central ctrl(op, ovf, ended, DUMP, sel_mux1, sel_mux2, sel_mux3);

  initial begin
    $monitor("[%0t] op=%b ovf=%b ended=%b DUMP=%b sel_mux1=%b sel_mux2=%b sel_mux3=%b",
              $time, op, ovf, ended, DUMP, sel_mux1, sel_mux2, sel_mux3);

    #0 op  <= 3'b000;
    #0 ovf <= 0;

    #1 op  <= 3'b001;
    #0 ovf <= 0;

    #1 op <= 3'b010;
    #0 ovf <= 0;

    #1 op <= 3'b011;
    #0 ovf <= 0;

    #1 op <= 3'b100;
    #0 ovf <= 0;

    #1 op <= 3'b111;
    #0 ovf <= 0;

    #1 op <= 3'b000;
    #0 ovf <= 1;

    #1 op <= 3'b001;
    #0 ovf <= 1;

    #1 op <= 3'b010;
    #0 ovf <= 1;

    #1 op <= 3'b011;
    #0 ovf <= 1;

    #1 op <= 3'b100;
    #0 ovf <= 1;

    #1 op <= 3'b111;
    #0 ovf <= 1;

    #0 $finish;
  end
endmodule