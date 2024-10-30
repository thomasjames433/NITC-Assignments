module alu_tb;
reg [7:0]a,b;
reg [1:0]s;
wire [7:0] O1,O2;


alu a1(O1,O2,a,b,s);

initial begin

a=100;b=150;s=2;

end 
endmodule
