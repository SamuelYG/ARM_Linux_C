   area abc,code,readonly
   code32
   PRESERVE8
   import mymain
   entry
   ldr sp,=0x1000  ; 4k
   mov r0,#100
   mov r1,#12
   mov r2,#11
   bl mymain
   mov r1,r0
loop
   b loop
   end
