`timescale 1ns / 1ps

/////
module maquina_100(
    input X, clk, reset,
    output reg Y
    );
    
    
    //Definition's state
parameter s0 = 2'b00,
          s1 = 2'b01,
          s2 = 2'b10,
          s3 = 2'b11;

reg [1:0] state,posState;

    
    always @(posedge clk )begin
    
        case(state)
        
            0: begin
                if(X)begin
                    state <= s1;
                end else begin
                    state <= s0;
                end
            end
            
            1: begin
                if(X)begin
                    state <= s1;
                end else begin
                    state <= s2;
                end
            end
            
            2: begin
                if(X)begin
                    state <= s1;
                end else begin
                    state <= s3;
                end
            end
            
            3: begin
                if(X)begin
                    state <= s1;
                end else begin
                    state <= s0;
                end
            end
            
            default: state <= s0;
        endcase      
    end
            
    always @(state)begin
    
        if(state == s3)begin
        
          Y = 1'b1;
        end
    end
    
endmodule
