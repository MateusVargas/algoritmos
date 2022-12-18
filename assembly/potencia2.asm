JMP start
var_gx: DB 1
var_x: DB 9
tmp_1: DB 0
tmp_2: DB 0
overf: DB "Overflow" 
       DB 0	

start:
	MOV D, 0
inicio_for:	
	CMP D, [var_x]
	JE fora_for
	MOV A, [var_gx]
	MUL 2
	JC print_over 
	MOV [var_gx], A
	INC D
	JMP inicio_for
fora_for:
	;print
; 215 / 100 = 2
; 215 - 200 = 15 / 10 = 1
; 215 - 200 - 10 = 5
MOV a, [var_gx]
DIV 100
ADD a, 48
MOV [232], a
SUB a, 48
MUL 100
MOV [tmp_1], a
MOV b, [var_gx]
SUB b, a
MOV a, b
DIV 10
ADD a, 48
MOV [233], a
SUB a, 48
MUL 10
MOV [tmp_2], a

MOV a, [var_gx]
SUB a, [tmp_1]
SUB a, [tmp_2]
ADD a, 48
MOV [234], a

HLT
	HLT

print_over:
	MOV C, overf    ; Point to var 
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
