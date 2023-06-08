#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int num;
	struct lista *prox;
}Lista;

Lista* inserir_inicio(Lista *inicio,int n){
	Lista *novo=(Lista*)malloc(sizeof(Lista));
	novo->num=n;
	
	if(inicio==NULL){
		novo->prox=novo;
		inicio=novo;
	}
	else{
		Lista *iterator=inicio;
		while(iterator->prox!=inicio){
			iterator=iterator->prox;
		}
		iterator->prox=novo;
		novo->prox=inicio;
		inicio=novo;	
	}
	
	return inicio;
}

void imp(Lista *p){
	Lista *iterator=p;
	do{
		printf("%d\t",iterator->num);
		iterator=iterator->prox;
	}while(iterator!=p);
	printf("\n");
}


Lista* remover_duplicados(Lista *inicio){
	if(inicio!=NULL && inicio->prox!=inicio){
		Lista *iterator=inicio,*jota,*ant=NULL;
		Lista *aux;
		
		do{
			aux=iterator;
			ant=iterator;
			jota=iterator->prox;
			
			do{
				
				if(iterator->num==jota->num){	
					ant->prox=jota->prox;
				}
				else{
					ant=jota;
				}
				
				jota=jota->prox;
			}while(jota!=aux);

			iterator=iterator->prox;
		}while(iterator!=aux);
		
	}
	
	return inicio;
}

int main(){
	Lista *inicio;
	inicio=inserir_inicio(inicio,7);
	inicio=inserir_inicio(inicio,2);
	inicio=inserir_inicio(inicio,9);
	inicio=inserir_inicio(inicio,8);
	inicio=inserir_inicio(inicio,1);
	inicio=inserir_inicio(inicio,2);
	inicio=inserir_inicio(inicio,7);
	imp(inicio);
	inicio=remover_duplicados(inicio);
	imp(inicio);
	return 0;
}
