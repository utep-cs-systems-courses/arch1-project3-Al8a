.text
	.balign 2
	
	.global switch_interrupt_handler 	;function is gonna be available oustide of this file.
	.extern switches 
	.extern switch_update_interrupt_sense 	;inlcude all functions and variables used from another file.
switch_interrupt_handler:
	call 	#switch_update_interrupt_sense	; p2val in 0(r1)
	xor.b 	#0xFF, r12			; coulde also be 0xff to get 1111 1111. r12 -> p2val from original. Instruction: ~p2val -> xor r12 with 1111 1111
	and.b 	#15, r12 			; p2val & switches. switches -> 0001 1111
	mov.b 	r12, &switches 
	pop 	r0
	
