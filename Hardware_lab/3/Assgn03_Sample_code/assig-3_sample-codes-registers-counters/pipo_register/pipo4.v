module pipo4(clk,rst,d,q);
//Inputs
input clk,rst;
input [3:0]d;
//Outputs
output reg[3:0]q=0;
always@(posedge clk)
	begin
	if(rst==1)
		q=0;
	else
		q=d;
	end
endmodule
