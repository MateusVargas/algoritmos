/*
Desenvolva um algoritmo para inserir dinamicamente elementos em uma pilha e depois:

Criar uma função para inverter a ordem dos elementos;
Reposicionar o elemento do topo para a base da pilha e o da base para o topo.
*/

#include <stdio.h>
#include <stdlib.h>

struct lista{
    int valor;
    struct lista *prox;
};

typedef struct lista Lista;


void inserir_fim(Lista **inicio, int num){
    Lista *novo, *iterator;

    novo = (Lista*)malloc(sizeof(Lista));
    novo->valor = num;
    novo->prox = NULL;

    if(*inicio == NULL){
        *inicio = novo;
    }
    else{
        iterator = *inicio;

        while(iterator->prox != NULL){
            iterator = iterator->prox;
        }

        iterator->prox = novo;
    }
}


void remover_fim(Lista **inicio){
    Lista *iterator = *inicio, *anterior = NULL;

    if(*inicio==NULL){
        printf("lista vazia\n");
    }
    else if((*inicio)->prox == NULL){
        free(*inicio);
        *inicio = NULL;
    }
    else{
        while(iterator->prox != NULL){
            anterior = iterator;
            iterator = iterator->prox;
        }

        anterior->prox = NULL;
        free(iterator);
    }

}


void imprimir(Lista *inicio){
    if(inicio != NULL){
        printf("%d\t",inicio->valor);
        imprimir(inicio->prox);
    }
    printf("\n");
}


void trocar(Lista **inicio){
    Lista *iterator = *inicio, *aux, *anterior;

    if(*inicio == NULL){
        printf("lista vazia\n");
    }
    else if((*inicio)->prox == NULL){
        printf("so existe um elemento\n");
    }
    else{
        while(iterator->prox != NULL){
            anterior = iterator;
            iterator = iterator->prox;
        }

        anterior->prox = *inicio; //proximo do penultimo passa a ser o inicio
        aux = (*inicio)->prox; //salva o proximo do inicio
        (*inicio)->prox = NULL; //proximo do inicio será NULL, porque o inicio vai pro fim
        *inicio = iterator; //inicio passa a ser o ultimo
        (*inicio)->prox = aux; //proximo do inicio passa a ser o antigo proximo do inicio
    }
}



void inverter(Lista **inicio){
    Lista *iterator = *inicio, *anterior = NULL, *novo = NULL, *aux = NULL, *inicio_lista2 = NULL;

    int total_elementos = 0;

    while(iterator != NULL){
        iterator = iterator->prox;
        total_elementos++;
    }


    for(int i=0; i<total_elementos;i++){

        iterator = *inicio;

        while(iterator->prox != NULL){
            anterior = iterator;
            iterator = iterator->prox;
        }

        novo = (Lista*)malloc(sizeof(Lista));
        novo->valor = iterator->valor;
        novo->prox = NULL;

        if(i==0){
            aux = novo;
            inicio_lista2 = novo;
        }
        else{
            aux->prox = novo;
        }

        aux = novo;

        anterior->prox = NULL;
        free(iterator);
    }


    iterator = inicio_lista2;
    printf("invertido\n");

    for( ; iterator != NULL; iterator = iterator->prox){
        printf("%d\t",iterator->valor);
    }

    *inicio = inicio_lista2;
}



int main(){
    Lista *inicio = NULL;
    int op, num;

    do{
        printf("PILHA\n1-inserir\n");
        printf("2-remover\n");
        printf("3-imprimir\n");
        printf("4-inverter ordem\n");
        printf("5-trocar primeiro com ultimo\n");
        printf("9-sair\n");
        scanf("%d",&op);

        switch(op){
            case 1:
                printf("valor: ");
                scanf("%d",&num);
                inserir_fim(&inicio, num);
                break;

            case 2:
                remover_fim(&inicio);
                break;

            case 3:
                imprimir(inicio);
                break;

            case 4:
                inverter(&inicio);
                break;

            case 5:
                inverter(&inicio);
                break;

        }

    }while(op!=9);

    return 0;
}
