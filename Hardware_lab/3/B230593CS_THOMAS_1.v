module sipo4(clk, rst, si, po);
input clk, rst;
input si;
output reg [3:0] po = 0;

always @(posedge clk)
    begin
        if (rst == 1)
            po = 4'b0000;  
        else
            po = {po[2:0], si}; 
    end
endmodule