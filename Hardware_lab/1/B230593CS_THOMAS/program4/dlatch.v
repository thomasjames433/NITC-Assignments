module dlatch1(en,d,out,r);
input en,d,r;
output out;
wire  y0,y1,y2,y3,y4;

not(y0,d);
nand(y1,en,d);
nand(y2,y0,en);
nand(y3,y4,y1);
nand(y4,y3,y2);
and(out,r,y3);
endmodule
