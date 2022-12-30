#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dados{
    char nome_time[30];
    int gols_marcados;
};

struct classificacao{
    int posicao;
    struct dados dados;
    struct classificacao *proximo;
};


struct controle_classificacao{
    struct classificacao *inicio;
    struct classificacao *fim;
};




void inserir_inicio(struct controle_classificacao **c){
    struct classificacao *novo;

    novo = (struct classificacao*)malloc(sizeof(struct classificacao));

    printf("posicao: ");
    scanf("%d",&novo->posicao);

    printf("nome time: ");
    getchar();
    gets(novo->dados.nome_time);

    printf("gols marcados: ");
    scanf("%d",&novo->dados.gols_marcados);

    //lista vazia, faz o fim apontar pro novo
    if((*c)->inicio == NULL){
        (*c)->fim = novo;
    }

    novo->proximo = (*c)->inicio;//novo aponta pro elemento que era o inicio mas que agora eh o segundo
    (*c)->inicio = novo;

    printf("\n\nc: %x\n",c);
    printf("*c: %x\n",*c);
    printf("(*c)->inicio: %x\t novo: %x\n\n",(*c)->inicio,novo);
    printf("(*c)->inicio: %d\n",(*c)->inicio->posicao);//acessa valor do nó que o inicio aponta
}



/*
void inserir_inicio2(struct controle_classificacao *c){
    struct classificacao *novo;

    novo = (struct classificacao*)malloc(sizeof(struct classificacao));

    printf("posicao: ");
    scanf("%d",&novo->posicao);

    printf("nome time: ");
    getchar();
    gets(novo->dados.nome_time);

    printf("gols marcados: ");
    scanf("%d",&novo->dados.gols_marcados);

    //lista vazia, faz o fim apontar pro novo
    if((*c).inicio == NULL){
        (*c).fim = novo;
    }

    novo->proximo = (*c).inicio;
    (*c).inicio = novo;

    printf("\n\nc: %x\n",c);
    printf("*c: %x\n",*c);
    printf("(*c).inicio: %x\t novo: %x\n\n",(*c).inicio,novo);
    printf("*(c).inicio: %x\n",*(*c).inicio);
}
*/



void inserir_final(struct controle_classificacao **c){
    struct classificacao *novo;
    novo = (struct classificacao*)malloc(sizeof(struct classificacao));

    printf("posicao: ");
    scanf("%d",&novo->posicao);

    printf("nome time: ");
    getchar();
    gets(novo->dados.nome_time);

    printf("gols marcados: ");
    scanf("%d",&novo->dados.gols_marcados);

    //lista vazia, inicio aponta pro novo
    if((*c)->inicio == NULL){
        (*c)->inicio = novo;
    }
    else{
        (*c)->fim->proximo = novo;
        //o proximo do elemento que era o fim, passa a apontar pro novo
    }

    //proximo do novo = NULL, e atualiza o ponteiro que aponta pro fim
    novo->proximo = NULL;
    (*c)->fim = novo;
}



void inserir_meio(struct controle_classificacao **c){
    char pesquisa[30];
    struct classificacao *procurar, *novo;
    int achou = 0;

    procurar = (*c)->inicio;
    novo = (struct classificacao*)malloc(sizeof(struct classificacao));

    printf("posicao: ");
    scanf("%d",&novo->posicao);

    printf("nome time: ");
    getchar();
    gets(novo->dados.nome_time);

    printf("gols marcados: ");
    scanf("%d",&novo->dados.gols_marcados);

    if((*c)->inicio == NULL){
        printf("lista vazia, inserindo no inicio...\n");
        novo->proximo = NULL;
        (*c)->inicio = novo;
        (*c)->fim = novo;
    }
    else{
        printf("inserir depois de qual time: ");
        getchar();
        gets(pesquisa);

        while((strcmp(procurar->dados.nome_time, pesquisa) != 0) && procurar->proximo != NULL){
            procurar = procurar->proximo;

            if(strcmp(procurar->dados.nome_time, pesquisa) != 0){
                achou = 1;
            }
        }

        //se achou, o proximo do novo aponta pro elemento que o elemento encontrado aponta
        //e o proximo do elemento encontrado aponta pro novo, assim o novo entra depois do elemento encontrado
        if(achou == 1){
            novo->proximo = procurar->proximo;
            procurar->proximo = novo;
        }
        else{
            printf("time nao achado, inserindo no fim...\n");
            novo->proximo = NULL;
            (*c)->fim->proximo = novo;
            (*c)->fim = novo;
        }
    }
}



