struct fila{
    char nome[20];
    int cod;
    struct fila *prox;
};

typedef struct fila Fila;

Fila* criaFila(){
    return NULL;
}

void INSERT(Fila **f, char nome[20], int cod){
    Fila *novo = NULL;

    novo = (Fila*)malloc(sizeof(Fila));
    novo->cod = cod;
    strcpy(novo->nome, nome);
    novo->prox = NULL;

    if(*f==NULL){
        *f = novo;
    }
    else if((*f)->prox == NULL){
        (*f)->prox = novo;
    }
    else{
        Fila *iterator = *f;

        while(iterator->prox != NULL){
            iterator = iterator->prox;
        }

        iterator->prox = novo;
    }
}


Fila* REMOVE(Fila *f){

    if(f==NULL){
        printf("fila vazia\n");
    }
    else if(f->prox == NULL){
        free(f);
        f = NULL;
    }
    else{
        Fila *aux = f;
        f = f->prox;
        free(aux);
    }

    return f;
}

void imprime(Fila *f){
    Fila *iterator = f;

    if(f==NULL){
        printf("fila vazia\n");
    }
    else{
        while(iterator!=NULL){
            printf("%s\t",iterator->nome);
            iterator = iterator->prox;
        }
    }
    printf("\n");
}
