
	;; switch_update_interrupt_handler-s.s
.text
	.balign 2

	.global switch_update_interrupt_sense
	.extern P2IES
	.extern P2IN
	

switch_update_interrupt_sense:

	sub.w 	#4, r1  		; Make room for temp variables
	
	mov.b 	&P2IN, 0(r1)    	; Move P2IN into p2val
	mov.b 	0(r1), 1(r1)		; T1
	mov.b 	0(r1), 2(r1)		; T2
	
	and.b 	#31, 0(r1)		; T1 = (p2val & SWITCHES)
	bis.b 	1(r1), &P2IES 		; P2IES |= T1 

	bis.b 	#0x7f, 2(r1)		; T2 = (p2val | ~SWITCHES)
	and.b 	2(r1), &P2IES  		; P2IES &= T2 

	mov.b 	0(r1), r12		; Move p2val into return address register
	add 	#4, r1			; Add stack pointer back 
	pop 	r0 			; pop program counter 
	
