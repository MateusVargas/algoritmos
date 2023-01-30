//mateus

// mostrar melhores estacoes da linha destino, na 10

/*
Em cada estação, deve-se saber com qual(is)
outra(s) estação(ões) ela faz ligação direta;

De cada estação deve-se saber quais linhas ela
dá acesso;

Ao longo dos anos, novas estações podem ser criadas
e, consequentemente, rotas que a ligam com outras
estações devem ser definidas;

Estações podem fechar permanentemente por
questões estratégicas ou temporariamente para
manutenção. Quando isto acontece, a estação que
levaria o trem até ela deve seguir direto para
a estação seguinte;

Deve-se saber o tempo de viagem em minutos entre
todas as estações (você deve definir);

O sistema deve permitir a alteração dos dados de
qualquer estação, inclusive o tempo entre vizinhas;

O programa deve permitir ao usuário selecionar
duas estações para visualizar as rotas possíveis
entre elas, juntamente com o tempo de viagem de
cada rota;

O programa deve permitir listar todas as estações
vizinhas a uma informada pelo usuário, juntamente
com o tempo para cada uma delas. Caso a estação
informada não exista, o programa deve permitir
sua inserção no mapa da linha, informando seus
dados (caminhos para outras linhas) e estações
vizinhas (com tempo de viagem até elas). Caso ela
esteja desativada, mostrar uma mensagem adequada;

O usuário deve ter a possibilidade de inserir a
estação em que se encontra e a linha do metrô em
que quer chegar. Ao fazer isto, o programa deve
mostrar qual(is) das estações dão acesso a linha
desejada;

O sistema deve possibilitar a geração de um
relatório com todas as estações e suas vizinhas.
O relatório também deve mostrar as linhas às
quais cada estação dá acesso.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TOTAL_ESTACOES 21

struct Conexoes;
struct EstacoesOrdenar;

//struct que guarda cada estacao
typedef struct estacao{
    int id;
    char nome[30];
    //char linhas[50];
    int situacao;

    struct Conexoes{
        int tempo;
        char linha[30];
        struct estacao *conexao;
        struct Conexoes *prox;
    } *conexoes;

    struct estacao *prox;
} Estacao;

/*struct que guarda os dados das
estacoes pra inicializar o algoritmo*/
typedef struct modelo{
    int id;
    char nome[30];
    //char linhas[50];
    int situacao;

    struct Conexao_Init{
        int tempo;
        char linha[30];
        int id_conexao;
    } conexoes[21];
} Modelo;

Modelo modelo_inicio[TOTAL_ESTACOES];


/*
guarda o nome das estacoes visitadas na
recursao que formam um percurso entre
origem e destino
*/
typedef struct estacoes_visitadas{
    char nome[30];
    struct estacoes_visitadas *prox;
} EstacoesVisitadas;


/*
guarda todos os percursoso possiveis
entre origem e destino, com numero da rota,
tempo e as estacoes. as estacoes estao
numa lista encadeada interna
*/
typedef struct estacoes_visitadas_ordenado{
    int num_rota;
    int tempo;

    struct EstacoesOrdenar{
        char nome[30];
        struct ests *prox;
    } *estacoes;

    struct estacoes_visitadas_ordenado *prox;
} EstacoesVisitadasOrdenado;


void limpar_console();
int gerar_tempo_aleatorio();


