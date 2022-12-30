#include <stdio.h>
#include <stdlib.h>

struct lista{
    int valor;
    struct lista *prox;
};

typedef struct lista Lista;


void popular_vetor(int *vet, int inicio){
    int stop = inicio == 2 ? 8 : 7;
    int valores = inicio;

    for(int i=0; i<4; i++){
        *(vet+i) = valores;
        valores+=2;
    }

}


/*
1a iteracao:
novo->valor = 8
novo->prox = NULL
inicio = 8

2a:
novo->valor = 6
novo->prox = 8;
inicio = 6

3a:
novo->valor = 4
novo->prox = 6;
inicio = 4

4a:
novo->valor = 2
novo->prox = 4
inicio = 2

aux esta sempre um passo atras, por isso novo->prox aponta pro elemento inserido antes
*/
void inserir_vetor_na_lista_no_inicio(Lista **inicio, int *vetor){

    Lista *novo = NULL, *aux = NULL;

    for(int i=3;i>=0;i--){

        novo = (Lista*)malloc(sizeof(Lista));
        novo->valor = *(vetor+i);
        novo->prox = aux;

        *inicio = novo;
        aux = novo;
    }

}


void imprimir(Lista *inicio){

    Lista *iterator = inicio;

    printf("\nlista encadeada:\n");

    for( ; iterator != NULL; iterator = iterator->prox){
        printf("%d\t",iterator->valor);
    }

}



Lista* intercalar(Lista *inicio_pares, Lista *inicio_impares){

    Lista *inicio = NULL;
    Lista *iterator_pares = inicio_pares;
    Lista *iterator_impares = inicio_impares;
    Lista *aux_novo2 = NULL, *novo = NULL, *novo2 = NULL;
    int i=0;

    for( ; iterator_impares != NULL; ){

        novo = (Lista*)malloc(sizeof(Lista));
        novo2 = (Lista*)malloc(sizeof(Lista));

        novo->valor = iterator_impares->valor;
        novo->prox = NULL;

        novo2->valor = iterator_pares->valor;
        novo2->prox = NULL;

        if(i==0){
            inicio = novo;
            aux_novo2 = novo2;
            novo->prox = novo2;
        }
        else{
            aux_novo2->prox = novo;
            novo->prox = novo2;
        }

        aux_novo2 = novo2;

        iterator_impares = iterator_impares->prox;
        iterator_pares = iterator_pares->prox;
        i++;

    }



    return inicio;
}



int main()
{
    int *vetor_pares = NULL, *vetor_impares = NULL;

    Lista *inicio_lista_pares = NULL;
    Lista *inicio_lista_impares = NULL;
    Lista *inicio_lista_intercalada = NULL;

    vetor_pares = (int*)malloc(4 * sizeof(int));
    vetor_impares = (int*)malloc(4 * sizeof(int));

    popular_vetor(vetor_pares,2);
    popular_vetor(vetor_impares,1);

    for(int i=0;i<4;i++){
        printf("%d\t",*(vetor_pares+i));
    }

    printf("\n");

    for(int i=0;i<4;i++){
        printf("%d\t",*(vetor_impares+i));
    }

    inserir_vetor_na_lista_no_inicio(&inicio_lista_pares, vetor_pares);
    imprimir(inicio_lista_pares);

    inserir_vetor_na_lista_no_inicio(&inicio_lista_impares, vetor_impares);
    imprimir(inicio_lista_impares);


    printf("\n\n\nintercalando as listas:\n");
    inicio_lista_intercalada = intercalar(inicio_lista_pares,inicio_lista_impares);
    imprimir(inicio_lista_intercalada);

    return 0;
}


