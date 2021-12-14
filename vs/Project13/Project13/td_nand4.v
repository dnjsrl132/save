`timescale 1ns/1ps
module tb_nand4;
   reg [3:0] a;
   wire y;
   integer i;

   nand4_if tb(a,y);

   //------���⼭ ���� �Ʒ� �������� waveform�� �������� ������ ����� �ڵ��̴�.---- 
   initial
   begin
      $dumpfile("test_out.vcd");
      $dumpvars(-1,tb);  // tb�� ���� nand4_if tb(a,y)�� tb�� ���Ѵ�. 
      $monitor("%b",y);
   end
   //------------------------------------------------------------------------------

   initial
   begin
      a=0;
      for(i=0; i<32; i = i+1)
      begin
         #20;
         a=i;
      end
      $finish;
   end
endmodule