//dados das 21 estacoes iniciais, com um vetor com o id das conexoes
void inicializar_dados(){
    modelo_inicio[0].id = 1;
    strcpy(modelo_inicio[0].nome,"Edgware Road");
    //strcpy(modelo_inicio[0].linhas,"amarela");
    modelo_inicio[0].situacao = 1;
    modelo_inicio[0].conexoes[0].id_conexao = 2;
    modelo_inicio[0].conexoes[0].tempo = 15;
    strcpy(modelo_inicio[0].conexoes[0].linha,"amarela");
    modelo_inicio[0].conexoes[1].id_conexao = 16;
    modelo_inicio[0].conexoes[1].tempo = 12;
    strcpy(modelo_inicio[0].conexoes[1].linha,"amarela");
    modelo_inicio[0].conexoes[2].id_conexao = -1;

    modelo_inicio[1].id = 2;
    strcpy(modelo_inicio[1].nome,"Paddington");
    //strcpy(modelo_inicio[1].linhas,"amarela");
    modelo_inicio[1].situacao = 1;
    modelo_inicio[1].conexoes[0].id_conexao = 1;
    modelo_inicio[1].conexoes[0].tempo = 15;
    strcpy(modelo_inicio[1].conexoes[0].linha,"amarela");
    modelo_inicio[1].conexoes[1].id_conexao = 3;
    modelo_inicio[1].conexoes[1].tempo = 4;
    strcpy(modelo_inicio[1].conexoes[1].linha,"amarela");
    modelo_inicio[1].conexoes[2].id_conexao = -1;

    modelo_inicio[2].id = 3;
    strcpy(modelo_inicio[2].nome,"Notting Hill Gate");
    //strcpy(modelo_inicio[2].linhas,"amarela");
    modelo_inicio[2].situacao = 1;
    modelo_inicio[2].conexoes[0].id_conexao = 2;
    modelo_inicio[2].conexoes[0].tempo = 4;
    strcpy(modelo_inicio[2].conexoes[0].linha,"amarela");
    modelo_inicio[2].conexoes[1].id_conexao = 4;
    modelo_inicio[2].conexoes[1].tempo = 11;
    strcpy(modelo_inicio[2].conexoes[1].linha,"amarela");
    modelo_inicio[2].conexoes[2].id_conexao = -1;

    modelo_inicio[3].id = 4;
    strcpy(modelo_inicio[3].nome,"South Kensington");
    //strcpy(modelo_inicio[3].linhas,"amarela, azul");
    modelo_inicio[3].situacao = 1;
    modelo_inicio[3].conexoes[0].id_conexao = 3;
    modelo_inicio[3].conexoes[0].tempo = 11;
    strcpy(modelo_inicio[3].conexoes[0].linha,"amarela");
    modelo_inicio[3].conexoes[1].id_conexao = 5;
    modelo_inicio[3].conexoes[1].tempo = 9;
    strcpy(modelo_inicio[3].conexoes[1].linha,"amarela");
    modelo_inicio[3].conexoes[2].id_conexao = -1;

    modelo_inicio[4].id = 5;
    strcpy(modelo_inicio[4].nome,"Victoria");
    //strcpy(modelo_inicio[4].linhas,"amarela, azul");
    modelo_inicio[4].situacao = 1;
    modelo_inicio[4].conexoes[0].id_conexao = 4;
    modelo_inicio[4].conexoes[0].tempo = 9;
    strcpy(modelo_inicio[4].conexoes[0].linha,"amarela");
    modelo_inicio[4].conexoes[1].id_conexao = 18;
    modelo_inicio[4].conexoes[1].tempo = 23;
    strcpy(modelo_inicio[4].conexoes[1].linha,"azul");
    modelo_inicio[4].conexoes[2].id_conexao = 6;
    modelo_inicio[4].conexoes[2].tempo = 3;
    strcpy(modelo_inicio[4].conexoes[2].linha,"amarela");
    modelo_inicio[4].conexoes[3].id_conexao = -1;

    modelo_inicio[5].id = 6;
    strcpy(modelo_inicio[5].nome,"Westminster");
    //strcpy(modelo_inicio[5].linhas,"amarela, cinza");
    modelo_inicio[5].situacao = 1;
    modelo_inicio[5].conexoes[0].id_conexao = 5;
    modelo_inicio[5].conexoes[0].tempo = 3;
    strcpy(modelo_inicio[5].conexoes[0].linha,"amarela");
    modelo_inicio[5].conexoes[1].id_conexao = 8;
    modelo_inicio[5].conexoes[1].tempo = 7;
    strcpy(modelo_inicio[5].conexoes[1].linha,"amarela");
    modelo_inicio[5].conexoes[2].id_conexao = 7;
    modelo_inicio[5].conexoes[2].tempo = 17;
    strcpy(modelo_inicio[5].conexoes[2].linha,"cinza");
    modelo_inicio[5].conexoes[3].id_conexao = 18;
    modelo_inicio[5].conexoes[3].tempo = 40;
    strcpy(modelo_inicio[5].conexoes[3].linha,"cinza");
    modelo_inicio[5].conexoes[4].id_conexao = -1;

    modelo_inicio[6].id = 7;
    strcpy(modelo_inicio[6].nome,"Waterloo");
    //strcpy(modelo_inicio[6].linhas,"cinza, marrom");
    modelo_inicio[6].situacao = 1;
    modelo_inicio[6].conexoes[0].id_conexao = 6;
    modelo_inicio[6].conexoes[0].tempo = 17;
    strcpy(modelo_inicio[6].conexoes[0].linha,"cinza");
    modelo_inicio[6].conexoes[1].id_conexao = 8;
    modelo_inicio[6].conexoes[1].tempo = 16;
    strcpy(modelo_inicio[6].conexoes[1].linha,"marrom");
    modelo_inicio[6].conexoes[2].id_conexao = -1;

    modelo_inicio[7].id = 8;
    strcpy(modelo_inicio[7].nome,"Embankment");
    //strcpy(modelo_inicio[7].linhas,"amarela, marrom");
    modelo_inicio[7].situacao = 1;
    modelo_inicio[7].conexoes[0].id_conexao = 6;
    modelo_inicio[7].conexoes[0].tempo = 7;
    strcpy(modelo_inicio[7].conexoes[0].linha,"amarela");
    modelo_inicio[7].conexoes[1].id_conexao = 7;
    modelo_inicio[7].conexoes[1].tempo = 16;
    strcpy(modelo_inicio[7].conexoes[1].linha,"marrom");
    modelo_inicio[7].conexoes[2].id_conexao = 9;
    modelo_inicio[7].conexoes[2].tempo = 36;
    strcpy(modelo_inicio[7].conexoes[2].linha,"amarela");
    modelo_inicio[7].conexoes[3].id_conexao = 21;
    modelo_inicio[7].conexoes[3].tempo = 4;
    strcpy(modelo_inicio[7].conexoes[3].linha,"marrom");
    modelo_inicio[7].conexoes[4].id_conexao = -1;

    modelo_inicio[8].id = 9;
    strcpy(modelo_inicio[8].nome,"Blackfriars");
    //strcpy(modelo_inicio[8].linhas,"amarela");
    modelo_inicio[8].situacao = 1;
    modelo_inicio[8].conexoes[0].id_conexao = 8;
    modelo_inicio[8].conexoes[0].tempo = 36;
    strcpy(modelo_inicio[8].conexoes[0].linha,"amarela");
    modelo_inicio[8].conexoes[1].id_conexao = 10;
    modelo_inicio[8].conexoes[1].tempo = 6;
    strcpy(modelo_inicio[8].conexoes[1].linha,"amarela");
    modelo_inicio[8].conexoes[2].id_conexao = -1;

    modelo_inicio[9].id = 10;
    strcpy(modelo_inicio[9].nome,"Monument");
    //strcpy(modelo_inicio[9].linhas,"amarela");
    modelo_inicio[9].situacao = 1;
    modelo_inicio[9].conexoes[0].id_conexao = 9;
    modelo_inicio[9].conexoes[0].tempo = 6;
    strcpy(modelo_inicio[9].conexoes[0].linha,"amarela");
    modelo_inicio[9].conexoes[1].id_conexao = 11;
    modelo_inicio[9].conexoes[1].tempo = 2;
    strcpy(modelo_inicio[9].conexoes[1].linha,"amarela");
    modelo_inicio[9].conexoes[2].id_conexao = -1;

    modelo_inicio[10].id = 11;
    strcpy(modelo_inicio[10].nome,"Tower Hill");
    //strcpy(modelo_inicio[10].linhas,"amarela");
    modelo_inicio[10].situacao = 1;
    modelo_inicio[10].conexoes[0].id_conexao = 10;
    modelo_inicio[10].conexoes[0].tempo = 2;
    strcpy(modelo_inicio[10].conexoes[0].linha,"amarela");
    modelo_inicio[10].conexoes[1].id_conexao = 12;
    modelo_inicio[10].conexoes[1].tempo = 22;
    strcpy(modelo_inicio[10].conexoes[1].linha,"amarela");
    modelo_inicio[10].conexoes[2].id_conexao = -1;

    modelo_inicio[11].id = 12;
    strcpy(modelo_inicio[11].nome,"Liverpool Street");
    //strcpy(modelo_inicio[11].linhas,"amarela");
    modelo_inicio[11].situacao = 1;
    modelo_inicio[11].conexoes[0].id_conexao = 11;
    modelo_inicio[11].conexoes[0].tempo = 22;
    strcpy(modelo_inicio[11].conexoes[0].linha,"amarela");
    modelo_inicio[11].conexoes[1].id_conexao = 13;
    modelo_inicio[11].conexoes[1].tempo = 7;
    strcpy(modelo_inicio[11].conexoes[1].linha,"amarela");
    modelo_inicio[11].conexoes[2].id_conexao = -1;

    modelo_inicio[12].id = 13;
    strcpy(modelo_inicio[12].nome,"Farrington");
    //strcpy(modelo_inicio[12].linhas,"amarela");
    modelo_inicio[12].situacao = 1;
    modelo_inicio[12].conexoes[0].id_conexao = 12;
    modelo_inicio[12].conexoes[0].tempo = 7;
    strcpy(modelo_inicio[12].conexoes[0].linha,"amarela");
    modelo_inicio[12].conexoes[1].id_conexao = 14;
    modelo_inicio[12].conexoes[1].tempo = 5;
    strcpy(modelo_inicio[12].conexoes[1].linha,"amarela");
    modelo_inicio[12].conexoes[2].id_conexao = -1;

    modelo_inicio[13].id = 14;
    strcpy(modelo_inicio[13].nome,"Kings Cross");
    //strcpy(modelo_inicio[13].linhas,"amarela");
    modelo_inicio[13].situacao = 1;
    modelo_inicio[13].conexoes[0].id_conexao = 13;
    modelo_inicio[13].conexoes[0].tempo = 5;
    strcpy(modelo_inicio[13].conexoes[0].linha,"amarela");
    modelo_inicio[13].conexoes[1].id_conexao = 15;
    modelo_inicio[13].conexoes[1].tempo = 8;
    strcpy(modelo_inicio[13].conexoes[1].linha,"amarela");
    modelo_inicio[13].conexoes[2].id_conexao = -1;

    modelo_inicio[14].id = 15;
    strcpy(modelo_inicio[14].nome,"Warren");
    //strcpy(modelo_inicio[14].linhas,"amarela, azul");
    modelo_inicio[14].situacao = 1;
    modelo_inicio[14].conexoes[0].id_conexao = 14;
    modelo_inicio[14].conexoes[0].tempo = 8;
    strcpy(modelo_inicio[14].conexoes[0].linha,"amarela");
    modelo_inicio[14].conexoes[1].id_conexao = 16;
    modelo_inicio[14].conexoes[1].tempo = 18;
    strcpy(modelo_inicio[14].conexoes[1].linha,"amarela");
    modelo_inicio[14].conexoes[2].id_conexao = 19;
    modelo_inicio[14].conexoes[2].tempo = 24;
    strcpy(modelo_inicio[14].conexoes[2].linha,"azul");
    modelo_inicio[14].conexoes[3].id_conexao = -1;

    modelo_inicio[15].id = 16;
    strcpy(modelo_inicio[15].nome,"Baker Street");
    //strcpy(modelo_inicio[15].linhas,"amarela, marrom, cinza");
    modelo_inicio[15].situacao = 1;
    modelo_inicio[15].conexoes[0].id_conexao = 15;
    modelo_inicio[15].conexoes[0].tempo = 18;
    strcpy(modelo_inicio[15].conexoes[0].linha,"amarela");
    modelo_inicio[15].conexoes[1].id_conexao = 1;
    modelo_inicio[15].conexoes[1].tempo = 12;
    strcpy(modelo_inicio[15].conexoes[1].linha,"amarela");
    modelo_inicio[15].conexoes[2].id_conexao = 17;
    modelo_inicio[15].conexoes[2].tempo = 20;
    strcpy(modelo_inicio[15].conexoes[2].linha,"cinza");
    modelo_inicio[15].conexoes[3].id_conexao = 19;
    modelo_inicio[15].conexoes[3].tempo = 21;
    strcpy(modelo_inicio[15].conexoes[3].linha,"marrom");
    modelo_inicio[15].conexoes[4].id_conexao = -1;

    modelo_inicio[16].id = 17;
    strcpy(modelo_inicio[16].nome,"Bond Street");
    //strcpy(modelo_inicio[16].linhas,"cinza");
    modelo_inicio[16].situacao = 1;
    modelo_inicio[16].conexoes[0].id_conexao = 16;
    modelo_inicio[16].conexoes[0].tempo = 20;
    strcpy(modelo_inicio[16].conexoes[0].linha,"cinza");
    modelo_inicio[16].conexoes[1].id_conexao = 18;
    modelo_inicio[16].conexoes[1].tempo = 6;
    strcpy(modelo_inicio[16].conexoes[1].linha,"cinza");
    modelo_inicio[16].conexoes[2].id_conexao = -1;

    modelo_inicio[17].id = 18;
    strcpy(modelo_inicio[17].nome,"Green Park");
    //strcpy(modelo_inicio[17].linhas,"cinza, azul");
    modelo_inicio[17].situacao = 1;
    modelo_inicio[17].conexoes[0].id_conexao = 17;
    modelo_inicio[17].conexoes[0].tempo = 6;
    strcpy(modelo_inicio[17].conexoes[0].linha,"cinza");
    modelo_inicio[17].conexoes[1].id_conexao = 5;
    modelo_inicio[17].conexoes[1].tempo = 23;
    strcpy(modelo_inicio[17].conexoes[1].linha,"azul");
    modelo_inicio[17].conexoes[2].id_conexao = 19;
    modelo_inicio[17].conexoes[2].tempo = 16;
    strcpy(modelo_inicio[17].conexoes[2].linha,"azul");
    modelo_inicio[17].conexoes[3].id_conexao = 6;
    modelo_inicio[17].conexoes[3].tempo = 40;
    strcpy(modelo_inicio[17].conexoes[3].linha,"cinza");
    modelo_inicio[17].conexoes[4].id_conexao = -1;

    modelo_inicio[18].id = 19;
    strcpy(modelo_inicio[18].nome,"Oxford Circus");
    //strcpy(modelo_inicio[18].linhas,"marrom, azul");
    modelo_inicio[18].situacao = 1;
    modelo_inicio[18].conexoes[0].id_conexao = 15;
    modelo_inicio[18].conexoes[0].tempo = 24;
    strcpy(modelo_inicio[18].conexoes[0].linha,"azul");
    modelo_inicio[18].conexoes[1].id_conexao = 16;
    modelo_inicio[18].conexoes[1].tempo = 21;
    strcpy(modelo_inicio[18].conexoes[1].linha,"marrom");
    modelo_inicio[18].conexoes[2].id_conexao = 20;
    modelo_inicio[18].conexoes[2].tempo = 4;
    strcpy(modelo_inicio[18].conexoes[2].linha,"marrom");
    modelo_inicio[18].conexoes[3].id_conexao = 18;
    modelo_inicio[18].conexoes[3].tempo = 16;
    strcpy(modelo_inicio[18].conexoes[3].linha,"azul");
    modelo_inicio[18].conexoes[4].id_conexao = -1;

    modelo_inicio[19].id = 20;
    strcpy(modelo_inicio[19].nome,"Piccadilly Circus");
    //strcpy(modelo_inicio[19].linhas,"marrom");
    modelo_inicio[19].situacao = 1;
    modelo_inicio[19].conexoes[0].id_conexao = 19;
    modelo_inicio[19].conexoes[0].tempo = 4;
    strcpy(modelo_inicio[19].conexoes[0].linha,"marrom");
    modelo_inicio[19].conexoes[1].id_conexao = 21;
    modelo_inicio[19].conexoes[1].tempo = 3;
    strcpy(modelo_inicio[19].conexoes[1].linha,"marrom");
    modelo_inicio[19].conexoes[2].id_conexao = -1;

    modelo_inicio[20].id = 21;
    strcpy(modelo_inicio[20].nome,"Charing Cross");
    //strcpy(modelo_inicio[20].linhas,"marrom");
    modelo_inicio[20].situacao = 1;
    modelo_inicio[20].conexoes[0].id_conexao = 8;
    modelo_inicio[20].conexoes[0].tempo = 4;
    strcpy(modelo_inicio[20].conexoes[0].linha,"marrom");
    modelo_inicio[20].conexoes[1].id_conexao = 20;
    modelo_inicio[20].conexoes[1].tempo = 3;
    strcpy(modelo_inicio[20].conexoes[1].linha,"marrom");
    modelo_inicio[20].conexoes[2].id_conexao = -1;
}



