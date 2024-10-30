module fsb8(dif,bor,a,b);
input [7:0]a,b;
output[7:0]dif,bor;
wire [6:0]x;

fsb fa0(dif[0],x[0],a[0],b[0],0);
fsb fa1(dif[1],x[1],a[1],b[1],x[0]);
fsb fa2(dif[2],x[2],a[2],b[2],x[1]);
fsb fa3(dif[3],x[3],a[3],b[3],x[2]);
fsb fa4(dif[4],x[4],a[4],b[4],x[3]);
fsb fa5(dif[5],x[5],a[5],b[5],x[4]);
fsb fa6(dif[6],x[6],a[6],b[6],x[5]);
fsb fa7(dif[7],bor[0],a[7],b[7],x[6]);

not(bor[1], 1);
not(bor[2], 1);
not(bor[3], 1);
not(bor[4], 1);
not(bor[5], 1);
not(bor[6], 1);
not(bor[7], 1);


endmodule
