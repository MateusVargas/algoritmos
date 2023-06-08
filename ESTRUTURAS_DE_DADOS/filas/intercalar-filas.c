#include <stdio.h>
#include <stdlib.h>

struct lista{
	int num;
	struct lista *prox;
};
typedef struct lista Lista;

Lista* insere(Lista *p,int n){
	Lista *novo=(Lista*)malloc(sizeof(Lista));
	novo->num=n;
	novo->prox=NULL;
	
	if(p==NULL){
		p=novo;
	}
	else{
		Lista *iterator=p;
		while(iterator->prox!=NULL){
			iterator=iterator->prox;
		}
		iterator->prox=novo;
	}
	
	return p;
}

void imp(Lista *p){
	while(p!=NULL){
		printf("%d\t",p->num);
		p=p->prox;
	}
	printf("\n");
}

Lista* intercalar(Lista **l1,Lista **l2){
	Lista *itL1=*l1,*itL2=*l2,*l3=NULL,*aux=NULL,*novo;
	int i=0;
	
	while(itL1!=NULL && itL2!=NULL){
		novo=(Lista*)malloc(sizeof(Lista));
		novo->num=itL1->num;
		novo->prox=NULL;
		
		if(i==0){
			l3=novo;
			aux=novo;
			i++;
		}
		else{
			aux->prox=novo;
			aux=novo;
		}
		
		novo=(Lista*)malloc(sizeof(Lista));
		novo->num=itL2->num;
		novo->prox=NULL;
		
		aux->prox=novo;
		aux=novo;
		
		Lista *t=itL1,*t1=itL2;
		itL1=itL1->prox;
		itL2=itL2->prox;
		free(t);
		free(t1);
	}
	
	if(itL1!=NULL){
		while(itL1!=NULL){
			novo=(Lista*)malloc(sizeof(Lista));
			novo->num=itL1->num;
			novo->prox=NULL;
			aux->prox=novo;
			aux=novo;
			Lista *t=itL1;
			itL1=itL1->prox;
			free(t);
		}
	}
	else if(itL2!=NULL){
		while(itL2!=NULL){
			novo=(Lista*)malloc(sizeof(Lista));
			novo->num=itL2->num;
			novo->prox=NULL;
			aux->prox=novo;
			aux=novo;
			Lista *t=itL2;
			itL2=itL2->prox;
			free(t);
		}
	}
	
	*l1=NULL;
	*l2=NULL;
	return l3;
}


int main(){
	Lista *l1,*l2,*l3;
	l1=insere(l1,1);
	l1=insere(l1,2);
	l1=insere(l1,3);
	
	l2=insere(l2,4);
	l2=insere(l2,5);
	l2=insere(l2,6);
	l2=insere(l2,7);
	
	imp(l1);
	imp(l2);
	l3=intercalar(&l1,&l2);
	imp(l3);
	imp(l2);
	return 0;
}
