//cada nó tem 2 ponteiros, um apontando pro próximo nó e outro pro anterior
//pode-se imprimir nos dois sentidos, tanto do inicio pro fim, como do fim pro inicio
//cada operação de inserção e remoção implica em ter que atualizar os ponteiros que apontam pro anterior e pro próximo

#include<stdio.h>
#include<stdlib.h>


//cada nó pode ser representado por uma struct
struct no{
	int valor;
	struct no *proximo;
	struct no *anterior;
};

typedef struct no No;

/*
	procedimento para inserir um novo nó no início da lista
*/
void inserir_no_inicio(No **lista, int num){
    No *novo = malloc(sizeof(No));
    
    //variavel lista dentro dessa função é o endereco de lista da main pois foi passado &lista
    //*lista vai no valor guardado na lista da main e pega esse valor (que é um endereco ou NULL)
    //**lista vai no valor guardado na lista da main (que é um endereco ou NULL), vai nesse endereco e traz o valor dele
    
    if(*lista == NULL){
        printf("*lista = NULL");
    }
    else{
        //printf("*lista %x\n",*lista);    
    }

    //printf("**lista %x\n",**lista);
    //printf("lista %x\n",lista);

    if(novo){
        novo->valor = num;

        // próximo do novo nó aponta para o início da lista
        //se a lista estiver vazia, o proximo aponta pra NULL
        novo->proximo = *lista;

        // o anterior é nulo pois é o primeiro nó
        novo->anterior = NULL;

        // se a lista não estiver vazia, o anterior do que era o primeiro nó aponta para o novo nó, 
        //pois o novo nó passará a ser o primeiro
        if(*lista){
            (*lista)->anterior = novo;
        }

        // o novo nó passa a ser o início da lista (o primeiro nó da lista)
        *lista = novo;
    }
    else{
        printf("Erro ao alocar memoria!\n");
    }
}



// procedimento para inserir no fim
void inserir_no_fim(No **lista, int num){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = NULL;//como está inserindo no fim, o proximo é NULL

        // é o primeiro?
        //vai no valor guardado em lista da main e pega esse valor (que é um endereco ou NULL)
        //se for NULL não tem nenhum nó armazenado nele
        if(*lista == NULL){
            *lista = novo;
            novo->anterior = NULL;
        }
        else{
            aux = *lista;//aux recebe o ponteiro por inicio da lista
            
            //aux recebe o valor guardado em lista que é um ponteiro pro primeiro elemento da lista
            //enquanto o proximo for != NULL aux vai recebendo o proximo elemento
            //quando o proximo for NULL sai do while, e aux terá um ponteiro pro ultimo elemento valido da lista
            
            while(aux->proximo){
                aux = aux->proximo;
            }
            
            //aux tem o ultimo elemento valido, então o proximo dele é NULL,
            //como se está inserindo um novo elemento no fim o proximo que era NULL vai apontar pra esse novo elemento inserido
            //e o anterior desse novo elemento inserido vai apontar pro elemento que até então era o ultimo mas agora será o penultimo
            aux->proximo = novo;
            novo->anterior = aux;
        }
    }
    else{
        printf("Erro ao alocar memoria!\n");
    }
}

// procedimento para inserir no meio
void inserir_no_meio(No **lista, int num, int ant){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        
        // é o primeiro?
        //se *lista que aponta pro inicio for NULL então se está inserindo no inicio
        //anterior é proximo ficam nulos
        if(*lista == NULL){
            novo->proximo = NULL;
            novo->anterior = NULL;
            *lista = novo;
        }
        else{
            aux = *lista; //aux recebe ponteiro pro inicio da lista
            
            //percorre ate achar o nó que corresponde ao valor passado
            //e enquanto não chega no fim da lista
            while(aux->valor != ant && aux->proximo){
                aux = aux->proximo;
            }
            

            //novo nó será inserido depois de aux e antes do próximo de aux, ou seja, no meio deles
            //então o que era o próximo de aux passará a ser o proximo do novo nó
            novo->proximo = aux->proximo;

            //se aux for o ultimo elemento então o próximo dele será NULL
            //senão, cai no if e o anterior do próximo nó que antes apontava pra aux vai apontar pro novo nó
            //pois o novo nó foi inserido no meio deles
            if(aux->proximo){
                aux->proximo->anterior = novo;
            }
            
            //por fim o anterior do novo nó aponta pra aux, pois ele foi inserido depois dele
            //e o próximo de aux aponta pro novo nó pois ele foi inserido depois dele
            novo->anterior = aux;
            aux->proximo = novo;
        }
    }
    else{
        printf("Erro ao alocar memoria!\n");
    }
}

