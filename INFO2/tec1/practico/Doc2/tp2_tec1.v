`timescale 1ns/1ps
//Module name and port list
//Decodificador module
module decodificador(
   
//port declarations
input D,C,B,A,
output a,b,c,d,e,f,g
);

assign a = ~A&B&D    | A&~B&~C | ~A&~B&C  | ~A&~B&~C;
assign b = ~A&~B     | ~B&~C   | ~A&~C&~D | ~A&C&D;
assign c = ~A & B    | ~A&~C   | ~A&D     | ~B&~C; 
assign d = ~B&~C&~D  | ~A&C&~D | ~A&~B&C  | ~A&B&~C&D;
assign e = ~A&C&~C   | ~B&~C&~D;
assign f = A&~B&~C   | ~A&B&~C | ~B&~C&~D | ~A&B&~D;
assign g = A&~B&~C   | ~A&~B&C | ~A&B&~C  | ~A&C&~D;

//Maxiterms
/*
assign a = ~A&B&D    | A&~B&~C | ~A&~B&C  | ~A&~B&~C;
assign b = ~A&~B     | ~B&~C   | ~A&~C&~D | ~A&C&D;
assign c = ~A & B    | ~A&~C   | ~A&D     | ~B&~C;
assign d = ~B&~C&~D  | ~A&C&~D | ~A&~B&C  | ~A&B&~C&D;
assign e = ~A&C&~D   | ~B&~C&~D;
assign f = A&~B&~C   | ~A&B&~C | ~B&~C&~D | ~A&B&~D;
assign g = A&~B&~C   | ~A&~B&C | ~A&B&~C  | ~A&C&~D;
*/

initial begin
	$dumpfile("tp2.vcd");
	$dumpvars(0);
end

endmodule
