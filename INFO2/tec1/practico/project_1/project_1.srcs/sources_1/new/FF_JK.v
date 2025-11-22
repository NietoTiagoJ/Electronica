`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/22/2024 10:17:26 AM
// Design Name: 
// Module Name: FF_T
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


module FF_JK(
    input J,K,clk,reset,
    output reg Q
    );
    
    
    always @(clk)begin
    
        if(reset)begin
            Q <= 1'b0;
        end else if(J && !K)begin
            Q <= 1'b1;
        end else if (!J && K)begin
            Q <= 1'b0;
        end else if (J && K)begin
            Q <= ~Q;
        end
    end
endmodule
