`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 08/20/2024 12:24:15 AM
// Design Name: 
// Module Name: mx
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


module mx(
    input  wire [7:0] A,
    input  wire [2:0] S,
    input  wire EN,
    output reg Out  
    );
    
    always @(*) begin
        if (EN) begin
            Out = 1'bz; // Alta impedancia 
        end else begin
            case (S)
                3'b000: Out = A[0];
                3'b001: Out = A[1];
                3'b010: Out = A[2];
                3'b011: Out = A[3];
                3'b100: Out = A[4];
                3'b101: Out = A[5];
                3'b110: Out = A[6];
                3'b111: Out = A[7];
                default: Out = 1'b0; 
            endcase
        end
    end
    
endmodule
