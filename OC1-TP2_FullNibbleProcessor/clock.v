module clock(
    output clock
);
    reg clk;
    initial begin
      clk = 0;
    end

    always begin
        #5 clk = ~clk;
    end

    assign clock = clk;
endmodule