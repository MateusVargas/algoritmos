#include <stdio.h>
#include <stdlib.h>

struct lista{
	int num;
	struct lista *prox;
};

typedef struct lista Lista;

Lista* inserir_inicio(Lista *inicio,int n){
	Lista *novo=(Lista*)malloc(sizeof(Lista));
	novo->num=n;
	novo->prox=inicio;
	return novo;
}

void imp(Lista *p){
	while(p!=NULL){
		printf("%d\t",p->num);
		p=p->prox;
	}
	printf("\n");
}

Lista* mover(Lista *inicio,int x,int n){
	if(inicio!=NULL && inicio->prox!=NULL && n>0){
		Lista *iterator=inicio,*ant=NULL,*aux;
		int cont=0;
		
		while(iterator!=NULL && iterator->num!=x){
			ant=iterator;
			iterator=iterator->prox;
		}
		if(iterator!=NULL){
			Lista *p=iterator;
			
			while(p!=NULL){
				cont++;
				p=p->prox;
			}
			
			if(cont <= n){
				printf("nao ha casas suficientes\n");
			}
			else{
				cont = 0;
				p=iterator;
				
				while(cont < n){
					cont++;
					p=p->prox;
				}
				
				if(ant==NULL){
					inicio=iterator->prox;
					aux=p->prox;
					p->prox=iterator;
					iterator->prox=aux;
				}
				else{
					ant->prox=iterator->prox;
					aux=p->prox;
					p->prox=iterator;
					iterator->prox=aux;
				}
			}
			
		}
		
	}
	return inicio;
}

int main(){
	Lista *inicio;
	inicio=inserir_inicio(inicio,4);
	inicio=inserir_inicio(inicio,3);
	inicio=inserir_inicio(inicio,2);
	inicio=inserir_inicio(inicio,15);
	inicio=inserir_inicio(inicio,10);
	inicio=inserir_inicio(inicio,8);
	inicio=inserir_inicio(inicio,9);
	imp(inicio);
	inicio=mover(inicio,10,3);
	imp(inicio);
	return 0;
}
