module mod12_test;
	//Inputs
	reg clk;
	//Outputs
	wire [3:0] count;
	//Instantiate the Unit Under Test
	mod12 m2(clk,count);
	initial begin
			clk=1;
			  end
//Simulate clock signal
	always #5 clk=~clk;
//stop the simulation
	initial #250 $stop;
endmodule
		
				
