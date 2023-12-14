#include <stdio.h>
#include <stdlib.h>

struct lista{
  	int valor;
  	struct lista *prox;
};

typedef struct lista Lista;

void inserir_i(Lista **inicio,Lista **fim,int num){
	Lista *novo=(Lista*)malloc(sizeof(Lista));
	novo->valor=num;
	
	if(*inicio==NULL){
  		novo->prox=novo;
  		*inicio=novo;
  		*fim=novo;
	}
	else{
  		novo->prox = *inicio;
  		*inicio=novo;
  		(*fim)->prox=*inicio;
	}

}

void inserir_f(Lista **inicio,Lista **fim,int num){
	Lista *novo=(Lista*)malloc(sizeof(Lista));
	novo->valor=num;
	
	if(*inicio==NULL){
  		novo->prox=novo;
  		*inicio=novo;
  		*fim=novo;
	}
	else
	{
  		(*fim)->prox=novo;
  		novo->prox=*inicio;
  		*fim=novo;
	}
}


void imprimir(Lista *inicio){
	if(inicio==NULL){
		  printf("lista vazia\n");
	}
	else{
		  Lista *aux = inicio;
  		do{
  			  printf("%d\t",aux->valor);
  			  aux = aux->prox;
  		}while(aux != inicio);
	}

	printf("\n\n\n");
}


void ord(Lista **inicio,Lista **fim){
	Lista *ant_i=NULL,*ant_j=NULL;
	Lista *i=*inicio,*j=i;
	Lista *aux;
	
	do{
    		printf("\ni: %d\n",i->valor);
    		do{
        			if(i->valor > j->valor){
        				
            		    printf("\n%d > %d\n",i->valor,j->valor);
            	
            				aux = i;
            				i->prox = j->prox;
            				j->prox = aux->prox;
            				j->prox->prox = aux;
            				
            				
            				if(*inicio == i){
            					*inicio=j;
            					(*fim)->prox=j;
            				}
            				if(*fim == j){
            					//(*fim)->prox=i;
            					*fim=i;
            					(*fim)->prox=*inicio;
            				}
            				
            				j=i;
            								
            				/*if(ant_i == NULL){
            					aux=i;
            					i->prox=j->prox;
            					j->prox=aux->prox;
            					j->prox->prox = aux;
            					ant_i = j;
            					
            					if(j->valor > (*inicio)->valor){
            						
            					*inicio=j;
            					(*fim)->prox = *inicio;
            					}
            					if(*fim == j){
            						
            					}
            				}
            				else{
            					aux=i;
            					i->prox=j->prox;
            					j->prox->prox=aux;
            					ant_i=j;
            				}*/
            				
        			}
    			//ant_i=
    			//ant_j=j;
    			printf("j: %d\t",j->valor);
    			j=j->prox;
    		}while(j != *inicio);
    		
    		//ant_i=i;
    		
    		i=i->prox;
    		j=i;
	}while(i != *inicio);
	
	
}


int main(){
	Lista *inicio = NULL, *fim = NULL;
	int op, num;

	
	while(op!=5){
    	printf("1-ins i\n2-ins f\n3-ord\n4-imprimir\n");
    	scanf("%d",&op);
    		
    	if(op==1){
    		printf("num: ");
    		scanf("%d",&num);
    		inserir_i(&inicio,&fim,num);
    	}
    	else if(op==2){
    		printf("num: ");
    		scanf("%d",&num);
    		inserir_f(&inicio,&fim,num);
    	}
    	else if(op==3){
    		ord(&inicio,&fim);
    	}
    	else if(op==4){
    		imprimir(inicio);
    	}
	}
	
	return 0;
}
