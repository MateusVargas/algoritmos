#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_PILHA 100


//struct pra guadar a pilha e a variavel que controla o tamanho dela
struct pilha{
	int topo;
	int itens[TAMANHO_PILHA];
};


//verifica se a pilha esta vazia
int empty(struct pilha *p){
	if(p->topo==-1){
		return 1;
	}
	return 0;
}


//remove o elemento do topo da pilha e retorna o elemento do topo
int pop(struct pilha *p){
	if(empty(p)){
		printf("\npilha vazia");
		exit(0);
	}
	//p->topo--;
	//printf("\ntopo %d",p->topo);
	return (p->itens[p->topo--]);
}


//verifica se a pilha esta cheia, e adiciona o elemento no topo
void push(struct pilha *p, int valor){
	if(p->topo==TAMANHO_PILHA-1){
		printf("\npilha esta cheia");
		exit(0);
	}
	p->itens[++(p->topo)]=valor;
}


//retorna o tamanho da pilha, +1 porque comeca em zero
int size(struct pilha *p){
	return p->topo+1;
}


//retorna o elemento do topo da pilha
int stackpop(struct pilha *p){
	return p->itens[p->topo];
}


int main(){
	struct pilha pilha;
	pilha.topo=-1;
	
	push(&pilha,1);
	push(&pilha,2);
	push(&pilha,3);
	
	printf("\ntamanho da pilha: %d",size(&pilha));
	printf("\nelemento do topo: %d",stackpop(&pilha));
	
	printf("\nretirando elemento e trazendo o elemento do topo: %d",pop(&pilha));
	//printf("\ntopo %d",pilha.topo);
	printf("\nretirando elemento e trazendo o elemento do topo: %d",pop(&pilha));
	//printf("\ntopo %d",pilha.topo);
	printf("\ntamanho da pilha: %d",size(&pilha));
	return 0;
}
