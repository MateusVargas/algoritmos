#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int num;
    struct lista *prox;
} Lista;


int tamanho_lista(Lista *p){
    if(p==NULL)
        return 0;
    return 1+tamanho_lista(p->prox);
}

void selection_sort(Lista *p, int tamanho_lista){
    int aux;
    
    Lista *iterator_i, *iterator_j, *menor, no_aux, *prox_aux;
    
    for(iterator_i = p; iterator_i->prox!=NULL; iterator_i = iterator_i->prox){
        menor = iterator_i;
        
        for(iterator_j = iterator_i->prox; iterator_j!=NULL; iterator_j = iterator_j->prox){
            if(iterator_j->num < menor->num){
                menor = iterator_j;
            }
        }
        
        //trocando valor dos nós
        // aux = iterator_i->num;
        // iterator_i->num = menor->num;
        // menor->num = aux;
        
        //trocar nós de lugar
        no_aux = *iterator_i;
        *iterator_i = *menor;
        *menor = no_aux;
        
        prox_aux = iterator_i->prox;
        iterator_i->prox = menor->prox;
        menor->prox = prox_aux;
    }
}


void inserir(Lista **p, int num){
    Lista *novo=(Lista*)malloc(sizeof(Lista));
    novo->num = num;
    novo->prox = *p;
    *p = novo;
}

void print(Lista *p){
    if(p != NULL){
        printf("%d\t",p->num);
        print(p->prox);
    }
    printf("\n");
}

int main(){
    Lista *inicio = NULL;
    
    inserir(&inicio, 7);
    inserir(&inicio, 70);
    inserir(&inicio, 65);
    inserir(&inicio, 3);
    inserir(&inicio, 12);
    inserir(&inicio, 5);
    inserir(&inicio, 23);
    print(inicio);
    selection_sort(inicio,tamanho_lista(inicio));
    print(inicio);
    
    return 0;
}
