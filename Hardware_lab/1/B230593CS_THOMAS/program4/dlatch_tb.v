module dlatch_tb;
reg [7:0] d;
reg en,r;
wire[7:0] out;
dlatch8 d1(en,d,out,r);

initial begin
d=24;r=1;en=0;
#10
d=24;r=0;en=0;
#10	
d=34;r=1;en=1;
#10
d=24;r=1;en=1;
#10
d=24;r=1;en=1;
#10	
d=34;r=1;en=0;
#10
d=44;r=1;en=0;

end
endmodule
