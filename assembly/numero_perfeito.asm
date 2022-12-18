; Simple example
; Writes Hello World to the output
;Dado um número em uma posição de memória 
;verifique se este é um número perfeito. Imprima “verdadeiro” ou ;“falso” na saída.

	JMP start
verdadeiro: DB "verdadeiro"
	DB 0	; String terminator
falso:      DB "falso"
	DB 0	; String terminator

num: DB 6
var_i: DB 0
soma: DB 0
temp: DB 0

start:
MOV A, [num]
SUB A, 1
MOV [var_i], A

loop:
MOV B, [var_i]
CMP B, 0
JE fora
MOV A, [num]
DIV B
MOV [temp], B
MUL B
CMP A, [num]
JE somar
JNE t

somar:
ADD C, [temp]
MOV [soma], C
JMP t

t:
MOV B, [var_i]
DEC B
MOV [var_i], B
JMP loop

fora:
MOV A, [soma]
CMP A, [num]
JE true
JNE false

true:
MOV C, verdadeiro
MOV D, 232
JMP print

false:
MOV C, falso
MOV D, 232
JMP print

print:
MOV A, [C]	; Get char from var
MOV [D], A	; Write to output
INC C
INC D  
CMP B, [C]	; Check if end
JNZ print	; jump if not

