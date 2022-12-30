#include <stdio.h>
#include <stdlib.h>

struct lista{
	int valor;
	struct Lista *prox;
};

typedef struct lista Lista;


int empty(Lista *inicio){
	if(inicio==NULL){
		return 1;
	}
	return 0;
}


void inserir_fim(Lista **inicio, int num){
	Lista *iterator=*inicio;
	Lista *novo=(Lista*)malloc(sizeof(Lista));
	
	novo->valor=num;
	novo->prox=NULL;
	
	if(empty(*inicio)){
		*inicio=novo;
	}
	else{
		while(iterator->prox!=NULL){
			iterator=iterator->prox;
		}
		
		iterator->prox=novo;
	}
}


void remover_inicio(Lista **inicio){
	if(empty(*inicio)){
		printf("lista vazia\n");
	}
	else{
		*inicio=(*inicio)->prox;
	}
}


int tamanho(Lista *inicio){
	int tamanho = 0;
	
	while(inicio!=NULL){
		tamanho++;
		inicio=inicio->prox;
	}
	
	return tamanho;
}


void front(Lista *inicio){
	if(empty(inicio)){
		printf("lista vazia\n");
	}
	else{
		printf("%d\n",inicio->valor);
	}
}


void imprimir(Lista *inicio){
	while(inicio!=NULL){
		printf("%d\t",inicio->valor);
		inicio=inicio->prox;
	}
	printf("\n");
}


int main(){
	Lista *inicio=NULL;
	int op, num;
	
	do{
		printf("1-inserir\n");
		printf("2-remover\n");
		printf("3-imprimir\n");
		printf("4-primeiro elemento\n");
		printf("5-tamanho da fila\n");
		printf("9-sair\n");
		scanf("%d",&op);
		
		switch(op){
			case 1:
				printf("valor: ");
				scanf("%d",&num);
				inserir_fim(&inicio,num);
				break;
			
			case 2:
				remover_inicio(&inicio);
				break;
			
			case 3:
				imprimir(inicio);
				break;
			
			case 4:
				front(inicio);
				break;
			
			case 5:
				printf("%d\n",tamanho(inicio));
				break;
		}
		
	}while(op!=9);
	
	return 0;
}