/*
adiciona numa pilha o nome de cada estacao
visitada na recursao que gera as rotas pra
impedir de a mesma estacao
ser adicionada 2 vezes e também pra salvar
as estacoes que compoem o caminho do percurso
*/
void adicionar_pilha_estacoes_visitadas(EstacoesVisitadas **estacoes, char nome[30]){
    EstacoesVisitadas *novo = (EstacoesVisitadas*)malloc(sizeof(EstacoesVisitadas));
    strcpy(novo->nome, nome);
    novo->prox = NULL;

    if(*estacoes == NULL){
        *estacoes = novo;
    }
    else{
        EstacoesVisitadas *p = *estacoes;
        while(p->prox!=NULL){
            p=p->prox;
        }
        p->prox = novo;
    }

    //printf("add pilha: %s\n",novo->nome);
}



/*
remove da pilha de estacoes visitadas.
ocorre quando foi verificado todas as
conexoes de uma estacao e ja se gerou
todos os percursos possiveis com elas
envolvendo aquela estacao e suas conexoes
na funcao recursiva, dai a funcao percurso
encerra o while e volta pra execução
anterior e essa estacao que estava na
pilha eh tirada
*/
void remove_pilha_estacoes_visitadas(EstacoesVisitadas **estacoes){
    if(*estacoes == NULL || (*estacoes)->prox == NULL){
        *estacoes = NULL;
    }
    else{
        EstacoesVisitadas *p = *estacoes, *ant;
        while(p->prox!=NULL){
            ant=p;
            p=p->prox;
        }
        ant->prox = NULL;
        //printf("rem %s\n",p->nome);
        free(p);
    }
}


/*
quando a recursao da funcao percurso chegar no
destino, entao eh mostrada as estacoes que
formam o caminho ate o destino pois todas as
estacoes estao salvas na pilha.
e tambem salva esse percurso com os nomes
das estacoes numa outra lista encadeada,
essa outra lista tem o tempo do percurso,
numero da rota e uma lista encadeada interna
com os nomes das estacoes que formam o percurso.
essa lista existe apenas para fazer uma
ordenação por tempo entre os varios percursos
ex: se tiver 50 percursos entao serao 50 nós e
dentro de cada um o identificador do percurso
(numero) e as estacoes que o compoem
*/
void ver_pilha_estacoes_visitadas(EstacoesVisitadas *estacoes, int *caminho, EstacoesVisitadasOrdenado **ests_ordenado, int tempo){
    EstacoesVisitadas *p = estacoes;

    //guarda os percursos em outra lista pra ordenar depois
    EstacoesVisitadasOrdenado *novo;
    struct EstacoesOrdenar *aux=NULL;

    novo = (EstacoesVisitadasOrdenado*)malloc(sizeof(EstacoesVisitadasOrdenado));
    novo->num_rota = ++(*caminho);
    novo->tempo = tempo;
    novo->prox = NULL;

    printf("Rota %d:\n\n",*caminho);

    while(p!=NULL){

        /*
        alem de imprimir o percurso
        cria uma lista encadeada com os nomes
        das estacoes que formam o percurso,
        ou seja, que estão na pilha, e coloca
        ela dentro do nó relativo ao percurso
        */
        struct EstacoesOrdenar *est = (struct EstacoesOrdenar*)malloc(sizeof(struct EstacoesOrdenar));
        strcpy(est->nome,p->nome);
        est->prox = NULL;

        if(aux==NULL)
            novo->estacoes = est;
        else
            aux->prox = est;

        aux = est;

        printf("\t- %s\n",p->nome);
        p=p->prox;

    }


    //cada percurso eh salvo na lista
    if(*ests_ordenado==NULL){
        *ests_ordenado = novo;
    }
    else{
        EstacoesVisitadasOrdenado *ests_visits = *ests_ordenado;

        while(ests_visits->prox!=NULL)
            ests_visits=ests_visits->prox;

        ests_visits->prox = novo;
    }

    printf("\n");
}


int procurar_estacao_visitada_pilha(EstacoesVisitadas **estacoes, char nome[30]){
    int existe = 0;

    for(EstacoesVisitadas *p=*estacoes; p!=NULL && existe == 0; p=p->prox){
        if(strcmp(p->nome, nome)==0)
            existe = 1;
    }

    return existe;
}


/*
percorre as estacoes iniciais e guarda elas
numa lista encadeada
*/
void criar_estacoes(Estacao **estacao){
    Estacao *aux = NULL;

    for(int i=0;i<TOTAL_ESTACOES;i++){

        Estacao *novo = (Estacao*)malloc(sizeof(Estacao));
        novo->id = modelo_inicio[i].id;
        strcpy(novo->nome, modelo_inicio[i].nome);
        //strcpy(novo->linhas, modelo_inicio[i].linhas);
        novo->situacao = modelo_inicio[i].situacao;
        novo->prox=NULL;

        if(i==0)
            *estacao = novo;
        else
            aux->prox = novo;

        aux = novo;
    }
}


