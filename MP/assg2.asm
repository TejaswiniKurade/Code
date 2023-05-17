%macro read 2
	mov rax, 0
	mov rdi, 0
	mov rsi, %1
	mov rdx, %2
	syscall
%endmacro

%macro write 2
	mov rax, 1
	mov rdi, 1
	mov rsi, %1
	mov rdx, %2
	syscall
%endmacro


section .data
	msg db "Enter the String :"
	len equ $-msg
	endl db 10

section .bss
	string resb 40
	temp resb 2
	
section .text
	global _start
_start :

	write msg, len
	write endl, 1
	
	read string, 40
	
	dec rax
	mov rbx, rax
	
	call display
	
	mov rax, 60
	mov rsi, 0
	syscall 
	
display :
	mov rsi, temp
	mov cx, 10 
	next :
		xor edx, edx
		div cx 
		add dl, '0' 
		mov [rsi], dl 
		dec rsi
		test ax, ax
		jnz next
			
		inc rsi 
		write rsi, 3
		write endl, 1
		ret
	