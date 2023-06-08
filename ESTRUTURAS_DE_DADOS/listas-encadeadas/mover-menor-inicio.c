#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int num;
	struct lista *prox;
}Lista;

void inserir_inicio(Lista **inicio,int n){
	Lista *novo=(Lista*)malloc(sizeof(Lista));
	novo->num=n;
	novo->prox=*inicio;
	*inicio=novo;
}

void imp(Lista *p){
	if(p==NULL) return;
	printf("%d\t",p->num);
	imp(p->prox);
	printf("\n");
}

Lista* mover(Lista *inicio,Lista *l,Lista *ant,Lista *menor,Lista *aux){
	if(l==NULL){
		if(menor==NULL) return l;
		if(ant==NULL) return l;
		ant->prox=menor->prox;
		menor->prox=inicio;
		inicio=menor;
		return inicio;
	}
	if(l->num < menor->num){
		ant=aux;
		menor=l;
	}
	aux=l;
	return mover(inicio,l->prox,ant,menor,aux);
}

int main(){
	Lista *inicio;
	inserir_inicio(&inicio,4);
	inserir_inicio(&inicio,34);
	inserir_inicio(&inicio,25);
	inserir_inicio(&inicio,16);
	imp(inicio);
	inicio=mover(inicio,inicio,NULL,inicio,NULL);
	imp(inicio);
	return 0;
}
