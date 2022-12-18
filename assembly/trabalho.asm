; Simple example
; Writes Hello World to the output

JMP start
x_0: DB 8
x_1: DB 6
x_2: DB 1
x_3: DB 4
y_0: DB 5
y_1: DB 0
y_2: DB 2
y_3: DB 9
r_0: DB 0
r_1: DB 0
r_2: DB 0
r_3: DB 0
r_4: DB 0
temp_1: DB 0


start:
MOV A, [x_3]
ADD A, [y_3]
CMP A, 10
JAE vaium_3
MOV [r_4], A

soma_2:
MOV A, [x_2]
ADD A, [y_2]
CMP A, 10
JAE vaium_2
MOV [r_3], A

soma_3:
MOV A, [x_1]
ADD A, [y_1]
CMP A, 10
JAE vaium_1
MOV [r_2], A

soma_4:
MOV A, [x_0]
ADD A, [y_0]
MOV [r_1], A
CMP A, 10
JAE vaium_0
JMP print

vaium_3:
SUB A, 10
MOV B, [x_2]
INC B
MOV [x_2], B
MOV [r_4], A
JMP soma_2

vaium_2:
SUB A, 10
MOV B, [x_1]
INC B
MOV [x_1], B
MOV [r_3], A
JMP soma_3

vaium_1:
SUB A, 10
MOV B, [x_0]
INC B
MOV [x_0], B
MOV [r_2], A
JMP soma_4

vaium_0:
SUB A, 10
MOV [r_0], 1
MOV [r_1], A
JMP print


print:
MOV A, [r_0]
MOV [temp_1], A
ADD A, 48
MOV D, 232
MOV [D], A
INC D
MOV A, [r_1]
MOV [temp_1], A
ADD A, 48
MOV [D], A
INC D
MOV A, [r_2]
MOV [temp_1], A
ADD A, 48
MOV [D], A
INC D
MOV A, [r_3]
MOV [temp_1], A
ADD A, 48
MOV [D], A
INC D
MOV A, [r_4]
MOV [temp_1], A
ADD A, 48
MOV [D], A


HLT ;stop execution
