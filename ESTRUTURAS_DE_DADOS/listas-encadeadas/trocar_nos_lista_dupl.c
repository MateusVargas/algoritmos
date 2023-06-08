#include <stdio.h>
#include <stdlib.h>

struct lista{
	int num;
	struct lista *anterior;
	struct lista *proximo;
};
typedef struct lista Lista;

Lista* inserir_inicio(Lista *inicio,int num){
	Lista *novo = (Lista*)malloc(sizeof(Lista));
	novo->num=num;
	novo->anterior=NULL;
	novo->proximo=inicio;
	
	if(inicio!=NULL){
		inicio->anterior=novo;
	}
	
	inicio=novo;
	return inicio;
}

Lista* inserir_fim(Lista *inicio,int num){
	Lista *novo=(Lista*)malloc(sizeof(Lista));
	novo->num=num;
	novo->proximo=NULL;
	
	if(inicio==NULL){
		novo->anterior=NULL;
		inicio=novo;
	}
	else{
		Lista *iterator=inicio;
		while(iterator->proximo!=NULL){
			iterator=iterator->proximo;
		}
		iterator->proximo=novo;
		novo->anterior=iterator;
	}
	
	return inicio;
}

void imp(Lista* inicio){
	if(inicio==NULL) return;
	printf("%d\t",inicio->num);
	imp(inicio->proximo);
	printf("\n");
}

Lista* trocar(Lista *inicio,int a,int b){
	Lista *iterator=inicio,*nodeA=NULL,*nodeB=NULL;
	
	while(iterator!=NULL){
		if(iterator->num==a) nodeA=iterator;
		else if(iterator->num==b) nodeB=iterator;
		iterator=iterator->proximo;
	}
	
	if(nodeA!=NULL && nodeB!=NULL){
		
		if(nodeB->proximo == nodeA){
			Lista *aux=nodeA;
			nodeA=nodeB;
			nodeB=aux;
		}
		
		if(nodeA->proximo==nodeB || nodeB->proximo==nodeA){
			Lista *aux_ant=nodeA->anterior;
			Lista *aux_prox=nodeA->proximo;
			nodeA->anterior=nodeB;
			nodeA->proximo=nodeB->proximo;
			nodeB->anterior=aux_ant;
			nodeB->proximo=nodeA;
			if(nodeB->anterior!=NULL)
				nodeB->anterior->proximo=nodeB;
		}
		else{
			Lista *aux_ant=nodeA->anterior;
			Lista *aux_prox=nodeA->proximo;
			nodeA->anterior=nodeB->anterior;
			nodeA->proximo=nodeB->proximo;
			nodeB->anterior=aux_ant;
			nodeB->proximo=aux_prox;
			
			if(nodeA->anterior!=NULL)
				nodeA->anterior->proximo=nodeA;
			if(nodeA->proximo!=NULL)
				nodeA->proximo->anterior=nodeA;
			if(nodeB->anterior!=NULL)
				nodeB->anterior->proximo=nodeB;
			if(nodeB->proximo!=NULL)
				nodeB->proximo->anterior=nodeB;
		}
		
		if(inicio==nodeA) inicio=nodeB;
		else if(inicio==nodeB) inicio=nodeA;
	}
	
	return inicio;
}

Lista* trocar2(Lista *l,int a,int b){
	if(l!=NULL && l->proximo!=NULL){
		Lista *iterator=l,*nodeA=NULL,*nodeB=NULL;
		Lista aux, *aux_prox;
		
		while(iterator!=NULL){
			if(iterator->num==a) nodeA = iterator;
			else if(iterator->num==b) nodeB=iterator;
			iterator=iterator->proximo;
		}
		
		if(nodeA!=NULL && nodeB!=NULL){
			aux=*nodeA;
			*nodeA=*nodeB;
			*nodeB=aux;
			
			aux_prox=nodeA->proximo;
			nodeA->proximo=nodeB->proximo;
			nodeB->proximo=aux_prox;
			
			aux_prox=nodeA->anterior;
			nodeA->anterior=nodeB->anterior;
			nodeB->anterior=aux_prox;
		}
	}
	
	return l;
}

int main(){
	Lista *inicio=NULL;
	inicio=inserir_inicio(inicio,3);
	inicio=inserir_inicio(inicio,2);
	inicio=inserir_fim(inicio,4);
	inicio=inserir_fim(inicio,5);
	imp(inicio);
	inicio=trocar(inicio,3,2);
	imp(inicio);
	inicio=trocar2(inicio,2,4);
	imp(inicio);
	return 0;
}
