;Write an assembly level program to stroe 5 64 bit hexadecimal number from user and store it in array and display back on screen
;Name: Priyanshu Rawat (7242)
;Date of Program: 1 March 2023

%macro read 2			;macro for reading
	mov rax, 0
	mov rdi, 0
	mov rsi, %1
	mov rdx, %2
	syscall
%endmacro

%macro write 2			;macro for writing
	mov rax, 1
	mov rdi, 1
	mov rsi, %1
	mov rdx, %2
	syscall
%endmacro

section .data
	msg1 db "Enter 5 64-bit hexadecimal numbers: ",10
	msg1_len equ $-msg1
	msg2 db "Your numbers are:",10
	msg2_len equ $-msg2
	endl db 10
	
	
section .bss
	num resb 17			;16 characters and 1 bit for newline 
	hex resq 5			;hex representation
	ascii resb 16		;ascii representation

section .text

global _start

_start:
	
	write msg1, msg1_len

	mov rcx, 5
	mov rsi, hex

main_loop:	

	push rsi
	push rcx
	
	read num, 17

	call ascii_hex64
	
	pop rcx
	pop rsi
	
	mov [rsi],rbx
	add rsi,8
	loop main_loop
	
	write endl,1
	write msg2, msg2_len
	
	mov rcx, 5
	mov rsi, hex
	
write_loop:

	mov rbx,[rsi]
	
	push rcx
	push rsi
	
	call hex_ascii64
	
	pop rsi
	pop rcx
	
	add rsi,8
	
	loop write_loop
	
	mov rax,60
	mov rdi,0
	syscall
	
ascii_hex64:
	mov rbx,0			;stores the hex representation
	mov rcx,16			;because 64 bit number
	mov rsi,num			;pointing to current character
	
next:
	rol rbx,4			;rotate left rbx by 4 bits
	mov al,[rsi]
	cmp al,39h			;check if given char is 0-9 or A-F
	jbe sub30h
	sub al,7h
sub30h:
	sub al,30h
	
	add bl,al			;add to hex number
	inc rsi				;moving on the next character
	
	loop next
	
ret 
	
hex_ascii64:
	mov rsi,ascii 		;rsi points to array
	mov rcx,16
	
	
next2:
	rol rbx,4			;rotate left rbx by 4
	mov al,bl			
	and al,0Fh
	cmp al,9
	jbe add30h
	add al,7h
add30h:
	add al,30h
	
	mov [rsi],al
	inc rsi
	
	loop next2
	write ascii, 16
	write endl,1
ret
	
	
	
	
	
	
	
	
	
	
	
