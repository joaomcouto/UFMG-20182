module testbench_single_port_rom();
  reg  [4:0]  addr;
  reg         clk; 
  wire [23:0] q;

  // Instância do módulo
  single_port_rom rom(addr, clk, q);

  initial begin
    // Display na tela
    $monitor("[%0t] clk=%b addr=%b q=%b", $time, clk, addr, q);

    // Iniciamos nosso clk com 0
    #0 clk = 0;

    // Testando as instruçõs que temos no .txt
    #0 addr = 5'b00000;
    #2 addr = addr + 1;
    #2 addr = addr + 1;
    #2 addr = addr + 1;
    #2 addr = addr + 1;
    #2 addr = addr + 1;
    
    // Término do programa
    #1 $finish;
  end

  // A cada 1 ciclo há um pulso de clk
  always begin
    #1 clk = ~clk;
  end

endmodule