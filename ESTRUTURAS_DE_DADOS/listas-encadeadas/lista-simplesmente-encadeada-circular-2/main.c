#include <stdio.h>
#include <stdlib.h>

struct lista{
    int valor;
    struct lista *prox;
};

typedef struct lista Lista;


//recebe o endereco dos ponteiros inicio e fim, pra que as mudanças reflitam fora da funcao (passagem por referencia)
void inserir_inicio(Lista **inicio, Lista **fim, int num){

    Lista *novo = (Lista*)malloc(sizeof(Lista));

    //se esta inserindo no inicio, entao o novo nó aponta pro antigo nó de inicio
    //e o inicio é atualizado com o novo
    novo->valor = num;
    novo->prox = *inicio;
    *inicio = novo;

    //se eh o 1o elemento fim aponta pra NULL, entao ele passa a apontar pro novo
    if(*fim == NULL){
        *fim = novo;
    }

    //proximo do ultimo elemento aponta pro inicio
    (*fim)->prox = *inicio;

}



void inserir_fim(Lista **inicio, Lista **fim, int num){

    Lista *novo = (Lista*)malloc(sizeof(Lista));

    novo->valor = num;

    //se a lista esta vazia, inicio, fim e proximo do ultimo apontam pro novo
    //senao entao o antigo nó do fim passa a apontar pro novo, o ponteiro do fim é atualizado com o novo nó
    //e o novo nó aponta pro inicio
    if(*inicio == NULL){
        *inicio = novo;
        *fim = novo;
        (*fim)->prox = inicio;
    }
    else{
        (*fim)->prox = novo;
        *fim = novo;
        novo->prox = *inicio;
    }

}



Lista* remover(Lista **inicio, Lista **fim, int valor){

    Lista *aux = NULL, *no_removido = NULL;

    //se a lista esta vazia
    if(*inicio != NULL){

        //se so existe um elemento na lista e se quer tirar ele
        if(*inicio == *fim && (*inicio)->valor == valor){
            no_removido = *inicio;
            *inicio = NULL;
            *fim = NULL;
        }

        //se existe mais de um elemento e se quer tirar o primeiro
        //entao o inicio passa a apontar pro proximo dele mesmo
        //e o fim aponta pro valor de inicio ja atualizado
        else if((*inicio)->valor == valor){
            no_removido = *inicio;
            *inicio = (*inicio)->prox;
            (*fim)->prox = *inicio;
        }


        else{
            aux = *inicio;

            //enquanto o proximo do nó atual for != NULL
            //e o proximo do nó atual for != do valor procurado

            //se achar o elemento pra remover esse elemento será o aux->prox
            //e o aux será o elemento anterior
            while(aux->prox != *inicio && aux->prox->valor != valor){
                aux = aux->prox;
            }

            //se achou o elemento
            if(aux->prox->valor == valor){

                //se o nó pra remover é o ultimo nó
                //aux é o anterior, entao o proximo do anterior é o proximo do nó a ser removido
                //por isso aux->prox->prox
                //fim aponta pro aux, que é o anterior do nó a ser removido
                if(*fim == aux->prox){
                    no_removido = aux->prox;
                    aux->prox = aux->prox->prox;
                    *fim = aux;
                }

                //senao for o ultimo faz o mesmo que esta no if, mas sem mexer no ponteiro do fim
                else{
                    no_removido = aux->prox;
                    aux->prox = aux->prox->prox;
                }

            }

        }

    }
    else{
        printf("lista vazia.\n");
    }

    return no_removido;

}



void imprimir(Lista *inicio, Lista *fim){

    Lista *iterator = inicio;

    if(iterator == NULL){
        printf("lista vazia.\n");
    }
    else{

        do{
            printf("%d\t",iterator->valor);
            iterator = iterator->prox;
        }while(iterator != inicio);

        printf("\ninicio: %d\n",iterator->valor);

    }

    printf("\n\n");

}



void ordem_crescente(Lista *inicio){

    Lista *iterator_i = inicio, *iterator_j = inicio;
    int aux;

    do{
        do{
            if(iterator_i->valor > iterator_j->valor){
                aux = iterator_i->valor;
                iterator_i->valor = iterator_j->valor;
                iterator_j->valor = aux;
            }

            iterator_j = iterator_j->prox;

        }while(iterator_j != inicio);

        iterator_i = iterator_i->prox;
        iterator_j = iterator_i;

    }while(iterator_i != inicio);

}



int main()
{
    Lista *inicio = NULL, *fim = NULL;

    int opcao, num, valor_remover;

    do{

        printf("1-inserir inicio\n2-inserir fim\n3-remover\n4-imprimir\n5-ordenar ordem crescente\n9-sair\n");
        scanf("%d",&opcao);

        switch(opcao){
            case 1:
                printf("valor: ");
                scanf("%d",&num);
                inserir_inicio(&inicio,&fim,num);
                break;

            case 2:
                printf("valor: ");
                scanf("%d",&num);
                inserir_fim(&inicio,&fim,num);
                break;

            case 3:
                Lista *removido = NULL;

                printf("valor a ser removido: ");
                scanf("%d",&valor_remover);
                removido = remover(&inicio, &fim, valor_remover);
                if(removido){
                    printf("%d removido\n",removido->valor);
                    free(removido);
                }
                else{
                    printf("elemento nao encontrado.\n");
                }
                break;

            case 4:
                imprimir(inicio,fim);
                break;

            case 5:
                ordem_crescente(inicio);
                break;
        }

    }while(opcao != 9);

    return 0;
}