/*
no modelo inicial dentro de cada estacao tem um
vetor de conexoes que sao as estacoes vizinhas,
percorre esse vetor e coloca em uma lista encadeada
interna dentro do no de cada estacao.
pra adicionar a estacao vizinha dentro das conexoes
da estacao corretamente é comparado o id da estacao
*/
void adicionar_conexoes(Estacao *estacoes){
    struct Conexoes *nova_conexao, *aux;
    Estacao *iterator = estacoes, *iterator_aux;

    while(iterator!=NULL){

        for(int i=0;modelo_inicio[iterator->id - 1].conexoes[i].id_conexao!= -1; i++){

            iterator_aux = estacoes;

            while(iterator_aux!=NULL && iterator_aux->id != modelo_inicio[iterator->id -1].conexoes[i].id_conexao){

                //printf("%s, %d, i:%d, %d\n",iterator->nome,modelo_inicio[iterator->id -1].conexoes[i].id_conexao,i,iterator_aux->id);
                iterator_aux = iterator_aux->prox;
            }

            //printf("\n\n\n%d, %s\n",iterator->id,iterator->nome);
            //debug: printf("%d, %x\n\n",modelo_inicio[iterator->id -1].conexoes[i].tempo,iterator_aux);

            nova_conexao = (struct Conexoes*)malloc(sizeof(struct Conexoes));
            nova_conexao->tempo = modelo_inicio[iterator->id -1].conexoes[i].tempo;
            strcpy(nova_conexao->linha, modelo_inicio[iterator->id -1].conexoes[i].linha);
            nova_conexao->conexao = iterator_aux;
            nova_conexao->prox = NULL;

            if(i==0)
                iterator->conexoes = nova_conexao;
            else
                aux->prox = nova_conexao;

            aux = nova_conexao;

        }

        iterator = iterator->prox;
    }

}


/*mostra as estacoes suas linhas e conexoes*/
void ver_estacoes(Estacao *p, int mostrar_conexoes){
    if(p!=NULL){
        printf("ESTACAO: %s: \n",p->nome);

        char linhas[50];
        int i=0;

        /*
        debug enderecos
        printf("\tLINHAS:\n\t\t- %s,%x\n",p->linhas,p->conexoes);
        */

        for(struct Conexoes *c=p->conexoes;c!=NULL;c=c->prox){

        	/*
        	concatena na string linhas a linha
        	da conexao caso ela ainda nao
        	esteja na string, strstr verifica
        	se ha uma substring dentro de uma string
        	*/
        	if(!strstr(linhas,c->linha)){
                if(i==0){
                    strcpy(linhas,c->linha);
                    strcat(linhas," ");
                    i++;
                }
                else{
                    strcat(linhas,c->linha);
                    strcat(linhas," ");
                }
        	}

        }

        //se a linha nao tem conexoes nao mostra o vetor que guarda as linhas
        if(p->conexoes != NULL)
            printf("\tLINHAS: %s\n",linhas);

        p->situacao ? printf("\tSITUACAO: ABERTA\n") : printf("\tSITUACAO: FECHADA\n");

        if(mostrar_conexoes){
            printf("\n\tCONEXOES:\n");

            for(struct Conexoes *c = p->conexoes; c!=NULL; c = c->prox){
                /*
                debug enderecos
                printf("\t\t- %s, %x\n",c->conexao->nome,c->conexao);
                */
                printf("\t\t- %s, Linha: %s, Tempo: %d mins\n",c->conexao->nome,c->linha,c->tempo);
            }
        }

        printf("\n-----------------------------------\n\n");

        ver_estacoes(p->prox,mostrar_conexoes);
    }
}



void percurso(Estacao *destino, Estacao *estacao_atual, EstacoesVisitadas **estacoes_visitadas, int *tempo,int *caminho, EstacoesVisitadasOrdenado **ests_ordenado);



Estacao* busca_estacao(Estacao *estacao, char nome[30]){
    if(estacao==NULL) return NULL;
    if(strcmp(estacao->nome,nome)==0) return estacao;
    return busca_estacao(estacao->prox,nome);
}


/*
percorre todas estacoes e compara o campo linha
da conexao com o parametro recebido, se for
igual entao o nome eh exibido
*/
void busca_estacoes_por_linha(Estacao *p, char linha[30]){
    if(p==NULL) return;

    struct Conexoes *con = p->conexoes;

    while(con!=NULL){
    	if(strcmp(con->linha,linha)==0){
    		printf("\t-%s\n",p->nome);
    		break;
    	}
    	con=con->prox;
    }

    busca_estacoes_por_linha(p->prox,linha);
}



