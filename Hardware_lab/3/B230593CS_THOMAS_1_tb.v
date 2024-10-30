module sipo4_test;
reg clk, rst;
reg si;
wire [3:0] po;

sipo4 s1 (clk, rst, si, po);

initial begin
    clk = 1;
    rst = 1;
    si = 0;
    #100 rst = 0;

    #100 si = 1;
    #100 si = 0;
    #100 si = 1;
    #100 si = 1;
    #100 rst = 1;
end

always #25 clk = ~clk;

initial #600 $stop;
endmodule