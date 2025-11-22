`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 08/20/2024 12:37:34 AM
// Design Name: 
// Module Name: topM
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module topM(
    input wire A, B, C, D,
    output wire Out  
    );
    
    
    wire outmx1, outmx2;  
    wire [7:0] muxInputs1; // Primeros ochos
    wire [7:0] muxInputs2; // Segundos ochos
    wire [2:0] selec;      
    wire en;               

    // Asignaciones de valores para muxInputs1
    assign muxInputs1 = 8'b00101111;

    // Asignaciones de valores para muxInputs2
    assign muxInputs2 = 8'b11011110;
    assign selec = {D, C, B};
    assign en = ~A;
    
    
    mx mux1(
        .A(muxInputs1),
        .S(selec),
        .EN(A),
        .Out(outmx1)
    );
    
    mx mux2(
        .A(muxInputs2),
        .S(selec),
        .EN(en),
        .Out(outmx2)
    );
    
    
    assign Out = outmx1 | outmx2;
    
endmodule
