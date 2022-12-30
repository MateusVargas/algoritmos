#include <stdio.h>
#include <stdlib.h>

struct lista{
	int valor;
	struct lista *anterior;
	struct lista *proximo;
};

typedef struct lista Lista;


void inserir_inicio(Lista **inicio,int num){
	Lista *novo=(Lista*)malloc(sizeof(Lista));
	novo->valor=num;
	novo->anterior=NULL;
	
	if(*inicio==NULL){
		novo->proximo=NULL;
		*inicio=novo;
	}
	else{
		(*inicio)->anterior=novo;
		novo->proximo=*inicio;
		*inicio=novo;
	}
}



void inserir_fim(Lista **inicio,int num){
	Lista *novo=(Lista*)malloc(sizeof(Lista));
	Lista *iterator = *inicio;
	
	novo->valor=num;
	novo->proximo=NULL;
	
	if(*inicio==NULL){
		novo->anterior=NULL;
		*inicio=novo;
	}
	else{
			
		while(iterator->proximo != NULL){
			iterator=iterator->proximo;
		}
		
		iterator->proximo=novo;
		novo->anterior=iterator;
	}	
}



void imprimir(Lista *inicio){
	if(inicio != NULL){
		printf("%d\t",inicio->valor);
		imprimir(inicio->proximo);
	}
}



void remover(Lista **inicio,int num){
	Lista *iterator = *inicio;
	
	if((*inicio)->valor == num){
		
		if((*inicio)->proximo != NULL){
			free((*inicio)->proximo->anterior);
			(*inicio)->proximo->anterior=NULL;
			*inicio=(*inicio)->proximo;
		}
		else{
			*inicio=NULL;
			free(*inicio);
		}
		
	}
	
	else{
		
		while(iterator != NULL && iterator->valor != num){
			iterator=iterator->proximo;
		}
		
		if(iterator == NULL){
			printf("nao encontrado\n");
		}
		else{
			
			if(iterator->proximo == NULL){
				iterator->anterior->proximo = NULL;
			}
			else{
				iterator->anterior->proximo = iterator->proximo;
				iterator->proximo->anterior = iterator->anterior;
			}
			
			free(iterator);
		}
		
	}
}


void inserir_ordenado(Lista **inicio,int num){
	Lista *iterator = *inicio, *ant = NULL;
	Lista *novo=(Lista*)malloc(sizeof(Lista));
	novo->valor=num;
	
	if(*inicio==NULL){
		novo->anterior=NULL;
		novo->proximo=NULL;
		*inicio=novo;
	}
	else if((*inicio)->proximo==NULL){
		
		if(novo->valor < (*inicio)->valor){
			novo->anterior=NULL;
			novo->proximo=*inicio;
			(*inicio)->anterior = novo;
			*inicio=novo;
		}
		else{
			novo->anterior=*inicio;
			novo->proximo=NULL;
			(*inicio)->proximo=novo;
		}
	}
	else{
		
		while(iterator != NULL && novo->valor > iterator->valor){
			ant = iterator;
			iterator=iterator->proximo;
		}
		
		if(iterator == NULL){
			novo->proximo = NULL;
			novo->anterior = ant;
			ant->proximo = novo;
		}
		else if(ant == NULL){
			novo->anterior = NULL;
			novo->proximo = *inicio;
			(*inicio)->anterior = novo;
			(*inicio) = novo;
		}
		else{
			printf("a");
			novo->proximo = iterator;
			novo->anterior = ant;
			ant->proximo = novo;
			//iterator->anterior->proximo = novo;
			iterator->anterior = novo;
		}
		
	}
	
}



int main(){
	Lista *inicio = NULL;
	int op, num;
	
	do{
		printf("1-inserir inicio\n");
		printf("2-inserir fim\n");
		printf("3-inserir ordenado\n");
		printf("4-remover\n");
		printf("5-imprimir\n");
		printf("9-sair\n");
		scanf("%d",&op);
		
		switch(op){
			case 1:
				printf("valor: ");
				scanf("%d",&num);
				inserir_inicio(&inicio,num);
				break;
			
			case 2:
				printf("valor: ");
				scanf("%d",&num);
				inserir_fim(&inicio,num);
				break;
			
			case 3:
				printf("valor: ");
				scanf("%d",&num);
				inserir_ordenado(&inicio,num);
				break;
			
			case 4:
				if(inicio==NULL){
					printf("lista vazia\n");
				}
				else{
					printf("valor: ");
					scanf("%d",&num);
					remover(&inicio,num);
				}
				break;
				
			case 5:
				imprimir(inicio);
				printf("\n");
				break;
		}
		
	}while(op!=9);
	
	return 0;
}
