/*Dada uma pilha P, construir uma função que inverte a ordem dos elementos dessa pilha, utilizando apenas uma estrutura auxiliar. Definir adequadamente a estrutura auxiliar e prever a possibilidade da pilha 
estar vazia.*/

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 20

struct pilha{
	int tam;
	int pilha[TAMANHO];
};

void push(struct pilha *p,int num){
	if(p->tam==TAMANHO){
		printf("\npilha esta cheia");
		exit(0);
	}
	p->pilha[p->tam]=num;
	p->tam++;
}

void size(struct pilha *p){
	printf("\ntamanho da pilha: %d",p->tam);
}

void pop(struct pilha *p){
	if(p->tam==0){
		printf("\npilha vazia");
		exit(0);
	}
	p->tam--;
}

void inverter_ordem(struct pilha *p){
	struct pilha p_aux;
	p_aux.tam=p->tam;
	
	for(int i=0;i<(p->tam);i++){
		p_aux.pilha[i]=p->pilha[i];
	}
	
	for(int i=0;i<(p->tam);i++){
		p->pilha[i]=p_aux.pilha[(p_aux.tam-1)-i];
	}
}

void mostrar_pilha(struct pilha *p){
	for(int i=0;i<(p->tam);i++){
		printf("\npilha[%d]=%d",i,p->pilha[i]);
	}
}

int main(){
	struct pilha *p;
	
	p=(struct pilha*)malloc(sizeof(struct pilha*));
	
	p->tam=0;
	
	push(p,1);
	push(p,2);
	push(p,3);
	push(p,4);
	size(p);
	pop(p);
	size(p);
	
	mostrar_pilha(p);
	inverter_ordem(p);
	mostrar_pilha(p);
	return 0;
}
