#include <stdio.h>
#include <stdlib.h>

struct lista{
	int num;
	struct lista *prox;
};
typedef struct lista Lista;

void empilha(Lista **l,int n){
	Lista *novo=(Lista*)malloc(sizeof(Lista));
	novo->num=n;
	novo->prox=NULL;
	
	if(*l==NULL){
		*l=novo;
	}
	else{
		Lista *p=*l;
		while(p->prox!=NULL){
			p=p->prox;
		}
		p->prox=novo;
	}
}

void imp(Lista *p){
	if(p==NULL) return;
	printf("%d\t",p->num);
	imp(p->prox);
	printf("\n");
}

Lista* remover(Lista *lista,int x){
	Lista *iterator=lista,*l2=NULL,*p,*ant=NULL,*aux;
	int i=0;
	
	if(lista==NULL) return NULL;
	
	/*
	tira 1 por 1 dos elementos ate achar o no
	e coloca eles numa pilha auxliliar
	*/
	while(iterator!=NULL){
		ant=iterator;
		p=iterator->prox;
		if(iterator->prox!=NULL){
			while(p->prox!=NULL){
				ant=p;
				p=p->prox;
			}
		}
		
		if(iterator->prox==NULL){
			if(iterator->num==x){
				free(iterator);
				iterator=NULL;
				lista=NULL;
			}
			else break;
		}
		else{
			if(p->num==x){
				Lista *t=p->prox;
				ant->prox=t;
				free(p);
				break;
			}
			else{
				if(i==0){
					l2=p;
					aux=p;
					i++;
				}
				else{
					aux->prox=p;
					aux=p;
				}
				ant->prox=p->prox;
			}
			
		}
		
	}
		
		
	/*
	depois de remover coloca denovo os elementos
	da pilha aux pra pilha original
	*/
	iterator=l2;
	Lista *itL2=lista;
	
	while(iterator!=NULL){
		ant=iterator;
		p=iterator->prox;
		
		if(iterator->prox!=NULL){
			while(p->prox!=NULL){
				ant=p;
				p=p->prox;
			}
		}
		
		if(iterator->prox==NULL){
			if(lista==NULL){
				lista=p;
			}
			else{
				while(itL2->prox!=NULL){
					itL2=itL2->prox;
				}
				itL2->prox=iterator;
				iterator=NULL;
			}
		}
		else{
			if(lista==NULL){
				lista=p;
				aux=p;
				itL2=lista;
			}
			else{
				while(itL2->prox!=NULL){
					itL2=itL2->prox;
				}
				itL2->prox=p;
			}
		
			ant->prox=p->prox;
		}
		
	}
	
	return lista;
}

int main(){
	Lista *lista;
	empilha(&lista,2);
	empilha(&lista,4);
	empilha(&lista,1);
	empilha(&lista,78);
	empilha(&lista,92);
	empilha(&lista,11);
	imp(lista);
	lista=remover(lista,2);
	imp(lista);
	return 0;
}
