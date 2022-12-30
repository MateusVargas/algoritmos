/*Dada uma pilha contendo números inteiros quaisquer, construir uma função que coloca os pares na base da pilha e os ímpares no topo da pilha. Usar duas pilhas como auxiliares.*/
#include <stdio.h>
#include <stdlib.h>

#define tamanho 30

void push(int *p,int *total,int num){
	if(*total==tamanho){
		exit(0);
	}
	p[*total]=num;
	(*total)++;
}


void mostrar(int *p,int t){
	for(int i=0;i<t;i++){
		printf("%d\t",p[i]);
	}
	printf("\n");
}


void agrupar(int *p,int t){
	int pares[tamanho], impares[tamanho];
	int index_pares=0, index_imp=0;
	
	for(int i=0;i<t;i++){
		if(p[i]%2==0){
			pares[index_pares]=p[i];
			index_pares++;
		}
		else{
			impares[index_imp]=p[i];
			index_imp++;
		}
	}
	
	for(int i=0;i<index_pares;i++){
		p[i]=pares[i];
	}
	for(int i=index_pares;i<index_pares+index_imp;i++){
		p[i]=impares[i-index_pares];
	}
}


int main(){
	int *pilha, total=0;
	pilha=(int *)malloc(sizeof(int*)*tamanho);
	
	push(pilha,&total,1);
	push(pilha,&total,2);
	push(pilha,&total,3);
	push(pilha,&total,4);
	push(pilha,&total,5);
	push(pilha,&total,6);
	push(pilha,&total,8);
	
	mostrar(pilha,total);
	agrupar(pilha,total);
	mostrar(pilha,total);
	
	return 0;
}
