module fad8(sum,carry,a,b);
input [7:0]a,b;
output[7:0]sum;
output carry;
wire x[6:0];

fad fa0(sum[0],x[0],a[0],b[0],0);
fad fa1(sum[1],x[1],a[1],b[1],x[0]);
fad fa2(sum[2],x[2],a[2],b[2],x[1]);
fad fa3(sum[3],x[3],a[3],b[3],x[2]);
fad fa4(sum[4],x[4],a[4],b[4],x[3]);
fad fa5(sum[5],x[5],a[5],b[5],x[4]);
fad fa6(sum[6],x[6],a[6],b[6],x[5]);
fad fa7(sum[7],carry,a[7],b[7],x[6]);

endmodule