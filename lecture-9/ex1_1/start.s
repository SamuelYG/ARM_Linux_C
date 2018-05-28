   area myabc,code,readonly
   entry  ;   // main  function
   code32
   movs  r0,#0x1e   ; int a = 30
   ; a++
   add  r0,r0,#1
loop
   b loop;
   end
