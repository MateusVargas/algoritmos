#include <stdio.h>
#include <stdlib.h>

/**
arvore: menores a esquerda, maiores a direita
            8
          /  \
         /    \
        /      \
       /        \
      5          14
     / \        /  \
    /   \      /    \
   2     6    10    20
        / \         / \
       /   \       /   \
      3     7     15   18
           /       \
          /         \
         4          16
*/

typedef struct no{
    int valor;
    struct no *esquerda;
    struct no *direita;
} No;

void inserirDireita(No **raiz, int valor);

void inserirEsquerda(No **raiz, int valor){
    if((*raiz)->esquerda == NULL){
        No *novo = (No*)malloc(sizeof(No));
        novo->valor = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        (*raiz)->esquerda = novo;
    }
    else{
        if(valor < (*raiz)->esquerda->valor){
            inserirEsquerda(&(*raiz)->esquerda, valor);
        }
        if(valor > (*raiz)->esquerda->valor){
            inserirDireita(&(*raiz)->esquerda, valor);
        }
    }
}

void inserirDireita(No **raiz, int valor){
    if((*raiz)->direita == NULL){
        No *novo = (No*)malloc(sizeof(No));
        novo->valor = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        (*raiz)->direita = novo;
    }
    else{
        if(valor > (*raiz)->direita->valor){
            inserirDireita(&(*raiz)->direita, valor);
        }
        if(valor < (*raiz)->direita->valor){
            inserirEsquerda(&(*raiz)->direita, valor);
        }
    }
}




/**
 * se a arvore tiver vazia cai no if e cria a raiz
 * se não tiver vazia começa a recursão

supondo que queira inserir numero 16 nesta arvore: (deve ficar abaixo do 15)
            8
          /  \
         /    \
        /      \
       /        \
      5          14
     / \        /  \
    /   \      /    \
   2     6    10    20
        / \         / \
       /   \       /   \
      3     7     15   18
           /       \
          /         \
         4          

função inserir(): 
raiz não é nula então entra no else
valor = 16, raiz = 8 valor > raiz chama inserirDireita(raiz,16)

1a iteração:
função inserirDireita():
    -recebe a raiz que é 8, e o valor que é 16
    -verifica se raiz->direita == null, não é pois a direita do 8 tem o 14, entra no else
    -if(valor > (*raiz)->direita->valor) 16 > 14 = true, chama função inserirDireita() passando endereço do nó 14 inserirDireita(&(*raiz)->direita, 16);
    -depois de encerrada a 2a it. volta pra 1a it.
    -verifica o próximo if, if(valor < (*raiz)->direita->valor) 16 < 14 = false, não entra no if e encerra execução

2a iteração:
função inserirDireita():
    -recebe a raiz que é 14, e o valor que é 16
    -verifica se raiz->direita == null, não é pois a direita do 14 tem o 20, entra no else
    -if(valor > (*raiz)->direita->valor) 16 > 20 = false
    -if(valor < (*raiz)->direita->valor) 16 < 20 = true, chama função inserirEsquerda() passando endereço do nó 20 inserirEsquerda(&(*raiz)->direita, 16);
    -depois de encerrada a 3a it. volta pra 2a it. e encerra execução e volta pra 1a it.

3a iteração:
função inserirEsquerda():
    -recebe a raiz que é 20, e o valor que é 16
    -verifica se raiz->esquerda == null, não é pois a esquerda do 20 tem o 15, entra no else
    -if(valor < (*raiz)->esquerda->valor) 16 < 15 = false
    -if(valor > (*raiz)->esquerda->valor) 16 > 15 = true, chama função inserirDireita() passando endereço do nó 15 inserirDireita(&(*raiz)->esquerda, 16);
    -depois de encerrada a 4a it. volta pra 3a it. e encerra execução e volta pra 2a it.

4a iteração:
função inserirDireita():
    -recebe a raiz que é 15, e o valor que é 16
    -verifica se raiz->direita == null, true então cria o nó com valor 16 e faz o nó 15->direita apontar pro nó criado
    -não tem mais o que fazer então encerra execução e volta pra 3a it.
*/
void inserir(No **raiz, int valor){
    if(*raiz == NULL){
        No *novo = (No*)malloc(sizeof(No));
        novo->valor = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        *raiz = novo;
    }
    else{
        if(valor < (*raiz)->valor){
            inserirEsquerda(raiz, valor);
        }
        if(valor > (*raiz)->valor){
            inserirDireita(raiz, valor);
        }
    }
}


