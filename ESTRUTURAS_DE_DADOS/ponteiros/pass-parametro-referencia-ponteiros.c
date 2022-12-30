// passagem de parametros por referencia usando ponteiros
#include <stdio.h>

//a função recebe 2 ponteiros
//a troca de valores é feita diretamente na memória
void trocar(int *pta, int *ptb){
    int aux;
    aux = *pta; //aux=5, aux recebe o valor da variavel que pta aponta
    *pta = *ptb; //valor da variavel que pta aponta = 19
    *ptb = aux; //valor da variabel que ptb aponta = 5
}

int main() {
    int a=19,b=5;
    int *pA = &a, *pB = &b;//ponteiros que guardam os endereços das variaveis
    
    printf("a: %d, b: %d",a,b);
    trocar(pA,pB);
    //trocar(&a,&b); //outra forma de chamar função
    printf("\na: %d, b: %d",a,b);
     
    return 0;
}