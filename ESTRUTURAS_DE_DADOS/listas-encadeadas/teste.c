#include <stdio.h>
#include <stdlib.h>

struct lista{
	int num;
	struct lista *prox;
};
typedef struct lista Lista;

Lista* insere(Lista *inicio,int num){
	Lista *novo=(Lista*)malloc(sizeof(Lista));
	novo->num=num;
	novo->prox=inicio;
	inicio=novo;
	return inicio;
}
void imp(Lista *inicio){
	if(inicio==NULL)
		return;
	printf("%d\t",inicio->num);
	imp(inicio->prox);
}

//funcao nao apaga nem o primeiro nem o ultimo
void remover(Lista *p, Lista *ini) { 
	//p=NULL; nao reflete fora da funcao
	//p->num=777; reflete fora
	Lista *morta; 
	morta = p->prox; 
	if (morta->prox == NULL) p->prox = NULL; 
	else p->prox = morta->prox; 
	free (morta);
} 

//errado, porque esta se fazendo os apontamentos
//erradamente, porque o novo aponta pra p, e p aponta
//pra novo fazendo com que se perca os outros nos
void insere2(int x, Lista *p) { 
	Lista nova; 
	nova.num = x; 
	nova.prox = p->prox; 
	p->prox = &nova;
}

int main(){
	Lista *inicio=NULL, *aux=NULL;
	inicio=insere(inicio,34);
	inicio=insere(inicio,11);
	inicio=insere(inicio,3);
	inicio=insere(inicio,7);
	inicio=insere(inicio,27);
	inicio=insere(inicio,2);

	aux=inicio;
	for(int i=0;;i++){
		if(aux->num==11){
			break;
		}
		aux=aux->prox;
	}
	imp(inicio);
	printf("\n");
	remover(aux,inicio);
	imp(inicio);
	
	insere2(120,inicio);
	imp(inicio);
	return 0;
}
