; Simple example
; Writes Hello World to the output

JMP start
var_i: db 0
var_b: db 8
var_x: db 0
temp_1: db 0
temp_2: db 0

start:
	MOV A, [var_i]	; primeiro destino, depois origem
inicio_for:
	CMP A, 7
	JE fora_for
        MUL [var_b]
	ADD A, [var_x]
	MOV [var_x], A
	MOV A, [var_i]
	INC A
	MOV [var_i], A
	JMP inicio_for
fora_for:
	MOV A, [var_x]
	DIV 100			; num/100*100=result/10=result
	MOV [temp_1], A
	ADD A, 48
	MOV D, 232
	MOV [D], A
	MOV A, [temp_1]
	MUL 100
	MOV [temp_1], A
	MOV A, [var_x]	
	SUB A, [temp_1]
	MOV [temp_2], A
	DIV 10
	MOV [temp_2], A
	ADD A, 48
	INC D
	MOV [D], A
	MOV A, 	[temp_2]
	MUL 10
	MOV [temp_2], A
	MOV A, [var_x]
	SUB A, [temp_1]
	SUB A, [temp_2]
	ADD A, 48 ;transformando em ascii, 48 em ascii é zero
	INC D
	MOV [D], A
	


	HLT ;stop execution
