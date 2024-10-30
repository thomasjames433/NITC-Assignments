module ls(lssum,a);
input [7:0]a;
output [7:0]lssum;

or(lssum[7],0,a[3]);
or(lssum[6],0,a[2]);
or(lssum[5],0,a[1]);
or(lssum[4],0,a[0]);
or(lssum[3],0,0);
or(lssum[2],0,0);
or(lssum[1],0,0);
or(lssum[0],0,0);

endmodule
