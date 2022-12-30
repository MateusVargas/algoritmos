#include <stdio.h>
#include <stdlib.h>

struct lista{
    int valor;
    struct lista *prox;
};

typedef struct lista Lista;


Lista* inserir_inicio(Lista *inicio, int num){

    Lista *novo = (Lista*)malloc(sizeof(Lista)), *iterator = NULL;

    novo->valor = num;

    //se eh o primeiro a ser inserido, 1o elemento aponta pra ele mesmo
    if(inicio == NULL){
        novo->prox = novo;
    }
    else{

        //se o inicio aponta pra ele mesmo entao so tem 1 elemento, entao esta adicionando o 2o elemento, o primeiro aponta pro segundo e vice-versa
        if(inicio->prox == inicio){
            novo->prox = inicio;
            inicio->prox = novo;
        }
        else{
            for(iterator = inicio; iterator->prox != inicio; iterator = iterator->prox){

            }

            iterator->prox = novo;
            novo->prox = inicio;
        }
    }

    inicio = novo;

    return inicio;
}



Lista* inserir_fim(Lista *inicio, int num){

    Lista *novo = (Lista*)malloc(sizeof(Lista));
    Lista *iterator = inicio;

    novo->valor = num;

    if(inicio == NULL){
        printf("lista vazia, inserindo no inicio..\n");
        novo->prox = novo;
        inicio = novo;
    }
    else{

        //percorre enquanto o proximo do elemento nao apontar pro inicio, quando apontar entao eh o ultimo elemento
        while(iterator->prox != inicio){
            iterator = iterator->prox;
        }

        //elemento que antes apontava pro inicio, aponta pro novo
        iterator->prox = novo;
        novo->prox = inicio;
    }

    return inicio;
}




void inserir_meio(Lista *inicio, int num, int referencia){

    Lista *novo = (Lista*)malloc(sizeof(Lista));
    Lista *iterator = inicio;

    int achou = 0;

    novo->valor = num;

    while(1==1){
        if(iterator->valor == referencia){
            achou = 1;
            break;
        }

        if(iterator->prox == inicio){
            break;
        }

        iterator = iterator->prox;
    }


    if(!achou){
        printf("elemento nao encontrado.\n");
    }
    else{
        novo->prox = iterator->prox;
        iterator->prox = novo;
    }

}




Lista* remover_inicio_meio_ou_fim(Lista *inicio, int num){

    Lista *iterator = inicio, *anterior = NULL;
    int achou = 0;

    for( ; ; iterator = iterator->prox){
        if(iterator->valor == num){
            achou = 1;
            break;
        }

        if(iterator->prox == inicio){
            break;
        }

        anterior = iterator;
    }

    if(!achou){
        printf("elemento nao encontrado.\n");
    }
    else{

        //se achou e o elemento eh o primeiro da lista
        if(anterior == NULL){
            if(iterator == inicio->prox){
                inicio = NULL;
            }

            else{
                Lista *aux = inicio;

                inicio = iterator->prox;
                //free(iterator);

                for(iterator = inicio; iterator->prox != aux; iterator = iterator->prox){

                }

                iterator->prox = inicio;
            }


        }

        //se achou e eh o ultimo elemento da lista
        else if(iterator->prox == inicio){
            printf("removendo ultimo elemento..\n");
            anterior->prox = inicio;
            free(iterator);
        }

        else{
            printf("removendo elemento..\n");
            anterior->prox = iterator->prox;
            free(iterator);
        }
    }


    return inicio;
}




void imprimir(Lista *inicio){

    Lista *iterator = inicio;

    if(inicio == NULL){
        printf("lista vazia\n");
    }
    else if(iterator->prox == inicio){
        printf("%d\n",iterator->valor);
    }
    else{
        for( ; ; iterator = iterator->prox){
            printf("%d\t",iterator->valor);

            //se o proximo do atual aponta pro inicio entao chegou ao fim
            if(iterator->prox == inicio){
                break;
            }
        }
    }

    printf("\n");

}


int main()
{
    Lista *inicio = NULL;
    int opcao, num;

    do{
        printf("1-inserir inicio\n");
        printf("2-inserir no fim\n");
        printf("3-inserir no meio\n");
        printf("4-remover\n");
        printf("5-imprimir\n");
        printf("6-sair\n");
        scanf("%d",&opcao);

        switch(opcao){
            case 1:
                printf("valor: ");
                scanf("%d",&num);
                inicio = inserir_inicio(inicio,num);
                break;

            case 2:
                printf("valor: ");
                scanf("%d",&num);
                inicio = inserir_fim(inicio,num);
                break;

            case 3:
                printf("valor: ");
                scanf("%d",&num);

                if(inicio == NULL){
                    printf("lista vazia, inserindo no inicio..\n");
                    inicio = inserir_inicio(inicio,num);
                }
                else{
                    int referencia;
                    printf("inserir depois de quem: ");
                    scanf("%d",&referencia);

                    inserir_meio(inicio,num,referencia);
                }

                break;

            case 4:
                if(inicio == NULL){
                    printf("lista vazia..\n");
                }
                else{
                    printf("valor para excluir: ");
                    scanf("%d",&num);
                    inicio = remover_inicio_meio_ou_fim(inicio,num);
                }

                break;

            case 5:
                imprimir(inicio);
                break;

        }

    }while(opcao != 6);


    return 0;
}
