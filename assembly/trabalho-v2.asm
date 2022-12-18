; Simple example
; Writes Hello World to the output
; somar 2 numeros de 32 bits

JMP start
x_0: DB 88
x_1: DB 60
x_2: DB 10
x_3: DB 48
y_0: DB 59
y_1: DB 89
y_2: DB 20
y_3: DB 12
result: DB 0
temp_1: DB 0
temp_2: DB 0

start:
MOV A, [x_3]
ADD A, [y_3]
JC vaium_3
s1:
MOV [result], A
MOV D, 244
INC B
CALL print

soma_2:
MOV A, [x_2]
ADD A, [y_2]
JC vaium_2
s2:
MOV [result], A
MOV D, 240
INC B
CALL print

soma_3:
MOV A, [x_1]
ADD A, [y_1]
JC vaium_1
s3:
MOV [result], A
MOV D, 236
INC B
CALL print

soma_4:
MOV A, [x_0]
ADD A, [y_0]
JC over
MOV [result], A
MOV D, 232
INC B
CALL print

vaium_3:
MOV C, [x_2]
INC C
MOV [x_2], C
JMP s1

vaium_2:
MOV C, [x_1]
INC C
MOV [x_1], C
JMP s2

vaium_1:
MOV C, [x_0]
INC C
MOV [x_0], C
JMP s3

over:
MOV [result], 0
MOV D, 232
INC B
JMP print

print:
MOV A, [result]
DIV 100			; num/100*100=result/10=result
MOV [temp_1], A
ADD A, 48
MOV [D], A
MOV A, [temp_1]
MUL 100
MOV [temp_1], A
MOV A, [result]	
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
MOV A, [result]
SUB A, [temp_1]
SUB A, [temp_2]
ADD A, 48 ;transformando em ascii, 48 em ascii é zero
INC D
MOV [D], A
CMP B, 1
JE soma_2
CMP B, 2
JE soma_3
CMP B, 3
JE soma_4

HLT ;stop execution
