#include <stdio.h>
#include <stdlib.h>

struct lista{
	int valor;
	struct lista *prox;
};


struct lista* inserir_inicio(
	struct lista *inicio,
	int num
){
	struct lista *novo;
	novo=(struct lista*)malloc(sizeof(struct lista));
	novo->valor=num;
	
	if(inicio==NULL){
		novo->prox=NULL;
		inicio=novo;
	}
	else{
		novo->prox=inicio;
		inicio=novo;
	}
	
	return inicio;
}


void inserir_fim(struct lista *inicio,int num){
	struct lista *novo, *iterator = inicio;
	novo =(struct lista*)malloc(sizeof(struct lista));
	novo->valor=num;
	novo->prox = NULL;
	
	while(iterator->prox != NULL){
		iterator=iterator->prox;
	}
	iterator->prox = novo;
}



void imprimir(struct lista *inicio){
	struct lista *iterator = inicio;
	
	if(inicio==NULL){
		printf("losta vazia");
	}
	else{
		for(;iterator != NULL;iterator=iterator->prox){
			printf("%d\t",iterator->valor);
		}
	}
}



void trocar_nos(struct lista *inicio, int a, int b){
	struct lista *nodeA=NULL, *nodeB=NULL;
	struct lista *iterator = inicio, aux, *aux_prox;
	
	while(inicio != NULL){
		if(inicio->valor == a){
			nodeA = inicio;
		}
		else if(inicio->valor == b){
			nodeB = inicio;
		}
		inicio=inicio->prox;
	}
	
	if(nodeA != NULL && nodeB != NULL){
		aux = *nodeA;
		*nodeA = *nodeB;
		*nodeB = aux;

		aux_prox = nodeA->prox;
		nodeA->prox = nodeB->prox;
		nodeB->prox = aux_prox;	
	}

}


int main(){
	struct lista *inicio=NULL;
	inicio = inserir_inicio(inicio,7);
	inicio = inserir_inicio(inicio,6);
	inicio = inserir_inicio(inicio,5);
	inicio = inserir_inicio(inicio,4);
	inicio = inserir_inicio(inicio,3);
	inicio = inserir_inicio(inicio,2);
	inicio = inserir_inicio(inicio,1);
	inserir_fim(inicio,8);
	
	imprimir(inicio);
	
	printf("\n");
	
	trocar_nos(inicio,2,5);
	printf("\ninicio: %d\n\n",inicio->valor);
	imprimir(inicio);
	
	trocar_nos(inicio,1,4);
	printf("\ninicio: %d\n\n",inicio->valor);
	imprimir(inicio);
	
	trocar_nos(inicio,8,3);
	printf("\ninicio: %d\n\n",inicio->valor);
	imprimir(inicio);
	
	trocar_nos(inicio,1,2);
	printf("\ninicio: %d\n\n",inicio->valor);
	imprimir(inicio);

}
