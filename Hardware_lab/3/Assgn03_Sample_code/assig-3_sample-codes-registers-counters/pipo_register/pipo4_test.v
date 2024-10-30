module pipo4_test;
//Inputs
reg clk,rst;
reg [3:0]d;
//Outputs
wire [3:0]q;
//Instantiate the Unit Under Test
pipo4 p1(clk,rst,d,q);
initial begin
	clk=1;
	rst=1;
	d=4'b0000;
	#100 rst=0;
	#100 d=4'b0011;
	#100 d=4'b1011;
	#100 d=4'b1111;
	#100 rst=1;
		end
//Simulate clock signal
always #25 clk=~clk;
//stop the simulation
initial #600 $stop;
endmodule
