module mux(o,i0,i1,i2,i3,s);
input i0,i1,i2,i3;
input [1:0]s;
output o;

wire a1,a2,a3,a4,n1,n0;

not(n0,s[0]);
not(n1,s[1]);

and(a1,i0,n0,n1);
and(a2,i1,n0,s[1]);
and(a3,i2,s[0],n1);
and(a4,i3,s[0],s[1]);
or(o,a1,a2,a3,a4);

endmodule