/*adiciona nova estacao entre 2 existentes ou na ponta de uma linha*/
void adicionar_nova_estacao(Estacao *estacoes, int *id){
	char nome[30];
	Estacao *est1=NULL, *est2=NULL;
	int op;
	int i=0;
	struct Conexoes *con=NULL;

    printf("1-adicionar entre 2 estacoes\n");
    printf("2-adicionar na ponta de uma linha\n");
    scanf("%d",&op);

    //adicionar entre 2 estacoes
    if(op==1){

        printf("adicionar depois de qual estacao: ");
        getchar();
        gets(nome);

        est1 = busca_estacao(estacoes,nome);

        while(est1==NULL){
            printf("estacao nao encontrada. adicionar depois de qual estacao: ");
            gets(nome);
            est1 = busca_estacao(estacoes,nome);
        }

    	/*
    	salva as conexoes dessa estacao
    	pra escolher entre qual conexao
    	que vai entrar a nova estacao
    	*/
    	con=est1->conexoes;

    	printf("adicionar estacao entre %s e:\n",est1->nome);

    	/*
    	lista vizinhas e vincula variavel i
    	com cada estacao vizinha
    	*/
    	while(con!=NULL){
    		printf("%d-%s\n",++i,con->conexao->nome);
    		con=con->prox;
    	}

    	printf("%d-Cancelar\n",i+1);
    	scanf("%d",&op);

    	while(op<1 || op>i+1){
    		printf("opcao invalida. digite uma opcao entre 1 e %d: ",i+1);
    		scanf("%d",&op);
    	}

    	//se ele nao cancelou
    	if(op!=i+1){
            char linha_conexao[20];
            con = est1->conexoes;
            i=1;

            /*
            procura pela estacao escolhida, se foi
            digitado 2 entao percorre o loop 2 vezes
            para achar a estacao que bate com o numero
            da opcao
            */
            while(i<op){
                con=con->prox;
                i++;
            }

            est2=con->conexao;

            //salva a linha em que a nova estacao vai entrar
            strcpy(linha_conexao, con->linha);

            //id auto increment
            (*id)++;

            Estacao *existe=NULL;
            Estacao *novo=(Estacao*)malloc(sizeof(Estacao));
            novo->id=*id;

            printf("nome estacao: ");
            getchar();
            gets(novo->nome);

            //verifica se estacao ja existe
            existe = busca_estacao(estacoes,novo->nome);

            while(existe!=NULL){
                printf("estacao ja cadastrada. nome estacao: ");
                gets(novo->nome);
                existe = busca_estacao(estacoes,novo->nome);
            }

            //strcpy(novo->linhas,est1->linhas);
            novo->situacao=1;
            novo->prox=NULL;

            /*adiciona na lista de conexoes da
            nova estacao as 2 estacoes que antes
            eram vizinhas mas que agora deixam de
            ser pois a nova entra no meio delas,
            as 2 estacoes estao salvas nas variaveis
            est1 e est2*/
            struct Conexoes *aux;

            con=(struct Conexoes*)malloc(sizeof(struct Conexoes));

            //numero aleatorio pro tempo
            con->tempo=gerar_tempo_aleatorio();
            strcpy(con->linha, linha_conexao);
            con->conexao=est1;
            con->prox=NULL;
            aux=con;
            novo->conexoes=con;

            con=(struct Conexoes*)malloc(sizeof(struct Conexoes));

            con->tempo=gerar_tempo_aleatorio();
            strcpy(con->linha, linha_conexao);
            con->conexao=est2;
            con->prox=NULL;
            aux->prox=con;

            /*
            percorre as 2 estacoes que eram vizinhas
            e substitui a conexao de uma com a outra
            pela nova estacao, pois ela entra entre as 2
            */
            con=est1->conexoes;
            while(strcmp(con->conexao->nome,est2->nome)!=0)
                con=con->prox;

            con->conexao=novo;

            con=est2->conexoes;
            while(strcmp(con->conexao->nome,est1->nome)!=0)
                con=con->prox;

            con->conexao=novo;

            /*adiciona nova estacao no final da lista
            encadeada de estacoes*/
            while(estacoes->prox!=NULL)
                estacoes=estacoes->prox;

            estacoes->prox=novo;
        }

    }

    else if(op==2){

        //inserir na ponta de uma linha
        int eh_uma_ponta = 0;
        int cont_conexoes_linha = 0;

        char mat[4][20];

		/*matriz que guarda as linhas*/
		strcpy(mat[0],"amarela");
		strcpy(mat[1],"azul");
		strcpy(mat[2],"cinza");
		strcpy(mat[3],"marrom");

        printf("estacao da ponta: ");
        getchar();
        gets(nome);

        est1 = busca_estacao(estacoes,nome);

        //valida estacao
        while(est1==NULL){
            printf("estacao nao encontrada, informe outra: ");
            gets(nome);
            est1 = busca_estacao(estacoes,nome);
        }


        /*
        percorre a matriz com as linhas e
        verifica se a estacao possui 1
        conexao apenas em alguma linha,
        se sim entao ela ta na ponta de
        uma linha.
        no momento que for achado so 1
        conexao em uma linha o sai do while
        */
        while(i<4 && cont_conexoes_linha!=1){

            cont_conexoes_linha = 0;
            con = est1->conexoes;

            while(con!=NULL){

                if(strcmp(con->linha, mat[i])==0){
                    cont_conexoes_linha++;
                }

                con = con->prox;
            }

            i++;

        }

        /*
        se tiver so 1 conexao em uma linha
        entao entra no if, depois o usuario
        insere a linha que quer adicionar
        a nova estacao, e verifica se a
        estacao eh ponta dessa linha ou nao
        */
        if(cont_conexoes_linha==1){

            cont_conexoes_linha = 0;

            char linha[20];

            printf("informe a linha em que a estacao eh ponta: ");
            gets(linha);

            con = est1->conexoes;

            /*
            verifica se a estacao eh ponta dessa linha ou nao
            percorrendo suas conexoes
            */
            while(con!=NULL){

                if(strcmp(con->linha, linha)==0)
                    cont_conexoes_linha++;

                con = con->prox;
            }


            /*
            se o contador for 1, entao eh ponta da linha,
            depois cria a nova estacao validando nome,
            e atribui a estacao que eh ponta como uma conexao
            dessa nova estacao
            */
            if(cont_conexoes_linha==1){
                int tempo = gerar_tempo_aleatorio();

                (*id)++;

                Estacao *novo = (Estacao*)malloc(sizeof(Estacao));
                novo->id = *id;

                printf("nome estacao: ");
                //getchar();
                gets(novo->nome);

                //verifica se estacao ja existe
                Estacao *existe = busca_estacao(estacoes,novo->nome);

                while(existe!=NULL){
                    printf("estacao ja cadastrada. nome estacao: ");
                    gets(novo->nome);
                    existe = busca_estacao(estacoes,novo->nome);
                }

                novo->situacao=1;
                novo->prox=NULL;

                /*
                cria conexao pra nova estacao, essa conexao
                sera a propria estacao que eh ponta obviamente
                */
                struct Conexoes *nova_conexao = (struct Conexoes*)malloc(sizeof(struct Conexoes));
                nova_conexao->tempo = tempo;
                strcpy(nova_conexao->linha, linha);
                nova_conexao->conexao = est1;
                nova_conexao->prox = NULL;

                novo->conexoes = nova_conexao;

                con = est1->conexoes;

                /*
                percorre as conexoes da estacao ponta,
                e adiciona essa nova estacao como uma
                nova conexao da estacao ponta
                */
                while(con->prox!=NULL)
                    con = con->prox;

                nova_conexao = (struct Conexoes*)malloc(sizeof(struct Conexoes));
                nova_conexao->tempo = tempo;
                strcpy(nova_conexao->linha, linha);
                nova_conexao->conexao = novo;
                nova_conexao->prox = NULL;

                con->prox = nova_conexao;


                /*adiciona nova estacao no final da lista
                encadeada de estacoes*/
                while(estacoes->prox!=NULL)
                    estacoes=estacoes->prox;

                estacoes->prox=novo;

            }
            else
                printf("esta estacao nao eh ponta desta linha.\n");

        }
        else
            printf("esta estacao nao eh uma ponta.\n");
    }

}


/*
edita nome, tempo de uma conexao,
ativa/desativa ou apaga uma estacao
*/
void editar_estacao(Estacao **estacoes){
	char nome[30];
	Estacao *est=NULL;
	int op;
	struct Conexoes *con;

	printf("estacao: ");
	getchar();
	gets(nome);
	est=busca_estacao(*estacoes,nome);

	//validar estacao
	while(est==NULL){
		printf("estacao nao encontrada: ");
		gets(nome);

		est=busca_estacao(*estacoes,nome);
	}

	printf("1-editar nome\n");
	printf("2-editar tempo\n");
	est->situacao ? printf("3-desativar estacao\n") : printf("3-ativar estacao\n");
	printf("4-fechar estacao (apagar)\n");
	printf("qualquer numero - cancelar\n");
	scanf("%d",&op);

	if(op==1){
		printf("novo nome: ");
		getchar();
		gets(nome);
		strcpy(est->nome,nome);
	}

	else if(op==2){
		con=est->conexoes;
		int i=0;

		printf("editar tempo de qual estacao vizinha:\n");

		/*lista as estacoes vizinhas, vinculando
		um numero a elas*/
		while(con!=NULL){
			printf("%d-%s, tempo: %d mins\n",++i,con->conexao->nome,con->tempo);
			con=con->prox;
		}
		op=0;
		printf("%d-cancelar\n",i+1);
		scanf("%d",&op);

		/*se nao cancelou e se existe pelo menos 1 conexao na
		estacao entao entra no if pra trocar o tempo*/
		if(op!=i+1 && con!=NULL){
			while(op<1||op>i+1){
				printf("opcao invalida.:");
				scanf("%d",&op);
			}

			i=1;
			con=est->conexoes;

			/*percorre ate que o numero de
			iteracoes seja igual ao digitado
			pra achar a estacao correspondente*/
			while(i<op){
				con=con->prox;
				i++;
			}

			printf("estacao: %s\n",con->conexao->nome);
			printf("tempo atual: %d\n",con->tempo);
			printf("novo tempo: ");
			scanf("%d",&op);
			con->tempo=op;

			/*
			mudar o tempo tambem no outro lado
			da conexao, por exemplo o tempo
			entre Warren e Baker foi trocado
			pra 10 entao percorre as conexoes
			de Warren ate achar Baker e troca
			o tempo pra 10, mas o contrario tbm
			precisa ser feito, percorrendo
			Baker ate achar Warren e trocar
			o tempo tbm
			*/

			con=con->conexao->conexoes;

			while(con !=NULL && strcmp(con->conexao->nome,est->nome)!=0){
				con = con->prox;
			}

			con->tempo = op;
		}
	}

	else if(op==3){
        if(est->situacao){
            est->situacao = 0;
            printf("\nestacao desativada com sucesso.\n");
        }
        else{
            est->situacao = 1;
            printf("\nestacao ativada com sucesso.\n");
        }
	}

	else if(op==4){
		char mat[4][20];

		/*matriz que guarda as linhas*/
		strcpy(mat[0],"amarela");
		strcpy(mat[1],"azul");
		strcpy(mat[2],"cinza");
		strcpy(mat[3],"marrom");

		/*
		apagar uma estacao:
		- percorrer cada conexao e tirar da lista
		de conexoes de cada uma a estacao que vai
		ser apagada.
		- percorrer a estacao que sera apagada e
		verificar se ela se conecta com 2 estacoes
		pela mesma linha, se sim ligar elas
		diretamente se ainda nao tiverem conectadas.
		- remover da lista que guarda as estacoes.
		*/

		con=est->conexoes;

		/*
		percorre cada conexao da estacao a ser
		apagada e percorre as conexoes desta
		conexao, obviamente entre as suas
		conexoes vai estar a estacao que se quer
		apagar, entao quando achar ela faz o
		anterior apontar pro proximo dela
		*/
		while(con!=NULL){
			Estacao *vizinha=con->conexao;
			struct Conexoes *p = vizinha->conexoes;
			struct Conexoes *ant=NULL;

			while(strcmp(p->conexao->nome,est->nome)!=0){
				ant=p;
				p=p->prox;
			}

			if(ant==NULL)
				vizinha->conexoes=p->prox;
			else
				ant->prox=p->prox;

			con=con->prox;
		}

		/*
		percorre a estacao que sera apagada e
		verifica se ela se conecta com 2 estacoes
		pela mesma linha usando um contador, se
		sim ligar elas diretamente se ainda
		nao tiverem conectadas
		*/

		/*
		cada linha da matriz tem o nome de uma linha,
		percorre cada linha da matriz, e dentro
		do loop percorre as conexoes da estacao
		e conta quantas conexoes tem nessa linha
		*/
		int cont;
		struct Conexoes *con_add_est1;
		struct Conexoes *con_add_est2;

		for(int i=0;i<4;i++){
			cont=0;
			con=est->conexoes;

			/*
			percorre as conexoes e conta quantas
			conexoes tem por linha, guarda cada
			conexao em uma variavel diferente pra
			manipular elas depois
			*/

			while(con!=NULL){
				//printf("\n %s, %s",con->linha,mat[i]);
				if(strcmp(con->linha,mat[i])==0){
					if(cont==0)
						con_add_est1=con;
					else if(cont==1)
						con_add_est2=con;

					cont++;
				}

				con=con->prox;
			}

			/*
			se tiver 2 conexoes em uma mesma linha
			entao conecta elas diretamente,
			essas 2 conexoes estao em variaveis
			diferentes, entao percorre as conexoes
			da primeira variavel e adiciona nela uma
			nova conexao que eh a conexao que esta
			na segunda variavel, depois percorre a
			2a variavel e adiciona nela a nova
			conexao que eh a primeira variavel,
			ou seja, liga diretamente as duas pois
			a estacao que as ligava sera apagada
			*/

			if(cont==2){
				//printf("\n%d",cont);
				int tempo = con_add_est1->tempo + con_add_est2->tempo;
				Estacao *est1=con_add_est1->conexao;
				Estacao *est2=con_add_est2->conexao;

				struct Conexoes *p=est1->conexoes;
				struct Conexoes *novo;

				//se caso a estacao nao tiver nenhuma conexao, ou seja, de todas ja terem sido apagadas
                if(p!=NULL){
                    while(p->prox!=NULL)
                        p=p->prox;
                }

				novo=(struct Conexoes*)malloc(sizeof(struct Conexoes));
				novo->tempo = tempo;
				strcpy(novo->linha, con_add_est2->linha);
				novo->conexao = est2;
				novo->prox = NULL;

				//se caso a estacao nao tiver nenhuma conexao, ou seja, de todas ja terem sido apagadas
				(est1->conexoes == NULL) ? (est1->conexoes = novo) : (p->prox = novo);


				p=est2->conexoes;

                if(p!=NULL){
                    while(p->prox!=NULL)
                        p=p->prox;
                }

				novo=(struct Conexoes*)malloc(sizeof(struct Conexoes));
				novo->tempo = tempo;
				strcpy(novo->linha, con_add_est1->linha);
				novo->conexao = est1;
				novo->prox = NULL;

				(est2->conexoes == NULL) ? (est2->conexoes = novo) : (p->prox = novo);
			}

		}

		//remover da lista que guarda as estacoes
		Estacao *ant=NULL, *iterator=*estacoes;
		while(iterator->id != est->id){
			ant=iterator;
			iterator=iterator->prox;
		}

		if(ant==NULL)
			*estacoes=iterator->prox;
		else
			ant->prox=iterator->prox;

		free(est);
	}
}


