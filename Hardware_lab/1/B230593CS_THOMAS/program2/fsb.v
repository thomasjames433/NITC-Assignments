module fsb(dif,bor,a,b,c);
input a,b,c;
output dif,bor;

wire x1,x2,a1,a2,n1,n2;
xor(x1,a,b);
xor(dif,c,x1);

not(n1,a);
not(n2,x1);
and(a1,n1,b);
and(a2,n2,c);
or(bor,a1,a2);

endmodule