#include <stdio.h>
#include <stdlib.h>

struct lista{
	int num;
	struct lista *anterior;
	struct lista *proximo;
};

typedef struct lista LISTA;

LISTA* inserir_inicio(LISTA *inicio,int num){
	LISTA *novo=(LISTA*)malloc(sizeof(LISTA));
	novo->num=num;
	novo->anterior=NULL;
	novo->proximo=inicio;
	
	if(inicio==NULL){
		inicio=novo;
	}
	else{
		inicio->anterior=novo;
		inicio=novo;
	}
	return inicio;
}

void imprimir(LISTA *inicio){
	if(inicio==NULL) return;
	printf("%d\t",inicio->num);
	imprimir(inicio->proximo);
	printf("\n\n");
}

LISTA *inverte(LISTA *inicio){
	LISTA *iterator=inicio,*ant=NULL,*aux=NULL;
	if(inicio!=NULL && inicio->proximo!=NULL){
		while(iterator!=NULL){
			aux=iterator;
			iterator->anterior=iterator->proximo;
			iterator=iterator->proximo;
			aux->proximo=ant;
			ant=aux;
			//ideia eh ter variaveis que estao
			//sempre um passo atras da variavel
			//iteradora
		}
		inicio=ant;
	}
	
	return inicio;
}

LISTA* inverte_rec(LISTA* inicio,LISTA *ant){
	if(inicio==NULL){
		inicio=ant;
		return inicio;
	}
	LISTA *aux=inicio->proximo;
	inicio->anterior=inicio->proximo;
	inicio->proximo=ant;
	ant=inicio;
	return inverte_rec(aux,ant);
}

int main(){
	LISTA *inicio=NULL;
	inicio=inserir_inicio(inicio,5);
	inicio=inserir_inicio(inicio,4);
	inicio=inserir_inicio(inicio,3);
	inicio=inserir_inicio(inicio,2);
	inicio=inserir_inicio(inicio,1);
	imprimir(inicio);
	inicio=inverte_rec(inicio,NULL);
	imprimir(inicio);
	return 0;
}
