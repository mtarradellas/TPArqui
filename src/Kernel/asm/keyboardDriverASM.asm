GLOBAL _getKey

section .text

_getKey:
	mov rax, 0
	IN al, 60h
	ret