/**
 *
calcular tamanho (qtd de nós) da arvore
            8
          /  \
         /    \
        /      \
       /        \
      5          14
     / \        /  \
    /   \      /    \
   2     6    10    20
        / \         / \
       /   \       /   \
      3     7     15   18
           /       \
          /         \
         4          16

getTamanho()
PERCORRENDO ESQUERDA DA ARVORE
1a it.
    -recebe a raiz que é 8
    -verifica se raiz é null, falso
    -inicia 2a it: return 1 + getTamanho(raiz->esquerda) //chama função passando nó 5
    -depois que 2a it. termina, continua sua execução iniciando a 15a it. chamando getTamanho(raiz->direita) passando direita do nó 8 que é o nó 14
    -depois que 15a it. termina, encerra a execução com 1 + os retornos da 2a e 15a it. que é 1 + 6 + 6
2a it.
    -recebe a raiz que é 5
    -verifica se raiz é null, falso
    -inicia 3a it: return 1 + getTamanho(raiz->esquerda) //chama função passando nó 2
    -depois que 3a it. termina, continua sua execução iniciando a 6it. chamando getTamanho(raiz->direita) passando direita do nó 5 que é o nó 6
    -depois que 6a it. termina, encerra a execução com 1 + os retornos da 3a e 6a it. que é 1 + 1 + 4
3a it.
    -recebe a raiz que é 2
    -verifica se raiz é null, falso
    -inicia 4a it: return 1 + getTamanho(raiz->esquerda) //chama função passando nó a esquerda de 2 que é null
    -depois que 4a it. termina, continua sua execução inicia 5a it: chamando getTamanho(raiz->direita) passando direita do nó 2 que é null
    -depois que 5a it. termina, encerra a execução com 1 + os retornos da 4a e 5a it. que é 1 + 0 + 0
4a it.
    -recebe a raiz que é null
    -verifica se raiz é null, true retorna 0;
    -volta pra 3a it;
5a it.
    -recebe a raiz que é null
    -verifica se raiz é null, true retorna 0;
    -volta pra 3a it;
6it.
    -recebe a raiz que é 6
    -verifica se raiz é null, falso
    -inicia 7a it: return 1 + getTamanho(raiz->esquerda) //chama função passando nó a esquerda de 6 que é nó 3
    -depois que 7a it. termina, continua sua execução inicia 10a it: chamando getTamanho(raiz->direita) passando direita do nó 6 que é nó 7
    -depois que 10a it. termina, encerra a execução com 1 + os retornos da 7a e 10a it. que é 1 + 1 + 2
7a it.
    -recebe a raiz que é 3
    -verifica se raiz é null, falso
    -inicia 8a it: return 1 + getTamanho(raiz->esquerda) //chama função passando nó a esquerda de 3 que é null
    -depois que 8a it. termina, continua sua execução inicia 9a it: chamando getTamanho(raiz->direita) passando direita do nó 3 que é null
    -depois que 9a it. termina, encerra a execução com 1 + os retornos da 8a e 9a it. que é 1 + 0 + 0
8a it.
    -recebe a raiz que é null
    -verifica se raiz é null, true retorna 0;
    -volta pra 7a it;
9a it.
    -recebe a raiz que é null
    -verifica se raiz é null, true retorna 0;
    -volta pra 7a it;
10a it.
    -recebe a raiz que é 7
    -verifica se raiz é null, falso
    -inicia 11a it: return 1 + getTamanho(raiz->esquerda) //chama função passando nó a esquerda de 7 que é o nó 4
    -depois que 11a it. termina, continua sua execução inicia 14a it: chamando getTamanho(raiz->direita) passando direita do nó 7 que é null
    -depois que 14a it. termina, encerra a execução com 1 + os retornos da 11a e 14a it. que é 1 + 1 + 0
11a it.
    -recebe a raiz que é 4
    -verifica se raiz é null, falso
    -inicia 12a it: return 1 + getTamanho(raiz->esquerda) //chama função passando nó a esquerda de 4 que é null
    -depois que 12a it. termina, continua sua execução inicia 13a it: chamando getTamanho(raiz->direita) passando direita do nó 4 que é null
    -depois que 13a it. termina, encerra a execução com 1 + os retornos da 12a e 13a it. que é 1 + 0 + 0
12a it.
    -recebe a raiz que é null
    -verifica se raiz é null, true retorna 0;
    -volta pra 11a it;
13a it.
    -recebe a raiz que é null
    -verifica se raiz é null, true retorna 0;
    -volta pra 11a it;
14a it.
    -recebe a raiz que é null
    -verifica se raiz é null, true retorna 0;
    -volta pra 10a it;


PERCORRENDO DIREITA DA ARVORE
15a it.
    -recebe a raiz que é 14
    -verifica se raiz é null, falso
    -inicia 16a it: return 1 + getTamanho(raiz->esquerda) //chama função passando nó a esquerda de 14 que é 10
    -depois que 16a it. termina, continua sua execução iniciando a 19it. chamando getTamanho(raiz->direita) passando direita do nó 14 que é o nó 20
    -depois que 19a it. termina, encerra a execução com 1 + os retornos da 16a e 19a it. que é 1 + 1 + 4
16a it.
    -recebe a raiz que é 10
    -verifica se raiz é null, falso
    -inicia 17a it: return 1 + getTamanho(raiz->esquerda) //chama função passando nó a esquerda de 10 que é null
    -depois que 17a it. termina, continua sua execução inicia 18a it: chamando getTamanho(raiz->direita) passando direita do nó 10 que é null
    -depois que 18a it. termina, encerra a execução com 1 + os retornos da 17a e 18a it. que é 1 + 0 + 0
17a it.
    -recebe a raiz que é null
    -verifica se raiz é null, true retorna 0;
    -volta pra 16a it;
18a it.
    -recebe a raiz que é null
    -verifica se raiz é null, true retorna 0;
    -volta pra 16a it;
19a it.
    -recebe a raiz que é 20
    -verifica se raiz é null, falso
    -inicia 20a it: return 1 + getTamanho(raiz->esquerda) //chama função passando nó a esquerda de 20 que é nó 15
    -depois que 20a it. termina, continua sua execução inicia 25a it: chamando getTamanho(raiz->direita) passando direita do nó 20 que é nó 18
    -depois que 25a it. termina, encerra a execução com 1 + os retornos da 20a e 25a it. que é 1 + 2 + 1
20a it.
    -recebe a raiz que é 15
    -verifica se raiz é null, falso
    -inicia 21a it: return 1 + getTamanho(raiz->esquerda) //chama função passando nó a esquerda de 15 que é null
    -depois que 21a it. termina, continua sua execução inicia 22a it: chamando getTamanho(raiz->direita) passando direita do nó 15 que é 16
    -depois que 22a it. termina, encerra a execução com 1 + os retornos da 21a e 22a it. que é 1 + 0 + 1
21a it.
    -recebe a raiz que é null
    -verifica se raiz é null, true retorna 0;
    -volta pra 20a it;
22a it.
    -recebe a raiz que é 16
    -verifica se raiz é null, falso
    -inicia 23a it: return 1 + getTamanho(raiz->esquerda) //chama função passando nó a esquerda de 16 que é null
    -depois que 23a it. termina, continua sua execução inicia 24a it: chamando getTamanho(raiz->direita) passando direita do nó 16 que é null
    -depois que 24a it. termina, encerra a execução com 1 + os retornos da 23a e 24a it. que é 1 + 0 + 0
23a it.
    -recebe a raiz que é null
    -verifica se raiz é null, true retorna 0;
    -volta pra 22a it;
24a it.
    -recebe a raiz que é null
    -verifica se raiz é null, true retorna 0;
    -volta pra 22a it;
25a it.
    -recebe a raiz que é 18
    -verifica se raiz é null, falso
    -inicia 26a it: return 1 + getTamanho(raiz->esquerda) //chama função passando nó a esquerda de 18 que é null
    -depois que 26a it. termina, continua sua execução inicia 27a it: chamando getTamanho(raiz->direita) passando direita do nó 18 que é null
    -depois que 27a it. termina, encerra a execução com 1 + os retornos da 26a e 27a it. que é 1 + 0 + 0
26a it.
    -recebe a raiz que é null
    -verifica se raiz é null, true retorna 0;
    -volta pra 25a it;
27a it.
    -recebe a raiz que é null
    -verifica se raiz é null, true retorna 0;
    -volta pra 25a it;
*/
int getTamanho(No *raiz){
    if(raiz == NULL) return 0;
    return 1 + getTamanho(raiz->esquerda) + getTamanho(raiz->direita);
}


