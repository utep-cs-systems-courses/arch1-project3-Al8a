.text
	.balign 2
	.global buzzer_timer_interrupt

jump_table:
	.word buzzer_on
	.word buzzer_off

	.extern buzzer_state
	.extern update_state

buzzer_timer_interrupt:
	mov &buzzer_state, r12
	add r12, r12
	mov jump_table(r12), r0

buzzer_off:
	jmp done
buzzer_on:
	call #update_state
	jmp done

done:
	ret
