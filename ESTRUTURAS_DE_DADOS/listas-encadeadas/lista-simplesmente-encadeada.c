#include <stdio.h>
#include <stdlib.h>

struct no{
    int num;
    struct no *proximo;
};

typedef struct no No;

struct lista{
    No *inicio, *fim;
    int total_elementos;
};

typedef struct lista Lista;


//INSERE NO INICIO DA LISTA
void inserir_inicio(Lista *lista, int num){
    No *novo = (No *) malloc(sizeof(No));
    novo->num = num;

    //se inicio=NULL entao a lista ta vazia, sera adicionado o elemento e o inicio e o fim apontam pra ele mesmo
    if(lista->inicio == NULL){
        novo->proximo = NULL;
        lista->inicio = novo;
        lista->fim = novo;
    }

    //senao, entao o inicio passa a ser o novo valor, pois se esta inserindo no inicio, e o elemento que antes era o inicio, deixa de ser e passa a ser o proximo
    else{
        novo->proximo = lista->inicio;
        lista->inicio = novo;
    }

    lista->total_elementos++;//incrementa total de elementos
}



//INSERE NO FIM DA LISTA
void inserir_fim(Lista *lista, int valor) {
    No *novo = (No*)malloc(sizeof(No)); // aloca memoria pro novo nó
    novo->num = valor;
    novo->proximo = NULL;

    //se inicio=NULL entao a lista ta vazia, sera adicionado o elemento e o inicio e o fim apontam pra ele mesmo
    if(lista->inicio == NULL) { // lista vazia
        lista->inicio = novo;
        lista->fim = novo;
    }
    
    /*senão, entao o fim da lista é atualizado com o novo valor inserido, pois se está inserindo no fim
    lista->fim->proximo = novo; antes lista->fim->proximo apontava pra NULL pois era o ultimo elemento, agora ele vai apontar pro 
    novo valor que se está inserindo.
    lista->fim = novo; lista->fim apontava pro ultimo que agora não é mais o ultimo e sim o penultimo, pois se está inserindo 
    um novo elementono fim, entao ele passa a apontar pra esse novo valor que se está inserindo como sendo o ultimo*/
    else { // lista não vazia
        lista->fim->proximo = novo;
        lista->fim = novo;
    }

    lista->total_elementos++;
}




// imprimir a lista
void imprimir(Lista *lista) {
    No *inicio = lista->inicio;
    printf("Tamanho da lista: %d\n", lista->total_elementos);

    //se o proximo for NULL entao acabou a lista
    while(inicio != NULL) {
        printf("%d ", inicio->num);
        inicio = inicio->proximo;
    }
    printf("\n\n");
}



// remover um elemento da lista em qualquer posição, procurando pelo num passado
void remover(Lista *lista, int num) {
    No *inicio = lista->inicio; // ponteiro para o início da lista
    No *noARemover = NULL; // ponteiro para o nó a ser removido

    if(inicio != NULL && lista->inicio->num == num) { // remover 1º elemento
        noARemover = lista->inicio;
        lista->inicio = noARemover->proximo;//o elemento do inicio será removido, entao o inicio passa a ser o proximo elemento que o inicio apontava
        
        if(lista->inicio == NULL){
            lista->fim = NULL;
        }
    }
    
    // remoção no meio ou no final
    else {
        while(inicio != NULL && inicio->proximo != NULL && inicio->proximo->num != num) {
            inicio = inicio->proximo;
        }
        
        if(inicio != NULL && inicio->proximo != NULL) {
            noARemover = inicio->proximo;
            inicio->proximo = noARemover->proximo;//o elemento será removido, entao o proximo passa a ser o proximo elemento que o ele apontava
            
            if(inicio->proximo == NULL){ // se o último elemento for removido
                lista->fim = inicio;
            }
        }
    }
    
    if(noARemover) {
        free(noARemover); // libera a memória do nó
        lista->total_elementos--; // decrementa o tamanho da lista
    }
}




//INSERE EM QUALQUER POSICAO
void inserir(Lista *lista, int num, int posicao){
    int cont=0;
    
    if(posicao == lista->total_elementos){//se posicao = 3 e total_elementos = 3, entao se quer inserir no fim
        inserir_fim(lista, num);
    }
    else{
        
        if(posicao == 0){//se posicao = 0, se quer inserir no inicio
            inserir_inicio(lista, num);
        }
        else{
            /*
            se tiver 3 elementos na lista (2,5,7) e cont = 0, entao se estara acessando o primeiro elemento, 
            se cont=1 estara acessando o segundo e assim por diante, se se quer inserir um elemento (10) na posicao 1 
            de modo que a lista fique (2,10,5,7) entao precisa acesssar o valor (2) pra que deixe de apontar pra (5)
            e passe a apontar pro novo valor (10), e esse novo valor (10) apontará pra (5) e o total de elementos é incrementado
            */
            
            No *novo = (No *)malloc(sizeof(No));
            novo->num = num;
            
            No *posterior = lista->inicio;
            No *anterior;
            
            //quando cont for igual a 1, posterior apontará pro elemento (5), e anterior apontará pro elemento (2)
            while(cont != posicao){
                if(cont == (posicao-1)){
                    anterior = posterior;
                }
                
                posterior = posterior->proximo;
                cont++;
            }
            
            anterior->proximo = novo; //anterior->proximo aponta agora pra 10, e nao mais pra 5
            novo->proximo = posterior; //o novo->proximo apontará pro elemento 5
            
            lista->total_elementos++;
        }
    }
}


//valida posicao de insercao digitada
int validar_posicao_insercao(Lista *lista, int posicao){
    if(posicao < 0 || posicao > lista->total_elementos){
        return 0;
    }
    return 1;
}


int main()
{
    Lista lista;
    int opcao, valor, posicao_insercao;
    
    lista.inicio = NULL;
    lista.fim = NULL;
    lista.total_elementos = 0;
    
    do { // menu de opções
        printf("1 - Inserir no inicio\n2 - Imprimir\n3 - Inserir no fim\n4 - Remover\n5 - Inserir qualquer posicao\n6 - Sair\n");
        scanf("%d", &opcao);

        switch(opcao) {
        case 1:
            printf("Digite um valor a ser inserido: ");
            scanf("%d", &valor);
            inserir_inicio(&lista, valor);
            break;
        case 2:
            printf("\nLista original:\n");
            imprimir(&lista);
            break;
        case 3:
            printf("Digite um valor a ser inserido: ");
            scanf("%d", &valor);
            inserir_fim(&lista, valor);
            break;
        case 4:
            printf("Digite um valor a ser removido: ");
            scanf("%d", &valor);
            remover(&lista, valor);
            break;
        case 5:
            printf("Digite a posicao: ");
            scanf("%d",&posicao_insercao);
            int valid = validar_posicao_insercao(&lista,posicao_insercao);
            
            while(valid == 0){
                printf("posicao invalida ,digite a posicao: ");
                scanf("%d",&posicao_insercao);
                valid = validar_posicao_insercao(&lista,posicao_insercao);  
            }
            
            printf("Digite o valor: ");
            scanf("%d",&valor);
            inserir(&lista, valor, posicao_insercao);
            break;
        case 6:
            printf("Finalizando...\n");
            break;
        default:
            printf("Opcao invalida!\n");
        }
    } while(opcao != 6);

    return 0;
}




