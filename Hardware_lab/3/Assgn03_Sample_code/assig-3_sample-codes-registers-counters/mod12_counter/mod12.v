module mod12(clk,count);
//Inputs
input clk;
//Outputs
output reg[3:0]count=0;
always @ (posedge clk)
	begin
		if(count < 11)
			count=count+1;
		else
			count=0;
	end
endmodule
		
