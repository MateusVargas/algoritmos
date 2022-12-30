/*
ponteiros:
- Um ponteiro é um tipo especial de variável que armazena um endereço
- Se um ponteiro p armazena o endereço de uma variável i, podemos dizer p aponta para i, ou, p é o endereço de i. 
- Se um ponteiro p tem valor diferente de NULL então *p é o valor da variável apontada por p. 
  Por exemplo, se i é uma variável e p vale &i então dizer *p é o mesmo que dizer i
  
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int idade = 34;
    printf("%x",&idade);
    //%x mostra valores hexadecimais
    //& retorna o endereço de memoria da variavel
    
    int *p; //declaração de um ponteiro para valores inteiros
    //int* p; //outra forma de declarar
    
    float *p2; //ponteiro para float
    char *p3; //ponteiro para char
    
    struct teste *p4; //ponteiro para struct
    
    int **p5; //ponteiro para outro ponteiro
    
    
    
    int a=5, b=3, *pA, *pB, soma;
    //ponteiro deve ser inicializado recebendo o endereço de memoria da variavel
    
    pA = &a;//pA aponta para o endereço de memoria de a e pB para o endereço de b
    pB = &b;
    
    soma = *pA + *pB; //pA guarda o endereço de a, mas, *pA retorna o valor de a, por isso da pra fazer a soma
    printf("\nsoma %d",soma);
    
    int **r;
    r = &pA; //r aponta pro endereço de pA
    soma += **r; //**r aponta pro valor da variavel que pA aponta
    printf("\nsoma %d",soma);
    
    int *p6, c=7;
    p6 = &c;
    *p6 = 99;//valor de c tambem será alterado
    
    printf("\np6: %d",p6);//endereço de memoria do ponteiro
    printf("\n&p6: %x",&p6);//endereço de memoria do ponteiro, pois ele é uma variavel tambem e ocupa espaço na memoria
    printf("\n*p6: %d",*p6);//valor da variavel que o ponteiro aponta, ex: p6 = &a, entao *p6=5
    
    return 0;
}


