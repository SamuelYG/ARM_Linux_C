   area myarea,code,readonly
   code32
   entry
   PRESERVE8
   import mymain
   ldr sp,=0x1000
   mov r0,#0x10
   mov r1,#0x11
   bl  mymain
   mov r1,r0
loop
   b loop
   end
