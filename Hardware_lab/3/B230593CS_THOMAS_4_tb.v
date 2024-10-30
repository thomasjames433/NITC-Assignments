module bcd__test;
	reg clk;
	wire [3:0] count;
	
	bcd b1 (clk, count);
	
	initial begin
		clk = 1;
	end
	
	always #5 clk = ~clk;
	
	initial #100 $stop;
endmodule