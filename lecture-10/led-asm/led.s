    area abc,code,readonly
    code32
    entry
	ldr r0,=0x56000050
	mov r1,#0x1400
	str r1,[r0]
kkk  ; led on
	ldr r0,=0x56000054
	mov r1,0x0
	str r1,[r0]
	
	ldr r0,=10000
loop
    sub r0,r0,#1
	cmp r0,#0
    bne loop
	; led off
	ldr r0,=0x56000054
	mov r1,0x60    ; 0110 0000
	str r1,[r0]
	
	ldr r0,=10000
loop1
    sub r0,r0,#1
	cmp r0,#0
    bne loop1
	b  kkk
    end
