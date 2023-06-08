#include <stdio.h>
#include <stdlib.h>

struct lista{
	int num;
	struct lista *prox;
};
typedef struct lista Lista;

void empilhar(Lista **inicio,int n){
	Lista *novo=(Lista*)malloc(sizeof(Lista));
	novo->num=n;
	novo->prox=NULL;
	
	if(*inicio==NULL){
		*inicio=novo;
		return;
	}
	Lista *iterator=*inicio;
	while(iterator->prox!=NULL){
		iterator=iterator->prox;
	}
	iterator->prox=novo;
}

void imp(Lista *p){
	if(p==NULL)return;
	printf("%d\t",p->num);
	imp(p->prox);
}


int maior(Lista **l){
	int maior=(*l)->num, i=0;
	Lista *l2,*aux;
	Lista *iterator=*l,*ultimo,*ant;
	
	while(iterator!=NULL){
		if(iterator->prox==NULL){
			ant=NULL;
			ultimo=iterator;
			iterator=NULL;
			*l=NULL;
		}
		else{
			ant=iterator;
			ultimo=iterator->prox;
			while(ultimo->prox!=NULL){
				ant=ultimo;
				ultimo=ultimo->prox;
			}
		}
		
		if(ultimo->num > maior) maior=ultimo->num;
		
		if(i==0){
			l2=ultimo;
			aux=ultimo;
		}
		else{
			aux->prox=ultimo;
			aux=ultimo;
		}
		i++;
		
		if(iterator && iterator->prox!=NULL){
			ant->prox=ultimo->prox;
		}
	}
	
	*l=l2;
	return maior;
}


int main(){
	Lista *l;
	empilhar(&l,12);
	empilhar(&l,4);
	empilhar(&l,85);
	empilhar(&l,1);
	imp(l);
	printf("\nmaior %d\n",maior(&l));
	imp(l);
	return 0;
}
