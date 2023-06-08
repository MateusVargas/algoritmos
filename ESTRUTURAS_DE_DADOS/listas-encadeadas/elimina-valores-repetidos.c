#include <stdio.h>
#include <stdlib.h>

struct lista{
	int num;
	struct lista *prox;
};
typedef struct lista LISTA;

LISTA* inserir_final(LISTA *inicio,int num){
	LISTA *novo=(LISTA*)malloc(sizeof(LISTA));
	novo->num=num;
	novo->prox=NULL;
	if(inicio==NULL){
		inicio=novo;
	}
	else{
		LISTA *iterator=inicio;
		while(iterator->prox!=NULL){
			iterator=iterator->prox;
		}
		iterator->prox=novo;
	}
	return inicio;
}

LISTA* remover_duplicados(LISTA *inicio){
	if(inicio!=NULL && inicio->prox!=NULL){
		LISTA *iterator1=inicio;
		LISTA *iterator2=NULL, *ant=NULL;
		LISTA *salvar_prox=NULL;
		int ocorreu_troca=0;
		
		while(iterator1!=NULL){
			ant=iterator1;
			iterator2=iterator1->prox;
			
			while(iterator2!=NULL){
				ocorreu_troca=0;
				salvar_prox=iterator2->prox;
				
				if(iterator1->num==iterator2->num){
					ant->prox=iterator2->prox;
					ocorreu_troca=1;
					free(iterator2);
				}
				if(!ocorreu_troca){
					ant=iterator2;
				}
				
				iterator2=salvar_prox;
			}
			
			iterator1=iterator1->prox;
		}
		
	}
	return inicio;
}
 
void imp(LISTA *inicio){
	if(inicio==NULL) return;
	
	printf("%d\t",inicio->num);
	imp(inicio->prox);
	printf("\n");
}

int main(){
	LISTA *inicio=NULL;
	inicio=inserir_final(inicio,3);
	inicio=inserir_final(inicio,2);
	inicio=inserir_final(inicio,2);
	inicio=inserir_final(inicio,3);
	inicio=inserir_final(inicio,8);
	inicio=inserir_final(inicio,16);
	imp(inicio);
	inicio=remover_duplicados(inicio);
	imp(inicio);
	return 0;
}
