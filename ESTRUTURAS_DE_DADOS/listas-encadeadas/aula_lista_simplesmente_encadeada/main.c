/*Descreva textualmente as etapas para criação de uma lista vazia e a
inserção de elementos nela?

• Desenvolva um algoritmo para criar uma lista encadeada vazia.
Depois crie uma função que permita que o inserir elementos nela.
Por último, apresente os valores pares da lista.

• Escreva uma função que receba por parâmetro um ponteiro para o
primeiro elemento da lista e retira um elemento do início, do meio
e do final da lista. Depois apagar da memória o elemento retirado.

• Escreva uma função que receba por parâmetro um valor e um
ponteiro para o primeiro elemento da lista e insere um nó na última
posição.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoa{
    char nome[30];
    int idade;
    struct pessoa *prox;
};

typedef struct pessoa Pessoa;


Pessoa* inserir_inicio(Pessoa *inicio, char nome[30], int idade){

    Pessoa *novo = (Pessoa*)malloc(sizeof(Pessoa));

    strcpy(novo->nome,nome);
    novo->idade = idade;
    novo->prox = inicio;

    return novo;
}


void inserir_fim(Pessoa *inicio, char nome[30], int idade){

    Pessoa *novo, *iterator = NULL;

    novo = (Pessoa*)malloc(sizeof(Pessoa));

    //procurar ultimo elemento, quando o proximo for NULL entao achou-se o ultimo elemento
    for(iterator = inicio; iterator->prox != NULL; iterator = iterator->prox){

    }

    strcpy(novo->nome, nome);
    novo->idade = idade;
    novo->prox = NULL;

    iterator->prox = novo;
}


void inserir_meio(Pessoa *inicio, char referencia[30], char nome[30], int idade){

    Pessoa *iterator = inicio, *novo = NULL;

    //percorre até o final da lista caso nao encontre o elemento pelo nome
    for( ; iterator != NULL && strcmp(iterator->nome,referencia) != 0; iterator = iterator->prox){

    }

    //se for NULL entao percorreu tudo e nao achou
    if(iterator == NULL){
        printf("pessoa nao encontrada\n");
    }
    else{
        novo = (Pessoa*)malloc(sizeof(Pessoa));
        strcpy(novo->nome, nome);
        novo->idade = idade;

        //proximo do novo será o proximo do elemento referencia
        //proximo do elemento referencia será o novo elemento
        novo->prox = iterator->prox;
        iterator->prox = novo;
    }
}


void imprimir(Pessoa *inicio){
    Pessoa *iterator = inicio;

    for( ;iterator != NULL; iterator = iterator->prox){
        printf("nome: %s, idade: %d\n",iterator->nome, iterator->idade);
    }
}


void imprimir_pares(Pessoa *inicio){
    Pessoa *iterator = inicio;

    for( ; iterator != NULL; iterator = iterator->prox){
        if((iterator->idade % 2) == 0){
            printf("nome: %s, idade: %d\n",iterator->nome, iterator->idade);
        }
    }
}


Pessoa* remover_inicio_meio_fim(Pessoa *inicio, char nome[30]){

    Pessoa *iterator = inicio, *anterior = NULL;

    while(iterator != NULL &&(strcmp(nome, iterator->nome) != 0)) {
        anterior = iterator; //pega o anterior
        iterator = iterator->prox;
    }

    //nao achou a pessoa
    if(iterator == NULL){
        printf("pessoa nao encontrada\n");
    }

    else{
        //se anterior for NULL, entao não entrou no while
        //e tambem a lista não eh vazia porque teria caido no if decima, entao achou a pessoa e ela
        //ta na 1a posicao
        if(anterior == NULL){
            inicio = iterator->prox;
        }

        //se cair aqui, entao achou a pessoa e ela nao ta no inicio
        //o proximo do anterior dessa pessoa apontava pra ela, agora aponta pro proximo da pessoa
        //pessoa é tirada da lista
        else{
            anterior->prox = iterator->prox;
        }

        free(iterator);
    }

    return inicio;
}


void limpar_lista(Pessoa *inicio){
    Pessoa *iterator = inicio;

    //limpa nó por nó
    while(iterator != NULL){
        free(iterator);
        iterator = iterator->prox;
    }
}


Pessoa* copiar_lista(Pessoa *inicio){

    Pessoa *iterator = inicio, *novo = NULL, *aux = NULL, *inicio_lista_copia = NULL;

    while(iterator != NULL){

        novo = (Pessoa*)malloc(sizeof(Pessoa));
        strcpy(novo->nome, iterator->nome);
        novo->idade = iterator->idade;
        novo->prox = NULL;

        //se for a primeira iteracao, cria um novo nó com os dados do primeiro elemento
        //e aponta o inicio da lista_copia pra esse primeiro nó
        if(iterator == inicio){
            inicio_lista_copia = novo;
            aux = novo;
        }
        else{
            aux->prox = novo;
            aux = novo;
        }

        iterator = iterator->prox;

    }

    return inicio_lista_copia;

}


int main()
{
    Pessoa *inicio = NULL, *lista_copia = NULL;
    char nome[30];
    int idade;
    int opcao;

    while(opcao != 11){
        printf("\n1-inserir inicio\n2-inserir meio\n3-inserir fim\n4-imprimir\n5-imprimir pessoas com idade par\n6-apagar\n7-limpar lista\n8-copiar lista\n9-imprimir copia\n10-limpar copia\n11-sair\n");
        scanf("%d",&opcao);

        if(opcao == 1){
            printf("nome: ");
            getchar();
            gets(nome);

            printf("idade: ");
            scanf("%d",&idade);

            inicio = inserir_inicio(inicio, nome, idade);
        }

        else if(opcao == 2){

            char referencia[30];

            printf("nome: ");
            getchar();
            gets(nome);

            printf("idade: ");
            scanf("%d",&idade);

            if(inicio == NULL){
                printf("lista vazia, inserindo no inicio..\n");
                inicio = inserir_inicio(inicio, nome, idade);
            }
            else{
                printf("inserir depois de quem: ");
                getchar();
                gets(referencia);

                inserir_meio(inicio, referencia, nome, idade);
            }

        }

        else if(opcao == 3){
            printf("nome: ");
            getchar();
            gets(nome);

            printf("idade: ");
            scanf("%d",&idade);

            //se a lista estiver vazia, insere no inicio
            if(inicio == NULL){
                inicio = inserir_inicio(inicio,nome,idade);
            }
            else{
                inserir_fim(inicio, nome, idade);
            }
        }

        else if(opcao == 4){
             //printf("%d",inicio->idade);
             imprimir(inicio);
        }

        else if(opcao == 5){
            imprimir_pares(inicio);
        }

        else if(opcao == 6){
            printf("nome da pessoa: ");
            getchar();
            gets(nome);

            inicio = remover_inicio_meio_fim(inicio, nome);
        }

        else if(opcao == 7){
            limpar_lista(inicio);
            inicio = NULL;
        }

        else if(opcao == 8){
            lista_copia = copiar_lista(inicio);
        }

        else if(opcao == 9){
            imprimir(lista_copia);
        }

        else if(opcao == 10){
            limpar_lista(lista_copia);
            lista_copia = NULL;
        }

    }

    return 0;
}
