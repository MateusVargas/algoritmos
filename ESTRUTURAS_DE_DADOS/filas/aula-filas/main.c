#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filas.h"

int main(){
    Fila *f;
    char nome[20] = {"joao"}, op;
    int cod;

    f = criaFila();

    do {
        printf("nome: ");
        getchar();
        gets(nome);
        printf("cod: ");
        scanf("%d",&cod);
        INSERT(&f, nome, cod);
        printf("inserir outro? (s/n)");
        getchar();
        scanf("%c", &op);
    } while(op == 's');

    imprime(f);
    f = REMOVE(f);
    imprime(f);


    return 0;
}

