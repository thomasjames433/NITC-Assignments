module dlatch8(en,d,out,r);
input en,r;
input[7:0] d;
output [7:0] out;
dlatch1 d0 (en,d[0],out[0],r);
dlatch1 d1 (en,d[1],out[1],r);
dlatch1 d2 (en,d[2],out[2],r);
dlatch1 d3 (en,d[3],out[3],r);
dlatch1 d4 (en,d[4],out[4],r);
dlatch1 d5 (en,d[5],out[5],r);
dlatch1 d6 (en,d[6],out[6],r);
dlatch1 d7 (en,d[7],out[7],r);
endmodule
