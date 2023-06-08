#include <stdio.h>
#include <stdlib.h>

struct lista{
	int num;
	struct lista *prox;
};

typedef struct lista Lista;

Lista* inserir(Lista *l,int n){
	Lista *novo=(Lista*)malloc(sizeof(Lista));
	novo->num=n;
	novo->prox=NULL;
	
	if(l==NULL){
		l=novo;
	}
	else{
		Lista *p=l;
		while(p->prox!=NULL){
			p=p->prox;
		}
		p->prox=novo;
	}
	return l;
}

Lista* contar(Lista *l,Lista *l2,Lista *aux,int *cont,int i){
	if(l==NULL) return l2;
	
	if(l->num %2==0) (*cont)++;
	
	Lista *novo=(Lista*)malloc(sizeof(Lista));
	novo->num=l->num;
	novo->prox=NULL;
	
	if(i==0){
		l2=novo;
		aux=novo;
	}
	else{
		aux->prox=novo;
		aux=novo;
	}
	Lista *t=l;
	l=l->prox;
	free(t);
	return contar(l,l2,aux,cont,i+1);
}

void imp(Lista *p){
	if(p==NULL) return;
	printf("%d\t",p->num);
	imp(p->prox);
	printf("\n");
}

int main(){
	Lista *lista;
	int cont;
	lista=inserir(lista,1);
	lista=inserir(lista,2);
	lista=inserir(lista,5);
	lista=inserir(lista,22);
	imp(lista);
	lista=contar(lista,NULL,NULL,&cont,0);
	printf("%d\n\n",cont);
	imp(lista);
	return 0;
}