void inserir_ordenado(No **lista, int num){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        // a lista está vazia?
        if(*lista == NULL){
            novo->proximo = NULL;
            novo->anterior = NULL;
            *lista = novo;
        } // é o menor?
        else if(novo->valor < (*lista)->valor){
            novo->proximo = *lista;
            (*lista)->anterior = novo;
            *lista = novo;
        }
        else{
            aux = *lista;
            while(aux->proximo && novo->valor > aux->proximo->valor){
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;

            if(aux->proximo){
                aux->proximo->anterior = novo;
            }
            
            novo->anterior = aux;
            aux->proximo = novo;
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
}



//remove um nó e retorna esse nó que foi apagado
No* remover(No **lista, int num){
    No *aux, *remover = NULL;

    //verifica se valor guardado em lista não é NULL
    if(*lista){
        
        //como *lista guarda o endereco do primeiro nó
        //verifica se o primeiro elemento é o que se deseja excluir
        
        if((*lista)->valor == num){
            remover = *lista; //o elemento a ser removido é o primeiro
            
            //*lista que guarda um ponteiro pro primeiro nó, passa a apontar pro proximo do que será removido
            //ou seja, aponta agora para o que era segundo elemento
            *lista = remover->proximo;
            
            //se o proximo do elemento removido for NULL então se está apagando o primeiro e único elemento da lista
            //fazendo com que o *lista que aponta pro primeiro nó seja NULL
            
            //se tiver mais elementos vai cair no if, e *lista vai apontar pro nó que antes era o segundo
            //como o segundo virou o primeiro o anterior dele deve ser NULL
            if(*lista){
                (*lista)->anterior = NULL;
            }
        }
        
        //se o elemento a ser excluido não é o primeiro
        else{
            aux = *lista;
            
            //percorre até o proximo for NULL e enquanto não achar o nó
            while(aux->proximo && aux->proximo->valor != num){
                aux = aux->proximo;
            }
            
            //
            if(aux->proximo){
                remover = aux->proximo;
                aux->proximo = remover->proximo;
                
                if(aux->proximo){
                    aux->proximo->anterior = aux;
                }
            }
        }
    }
    
    return remover;
}

No* buscar(No **lista, int num){
    No *aux, *no = NULL;

    aux = *lista;
    
    //percorre até o proximo ser NULL e enquanto não achar o valor procurado
    while(aux && aux->valor != num){
        aux = aux->proximo;
    }
    
    //se achou retorna o ponteiro pro nó, senão retorna NULL
    if(aux){
        no = aux;
    }
    
    return no;
}

void imprimir(No *no){
    printf("\n\tLista: ");
    
    //imprime até o proximo elemento ser NULL
    while(no){
        printf("%d ", no->valor);
        no = no->proximo;
    }
    printf("\n\n");
}

// retorna ponteiro para o último nó da lista
No* ultimo(No **lista){
    No *aux = *lista;
    
    //aux recebe ponteiro pro início da lista e vai percorrendo até o proximo for NULL
    //significa então que o ultimo elemento foi encontrado e ele é retornado pela função
    while(aux->proximo){
        aux = aux->proximo;
    }
    return aux;
}

// imprime a lista do fim para o início
// recebe um ponteiro para o último nó da lista
void imprimirContrario(No *no){
    printf("\n\tLista: ");
    
    //imprime de traz pra frente, quando anterior for NULL, chegou ao fim
    while(no){
        printf("%d ", no->valor);
        no = no->anterior;
    }
    printf("\n\n");
}

int main(){

    int opcao, valor, anterior;
    No *removido, *lista = NULL;
    //*lista é um ponteiro pro primeiro elemento, se ele for NULL então a lista está vazia
    
    do{
        printf("\n\t0 - Sair\n\t1 - InserirI\n\t2 - inserirF\n\t3 - InserirM\n\t4 - InserirO\n\t5 - Remover\n\t6 - Imprimir\n\t7 - Buscar\n\t8 - ImprimirC\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                //precisa passar o endereco de lista, porque o ponteiro lista = NULL
                //se passase só lista a função receberia NULL e não poderia fazer nada
                inserir_no_inicio(&lista, valor);
                break;
                
            case 2:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                inserir_no_fim(&lista, valor);
                break;
                
            case 3:
                printf("Digite um valor e o valor de referencia: ");
                scanf("%d%d", &valor, &anterior);
                inserir_no_meio(&lista, valor, anterior);
                break;
            
            case 4:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                inserir_ordenado(&lista, valor);
                break;
            
            case 5:
                printf("Digite um valor a ser removido: ");
                scanf("%d", &valor);
                removido = remover(&lista, valor);
                
                if(removido){
                    printf("Elemento a ser removido: %d\n", removido->valor);
                    free(removido);
                }
                else{
                    printf("Elemento inexistente!\n");
                }
                break;
            
            case 6:
                imprimir(lista);
                break;
            
            case 7:
                printf("Digite um valor a ser buscado: ");
                scanf("%d", &valor);
                removido = buscar(&lista, valor);
            
                if(removido){
                    printf("Elemento encontrado: %d\n", removido->valor);
                }
                else{
                    printf("Elemento nao encontrado!\n");
                }
                
                break;
            
            case 8:
                imprimirContrario(ultimo(&lista));
                break;
            
            default:
                if(opcao != 0){
                    printf("Opcao invalida!\n");
                }
        }

    }while(opcao != 0);

    return 0;
}