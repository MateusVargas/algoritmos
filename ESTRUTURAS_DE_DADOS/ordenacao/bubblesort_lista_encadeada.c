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

void bubblesort(Lista *p, int tamanho_lista){
    int aux;
    
    Lista *iterator_i, *iterator_j = p, *menor, no_aux, *prox_aux;
    
    for(iterator_i = p; iterator_i!=NULL; iterator_i = iterator_i->prox){
        menor = iterator_i;
        
        for(iterator_j = p; iterator_j->prox!=NULL; iterator_j = iterator_j->prox){
            if(iterator_j->num > iterator_j->prox->num){
                //trocando valor dos nós
                aux = iterator_j->num;
                iterator_j->num = iterator_j->prox->num;
                iterator_j->prox->num = aux;
            }
        }
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
    
    inserir(&inicio, 9);
    inserir(&inicio, 4);
    inserir(&inicio, 7);
    inserir(&inicio, 2);
    inserir(&inicio, 21);
    inserir(&inicio, 17);
    inserir(&inicio, 14);
    print(inicio);
    bubblesort(inicio,tamanho_lista(inicio));
    print(inicio);
    
    return 0;
}
