module cpr(clk, re, we, wd1, wd2, rd);
input clk, re, we;
input [15:0] wd1, wd2;
output reg [15:0] rd = 0; 
reg [15:0] register_data = 0;
reg write_selector = 0;

always @(posedge clk)
begin
    if (we)
    begin
        if (write_selector == 0)
        begin
            register_data <= wd1;
            write_selector <= 1; 
        end
        else
        begin
            register_data <= wd2;
            write_selector <= 0; 
            end
    end
    else if (re)
    begin
        rd <= register_data;
    end
end

endmodule