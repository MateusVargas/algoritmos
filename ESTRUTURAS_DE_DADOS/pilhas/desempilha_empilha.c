#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int num;
	struct lista *prox;
}Lista;

Lista* empilha(Lista *inicio,Lista *novo){
	if(inicio==NULL){
		inicio=novo;
	}else{
		Lista *p=inicio;
		while(p->prox!=NULL){
			p=p->prox;
		}
		p->prox=novo;
	}
	return inicio;
}

Lista* desempilha(Lista **inicio){
	if(*inicio==NULL) return NULL;
	else if((*inicio)->prox==NULL){
		Lista *p=*inicio;
		*inicio=NULL;
		return p;
	}
	
	Lista *p=*inicio,*ant=NULL;
	while(p->prox!=NULL){
		ant=p;
		p=p->prox;
	}
	
	ant->prox=p->prox;
	return p;
}

Lista* mover(Lista **inicio){
	Lista *nova_lista=NULL,*removido;
	int maior=(*inicio)->num;
	
	int sair=0;
	while(sair!=1){
		removido=desempilha(inicio);
		if(removido!=NULL){
			if(removido->num>maior)maior=removido->num;
		}
		nova_lista=empilha(nova_lista,removido);
		if(removido==NULL) sair=1;
	}
	printf("maior: %d\n",maior);
	return nova_lista;
}

void imp(Lista *p){
	for(;p!=NULL;p=p->prox)
		printf("%d\t",p->num);
	printf("\n");
}
	
int main(){
	Lista *inicio;
	Lista *novo=(Lista*)malloc(sizeof(Lista));
	novo->num=4;
	novo->prox=NULL;
	inicio=empilha(inicio,novo);
	
	novo=(Lista*)malloc(sizeof(Lista));
	novo->num=5;
	novo->prox=NULL;
	inicio=empilha(inicio,novo);
	
	novo=(Lista*)malloc(sizeof(Lista));
	novo->num=6;
	novo->prox=NULL;
	inicio=empilha(inicio,novo);
	
	imp(inicio);
	inicio=mover(&inicio);
	imp(inicio);
	inicio=mover(&inicio);
	imp(inicio);
	
	return 0;
}