/*
busca nó 15:
            8
          /  \
         /    \
        /      \
       /        \
      5          14
     / \        /  \
    /   \      /    \
   2     6    10    20
        / \         / \
       /   \       /   \
      3     7     15   18
           /       \
          /         \
         4          16

1a it.
    -recebe raiz que é 8
    -verifica se raiz é nula, falso
    -verifica se valor da raiz é igual a 15, falso
    -verifica se valor da raiz é maior que 15, falso
    -cai no else, return buscar(raiz->direita, valor); //chama funcao buscar() passando direita de 8 que é o nó 14
    -depois que 2a it. termina retorna valor retornado por ela pro método main()
2a it.
    -recebe raiz que é 14
    -verifica se raiz é nula, falso
    -verifica se valor da raiz é igual a 15, falso
    -verifica se valor da raiz é maior que 15, falso
    -cai no else, return buscar(raiz->direita, valor); //chama funcao buscar() passando direita de 14 que é o nó 20
    -depois que 3a it. termina retorna valor retornado por ela pra execução anterior
3a it.
    -recebe raiz que é 20
    -verifica se raiz é nula, falso
    -verifica se valor da raiz é igual a 15, falso
    -verifica se valor da raiz é maior que 15, true, return buscar(raiz->esquerda, valor); //chama funcao buscar() passando esquerda de 20 que é o nó 15
    -depois que 4a it. termina retorna valor retornado por ela pra execução anterior
4a it.
    -recebe raiz que é 15
    -verifica se raiz é nula, falso
    -verifica se valor da raiz é igual a 15, true. retorna 15 pra execução anterior
*/
int buscar(No *raiz, int valor){
    if(raiz == NULL) return -1;
    if(raiz->valor == valor) return raiz->valor;
    if(raiz->valor > valor) return buscar(raiz->esquerda, valor);
    else return buscar(raiz->direita, valor);
}

