#include <stdio.h>
#include <stdlib.h>

struct lista{
	int num;
	struct lista *prox;
};

typedef struct lista LISTA;

LISTA* inserir_fim(LISTA *inicio,int n){
	LISTA *iterator=inicio, *novo;
	
	novo=(LISTA*)malloc(sizeof(LISTA));
	novo->num=n;
	novo->prox=NULL;
	
	if(inicio==NULL){
		inicio=novo;
	}
	else{
		while(iterator->prox!=NULL){
			iterator=iterator->prox;
		}
		iterator->prox=novo;
	}
	return inicio;
}


void imp(LISTA *inicio){
	if(inicio==NULL) return;
	printf("%d\t",inicio->num);
	imp(inicio->prox);
	
	//printf("%d\t",inicio->num);
	//imprimir ao contrario, soh colocar depois
	//da chamada recursiva, que sera impresso
	//soh ao desempilhar
	
	printf("\n");
}


LISTA* buscar(LISTA *inicio,int x){
	if(inicio==NULL) return NULL;
	if(inicio->num==x) return inicio;
	return buscar(inicio->prox,x);
}


LISTA* dividir(LISTA *iterator,LISTA *aux,LISTA *inicio_lista2,int i){
	if(iterator==NULL){
		return inicio_lista2;
	}
	
	LISTA *novo;
	novo=(LISTA*)malloc(sizeof(LISTA));
	novo->num=iterator->num;
	novo->prox=NULL;
	
	if(i==0){
		inicio_lista2=novo;
		aux=novo;
	}
	else{
		aux->prox=novo;
		aux=novo;
	}
	
	return dividir(iterator->prox,aux,inicio_lista2,i+1);
}


LISTA* divide(LISTA *l1,int x){
	LISTA *l2=NULL;
	if(l1!=NULL && l1->prox!=NULL){
		LISTA *it=l1;
		while(it!=NULL && it->num!=x){
			it=it->prox;
		}
		if(it!=NULL && it->prox!=NULL){
			l2=it->prox;
			it->prox=NULL;
		}
	}
	return l2;
}

LISTA* divide_rec(LISTA *l1,int x){
	if(l1==NULL || l1->prox==NULL) return NULL;
	if(l1->num==x){
		LISTA *p=l1->prox;
		l1->prox=NULL;
		return p;
	}
	return divide_rec(l1->prox,x);
}

int main(){
	LISTA *inicio=NULL, *inicio_lista2=NULL, *busca=NULL;
	inicio=inserir_fim(inicio,1);
	inicio=inserir_fim(inicio,2);
	inicio=inserir_fim(inicio,3);
	inicio=inserir_fim(inicio,4);
	inicio=inserir_fim(inicio,5);
	imp(inicio);
	busca=buscar(inicio,4);
	//inicio_lista2=dividir(busca->prox,NULL,NULL,0);
	inicio_lista2=divide_rec(inicio,3);
	imp(inicio_lista2);
	return 0;
}
