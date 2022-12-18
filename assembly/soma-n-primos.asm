; Simple example
; Writes Hello World to the output
;Calcule a soma de todos os números primos
;no intervalo de precisão da máquina, imprimindo a soma na saída.

JMP start

limite: DB 25
var_i: DB 1
var_j: DB 0
soma: DB 0
temp: DB 0
temp_2: DB 0
start:

loop:
MOV A, [var_i]
CMP A, [limite]
JE fora
MOV B, [var_i]
DEC B
MOV [temp], A

	loop_2:
	CMP B, 0
	JE sair_loop_2
	DIV B
	MOV [temp_2], B
	MUL B
	CMP A, [temp]
	JE somar
	JNE continue

	somar:
	INC C
	;MOV [soma], C
	JMP continue

	continue:
	SUB B, 1
	MOV A, [temp]
	JMP loop_2

sair_loop_2:
CMP C, 1
JE primo
JNE prox

primo:
ADD D, [temp]
MOV [soma], D
JMP prox

prox:
MOV A, [temp]
INC A
MOV [var_i], A
MOV C, 0
JMP loop


fora:
MOV A, [soma]
DIV 100			; num/100*100=result/10=result
MOV [temp], A
ADD A, 48
MOV D, 232
MOV [D], A
MOV A, [temp]
MUL 100
MOV [temp], A
MOV A, [soma]	
SUB A, [temp]
MOV [temp_2], A
DIV 10
MOV [temp_2], A
ADD A, 48
INC D
MOV [D], A
MOV A, [temp_2]
MUL 10
MOV [temp_2], A
MOV A, [soma]
SUB A, [temp]
SUB A, [temp_2]
ADD A, 48 ;transformando em ascii, 48 em ascii é zero
INC D
MOV [D], A



HLT