//FORMAS DE PERCURSO PRE-FIXADO, SIMETRICO, POS-FIXADO
/*
imprimir modo simetrico: esq -> raiz -> dir
            8
          /  \
         /    \
        /      \
       /        \
      5          14
     / \        /  \
    /   \      /    \
   2     6    10    20
        / \         / \
       /   \       /   \
      3     7     15   18
           /       \
          /         \
         4          16
imprimirSimetrico(No *raiz); resultado: 2, 5, 3, 6, 4, 7, 8 ...
1a it:
    -recebe raiz que é 8
    -verifica se raiz é null, falso
    -inicia 2a it: chama funcao imprimirSimetrico() passando nó a esquerda de 8 que é o nó 5
    -depois que 2a it. termina printa 8 na tela
    -depois inicia 15a it: chama funcao imprimirSimetrico() passando nó a direita de 8 que é nó 14
2a it:
    -recebe raiz que é 5
    -verifica se raiz é null, falso
    -inicia 3a it: chama funcao imprimirSimetrico() passando nó a esquerda de 5 que é o nó 2
    -depois que 3a it. termina printa 5 na tela
    -depois inicia 6a it: chama funcao imprimirSimetrico() passando nó a direita de 5 que é nó 6
    -depois que 6a it. termina encerra execução e retorna pra 1a it.
3a it:
    -recebe raiz que é 2
    -verifica se raiz é null, falso
    -inicia 4a it: chama funcao imprimirSimetrico() passando nó a esquerda de 2 que é null
    -depois que 4a it. termina printa 2 na tela
    -depois inicia 5a it: chama funcao imprimirSimetrico() passando nó a direita de 2 que é null
    -depois que 5a it. termina encerra execução e retorna pra 2a it.
4a it:
    -recebe raiz que é null
    -verifica se raiz é null, true, retorna pra 3a it.
5a it:
    -recebe raiz que é null
    -verifica se raiz é null, true, retorna pra 3a it.
6a it:
    -recebe raiz que é 6
    -verifica se raiz é null, falso
    -inicia 7a it: chama funcao imprimirSimetrico() passando nó a esquerda de 6 que é o nó 3
    -depois que 7a it. termina printa 6 na tela
    -depois inicia 10a it. chama funcao imprimirSimetrico() passando nó a direita de 6 que é nó 7
    -depois que 10a it. termina encerra execução e retorna pra 2a it.
7a it:
    -recebe raiz que é 3
    -verifica se raiz é null, falso
    -inicia 8a it: chama funcao imprimirSimetrico() passando nó a esquerda de 3 que é null
    -depois que 8a it. termina printa 3 na tela
    -depois inicia 9a it: chama funcao imprimirSimetrico() passando nó a direita de 3 que é null
    -depois que 9a it. termina encerra execução e retorna pra 6a it.
8a it:
    -recebe raiz que é null
    -verifica se raiz é null, true, retorna pra 7a it.
9a it:
    -recebe raiz que é null
    -verifica se raiz é null, true, retorna pra 7a it.
10a it:
    -recebe raiz que é 7
    -verifica se raiz é null, falso
    -inicia 11a it: chama funcao imprimirSimetrico() passando nó a esquerda de 7 que é o nó 4
    -depois que 11a it. termina printa 7 na tela
    -depois inicia 14a it. chama funcao imprimirSimetrico() passando nó a direita de 7 que é null
    -depois que 14a it. termina encerra execução e retorna pra 6a it.
11a it:
    -recebe raiz que é 4
    -verifica se raiz é null, falso
    -inicia 12a it: chama funcao imprimirSimetrico() passando nó a esquerda de 4 que é null
    -depois que 12a it. termina printa 4 na tela
    -depois inicia 13a it. chama funcao imprimirSimetrico() passando nó a direita de 4 que é null
    -depois que 13a it. termina encerra execução e retorna pra 10a it.
12a it:
    -recebe raiz que é null
    -verifica se raiz é null, true, retorna pra 11a it.
13a it:
    -recebe raiz que é null
    -verifica se raiz é null, true, retorna pra 11a it.
14a it:
    -recebe raiz que é null
    -verifica se raiz é null, true, retorna pra 10a it.
*/
void imprimirSimetrico(No *raiz){
    if(raiz == NULL) return;
    imprimirSimetrico(raiz->esquerda);
    printf("%d\t",raiz->valor);
    imprimirSimetrico(raiz->direita);
}
//esq -> dir -> raiz
void imprimirPosFixado(No *raiz){
    if(raiz == NULL) return;
    imprimirPosFixado(raiz->esquerda);
    imprimirPosFixado(raiz->direita);
    printf("%d\t",raiz->valor);
}
//raiz -> esq -> dir
void imprimirPreFixado(No *raiz){
    if(raiz == NULL) return;
    printf("%d\t",raiz->valor);
    imprimirPreFixado(raiz->esquerda);
    imprimirPreFixado(raiz->direita);
}





