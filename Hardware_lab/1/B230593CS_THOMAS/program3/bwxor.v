module bwxor(o,a,b);
input [7:0]a,b;
output [7:0]o;

xor(o[0],a[0],b[0]);
xor(o[1],a[1],b[1]);
xor(o[2],a[2],b[2]);
xor(o[3],a[3],b[3]);
xor(o[4],a[4],b[4]);
xor(o[5],a[5],b[5]);
xor(o[6],a[6],b[6]);
xor(o[7],a[7],b[7]);

endmodule
