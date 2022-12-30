/*

Desenvolva um algoritmo que permita inserir elementos na última posição de uma lista duplamente encadeada.

Desenvolva um algoritmo que implemente uma lista circular duplamente encadeada.

Desenvolva um algoritmo para permitir a inclusão ordenada de elementos na lista.

Desenvolva um algoritmo para impedir inclusão de valores repetidos.

*/

#include <stdio.h>
#include <stdlib.h>

struct lista{
    int valor;
    struct lista *anterior;
    struct lista *proximo;
};

typedef struct lista Lista;


Lista* inseirir_inicio(Lista *inicio, Lista **fim, int valor){

    Lista *novo = (Lista*)malloc(sizeof(Lista));

    novo->valor = valor;
    novo->anterior = NULL;
    novo->proximo = inicio;

    if(inicio != NULL){
        inicio->anterior = novo;
    }

    if((*fim) == NULL){
        *fim = novo;
    }

    inicio = novo;

    return inicio;
}


Lista *inserir_fim(Lista *inicio, Lista *fim, int valor){
    Lista *novo = (Lista*)malloc(sizeof(Lista));

    novo->valor = valor;
    novo->proximo = NULL;
    novo->anterior = fim;
    fim->proximo = novo;
    fim = novo;

    return fim;
}


void imprimir(Lista* inicio){
    Lista *iterator = inicio;

    if(inicio == NULL){
        printf("lista vazia");
    }
    else{

        while(iterator != NULL){
            printf("%d\t",iterator->valor);
            iterator = iterator->proximo;
        }

    }

    printf("\n");
}



void imprimir_tras_pra_frente(Lista* fim){
    Lista *iterator = fim;

    if(fim == NULL){
        printf("lista vazia");
    }
    else{
        while(iterator != NULL){
            printf("%d\t",iterator->valor);
            iterator = iterator->anterior;
        }
    }

    printf("\n");
}


Lista* remover(Lista *inicio, Lista **fim, int valor){

    Lista *iterator = inicio;

    if(inicio == NULL){
        printf("lista vazia\n");
    }

    else{

        for( ; iterator != NULL && iterator->valor != valor; iterator = iterator->proximo){

        }

        if(iterator == NULL){
            printf("nao achou\n");
        }

        else{

            //achou e é o primeiro
            if(iterator == inicio){
                inicio = inicio->proximo;

                //se depois de inicio = inicio->proximo
                //o inicio nao for NULL entao quer dizer que nao o elemento removido nao era o unico elemento da lista
                if(inicio != NULL){
                    inicio->anterior = NULL;
                }
            }

            //achou e é o ultimo
            else if(iterator->proximo == NULL){
                *fim = (*fim)->anterior;
                (*fim)->proximo = NULL;
            }

            //achou no meio
            else{
                iterator->anterior->proximo = iterator->proximo;
                iterator->proximo->anterior = iterator->anterior;
            }

            free(iterator);

        }

    }

    return inicio;
}



Lista* verifica_repetido(Lista *inicio, int valor){

    Lista *iterator = inicio;

    while(iterator != NULL && iterator->valor != valor){
        iterator = iterator->proximo;
    }

    return iterator;
}



int main()
{
    Lista *inicio = NULL, *fim = NULL, *repetido = NULL;
    int opcao, valor;

    do{

        printf("1-inserir inicio\n");
        printf("2-inserir no final\n");
        printf("3-remover\n");
        printf("4-imprimir\n");
        printf("5-imprimir de tras pra frente\n");
        printf("9-sair\n");
        scanf("%d",&opcao);

        if(opcao == 1){
            printf("valor: ");
            scanf("%d",&valor);

            if(inicio == NULL){
                inicio = inseirir_inicio(inicio, &fim, valor);
            }
            else{
                repetido = verifica_repetido(inicio, valor);

                if(repetido == NULL){
                    inicio = inseirir_inicio(inicio, &fim, valor);
                }
                else{
                    printf("elemento ja existe\n");
                }

            }

        }

        else if(opcao == 2){
            printf("valor: ");
            scanf("%d",&valor);

            if(inicio == NULL){
                printf("lista vazia, inserindo no inicio\n");
                inicio = inseirir_inicio(inicio, &fim, valor);
            }
            else{
                fim = inserir_fim(inicio, fim, valor);
            }

        }

        else if(opcao == 3){
            printf("valor pra apagar: ");
            scanf("%d",&valor);
            inicio = remover(inicio, &fim, valor);
        }

        else if(opcao == 4){
            imprimir(inicio);
        }

        else if(opcao == 5){
            imprimir_tras_pra_frente(fim);
        }

    }while(opcao != 9);


    return 0;
}
