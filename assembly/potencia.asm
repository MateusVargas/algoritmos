; Simple example
; Writes Hello World to the output

JMP start
var_x: DB 10
var_gx: DB 1
temp_1: DB 0
temp_2: DB 0

start:
CMP B, [var_x]
JE fora
MOV A, [var_gx]
MUL 2
JC fora
MOV [var_gx], A
MOV A, B
INC A
MOV B, A
JMP start

fora:
MOV A, [var_gx]
DIV 100			; num/100*100=result/10=result
MOV [temp_1], A
ADD A, 48
MOV D, 232
MOV [D], A
MOV A, [temp_1]
MUL 100
MOV [temp_1], A
MOV A, [var_gx]	
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
MOV A, [var_gx]
SUB A, [temp_1]
SUB A, [temp_2]
ADD A, 48 ;transformando em ascii, 48 em ascii é zero
INC D
MOV [D], A

HLT ;stop execution