/*mostra a lista encadeada com todos os
percursos ordenada por tempo*/
void ver_estacoes_visitadas_ordenadas(EstacoesVisitadasOrdenado *ests){
    limpar_console();

    EstacoesVisitadasOrdenado *iterator_i, *iterator_j, aux, *aux_prox;

    iterator_i = ests;

    //bubblesort
    for( iterator_i = ests; iterator_i!=NULL; iterator_i=iterator_i->prox){

        for(iterator_j = iterator_i->prox; iterator_j != NULL; iterator_j = iterator_j->prox){

            if(iterator_i->tempo > iterator_j->tempo){

                //troca as structs que os ponteiros apontam

                aux = *iterator_j;
                *iterator_j = *iterator_i;
                *iterator_i = aux;

                //troca os prox das structs pra que apontem para os nos certos

                aux_prox = iterator_i->prox;
                iterator_i->prox = iterator_j->prox;
                iterator_j->prox = aux_prox;

            }

        }

    }


    while(ests!=NULL){
        printf("\nRota %d\n",ests->num_rota);

        struct EstacoesOrdenar *p = ests->estacoes;

        while(p!=NULL){
            printf("\t- %s\n",p->nome);
            p = p->prox;
        }

        printf("tempo de viagem: %d mins\n",ests->tempo);
        printf("\n\n-----------------------------------\n\n");
        ests = ests->prox;
    }
}


//exportar as rotas num arquivo txt
void exportar_rotas_txt(EstacoesVisitadasOrdenado *ests, char origem[30], char destino[30]){

	char nome[50]={"rotas_"};

	sprintf(nome,"rotas_%s_%s_%d.txt",origem,destino,time(0));

	//gera timestamp ex: Jan 15-01-23 10:23:45
	/*char *time_str = ctime(&now);
	time_str[strlen(time_str)-1]='\0';*/

	FILE *file;
	file=fopen(nome,"w");

	while(ests!=NULL){
		fprintf(file, "Rota %d\n",ests->num_rota);

		struct EstacoesOrdenar *p=ests->estacoes;

		while(p!=NULL){
			fprintf(file, "\t- %s\n",p->nome);
			p=p->prox;
		}

		fprintf(file, "Tempo: %d mins\n\n",ests->tempo);

		fprintf(file, "-----------------------------------\n\n");

		ests=ests->prox;
	}

	fclose(file);
}


//limpa lista encadeada que guarda os percursos
void limpa_estacoes_visitadas_ordenadas(EstacoesVisitadasOrdenado **ests){
	EstacoesVisitadasOrdenado *p=*ests, *aux;

	while(p!=NULL){
		aux = p;
		p=p->prox;
		free(aux);
	}

	*ests=NULL;
}


