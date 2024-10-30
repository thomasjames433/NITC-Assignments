module alu(O1,O2,a,b,s);
input [7:0]a,b;
input [1:0]s;
output [7:0] O1,O2;
wire [7:0] sum,dif,bxor,lssa,lssb,carry,bor;

fad8 fa1(sum,carry,a,b);
fsb8 fs1(dif,bor,a,b);
bwxor bw1(bxor,a,b);
ls l1 (lssa,a);
ls l2 (lssb,b);

mux8 m1(O1,sum,dif,lssa,bxor,s);
mux8 m2(O2,carry,bor,lssb,1'b0,s);

endmodule
