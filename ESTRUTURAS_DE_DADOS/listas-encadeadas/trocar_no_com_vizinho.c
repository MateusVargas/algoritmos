#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int num;
	struct lista *prox;
}Lista;

void imp(Lista *p){
	for(;p!=NULL;p=p->prox){
		printf("%d\t",p->num);
	}
	printf("\n");
}

Lista* inserir_fim(Lista *inicio,int n){
	Lista *novo=(Lista*)malloc(sizeof(Lista));
	novo->num=n;
	novo->prox=NULL;
	if(inicio==NULL)
		inicio=novo;
	else{
		Lista *p=inicio;
		while(p->prox != NULL)
			p=p->prox;
		p->prox=novo;
	}
	return inicio;
}

Lista* trocar(Lista *inicio,int x){
	if(inicio==NULL||inicio->prox==NULL)
		printf("n achou\n");
	else{
		Lista *iterator=inicio,*ant=NULL;
		while(iterator!=NULL && iterator->num!=x){
			ant=iterator;
			iterator=iterator->prox;
		}
		if(iterator==NULL) printf("n achou\n");
		else{
			if(iterator->prox==NULL)
				printf("n tem no vizinho\n");
			else{
				if(ant==NULL){
					Lista *aux=iterator->prox;
				   iterator->prox=iterator->prox->prox;
					aux->prox=iterator;
				    inicio=aux;
				}
				else{
					Lista *aux=iterator->prox;
				   iterator->prox=iterator->prox->prox;
				    aux->prox=iterator;
				    ant->prox=aux;
				}
			}
		}
	}
	return inicio;
}

int main(){
	Lista *inicio;
	inicio=inserir_fim(inicio,1);
	inicio=inserir_fim(inicio,2);
	inicio=inserir_fim(inicio,3);
	imp(inicio);
	inicio=trocar(inicio,2);
	imp(inicio);
	return 0;
}