int main(){
	srand(time(0));
    limpar_console();

    Estacao *estacoes = NULL;
    EstacoesVisitadas *estacoes_visitadas = NULL;
    struct Conexoes *con = NULL;
    int opcao;
    int prox_id=TOTAL_ESTACOES+1;
    int tempo=0;
    int num_rota=0;

    EstacoesVisitadasOrdenado *ests_ordenado = NULL;

    inicializar_dados();
    criar_estacoes(&estacoes);
    adicionar_conexoes(estacoes);

    do{
        printf("\n1-ver linhas de uma estacao\n");
        printf("2-adicionar estacao\n");
        printf("3-editar estacao\n");
        printf("4-ver rotas entre estacoes\n");
        printf("5-listar estacoes vizinhas\n");
        printf("6-ver estacoes que dao acesso a uma linha\n");
        printf("7-relatorio de estacoes\n");
        printf("8-sair\n");
        scanf("%d",&opcao);

        switch(opcao){
            case 1:
                ver_estacoes(estacoes,0);
            break;

            case 2:
            	adicionar_nova_estacao(estacoes,&prox_id);
            break;

            case 3:
            	editar_estacao(&estacoes);
            break;

            case 4:{
                char nome_origem[30];
                char nome_destino[30];
                int valid=0, i=0;
                Estacao *origem=NULL, *destino=NULL;

                printf("origem:");
                getchar();
                gets(nome_origem);

                origem = busca_estacao(estacoes,nome_origem);

                //verifica se estacao existe e nao ta fechada
                while(origem==NULL || !origem->situacao){
                    printf("estacao nao encontrada ou ela esta fechada. origem:");
                    gets(nome_origem);
                    origem = busca_estacao(estacoes,nome_origem);
                }

                printf("destino:");
                gets(nome_destino);

                destino = busca_estacao(estacoes,nome_destino);

                /*valida a 2a estacao pra que exista, esteja aberta e seja diferente da 1a*/
                while(!valid){
                    if(destino==NULL){
                        printf("estacao nao encontrada. destino:");
                        gets(nome_destino);
                        destino = busca_estacao(estacoes,nome_destino);
                    }
                    else if(strcmp(origem->nome,nome_destino)==0){
                        printf("informe uma estacao diferente:");
                        gets(nome_destino);
                    }
                    else if(!destino->situacao){
                        printf("estacao esta fechada. destino:");
                        gets(nome_destino);
                        destino = busca_estacao(estacoes,nome_destino);
                    }
                    else
                        valid=1;
                }

                limpa_estacoes_visitadas_ordenadas(&ests_ordenado);

                /*
                adiciona na pilha que vai guardar
                o percurso, a origem
                */
                adicionar_pilha_estacoes_visitadas(&estacoes_visitadas,origem->nome);
                struct Conexoes *con = origem->conexoes;

                /*
                percorre as conexoes da estacao.
                se a estacao tem 3 vizinhas
                entao gera todas as combinacoes
                possiveis de trajeto partindo
                de cada estacao vizinha usando
                um loop pra passar por cada conexao
                e a funcao recursiva
                */
                while(con!=NULL){
                    tempo = con->tempo;
                    percurso(destino,con->conexao,&estacoes_visitadas,&tempo,&num_rota,&ests_ordenado);
                    remove_pilha_estacoes_visitadas(&estacoes_visitadas);
                    con=con->prox;
                    printf("\n");
                }

                remove_pilha_estacoes_visitadas(&estacoes_visitadas);

                num_rota=0;

                printf("deseja ordenar por tempo os percursos? 1-para ordenar:");
                scanf("%d",&i);
                if(i==1){
                    ver_estacoes_visitadas_ordenadas(ests_ordenado);
                }

                printf("deseja exportar os percursos? 2-para exportar:");
                scanf("%d",&i);
                if(i==2){
                	exportar_rotas_txt(ests_ordenado,origem->nome,destino->nome);
                }

                break;
            }

            case 5:{
                char nome[30];
                Estacao *est = NULL;

                printf("estacao: ");
                getchar();
                gets(nome);

                est = busca_estacao(estacoes,nome);

                if(est==NULL){
                	int op;
                	printf("estacao nao encontrada. digite 1 para cadastrar:");
                	scanf("%d",&op);

                	if(op==1)
                		adicionar_nova_estacao(estacoes,&prox_id);
                }
                else if(!est->situacao){
                	printf("estacao temporariamente fechada\n");
                }
                else{
	                con = est->conexoes;
	                printf("estacoes vizinhas:\n");

	                while(con!=NULL){
	                	printf("\n\tID: %d\n",con->conexao->id);
	                	printf("\tESTACAO: %s\n",con->conexao->nome);
	                	printf("\tTEMPO: %d mins\n",con->tempo);
	                	printf("\tLINHA: %s\n",con->linha);
	                	con->conexao->situacao ? printf("\tSITUACAO: ABERTA\n") : printf("\tSITUACAO: FECHADA\n");

	                    con=con->prox;
	                }
	            }

                break;
            }

            case 6:{
                Estacao *est = NULL;
            	char nome[30];

            	printf("estacao atual: ");
            	getchar();
            	gets(nome);

            	est = busca_estacao(estacoes,nome);

            	//verifica se estacao existe e nao ta fechada
                while(est==NULL || !est->situacao){
                    printf("estacao nao encontrada ou ela esta fechada. origem:");
                    gets(nome);
                    est = busca_estacao(estacoes,nome);
                }

                char linha[30];
                printf("linha em que quer chegar: ");
                gets(linha);

                /*
                valida linha digitada e depois
                busca as estacoes que estao naquela
                linha
                */
                while(strcmp(linha,"amarela")!=0 && strcmp(linha,"cinza")!=0 && strcmp(linha,"marrom")!=0 && strcmp(linha,"azul")!=0){
                    printf("linha invalida. linha: ");
                    gets(linha);
                }
                printf("\nlinha: %s\n",linha);
                busca_estacoes_por_linha(estacoes,linha);
                break;
            }

            case 7:
                ver_estacoes(estacoes,1);
            break;
        }

    }while(opcao!=8);

    return 0;
}



int gerar_tempo_aleatorio(){
	return (rand()%20)+1;
}

void limpar_console(){
    #ifdef __linux__
        system("clear");
    #else
        system("cls");
    #endif
}



/*
gera o percurso entre origem e destino
*/
void percurso(Estacao *destino, Estacao *estacao_atual, EstacoesVisitadas **estacoes_visitadas, int *tempo, int *num_rota, EstacoesVisitadasOrdenado **ests_ordenado){
    //printf("%x, ",estacao_atual);

    adicionar_pilha_estacoes_visitadas(estacoes_visitadas, estacao_atual->nome);

    //if(con == NULL) return;
    //if(estacao_atual==NULL) return;

    if(strcmp(destino->nome,estacao_atual->nome)==0) {
        ver_pilha_estacoes_visitadas(*estacoes_visitadas,num_rota,ests_ordenado,*tempo);
        printf("tempo de viagem: %d mins\n",*tempo);
        printf("\n\n-----------------------------------\n\n");
        //*tempo=0;
        return;
    }

    struct Conexoes *c = estacao_atual->conexoes;

    while(c!=NULL){

        if(!procurar_estacao_visitada_pilha(estacoes_visitadas,c->conexao->nome)){
        	*tempo+=c->tempo;

            percurso(destino,c->conexao, estacoes_visitadas,tempo,num_rota,ests_ordenado);

            remove_pilha_estacoes_visitadas(estacoes_visitadas);

            *tempo -= c->tempo;
            //break;
        }
        c = c->prox;
    }

}


