#include <stdio.h>
#include <stdlib.h>

struct lista{
	int num;
	struct lista *anterior;
	struct lista *prox;
};

typedef struct lista Lista;

Lista* inserir_inicio(Lista *inicio,int n){
	Lista *novo;
	novo=(Lista*)malloc(sizeof(Lista));
	novo->num=n;
	novo->anterior=NULL;
	novo->prox=inicio;
	
	if(inicio==NULL){
		inicio=novo;
	}
	else{
		inicio->anterior=novo;
		inicio=novo;
	}
	
	return inicio;
}

void imp(Lista *inicio){
	while(inicio!=NULL){
		printf("%d\t",inicio->num);
		inicio=inicio->prox;
	}
	printf("\n");
}

Lista* multiplicar(Lista *lista1,Lista *lista2){
	Lista *it_lista1=lista1, *it_lista2=lista2;
	Lista *lista3, *novo, *aux;
	int i=0;
	
	while(it_lista1!=NULL && it_lista2!=NULL){
		novo=(Lista*)malloc(sizeof(Lista));
		novo->num=it_lista1->num*it_lista2->num;
		novo->prox=NULL;
		
		if(i==0){
			novo->anterior=NULL;
			lista3=novo;
			aux=novo;
		}
		else{
			novo->anterior=aux;
			aux->prox=novo;
			aux=novo;
		}
		
		it_lista1=it_lista1->prox;
		it_lista2=it_lista2->prox;
		i++;
	}
	
	return lista3;
}

int main(){
	Lista *lista1 = NULL,*lista2=NULL,*lista3=NULL;
	lista1=inserir_inicio(lista1,4);
	lista1=inserir_inicio(lista1,3);
	lista1=inserir_inicio(lista1,2);
	lista1=inserir_inicio(lista1,1);
	
	lista2=inserir_inicio(lista2,40);
	lista2=inserir_inicio(lista2,30);
	lista2=inserir_inicio(lista2,20);
	lista2=inserir_inicio(lista2,10);
	
	lista3 = multiplicar(lista1,lista2);
	imp(lista1);
	imp(lista2);
	imp(lista3);
	
	return 0;
}
