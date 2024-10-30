module fad8_tb;
reg [7:0]a,b;
wire [7:0]sum;
wire carry;
fad8 f1(sum,carry,a,b);

initial begin
$monitor("sum=%b,carry=%b,a=%b,b=%b",sum,carry,a,b);

a=34;b=64;
#10
a=255;b=1;
#10
a=123;b=43;
#10
a=134;b=164;
#10
a=74;b=164;

end
endmodule