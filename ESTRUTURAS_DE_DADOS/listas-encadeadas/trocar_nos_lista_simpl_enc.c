#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int num;
	struct lista *prox;
} Lista;

Lista* inserir_inicio(Lista *p,int n){
	Lista *novo=(Lista*)malloc(sizeof(Lista));
	novo->num=n;
	novo->prox=p;
	return novo;
}

void imp(Lista *p){
	if(p==NULL) return;
	printf("%d\t",p->num);
	imp(p->prox);
	printf("\n");
}

Lista* trocar(Lista *inicio,int a,int b){
	Lista *iterator=inicio,*nodeA=NULL,*nodeB=NULL;
	Lista *ant_nodeA=NULL,*ant_nodeB=NULL;
	
	while(iterator!=NULL){
		if(iterator->prox!=NULL){
			if(iterator->prox->num==a){
				ant_nodeA=iterator;
				nodeA=iterator->prox;
			}
			else if(iterator->prox->num==b){
				ant_nodeB=iterator;
				nodeB=iterator->prox;
			}
		}
		if(nodeA!=NULL&&nodeB!=NULL) break;
		iterator=iterator->prox;
	}
	
	if(inicio->num==a){
		ant_nodeA=NULL;
		nodeA=inicio;
	}
	else if(inicio->num==b){
		ant_nodeB=NULL;
		nodeB=inicio;
	}
	
	if(nodeA!=NULL&&nodeB!=NULL){
		if(nodeA->prox==nodeB){
			nodeA->prox=nodeB->prox;
			nodeB->prox=nodeA;
			
			if(ant_nodeA!=NULL)
				ant_nodeA->prox=nodeB;
		}
		else if(nodeB->prox==nodeA){
			nodeB->prox=nodeA->prox;
			nodeA->prox=nodeB;
			
			if(ant_nodeB!=NULL)
				ant_nodeB->prox=nodeA;
		}
		else{
			Lista *aux=nodeA->prox;
			nodeA->prox=nodeB->prox;
			nodeB->prox=aux;
			if(ant_nodeA!=NULL)
				ant_nodeA->prox=nodeB;
			if(ant_nodeB!=NULL)
				ant_nodeB->prox=nodeA;
		}
			
		if(inicio==nodeA) inicio=nodeB;
		else if(inicio==nodeB) inicio=nodeA;
	}
	return inicio;
}


int main(){
	Lista *inicio;
	inicio=inserir_inicio(inicio,5);
	inicio=inserir_inicio(inicio,4);
	inicio=inserir_inicio(inicio,3);
	inicio=inserir_inicio(inicio,2);
	inicio=inserir_inicio(inicio,1);
	imp(inicio);
	inicio=trocar(inicio,2,1);
	imp(inicio);
	return 0;
}