void imprimir(struct controle_classificacao *c){
    struct classificacao *nos;
    nos = c->inicio;

    while(nos != NULL){
        printf("pos. %d\t",nos->posicao);
        printf("time: %s\t",nos->dados.nome_time);
        printf("gm: %d\n",nos->dados.gols_marcados);
        printf("\n\n");

        nos = nos->proximo;
    }
}



void remover_inicio(struct controle_classificacao **c){

    if((*c)->inicio == NULL){
        printf("lista vazia.\n");
    }
    else{
        struct classificacao *aux;

        //faz o ponteiro que aponta pro inicio apontar pro segundo
        aux = (*c)->inicio;
        (*c)->inicio = (*c)->inicio->proximo;
        free(aux);
    }

}



void remover_final(struct controle_classificacao **c){

    if((*c)->inicio == NULL){
        printf("lista vazia.\n");
    }
    else{
        struct classificacao *achar_ultimo = (*c)->inicio;

        //se existe apenas 1 elemento na lista, remove ele e fica vazia a lista
        if((*c)->inicio == (*c)->fim){
            (*c)->inicio = NULL;
            (*c)->fim = NULL;
        }
        else{

            //senao, percorre ate o proximo do atual ter o mesmo endereço de memoria do ponteiro que aponta pro fim
            //ou seja, sera retornado o penultimo elemento, esse penultimo vira o ultimo
            while(achar_ultimo->proximo != (*c)->fim){
                achar_ultimo = achar_ultimo->proximo;
            }

            achar_ultimo->proximo = NULL;

            free((*c)->fim);
            (*c)->fim = achar_ultimo;
        }
    }

}




void remover_meio(struct controle_classificacao **c){
    char pesquisa[30];
    struct classificacao *procurar, *anterior;
    int achou = 0;

    if((*c)->inicio == NULL){
        printf("lista vazia.\n");
    }
    else{
        printf("time para remover: ");
        getchar();
        gets(pesquisa);

        procurar = (*c)->inicio;

        //se tem 1 elemento na lista apenas, apaga ele
        if((*c)->inicio == (*c)->fim){
            (*c)->inicio = NULL;
            (*c)->fim = NULL;
        }

        else{

            //senao percorre toda a lista e compara o nome do time em cada nó com o texto pesquisado
            //se achar sai do laço
            while(procurar->proximo != NULL){
                anterior = procurar;
                procurar = procurar->proximo;

                if(strcmp(procurar->dados.nome_time,pesquisa) == 0){
                    achou = 1;
                    break;
                }
            }

            if(!achou){
                printf("elemento nao encontrado.\n");
            }
            else{

                //se o elemento encontrado eh o ultimo, remove do final
                if(procurar->proximo == NULL){
                    anterior->proximo = NULL;
                    (*c)->fim = anterior;
                }
                else{
                    //senao, o anterior aponta pro proximo do elemento encontrado que se quer excluir
                    anterior->proximo = procurar->proximo;
                }

                free(procurar);

            }
        }

    }

}




int main(){
    struct controle_classificacao *controle_classificacao_inicio_fim;

    controle_classificacao_inicio_fim = (struct controle_classificacao*)malloc(sizeof(struct controle_classificacao));

    printf("controle_classificacao_inicio_fim: %x\n",controle_classificacao_inicio_fim);
    printf("&controle_classificacao_inicio_fim: %x\n\n",&controle_classificacao_inicio_fim);

    int opcao;

    while(opcao != 8){
        printf("\n1-inserir inicio\n2-imserir no fim\n3-inserir no meio\n4-remover inicio\n5-remover final\n6-remover meio\n7-imprimir\n8-sair\n");
        scanf("%d",&opcao);

        if(opcao == 1){
            inserir_inicio(&controle_classificacao_inicio_fim);
            //inserir_inicio2(controle_classificacao_inicio_fim);//outra forma de passar
        }
        else if(opcao == 2){
            inserir_final(&controle_classificacao_inicio_fim);
        }
        else if(opcao == 3){
            inserir_meio(&controle_classificacao_inicio_fim);
        }
        else if(opcao == 4){
            remover_inicio(&controle_classificacao_inicio_fim);
        }
        else if(opcao == 5){
            remover_final(&controle_classificacao_inicio_fim);
        }
        else if(opcao == 6){
            remover_meio(&controle_classificacao_inicio_fim);
        }
        else if(opcao == 7){
            imprimir(controle_classificacao_inicio_fim);
        }
    }

    return 0;
}


