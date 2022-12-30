/*
Na lista, cada elemento
contém um elo (endereço) para o próximo elemento da lista. Desta forma a lista
pode ser acessada de maneira randômica, podendo ser retirados, acrescidos ou
inseridos elementos no meio da lista dinamicamente.

Uma lista pode ter uma entre várias formas. Ela pode ser simplesmente
encadeada ou duplamente encadeada, pode ser ordenada ou não, e pode ser circular ou
não. Se uma lista é simplesmente encadeada, omitimos o ponteiro anterior em cada
elemento. Se uma lista é ordenada, a ordem linear da lista corresponde à or-
dem linear de chaves armazenadas em elementos da lista; o elemento minímo
é o início da lista e o elemento máximo é o im. Se a lista é não ordenada, os
elementos podem aparecer em qualquer ordem. Em uma lista circular, o pon-
teiro anterior do início da lista aponta para o im, e o ponteiro próximo do im
da lista aponta para o início. Desse modo, a lista pode ser vista como um anel
de elementos

Listas encadeadas podem ser singularmente (ou simples) ou duplamente
encadeadas (ligadas). Uma lista simplesmente encadeada contém um elo (ende-
reço) com o próximo item da lista. Uma lista duplamente encadeada contém elos
(endereços) com o elemento anterior e com o elemento posterior a ele

Normalmente a representação de uma lista simplesmente encadeada é dada
por um endereço (nó) que contém o próximo elemento

O último elemento da lista pode ter o endereço para um endereço nulo
(caracterizando o inal da lista) ou o endereço para o primeiro item lista (carac-
terizando uma lista circular)

Uma lista sem endereços (também conhecida como nós) é chamada de
lista vazia ou lista nula. Uma observação importante: a lista simplesmente en-
cadeada por ser utilizada para representar uma pilha ou ila de dados dinami-
camente.

Listas duplamente encadeadas consistem em dados e endereços (nós) para
o próximo item e para o item precedente. O fato de haver dois nós
tem duas vantagens principais: a lista pode ser lida em ambas as direções, o que
simpliica o gerenciamento da lista

As operações para manipulação de uma lista são:
• insert - insere num determinado ponto uma informação na lista.
• add - adiciona ao inal da lista uma informação.
• delete - deleta um nó da lista.
• info - retorna uma informação da lista atual.
• next - desloca o ponteiro atual da lista caminhando para o inal.
• last - desloca o ponteiro atual da lista caminhando para o início da lista.

** ao remover um elemento da lista, sera preciso refazer os elos, no caso juntar os elementos vizinhos ao que foi excluido
** ao inserir sera preciso tambem fazer os elos do elemento inserido com o seu antecessor e posterior

** diferente dos vetores que os elementos ficam em posicoes seguidas na memoria, nas listas encadeadas os elementos
podem ficar em qualquer posicao, pois tem um ponteiro que aponta pro proximo elemento da lista

Na implementação de listas em C normalmente são utilizadas structs
que, além de conter as informações necessárias - códigos, nomes etc. -, terão
campos adicionais para controle da própria lista
*/



//Exemplo de manipulação de lista simplesmente encadeada (que tem o endereco do proximo elemento apenas)

#include <stdio.h>
#include <stdlib.h>

struct lista{
    char nome[40];
    int idade;
    struct lista *pont_proximo; //ponteiro para o proximo elemento da lista
};

int main(){
    struct lista *p_lista;
    struct lista *p_inicio;//guarda o endereco do primeiro elemento

    p_lista = calloc(1,sizeof(struct lista));//alocacao dinamica pro primeiro elemento da lista, que sera uma struct com nome e idade

    if(p_lista == NULL){
        printf("\nErro de alocacao de memoria!");
        exit(0);
    }

    p_lista->pont_proximo = NULL;//ponteiro pro proximo elemento NULL (lista esta vazia por enquanto)

    p_inicio = p_lista;//guarda o endereco do primeiro elemento, pois p_lista vai apontar pros enderecos dos novos itens da lista

    for(int i=0;i<5;i++){
        printf("nome: ");
        getchar();
        fgets(p_lista->nome, 41, stdin);

        printf("idade: ");
        scanf("%d",&p_lista->idade);

        //depois de ler o primeiro elemento, aloca memoria pro proximo elemento, que sera uma struct com nome e idade
        p_lista->pont_proximo = calloc(1,sizeof(struct lista));

        if(p_lista == NULL){
            printf("\nErro de alocacao de memoria!");
            exit(0);
        }

        //p_lista recebe o endereco do segundo elemento, que sera lido no for e depois p_lista vai apontar pro proximo item e assim por diante
        p_lista = p_lista->pont_proximo;
        p_lista->pont_proximo = NULL;
        //pontero para o proximo e NULL pois e o ultimo elemento, quando entrar o terceiro elemento por exemplo esse ponteiro do segundo
        //elemento recebera o endereco do terceiro na linha 97, o terceiro recebe o endereco do quarto, e assim por diante
        //o ponteiro do ultimo elemento sera NULL significa que chegou ao fim a lista
    }

    //imprimir
    p_lista = p_inicio; //p_lista volta a apontar pro inicio, pra que seja possivel saber o primeiro elemento e assim imprimir todos

    while(p_lista->pont_proximo != NULL){
        puts(p_lista->nome);
        printf("idade: %d\n",p_lista->idade);

        //depois de imprimir o elemento, p_lista aponta pro proximo elemento
        //sera impresso esse proximo elemento e p_lista apontara pro proximo e assim por diante ate o fim
        p_lista = p_lista->pont_proximo;
    }


    /*p_lista = p_inicio;
    while(p_lista->pont_proximo != NULL){
        struct lista *proximo;
        proximo = p_lista->pont_proximo;

        free(p_lista);
        p_lista = NULL;
        p_lista = proximo;
    }*/

    return 0;
}
