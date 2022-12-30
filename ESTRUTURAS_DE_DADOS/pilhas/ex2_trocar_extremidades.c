/*Construir uma função que troca de lugar o elemento que está no topo da pilha com o que está na base da pilha. Usar apenas uma pilha como auxiliar.*/
#include <stdio.h>
#include <stdlib.h>

void add(int *p,int *tot,int num){
	if(*tot==10){
		printf("\npilha cheia");
		exit(0);
	}
	p[*tot]=num;
	(*tot)++;
}

void mostra(int *p,int tot){
	for(int i=0;i<tot;i++){
		printf("%d\t",p[i]);
	}
	printf("\n");
}

void troca(int *pilha,int tot){
	int aux[tot];
	
	for(int i=0;i<tot;i++){
		aux[i]=pilha[i];
	}
	
	pilha[0]=aux[tot-1];
	pilha[tot-1]=aux[0];
}

int main(){
	int *pilha, total=0;
	
	pilha=(int*)malloc(sizeof(int*)*10);
	//alocando memoria pro vetor
	
	add(pilha,&total,1);
	add(pilha,&total,2);
	add(pilha,&total,3);
	mostra(pilha,total);
	troca(pilha,total);
	mostra(pilha,total);
	
	return 0;
}
