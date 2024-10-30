module udc(clk, ud, count);
input clk, ud;

output reg [3:0] count = 0;  
always @(posedge clk)
    begin
        if (ud)
            count = count + 1;  
        else
            count = count - 1;  
    end
endmodule