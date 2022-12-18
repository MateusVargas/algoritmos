; Dado um número em uma posição de memória “n”, 
;verifique se este número é uma potência de k (constante do programa).
;Imprima “verdadeiro” ou “falso” na saída.

JMP start
true: DB "verdadeiro"
       DB 0
false: DB "falso"
	DB 0
msg: DB "overflow"
	DB 0
k: DB 4
num: DB 16
pot: DB 1

start:
	MOV A, [pot]
	for:
	MUL [k]
	JC overflow
	CMP A, [num]
	JAE func
	JMP for

	func:
	CMP A, [num]
	JA func_2
	
	func_1:
	MOV C, true    ; Point to var 
	JMP continue

	func_2:
	MOV C, false
	JMP continue

	overflow:
	MOV C, false
	JMP continue

	continue:
	MOV D, 232	; Point to output
	CALL print
        HLT             ; Stop execution

print:			; print(C:*from, D:*to)
	PUSH A
	PUSH B
	MOV B, 0
.loop:
	MOV A, [C]	; Get char from var
	MOV [D], A	; Write to output
	INC C
	INC D  
	CMP B, [C]	; Check if end
	JNZ .loop	; jump if not

	POP B
	POP A
	RET
