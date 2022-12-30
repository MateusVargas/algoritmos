#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int valor;
	struct lista *prox;
} Lista;


void inserir_inicio(Lista **inicio,int num){
	//inicio tem o endereco de inicio da main
	//*inicio tem o valor guardado em inicio da main
	//**inicio eh a propria struct
	//Lista lista = **inicio funciona
	
	Lista *novo = (Lista*)malloc(sizeof(Lista));
	novo->valor=num;
	novo->prox=*inicio;
	*inicio=novo;
}


void inserir_fim(Lista **inicio,int num){
	Lista *iterator;
	Lista *novo = (Lista*)malloc(sizeof(Lista));
	novo->valor=num;
	
	if(*inicio==NULL){
		novo->prox=NULL;
		*inicio=novo;
	}
	else{
		for(iterator=*inicio;iterator->prox!=NULL;iterator=iterator->prox){
		}
		
		iterator->prox=novo;
		novo->prox=NULL;
	}
}


void inserir_ordenado(Lista **inicio,int num){
	Lista *iterator=*inicio;
	Lista *aux=NULL, *anterior=NULL;
	Lista *novo=(Lista*)malloc(sizeof(Lista));
	
	novo->valor=num;
	
	if(*inicio==NULL){
		novo->prox=NULL;
		*inicio=novo;
	}
	else if((*inicio)->prox==NULL){
		if((*inicio)->valor > novo->valor){
			aux=*inicio;
			*inicio=novo;
			novo=aux;
			
			(*inicio)->prox=novo;
			novo->prox=NULL;
		}
		else{
			novo->prox=NULL;
			(*inicio)->prox=novo;
		}
	}
	else{
		
		while(iterator != NULL && iterator->valor < novo->valor){
			anterior=iterator;
			iterator=iterator->prox;
		}
		
		if(anterior==NULL){
			novo->prox=*inicio;
			*inicio=novo;
		}
		else if(anterior->prox==NULL){
			anterior->prox=novo;
			novo->prox=NULL;
		}
		else{
			anterior->prox=novo;
			novo->prox=iterator;
		}
	}
}


void remover(Lista **inicio,int num){
	Lista *iterator=*inicio, *anterior=NULL;
	
	if(*inicio==NULL){
		printf("lista vazia\n");
	}
	else if((*inicio)->valor==num){
		if((*inicio)->prox != NULL){
			*inicio=(*inicio)->prox;
		}
		else{
			*inicio=NULL;
		}
		free(*inicio);
	}
	else{
		while(iterator!=NULL && iterator->valor!=num){
			anterior=iterator;
			iterator=iterator->prox;
		}
		
		if(iterator==NULL){
			printf("404 not found\n");
		}
		else if(iterator->prox==NULL){
			anterior->prox=NULL;
			free(iterator);
		}
		else{
			anterior->prox=iterator->prox;
			free(iterator);
		}
	}
}


void imprimir(Lista *inicio){

	if(inicio==NULL){
		return;
	}
	else{
		/*while(iterator!=NULL){
			printf("end: %x, valor: %d, prox: %x\n",iterator,iterator->valor,iterator->prox);
			iterator=iterator->prox;
		}*/
		
		printf("end: %x, valor: %d, prox: %x\n",inicio,inicio->valor,inicio->prox);
		imprimir(inicio->prox);
	
	}
	
	/*por ser uma funcao recursiva, esse '\n'
	acontecera 3 vezes se tiver 3 elementos, 4 vezes
	se tiver 4 e assim por diante, pois antes de
	chegar nele a funcao eh chamada denovo na 
	linha 138, se tiver 3 elementos serao 3 
	chamadas recursivas e quando a ultima chamada for
	resolvida com o return da linha 129, as outras 
	serao resolvidas em cascata ou seja as linhas 
	depois da chamada da linha 138 serao executadas 
	em cada uma das execucoes pendentes desde a 
	ultima chamada ate a primeira la na main
	*/
	printf("\n");
}


void trocar_nos(Lista *inicio,int a, int b){
	Lista *iterator=inicio;
	Lista *nodeA=NULL,*nodeB=NULL, *aux=NULL;
	Lista troca;
	
	while(iterator!=NULL){
		if(iterator->valor==a){
			nodeA=iterator;
			//printf("it a %x\n",iterator);
		}
		if(iterator->valor==b){
			nodeB=iterator;
			//printf("it b %x\n",iterator);
		}
		iterator=iterator->prox;
	}
	
	if(nodeA != NULL && nodeB != NULL){
		//printf("nodeA: %x\n",nodeA);
		//printf("nodeB: %x\n",nodeB);
		
		/*a troca ocorre nas structs
		ou seja, eh trocada a struct que o 
		ponteiro aponta, nodeA eh um ponteiro
		o valor guardado nele eh um ponteiro
		pra uma struct, esse valor nao eh mexido
		e sim a struct que ele aponta e trocada 
		com a struct que nodeB aponta, ou seja,
		a struct que esta no endereco que ele aponta
		eh alterada
		*/
		troca=*nodeA;
		*nodeA=*nodeB;
		*nodeB=troca;
		
		//printf("nodeA: %x\n",nodeA);
		//printf("nodeB: %x\n",nodeB);
		
		//eh preciso trocar novamente os apontamentos
		aux=nodeA->prox;
		nodeA->prox=nodeB->prox;
		nodeB->prox=aux;
	}
}



void ordenar(Lista *inicio){
	Lista *iterator1 = inicio;
	Lista *iterator2 = iterator1->prox;
	Lista troca, *aux_prox = NULL;
	
	if(inicio==NULL){
		printf("lista vazia\n");
	}
	else if(inicio->prox==NULL){
		return;
	}
	else{
		
		for( ; iterator1 != NULL;iterator1=iterator1->prox){
			
			iterator2=iterator1->prox;
			
			for( ; iterator2!=NULL; iterator2=iterator2->prox){
				if(iterator1->valor > iterator2->valor){
					troca=*iterator1;
					*iterator1=*iterator2;
					*iterator2=troca;
					
					aux_prox=iterator1->prox;
					iterator1->prox=iterator2->prox;
					iterator2->prox=aux_prox;
				}
			}
		}
		
	}
}


int main(){
	Lista *inicio = NULL;
	int op,num;
	
	do{
		printf("1-inserir inicio\n");
		printf("2-inserir fim\n");
		printf("3-inserir ordenado\n");
		printf("4-remover\n");
		printf("5-imprimir\n");
		printf("6-trocar nos\n");
		printf("7-ordem crescente\n");
		printf("9-sair\n");
		scanf("%d",&op);
		
		if(op==1){
			printf("valor: ");
			scanf("%d",&num);
			inserir_inicio(&inicio,num);
		}
		else if(op==2){
			printf("valor: ");
			scanf("%d",&num);
			inserir_fim(&inicio,num);
		}
		else if(op==3){
			printf("valor: ");
			scanf("%d",&num);
			inserir_ordenado(&inicio,num);
		}
		else if(op==4){
			printf("valor a remover: ");
			scanf("%d",&num);
			remover(&inicio,num);
		}
		else if(op==5){
			imprimir(inicio);
		}
		else if(op==6){
			int a,b;
			printf("valor 1: ");
			scanf("%d",&a);
			printf("valor 2: ");
			scanf("%d",&b);
			
			if(a != b){
				trocar_nos(inicio,a,b);
			}
		}
		else if(op==7){
			ordenar(inicio);
		}
	}while(op!=9);
	
	
	return 0;
}
