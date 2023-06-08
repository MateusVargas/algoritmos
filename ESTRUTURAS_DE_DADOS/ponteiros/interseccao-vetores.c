/*
Crie uma função	que	receba como	parâmetros dois	
vetores de inteiros: x1 e x2 e as suas respectivas
quantidades de elementos: n1 e n2. A função deverá
retornar um ponteiro para um terceiro vetor, x3,
alocado	dinamicamente, contendo	a intersecção de
x1 e x2 e usar o ponteiro qtd para retornar	o tamanho
de x3. Sendo x1	= {1,3,5,6,7} e	x2 = {1,3,4,6,8},
x3 irá conter {1,3,6}. Assinatura da função: 
int* interseccao(int *x1, int *x2, int n1, int n2,
int *qtd);
*/
#include <stdio.h>
#include <stdlib.h>

int* interseccao(int *x1,int *x2,int n1,int n2,int *qtd){
	for(int i=0;i<n1;i++){
		for(int j=0;j<n2;j++){
			if(*(x1+i) == *(x2+j)){
				(*qtd)++;
			}
		}
	}
	
	int *x3=(int*)malloc(*qtd*sizeof(int));
	int pos=0;
	
	for(int i=0;i<n1;i++){
		for(int j=0;j<n2;j++){
			if(*(x1+i) == *(x2+j)){
				*(x3+pos)=*(x1+i);
				pos++;
			}
		}
	}

	return x3;
}

int main(){
	int x1[5]={1,3,5,6,7};
	int x2[5]={1,3,4,6,8};
	int *x3;
	int qtd=0;
	
	x3=interseccao(x1,x2,7,5,&qtd);
	
	for(int i=0;i<qtd;i++){
		printf("%d\t",*(x3+i));
	}
	
	return 0;
}
