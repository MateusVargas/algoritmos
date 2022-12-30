#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int num;
    struct lista *ant;
    struct lista *prox;
} Lista;

void push(Lista **l,Lista **fim,int n){
    Lista *novo=(Lista*)malloc(sizeof(Lista));
    novo->num=n;
    novo->prox=NULL;
    
    if(*l==NULL){
        novo->ant=NULL;
        *l=novo;
    }
    else{
        Lista *p;
        for(p = *l; p->prox!=NULL; p=p->prox){}
        p->prox=novo;
        novo->ant=p;
    }
    *fim=novo;
}

void print(Lista *l,int ordem){
    if(l==NULL) return;
    printf("%d\t",l->num);
    ordem ? print(l->prox,ordem) : print(l->ant,ordem);
}

void insertion_sort(Lista *l){
    Lista *i, *j, *p;
    int aux;
    
    for(i = l->prox; i!=NULL; i=i->prox){
        aux = i->num;
        p=i;
        for(j = i->ant; j!=NULL && aux < j->num; j=j->ant){
            p=j;
            j->prox->num = j->num;
        }
        p->num=aux;
    }
}

int main(){
    Lista *l=NULL,*fim=NULL;
    
    push(&l,&fim,10);
    push(&l,&fim,6);
    push(&l,&fim,3);
    push(&l,&fim,9);
    push(&l,&fim,1);
    push(&l,&fim,5);
    print(l,1);
    printf("\n");
    print(fim,0);
    
    insertion_sort(l);
    
    printf("\n");
    print(l,1);
    
    return 0;
}
