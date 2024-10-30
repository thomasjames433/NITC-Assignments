module fad(sum,carry,a,b,c);
input a,b,c;
output sum ,carry;
wire x1,a1,o1,a2;

xor(x1,a,b);
xor(sum,c,x1);

and(a1,a,b);
and(a2,x1,c);
or(carry,a1,a2);

endmodule
