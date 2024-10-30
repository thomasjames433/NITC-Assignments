module cpr_test;
    reg clk;
    reg re;
    reg we;
    reg [15:0] wd1;
    reg [15:0] wd2;
    wire [15:0] rd;

    cpr s1 (
        .clk(clk),
        .re(re),
        .we(we),
        .wd1(wd1),
        .wd2(wd2),
        .rd(rd)
    );

    always #5 clk = ~clk;

    initial begin
        clk = 0;
        re = 0;
        we = 0;
        wd1 = 16'hAAAA;
        wd2 = 16'h5555;
        
        we = 1;
        #10 we = 0; 
        
        we = 1;
        #10 we = 0;  
        
        re = 1;
        #10 re = 0;  

        #50 $stop;
    end
endmodule