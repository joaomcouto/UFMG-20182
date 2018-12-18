module controle_central(
    input      [7:0] op,
    input            ovf,
    output reg       ended,
    output reg       DUMP,
    output reg [1:0] sel_mux1, // Mux com 3 entradas (X, -X ou 1)
    output reg       sel_mux2, // Mux com 2 entradas (Y ou Q)
    output reg       sel_mux3  // Mux com 2 entradas (ADDR ou 0xF)
);
    // Sempre que o nosso op_code mudar
	 reg[2:0] opcode ;
	 
    always @(opcode or ovf) begin
		opcode <= op[2:0];
      // Se tivermos overflow
      if (ovf == 1) begin
        sel_mux1 <= 2; // Liberamos o valor 1 para incrementar nosso contador
        sel_mux2 <= 1; // Escolhemos o conteúdo do endereço escolhido
        sel_mux3 <= 1; // Escolhemos a posição 0xF
      end
      else begin
        // Implementamos o controle dos Mux baseados diretamente no op_code
        sel_mux1 <= opcode[1]; // op[1] == 0 --> X; op[1] == 1 --> X em complemento de 2
        sel_mux2 <= opcode[0]; // op[0] == 0 --> Y; op[0] == 1 --> Conteúdo em ADDR 
        sel_mux3 <= 0;     // Escolhemos a posição na memória dada por ADDR
      end

      ended <= (opcode == 3'b100); // Se o op for 100, ended = 1
      DUMP  <= (opcode == 3'b111); // Se o op for 111, DUMP = 1
    end
endmodule