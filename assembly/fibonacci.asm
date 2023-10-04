; Simple example
; Writes Hello World to the output

	JMP start
numero: DB 15
soma: DB 0
primeiro: DB 0
segundo: DB 1

start:
	MOV C, [numero]
	CMP C, 2	
	JBE setar_soma 
	MOV C, 2
loop:
	CMP C, [numero]
	JE print
	MOV A, [primeiro]
	MOV B, [segundo]
	ADD A, B
	MOV [soma], A
	MOV A, [segundo]
	MOV [primeiro], A
	MOV B, [soma]
	MOV [segundo], B
	INC C
	JMP loop

setar_soma:
	CMP C, 1
	JE soma_0
	JNE soma_1
	MOV [soma], C
	JMP print

soma_0:
	MOV [soma], 0
	JMP print
soma_1:
	MOV [soma], 1
	JMP print

print:
	MOV A, [soma]
	DIV 100
	MOV [primeiro], A
	ADD A, 48
	MOV D, 232
	MOV [D], A
	MOV A, [primeiro]
	MUL 100
	MOV [primeiro], A
	MOV A, [soma]	
	SUB A, [primeiro]
	MOV [segundo], A
	DIV 10
	MOV [segundo], A
	ADD A, 48
	INC D
	MOV [D], A
	MOV A, [segundo]
	MUL 10
	MOV [segundo], A
	MOV A, [soma]
	SUB A, [primeiro]
	SUB A, [segundo]
	ADD A, 48
	INC D
	MOV [D], A

	
