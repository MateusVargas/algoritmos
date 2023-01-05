/******************************************************************************

Utilizando os conceitos estudados
desenvolva um algoritmo para implementar um grafo com 6 vC)rtices
onde pelo menos dois deles devem ter graus 2 e 3.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define LIMITE_GRAUS 5

typedef struct grafo{
    int no;
    struct grafo *conexoes[LIMITE_GRAUS];
    struct grafo *prox;
} Grafo;


typedef struct modelo{
    int no;
    int conexoes[5];
} Modelo;



void imprimirTeste(Grafo *p){
    if(p!=NULL){
        printf("\n\nnum: %d, &p: %x\t",p->no,p);
        
        for(int i=0;i<LIMITE_GRAUS;i++){
            printf("\ncon[%d]: %x",i,p->conexoes[i]);
        }
        
        imprimirTeste(p->prox);
    }
}


void imprimirGrafo(Grafo *p){
    printf("GRAFO:\n\n");
    
    for( ; p != NULL; p=p->prox){
        
        printf("vertice: %d\n",p->no);
        
        for(int i=0; p->conexoes[i] != NULL; i++){
            printf("<%d, %d>\t",p->no,p->conexoes[i]->no);
        }
        
        printf("\n\n");
        
    }
}



void imprimirGrafoRec(Grafo *p, Grafo *con, int i){
    if(p == NULL) return;
    
    if(con == NULL){
        imprimirGrafoRec(p->prox,p->prox,-1);
    }
    else if(i==-1){
        printf("\n\nvertice: %d\n",p->no);
        imprimirGrafoRec(p,p->conexoes[0],0);
    }
    else{
        printf("<%d, %d>\t",p->no,p->conexoes[i]->no);
        imprimirGrafoRec(p,p->conexoes[++i],i+1);
    }
}



int main(){
    Modelo modelo[6];
    Grafo *inicio = NULL, *aux=NULL, *p, *p_aux;
    int x;
    
    //conexoes vertice 1
    modelo[0].no = 1;
    modelo[0].conexoes[0] = 2;
    modelo[0].conexoes[1] = 3;
    modelo[0].conexoes[2] = 0;
    modelo[0].conexoes[3] = 0;
    modelo[0].conexoes[4] = 0;
  
    //conexoes vertice 2
    modelo[1].no = 2;
    modelo[1].conexoes[0] = 1;
    modelo[1].conexoes[1] = 4;
    modelo[1].conexoes[2] = 0;
    modelo[1].conexoes[3] = 0;
    modelo[1].conexoes[4] = 0;

    //conexoes vertice 3
    modelo[2].no = 3;
    modelo[2].conexoes[0] = 5;
    modelo[2].conexoes[1] = 6;
    modelo[2].conexoes[2] = 0;
    modelo[2].conexoes[3] = 0;
    modelo[2].conexoes[4] = 0;

    //conexoes vertice 4
    modelo[3].no = 4;
    modelo[3].conexoes[0] = 1;
    modelo[3].conexoes[1] = 2;
    modelo[3].conexoes[2] = 5;
    modelo[3].conexoes[3] = 0;
    modelo[3].conexoes[4] = 0;

    //conexoes vertice 5
    modelo[4].no = 5;
    modelo[4].conexoes[0] = 1;
    modelo[4].conexoes[1] = 0;
    modelo[4].conexoes[2] = 0;
    modelo[4].conexoes[3] = 0;
    modelo[4].conexoes[4] = 0;

    //conexoes vertice 6
    modelo[5].no = 6;
    modelo[5].conexoes[0] = 0;
    modelo[5].conexoes[1] = 0;
    modelo[5].conexoes[2] = 0;
    modelo[5].conexoes[3] = 0;
    modelo[5].conexoes[4] = 0;
    
    
    //cria os nos baseado no modelo usando lista encadeada
    
    for(int i=0;i<6;i++){
        Grafo *novo = (Grafo*)malloc(sizeof(Grafo));
        novo->no = modelo[i].no;

        if(i==0)
            inicio = novo;
        
        if(aux!=NULL)
            aux->prox = novo;
        
        aux = novo;
    }

    
    p = inicio;
    
    
    //adiciona nos nós os endereços dos nós que são conexoes, baseado no modelo
    
    for(int i=0;i<6;i++){
        
        x = 0;
        
        for(int j=0;j<LIMITE_GRAUS;j++){
            //printf("p: %d, m:%d\n",p->no,modelo[i].conexoes[j]);
            //printf("p: %d, m:%d\n",p->no,modelo[i].conexoes[j]);
                    
            for(p_aux = inicio; p_aux!=NULL; p_aux=p_aux->prox){
                
                if(modelo[i].conexoes[j]!=0){
                    //printf("p_aux: %d, m:%d\n\n",p_aux->no,modelo[i].conexoes[j]);
                    
                    if(p_aux->no==modelo[i].conexoes[j]){
                        //printf("p: %d, cx: %d\n",p->no,p_aux->no);
                        //printf("X: %d, cx: %d\n",x,p_aux->no);
                        //printf("\nx %d",x);
                        p->conexoes[x] = p_aux;
                        x++;
                    }
                }
            }
        }
        
        for( ; x<LIMITE_GRAUS; x++)
            p->conexoes[x]=NULL;
        
        p=p->prox;
    }

    imprimirTeste(inicio); 
    
    printf("\n\n");
    
    imprimirGrafo(inicio);
    imprimirGrafoRec(inicio,inicio,-1);

    return 0;
}
