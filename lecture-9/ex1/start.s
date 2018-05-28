   area myarea,code,readonly
   entry
   code32
   mov  r1,#0x32  ;  int a = 0x31
   add  r0,r0,#1
loop
   b loop;   while(1);   goto loop
   end
