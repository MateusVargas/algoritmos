//lista duplamente emcadeada circular
#include <stdio.h>
#include <stdlib.h>

struct lista{
	int valor;
	struct lista *anterior;
	struct lista *proximo;
};

typedef struct lista Lista;


Lista* inserir_inicio(Lista *inicio,Lista **fim,int num){
	Lista *novo=(Lista*)malloc(sizeof(Lista));
	novo->valor = num;
	
	if(inicio==NULL){
		novo->anterior=novo;
		novo->proximo=novo;
		inicio=novo;
		(*fim)=inicio;
	}
	else{
		inicio->anterior=novo;
		novo->anterior=(*fim);
		novo->proximo=inicio;
		inicio=novo;
		(*fim)->proximo=inicio;
	}
	
	return inicio;
}


Lista* inserir_fim(Lista *inicio,Lista **fim,int num){
	Lista *novo = (Lista*)malloc(sizeof(Lista));
	novo->valor=num;
	
	if(inicio==NULL){
		novo->proximo=novo;
		novo->anterior=novo;
		inicio=novo;
		(*fim)=inicio;
	}
	else{
		novo->anterior=(*fim);
		novo->proximo=inicio;
		inicio->anterior=novo;
		(*fim)->proximo=novo;
		(*fim)=novo;
	}
	
	return inicio;
}


void imprimir(Lista *inicio){
	Lista *iterator = inicio;
	
	if(inicio==NULL){
		printf("lista vazia\n");
	}
	else{
		do
		{
			printf("%d\t",iterator->valor);
			iterator = iterator->proximo;
		}while(iterator!=inicio);
	}
}

void imprimir_contr(Lista *fim){
	Lista *iterator = fim;
	
	if(fim==NULL){
		printf("lista vazia\n");
	}
	else{
		do{
			printf("%d\t",iterator->valor);
			iterator=iterator->anterior;
		}while(iterator != fim);
	}
}


Lista* apagar(Lista *inicio,Lista **fim,int num){
	
	Lista *iterator = inicio;
	int achou = 0;
	
	if(inicio==NULL){
		printf("lista vazia\n");
	}
	else{
	
		do{
			if(iterator->valor==num){
				achou=1;
				break;
			}
			
			iterator = iterator->proximo;
		}while(iterator != inicio);
		
		if(!achou){
			printf("nao emcontrado\n");
		}
		else{
			if(iterator == inicio){
				
				if(inicio==*fim){
					inicio=NULL;
					*fim=NULL;
				}
				else{
					inicio=inicio->proximo;
					inicio->anterior=(*fim);
					(*fim)->proximo=inicio;
				}
				
			}
			
			else if(iterator==*fim){
				(*fim)=(*fim)->anterior;
				(*fim)->proximo=inicio;
			}
			
			else{
				iterator->anterior->proximo=iterator->proximo;
				iterator->proximo->anterior=iterator->anterior;
			}
			
			free(iterator);
		}	
		
	}
	
	return inicio;
}


int main(){
	Lista *inicio = NULL, *fim = NULL;
	int op, num;
	
	do{
		printf("\n1-inserir inicio\n");
		printf("2-inserir fim\n");
		printf("3-remover\n");
		printf("4-imprimir\n");
		printf("5-imprimir tras pra frente\n");
		printf("9-sair\n");
		scanf("%d",&op);
	
		switch(op){
			case 1:
				printf("valor: ");
				scanf("%d",&num);
				inicio=inserir_inicio(inicio,&fim,num);
				break;
			case 2:
				printf("valor: ");
				scanf("%d",&num);
				inicio=inserir_fim(inicio,&fim,num);
				break;
			case 3:
				printf("valor pra apagar: ");
				scanf("%d",&num);
				inicio=apagar(inicio,&fim,num);
				break;
			case 4:
				imprimir(inicio);
				break;
			case 5:
				imprimir_contr(fim);
				break;
		}
		
	}while(op!=9);
	
	
	
	return 0;
}