/*
REMOÇÃO:
arvore:
               15
              /  \
             /    \
            /      \
           /        \
          5          \
         / \          \
        /   \          \
       /     \          \
      /       \          \
     1         \          \
    / \         \          \
   /   \         \          \
  /     \         \          \
 0       3        10          \
        / \       / \          \
       /   \     /   \          \
      2     4   /     \          \
               7       \          \
              / \      12          21
             /   \     /\          / \
            6     8   /  \        /   \
                     /    \      /     \
                    11    13    17      \
                               / \      30
                              /   \     / \
                             16   19   /   \
                                      28   32
                                     /  \
                                    26  29
                                   /
                                  25


1° caso: remoção de um nó folha: nó 11 por exemplo, nesse caso é só tirar da arvore

remover(raiz, 11)
1a it.
    -função remover é chamada recebendo a raiz que é 15 e o valor que é 11
    -verifica se raiz é null, falso
    -verifica se raiz->valor == valor, 15 == 11, falso
    -no else, verifica se valor < raiz->valor, 11 < 15, true, aqui a lógica é verificar em qual lado da árvore o valor está para fazer a recursão no lado certo, pois a árvore usa o principio de maiores a direita e menores a esquerda
    -chama função remover passando nó a ESQUERDA de 15 que é o nó 5
    -depois que a 2a it. terminou, raiz->esquerda = 5, pois foi retornado 5 da 2a it, ou seja o nó 15->direita que antes apontava pro nó 5 agora aponta para o nó 5, ou seja nada mudou tambem
    -por fim, retorna o nó 15 pra main() onde foi chamada a função remover(), ou seja retorna a mesma raiz que recebeu pois a raiz (15) não foi alterada

2a it.
    -função remover é chamada recebendo a raiz que é 5 e o valor que é 11
    -verifica se raiz é null, falso
    -verifica se raiz->valor == valor, 5 == 11, falso
    -no else, verifica se valor < raiz->valor, 11 < 5, falso
    -então chama função remover passando nó a DIREITA de 5 que é o nó 10
    -depois que a 3a it. terminou, raiz->direita = 10, pois foi retornado 10 da 3a it, ou seja o nó 5->direita que antes apontava pro nó 10 agora aponta para o nó 10, ou seja nada mudou tambem
    -por fim, retorna o nó 5 pra execução anterior

3a it.
    -função remover é chamada recebendo a raiz que é 10 e o valor que é 11
    -verifica se raiz é null, falso
    -verifica se raiz->valor == valor, 10 == 11, falso
    -no else, verifica se valor < raiz->valor, 11 < 10, falso
    -então chama função remover passando nó a DIREITA de 10 que é o nó 12
    -depois que a 4a it. terminou, raiz->direita = 12, pois foi retornado 12 da 4a it, ou seja o nó 10->direita que antes apontava pro nó 12 agora aponta para o nó 12, ou seja nada mudou
    -por fim, retorna o nó 10 pra execução anterior

4a it.
    -função remover é chamada recebendo a raiz que é 12 e o valor que é 11
    -verifica se raiz é null, falso
    -verifica se raiz->valor == valor, 12 == 11, falso
    -no else, verifica se valor < raiz->valor, 11 < 12, true
    -chama função remover passando nó a ESQUERDA de 12 que é o nó 11
    -depois que a 5a it. terminou, raiz->esquerda = NULL, pois foi retornado NULL da 5a it, ou seja o nó 12->esquerda que antes apontava pro nó 11 agora aponta pra NULL
    -por fim, retorna o nó 12 pra execução anterior

5a it.
    -função remover é chamada recebendo a raiz que é 11 e o valor que é 11
    -verifica se raiz é null, falso
    -verifica se raiz->valor == valor, 11 == 11, true
    -então verifica se a esquerda e direita da raiz são nulas ou seja se é um nó folha, true, 11 é um nó folha
    -libera da memória esse nó e retorna NULL pra execução anterior


----------------------------------------------------------------------------------------------------------------------------------------


2° caso: remoção de um nó que tem 1 filho: nesse caso o filho do nó a ser removido vai ocupar o seu lugar
remoção nó 26

remover(raiz, 26)
1a it.
    -função remover é chamada recebendo a raiz que é 15 e o valor que é 26
    -verifica se raiz é null, falso
    -verifica se raiz->valor == valor, 15 == 26, falso
    -no else, verifica se valor < raiz->valor, 26 < 15, falso
    -então chama função remover passando nó a DIREITA de 15 que é o nó 21, aqui a lógica é verificar em qual lado da árvore o valor está para fazer a recursão no lado certo, pois a árvore usa o principio de maiores a direita e menores a esquerda
    -depois que a 2a it. terminou, raiz->direita = 21, pois foi retornado 21 da 2a it, ou seja o nó 15->direita que antes apontava pro nó 21 agora aponta para o nó 21, ou seja nada mudou tambem
    -por fim, retorna o nó 15 pra main() onde foi chamada a função remover(), ou seja retorna a mesma raiz que recebeu pois a raiz (15) não foi alterada

2a it.
    -função remover é chamada recebendo a raiz que é 21 e o valor que é 26
    -verifica se raiz é null, falso
    -verifica se raiz->valor == valor, 21 == 26, falso
    -no else, verifica se valor < raiz->valor, 26 < 21, falso
    -então chama função remover passando nó a DIREITA de 21 que é o nó 30
    -depois que a 3a it. terminou, raiz->direita = 30, pois foi retornado 30 da 3a it, ou seja o nó 21->direita que antes apontava pro nó 30 agora aponta para o nó 30, ou seja nada mudou tambem
    -por fim, retorna o nó 21 pra execução anterior

3a it.
    -função remover é chamada recebendo a raiz que é 30 e o valor que é 26
    -verifica se raiz é null, falso
    -verifica se raiz->valor == valor, 30 == 26, falso
    -no else, verifica se valor < raiz->valor, 26 < 30, true
    -chama função remover passando nó a ESQUERDA de 30 que é o nó 28
    -depois que a 4a it. terminou, raiz->esquerda = 28, pois foi retornado 28 da 4a it, ou seja o nó 30->esquerda que antes apontava pro nó 28 agora aponta para o nó 28, ou seja nada mudou
    -por fim, retorna o nó 30 pra execução anterior

4a it.
    -função remover é chamada recebendo a raiz que é 28 e o valor que é 26
    -verifica se raiz é null, falso
    -verifica se raiz->valor == valor, 28 == 26, falso
    -no else, verifica se valor < raiz->valor, 26 < 28, true
    -chama função remover passando nó a ESQUERDA de 28 que é o nó 26
    -depois que a 5a it. terminou, raiz->esquerda = 25, pois foi retornado 25 da 5a it, ou seja o nó 28->esquerda que antes apontava pro nó 26 agora aponta pra 25, pois se trata do 2° caso: (remoção de um nó que tem 1 filho: nesse caso o filho do nó a ser removido vai ocupar o seu lugar)
    -por fim, retorna o nó 28 pra execução anterior

5a it.
    -função remover é chamada recebendo a raiz que é 26 e o valor que é 26
    -verifica se raiz é null, falso
    -verifica se raiz->valor == valor, 26 == 26, true
    -então verifica se a esquerda E direita da raiz são nulas ou seja se é um nó folha, falso
    -então no else, verifica se a esquerda OU A direita da raiz são nulas, ou seja se um dos lados é NULL, true
    -depois, sabendo que um lado é NULL e o outro não, verifica se é o nó da esq. ou dir. que é != NULL e salva em *aux o nó que 26 aponta, libera da memória o nó 26 e retorna o nó que 26 aponta (25) pra execução anterior


----------------------------------------------------------------------------------------------------------------------------------------


3° caso: remoção de um nó com 2 filhos: 
nesse caso o nó a ser removido deve ser substituido pelo nó mais a esquerda da subarvore da direita OU 
substituí-lo pelo nó mais a direita da subarvore da esquerda 


*/
No* remover(No *raiz, int valor){
    if(raiz == NULL){
        printf("valor não encontrado\n");
        return NULL;
    }
    else{
        if(raiz->valor == valor){

            if(raiz->esquerda == NULL && raiz->direita == NULL){
                free(raiz);
                return NULL;
            }
            else{

                if(raiz->esquerda == NULL || raiz->direita == NULL){
                    No *aux = NULL;
                    if(raiz->esquerda != NULL)
                        aux = raiz->esquerda;
                    else
                        aux = raiz->direita;
                    free(raiz);
                    return aux;
                }
                else{
                    No *aux = raiz->esquerda;
                    while (aux->direita != NULL){
                        aux = aux->direita;
                    }
                    raiz->valor = aux->valor;
                    aux->valor = valor;
                    raiz->esquerda = remover(raiz->esquerda, valor);
                    return raiz;
                }
            }
        }
        else{
            if(valor < raiz->valor){
                raiz->esquerda = remover(raiz->esquerda, valor);
            }
            else{
                raiz->direita = remover(raiz->direita, valor);
            }
            return raiz;
        }
    }
}

int main(){
    int op, valor;
    No *raiz = NULL;

    do{
        printf("\n0 - sair\n1 - inserir\n2 - imprimir\n3 - buscar\n4 - remover\n5 - tamanho\n");
        scanf("%d",&op);

        switch (op){
            case 1:
                printf("valor: ");
                scanf("%d",&valor);
                inserir(&raiz, valor);
                break;
            case 2:
                imprimirSimetrico(raiz);
                break;
            case 3:
                printf("valor: ");
                scanf("%d",&valor);
                printf("%d",buscar(raiz,valor));
                break;
            case 4:
                printf("valor: ");
                scanf("%d",&valor);
                raiz = remover(raiz, valor);
                break;
            case 5:
                printf("%d",getTamanho(raiz));
                break;
            default:
                break;
        }
    } while (op != 0);
    
}
