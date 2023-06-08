#include<stdio.h>
#include<stdlib.h>

struct lista{
	int num;
	struct lista *prox;
};

typedef struct lista Lista;


void imp(Lista *p){
	while(p){
		printf("%d\t",p->num);
		p=p->prox;
	}
	printf("\n");
}

Lista* inserir_ordenado(Lista *inicio,int x){
	Lista *iterator=inicio,*ant=NULL;
	Lista *novo=(Lista*)malloc(sizeof(Lista));
	novo->num=x;
	
	if(inicio==NULL){
		novo->prox=NULL;
		inicio=novo;
	}
	else{
		while(iterator!=NULL && iterator->num < x){
			ant=iterator;
			iterator=iterator->prox;
		}
		
		if(ant==NULL){
			novo->prox=inicio;
			inicio=novo;
		}
		else if(iterator==NULL){
			ant->prox=novo;
			novo->prox=NULL;
		}
		else{
			ant->prox=novo;
			novo->prox=iterator;
		}
	}
	
	return inicio;
}

Lista* remover(Lista *inicio,int x){
	Lista *iterator=inicio,*aux=NULL,*ant=NULL;
	
	while(iterator!=NULL){
		if(aux==NULL && iterator->num!=x){
			aux=iterator;
		}
		if(iterator->num==x){
			if(ant!=NULL){
				ant->prox=iterator->prox;
			}
			Lista *t=iterator;
			iterator=iterator->prox;
			free(t);
		}
		else{
			ant=iterator;
			iterator=iterator->prox;
		}
		
	}
	
	return aux;
}

int main(){
	Lista *inicio;
	inicio=inserir_ordenado(inicio,1);
	inicio=inserir_ordenado(inicio,4);
	inicio=inserir_ordenado(inicio,5);
	inicio=inserir_ordenado(inicio,2);
	inicio=inserir_ordenado(inicio,3);
	imp(inicio);
	inicio=remover(inicio,1);
	imp(inicio);
	return 0;
}
