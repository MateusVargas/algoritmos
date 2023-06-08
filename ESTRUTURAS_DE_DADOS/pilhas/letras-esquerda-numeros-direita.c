#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct{
	char key;
	struct lista *prox;
}Lista;

int ehDigito(char c){
	if(isdigit(c)) return 1;
	return 0;
}

Lista* insere(Lista *p,char c){
	Lista *novo=(Lista*)malloc(sizeof(Lista));
	novo->key=c;
	novo->prox=p;
	return novo;
}

void empilhar(Lista **p,char c){
	Lista *novo=(Lista*)malloc(sizeof(Lista));
	novo->key=c;
	novo->prox=NULL;
	
	if(*p==NULL){
		*p=novo;
	}
	else{
		Lista *t=*p;
		while(t->prox!=NULL){
			t=t->prox;
		}
		t->prox=novo;
	}
}

Lista* desempilhar(Lista **p){
	if(*p==NULL) return NULL;
	else if((*p)->prox==NULL){
		Lista *t=*p;
		*p=NULL;
		return t;
	}
	else{
		Lista *t=*p,*ant=NULL;
		while(t->prox!=NULL){
			ant=t;
			t=t->prox;
		}
		ant->prox=t->prox;
		return t;
	}
	
}


void imp(Lista *p){
	if(p==NULL) return;
	printf("%c\t",p->key);
	imp(p->prox);
	printf("\n");
}


Lista* mover(Lista *inicio,Lista **pilha){
	if(inicio!=NULL && inicio->prox!=NULL){
		Lista *iterator=inicio,*ant=NULL,*aux=NULL;
		
		while(iterator!=NULL){
			if(aux==NULL && !ehDigito(iterator->key)){
				aux=iterator;
			}
			
			if(!ehDigito(iterator->key)){
				ant=iterator;
				iterator=iterator->prox;
			}
			else{
				empilhar(pilha,iterator->key);
				if(ant!=NULL){
					ant->prox=iterator->prox;
				}
				Lista *t=iterator;
				iterator=iterator->prox;
				free(t);
			}
			
		}
		
		inicio=aux;
		Lista *p;
		
		if(inicio==NULL){
			inicio=desempilhar(pilha);
			iterator=inicio;
			p=desempilhar(pilha);
			
			while(p!=NULL){
				while(iterator->prox!=NULL){
					iterator=iterator->prox;
				}
				iterator->prox=p;
				p=desempilhar(pilha);
			}
		}
		else{
			iterator=inicio;
			p=desempilhar(pilha);
			
			while(p!=NULL){
				while(iterator->prox!=NULL){
					iterator=iterator->prox;
				}
				iterator->prox=p;
				p=desempilhar(pilha);
			}
		}
		
	}
	
	return inicio;
}


int main(){
	Lista *inicio, *pilha;
	char c;
	
	for(int i=0;i<8;i++){
		printf("valor: ");
		scanf("%c",&c);
		inicio=insere(inicio,c);
	}
	
	imp(inicio);
	inicio=mover(inicio,&pilha);
	imp(inicio);
	
	return 0;
}
