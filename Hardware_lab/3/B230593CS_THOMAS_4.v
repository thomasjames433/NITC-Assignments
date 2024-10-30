module bcd_(clk, count);
input clk;
output reg [3:0] count = 0;  

always @(posedge clk)
	begin
		if (count < 9)
			count = count + 1;
		else
			count = 0;
	end
endmodule