/*
DEBUG FUNCAO PERCURSO:

PERCURSO ENTRE Piccadilly e Liverpool

a origem (Piccadilly) é adicionada na pilha e
inicia o loop pra percorrer as conexoes dela.

na 1a iteracao do loop do case 5 é feita a 1a chamada recursiva passando a 1a conexao
de Piccadilly que é Oxford

1a it:
-adiciona Oxford na pilha
-con recebe 1a conexao de Oxford que é Warren
-entra no while, verifica se Warren tá na pilha (nao ta) entao chama funcao percurso passando Warren

2a it:
-adiciona Warren na pilha e verifica se é o destino
-c recebe 1a conexao de Warren que é Kings Cross
-no while verifica se Kings Cross tá na pilha (nao) entao chama percurso passando Kings Cross

3a it:
-adiciona Kings Cross na pilha e verifica se é o destino
-c recebe 1a conexao de Kings Cross que é Farrington
-no while verifica se Farrington tá na pilha (nao) entao chama percurso passando Farrington

4a it:
-adiciona Farrington na pilha e verifica se é o destino
-c recebe 1a conexao de Farrington que é Liverpool
-no while verifica se Liverpool tá na pilha (nao) entao chama percurso passando Liverpool

5a it:
-adiciona Liverpool na pilha e verifica se é o destino (sim é o destino)
-Liverpool é o destino então printa a pilha (Piccadilly, Oxford, Warren, Kings Cross, Farrington, Liverpool)
-e retorna pra execução anterior

continuação 4a it:
-voltando pra 4a it depois que a 5a encerrou
-chama funcao pra remover da pilha o ultimo elemento que é Liverpool
-sai do if e vai pra linha onde tem c = c->prox, c recebe proxima conexao de Farrington que é Kings Cross
-verifica se Kings Cross tá na pilha (sim já tá) nao entra no IF e c recebe c->prox que é NULL
-sai do while, e encerra a 4a execução

continuação 3a it:
-voltando pra 3a it depois que a 4a encerrou
-chama funcao pra remover da pilha o ultimo elemento que é Farrington
-sai do if e vai pra linha onde tem c = c->prox, c recebe proxima conexao de Kings Cross que é Warren
-verifica se Warren tá na pilha (sim já tá) nao entra no IF e c recebe c->prox que é NULL
-sai do while, e encerra a 4a execução


continuação 2a it:
-voltando pra 2a it depois que a 3a encerrou
-chama funcao pra remover da pilha o ultimo elemento que é Kings Cross
-sai do if e vai pra linha onde tem c = c->prox, c recebe proxima conexao de Warren que é Baker
-verifica se Baker tá na pilha (nao tá) entao chama percurso passando Baker


6a it:
-adiciona Baker na pilha e verifica se é o destino
-c recebe 1a conexao de Baker que é Warren
-verifica se Warren tá na pilha (sim) nao entra no IF, e c recebe c->prox que é a proxima conexao de Baker que é Edgware
-verifica se Edgware tá na pilha (nao tá) entao chama percurso passando Edgware

7a it:
-adiciona Edgware na pilha e verifica se é o destino
-c recebe 1a conexao de Edgware que é Paddington
-no while verifica se Paddington tá na pilha (nao) entao chama percurso passando Paddington

8a it:
-adiciona Paddington na pilha e verifica se é o destino
-c recebe 1a conexao de Paddington que é Edgware
-no while, verifica se Edgware tá na pilha (sim) nao entra no IF, e c recebe c->prox que é a proxima conexao de Paddington que é Notting Hill
-verifica se Notting Hill tá na pilha (nao) entao chama percurso passando Notting Hill

9a it:
-adiciona Notting Hill na pilha e verifica se é o destino
-c recebe 1a conexao de Notting Hill que é Paddington
-no while, verifica se Paddington tá na pilha (sim) nao entra no IF, e c recebe c->prox que é a proxima conexao de Notting Hill que é South Kensington
-verifica se South Kensington tá na pilha (nao) entao chama percurso passando South Kensington

10a it:
-adiciona South Kensington na pilha e verifica se é o destino
-c recebe 1a conexao de South Kensington que é Notting Hill
-no while, verifica se Notting Hill tá na pilha (sim) nao entra no IF, e c recebe c->prox que é a proxima conexao de South Kensington que é Victoria
-verifica se Victoria tá na pilha (nao) entao chama percurso passando Victoria

11a it:
-adiciona Victoria na pilha e verifica se é o destino
-c recebe 1a conexao de Victoria que é South Kensington
-no while, verifica se South Kensington tá na pilha (sim) nao entra no IF, e c recebe c->prox que é a proxima conexao de Victoria que é Green Park
-verifica se Green Park tá na pilha (nao) entao chama percurso passando Green Park

12a it:
-adiciona Green Park na pilha e verifica se é o destino
-c recebe 1a conexao de Green Park que é Bond Street
-no while, verifica se Bond Street tá na pilha (nao) entao chama percurso passando Bond Street

13a it:
-adiciona Bond Street na pilha e verifica se é o destino
-c recebe 1a conexao de Bond Street que é Baker
-no while, verifica se Baker tá na pilha (sim, pois foi empilhado na 6a it) nao entra no IF, e c recebe c->prox que é a proxima conexao de Bond Street que é Green Park
-verifica se Green Park tá na pilha (sim) nao entra no IF, e c recebe c->prox que é a proxima conexao de Bond Street que é NULL pois já iterou nas 2
-sai do while, e encerra a 13a execução

continuação 12a it:
-voltando pra 12a it depois que a 13a encerrou
-chama funcao pra remover da pilha o ultimo elemento que é Bond Street
-sai do if e vai pra linha onde tem c = c->prox, c recebe proxima conexao de Green Park que é Victoria
-verifica se Victoria tá na pilha (sim já tá) nao entra no IF, e c recebe c->prox que é a proxima conexao de Green Park que é Oxford
-verifica se Oxford tá na pilha (sim já tá) nao entra no IF, e c recebe c->prox que é a proxima conexao de Green Park que é Westminster
-verifica se Westminster tá na pilha (nao) entao chama percurso passando Westminster

14a it:
-adiciona Westminster na pilha e verifica se é o destino
-c recebe 1a conexao de Westminster que é Victoria
-no while, verifica se Victoria tá na pilha (sim) nao entra no IF, e c recebe c->prox que é a proxima conexao de Westminster que é Embankment
-verifica se Embankment tá na pilha (nao) entao chama percurso passando Embankment

15a it:
-adiciona Embankment na pilha e verifica se é o destino
-c recebe 1a conexao de Embankment que é Westminster
-no while, verifica se Westminster tá na pilha (sim) nao entra no IF, e c recebe c->prox que é a proxima conexao de Embankment que é Waterloo
-verifica se Waterloo tá na pilha (nao) entao chama percurso passando Waterloo

16a it:
-adiciona Waterloo na pilha e verifica se é o destino
-c recebe 1a conexao de Waterloo que é Westminster
-no while, verifica se Westminster tá na pilha (sim) nao entra no IF, e c recebe c->prox que é a proxima conexao de Waterloo que é Embankment
-verifica se Embankment tá na pilha (sim) nao entra no IF, e c recebe c->prox que é a proxima conexao de Waterloo que é NULL pois já iterou nas 2
-sai do while, e encerra a 16a execução

continuação 15a it:
-voltando pra 15a it depois que a 16a encerrou
-chama funcao pra remover da pilha o ultimo elemento que é Waterloo
-sai do if e vai pra linha onde tem c = c->prox, c recebe proxima conexao de Embankment que é Blackfriars
-verifica se Blackfriars tá na pilha (nao) entao chama percurso passando Blackfriars

17a it:
-adiciona Blackfriars na pilha e verifica se é o destino
-c recebe 1a conexao de Blackfriars que é Embankment
-no while, verifica se Embankment tá na pilha (sim) nao entra no IF, e c recebe c->prox que é a proxima conexao de Blackfriars que é Monument
-verifica se Monument tá na pilha (nao) entao chama percurso passando Monument

18a it:
-adiciona Monument na pilha e verifica se é o destino
-c recebe 1a conexao de Monument que é Blackfriars
-no while, verifica se Blackfriars tá na pilha (sim) nao entra no IF, e c recebe c->prox que é a proxima conexao de Monument que é Tower Hill
-verifica se Tower Hill tá na pilha (nao) entao chama percurso passando Tower Hill

19a it:
-adiciona Tower Hill na pilha e verifica se é o destino
-c recebe 1a conexao de Tower Hill que é Monument
-no while, verifica se Monument tá na pilha (sim) nao entra no IF, e c recebe c->prox que é a proxima conexao de Tower que é Liverpool
-verifica se Liverpool tá na pilha (nao) entao chama percurso passando Liverpool

20a it:
-adiciona Liverpool na pilha e verifica se é o destino (sim é o destino)
-Liverpool é o destino então printa a pilha (Piccadilly, Oxford, Warren, Baker, Edgware, Paddington,
    Notting Hill, South Kensington, Victoria, Green Park, Westminster, Embankment,
    Blackfriars, Monument, Tower Hill, Liverpool)
-e retorna pra execução anterior

continuação 19a it:
-voltando pra 19a it depois que a 20a encerrou
-chama funcao pra remover da pilha o ultimo elemento que é Liverpool
-sai do if e vai pra linha onde tem c = c->prox, c recebe proxima conexao de Tower Hill que é NULL pois já iterou nas 2
-sai do while, e encerra a 19a execução

continuação 18a it:
-voltando pra 18a it depois que a 19a encerrou
-chama funcao pra remover da pilha o ultimo elemento que é Tower Hill
-sai do if e vai pra linha onde tem c = c->prox, c recebe proxima conexao de Monument que é NULL pois já iterou nas 2
-sai do while, e encerra a 18a execução

continuação 17a it:
-voltando pra 17a it depois que a 18a encerrou
-chama funcao pra remover da pilha o ultimo elemento que é Monument
-sai do if e vai pra linha onde tem c = c->prox, c recebe proxima conexao de Blackfriars que é NULL pois já iterou nas 2
-sai do while, e encerra a 17a execução

continuação 15a it:
-voltando pra 15a it depois que a 17a encerrou
-chama funcao pra remover da pilha o ultimo elemento que é Blackfriars
-sai do if e vai pra linha onde tem c = c->prox, c recebe proxima conexao de Embankment que é Charing Cross
-verifica se Charing Cross tá na pilha (nao) entao chama percurso passando Charing Cross


21a it:
-adiciona Charing Cross na pilha e verifica se é o destino
-c recebe 1a conexao de Charing Cross que é Embankment
-no while, verifica se Embankment tá na pilha (sim) nao entra no IF, e c recebe c->prox que é a proxima conexao de Charing Cross que é Piccadilly
-verifica se Piccadilly tá na pilha (sim) nao entra no IF, e c recebe c->prox que é a proxima conexao de Charing Cross que é NULL pois já iterou nos 2
-sai do while, e encerra a 21a execução


continuação 15a it:
-voltando pra 15a it depois que a 21a encerrou
-chama funcao pra remover da pilha o ultimo elemento que é Charing Cross
-sai do if e vai pra linha onde tem c = c->prox, c recebe proxima conexao de Embankment que é NULL pois já iterou em todas as conexoes de Embankment
-verifica se Charing Cross tá na pilha (nao) entao chama percurso passando Charing Cross
-sai do while, e encerra a 15a execução -voltando pra execução que a chamou (14a it)

continuação 14a it:
-voltando pra 14a it depois que a 15a encerrou
-chama funcao pra remover da pilha o ultimo elemento que é Embankment
-sai do if e vai pra linha onde tem c = c->prox, c recebe proxima conexao de Westminster que é Waterloo
-verifica se Waterloo tá na pilha (nao) entao chama percurso passando Waterloo...

e assim por diante, verifica se a proxima conexao nao ta na pilha e chama a recursao que verifica se a proxima
conexao da conexao passada por parametro ta na pilha e chama a recursao denovo, quando todas as conexoes
de uma estacao forem verificadas retorna pra execucao anterior que tem a estacao anterior dela

*/


