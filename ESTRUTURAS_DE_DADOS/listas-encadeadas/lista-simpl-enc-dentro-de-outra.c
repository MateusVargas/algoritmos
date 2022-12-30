#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dados{
	int valor;
	struct dados *prox;
};

struct lista{
	char *nome;
	struct dados *dados;
	struct lista *prox;
};

typedef struct lista Lista;


Lista* inserir_inicio(Lista *inicio,char *nome,int total_nos){
	
	Lista *novo=(Lista*)malloc(sizeof(Lista));
	int valor;
	
	novo->nome = nome;
	novo->dados = NULL;
	
	//inserindo no inicio da lista encadeada interna
	for(int i=0;i<total_nos;i++){
		printf("[%d]: ",i);
		scanf("%d",&valor);
		
		struct dados *novo_lista_interna=NULL;
		novo_lista_interna=(struct dados*)malloc(sizeof(struct dados));
		novo_lista_interna->valor=valor;
		novo_lista_interna->prox=NULL;
		
		if(novo->dados==NULL){
			novo->dados=novo_lista_interna;
			novo->dados->prox=NULL;
		}
		else{
			novo_lista_interna->prox=novo->dados;
			novo->dados=novo_lista_interna;
		}
	}
	
	if(inicio==NULL){
		novo->prox=NULL;
	}
	else{
		novo->prox=inicio;
	}
	
	inicio=novo;
	
	return inicio;
}


Lista* inserir_fim(Lista *inicio,char *nome,int total_nos){
	
	Lista *novo=(Lista*)malloc(sizeof(Lista));
	novo->nome = nome;
	novo->dados = NULL;
	
	//inserindo no fim da lista encadeada interna
	for(int i=0;i<total_nos;i++){
		struct dados *dados = (struct dados*)malloc(sizeof(struct dados));
		
		printf("[%d]: ",i);
		scanf("%d",&dados->valor);
		
		if(novo->dados==NULL){
			dados->prox=NULL;
			novo->dados=dados;
		}
		else{
			struct dados *iterator=novo->dados;
			
			while(iterator->prox != NULL){
				iterator=iterator->prox;
			}
			iterator->prox=dados;
			dados->prox=NULL;
		}
	}
	
	if(inicio==NULL){
		novo->prox=NULL;
		inicio=novo;
	}
	else{
		Lista *iterator=inicio;
		while(iterator->prox != NULL){
			iterator=iterator->prox;
		}
		iterator->prox=novo;
		novo->prox=NULL;
	}
	
	return inicio;
}


Lista* remover(Lista *inicio, char *nome){
	Lista *iterator=inicio, *anterior=NULL;
	struct dados *iterator_lista_interna=NULL;
	
	if(strcmp(inicio->nome, nome)==0){
		
		iterator_lista_interna=inicio->dados;
		
		//removendo elementos da lista interna
		while(iterator_lista_interna!=NULL){
			free(iterator_lista_interna);
			
			iterator_lista_interna=iterator_lista_interna->prox;
		}
		
		if(inicio->prox == NULL){
			free(inicio);
			inicio=NULL;
		}
		else{
			free(inicio);
			inicio=inicio->prox;
		}
		
	}
	else{
		while(iterator!=NULL && strcmp(iterator->nome,nome) != 0){
			anterior=iterator;
			iterator=iterator->prox;
		}
		
		if(iterator==NULL){
			printf("nao achou\n");
		}
		else{
			
			iterator_lista_interna=iterator->dados;
			
			//removendo elementos da lista interna
			while(iterator_lista_interna!=NULL){
				free(iterator_lista_interna);
				
				iterator_lista_interna=iterator_lista_interna->prox;
			}
			
			anterior->prox=iterator->prox;
			free(iterator);
		}
	}
	
	return inicio;
}



void imprimir_dados(struct dados *dados){
	if(dados!=NULL){
		printf("%d, ",dados->valor);
		imprimir_dados(dados->prox);
	}
	printf("\n");
}



void imprimir(Lista *inicio){
	if(inicio!=NULL){
		printf("%s\t",inicio->nome);
		imprimir_dados(inicio->dados);
		imprimir(inicio->prox);
	}
}


int main(){
	Lista *inicio=NULL;
	int op, total_nos;
	char *nome=NULL;
	
	do{
		printf("1-inserir inicio\n");
		printf("2-inserir fim\n");
		printf("3-inserir ordenado\n");
		printf("4-remover\n");
		printf("5-imprimir\n");
		printf("9-sair\n");
		scanf("%d",&op);
		
		if(op==1){
			nome=(char*)malloc(30*sizeof(char));
			printf("nome: ");
			getchar();
			gets(nome);
			
			printf("total de valores: ");
			scanf("%d",&total_nos);
			
			inicio=inserir_inicio(inicio,nome,total_nos);
		}
		else if(op==2){
			nome=(char*)malloc(30*sizeof(char));
			printf("nome: ");
			getchar();
			gets(nome);
			
			printf("total de valores: ");
			scanf("%d",&total_nos);
			
			inicio=inserir_fim(inicio,nome,total_nos);
		}
		else if(op==4){
			if(inicio==NULL){
				printf("lista vazia\n");
			}
			else{
				nome=(char*)malloc(30*sizeof(char));
				printf("nome: ");
				getchar();
				gets(nome);
				
				inicio=remover(inicio,nome);
			}
		}
		else if(op==5){
			imprimir(inicio);
		}
		
		
	}while(op!=9);
	
	return 0;
}
