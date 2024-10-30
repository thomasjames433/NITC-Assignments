module udc_test;
    reg clk;
    reg ud;
    wire [3:0] count;
    
    udc u1 (clk, ud, count);
    
    initial begin
        clk = 0;
        ud = 0;
    end
    
    always #5 clk = ~clk;
    
    initial begin
        ud = 1;
        #100;
        
        ud = 0;
        #100;
        
        $stop;
    end
endmodule