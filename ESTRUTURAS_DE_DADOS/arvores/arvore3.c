#include <stdio.h>
#include <stdlib.h>

/*
				50
			   /  \
			  /	   \
			 /		\
		    30	    70
		   /  \		  \
		  /	   \	   \
	     10	    40	    80
	           /  \     / \
              35  45   75 90
			   \
               37
*/

typedef struct arvore{
    int num;
    struct arvore *esq;
    struct arvore *dir;
} Arvore;


Arvore* adicionar(Arvore *raiz, int valor){
    if(raiz == NULL){
        Arvore *no = (Arvore*) malloc(sizeof(Arvore));
        no->num = valor;
        no->esq = NULL;
        no->dir = NULL;
        return no;
    }
    else if(raiz->num > valor){
        raiz->esq = adicionar(raiz->esq, valor);
    }
    else{
        raiz->dir = adicionar(raiz->dir, valor);
    }
    return raiz;
}


void imprime(Arvore *raiz){
    if(raiz == NULL) return;
    printf("%d",raiz->num);
    printf("\n%d -> esq: ",raiz->num);
    imprime(raiz->esq);
    printf("\n%d -> dir: ",raiz->num);
    imprime(raiz->dir);
}







/*
REMOÇÃO 
* a própria função remover() ajusta os apontamentos dos nós através da recursão

3° caso: remoção de um nó com 2 filhos: 
nesse caso o nó a ser removido deve ser substituido pelo nó mais a esquerda da subarvore da direita OU 
substituí-lo pelo nó mais a direita da subarvore da esquerda 


remover(raiz, 50)
1a it.
    -função remover é chamada recebendo a raiz que é 50 e o valor que é 50
    -verifica se raiz é null, falso
    -verifica se raiz->valor == valor, 50 == 50, true
    -então verifica se a esquerda E direita da raiz são nulas, ou seja, se é um nó folha, falso
    -então no else if, verifica se a esquerda OU A direita da raiz são nulas, ou seja, se um dos lados é NULL, falso
    
    -cai no else, procura filhos a direita na subarvore da esquerda
    -achou o 45 como o mais direita da subarvore da esquerda, então não entra no if(filho == NULL)
    -entra então no else.
    -faz anterior->dir = filho->esq, ou seja, 40->dir = 45->esq
    -CHAMA 2a it: faz filho->esq = remover(raiz->esq , valor); que significa: 45->esq = remover(50->esq)
    -recebe o retorno da 2a it. que é 30, e faz filho->dir = raiz->dir que significa 45->dir = 50->dir
    -agora o nó 45 aponta pra 30 na esquerda e pra 70 na direita;
    -depois retorna o nó 45 pra main()

2a it.
    -função remover é chamada recebendo a raiz que é 30 e o valor que é 50
    -verifica se raiz é null, falso
    -verifica se raiz->valor == valor, 30 == 50, falso
    -no else if, verifica se raiz->num > valor, (30 > 50), falso
    -cai no else: CHAMA 3a it.  raiz->dir = remover(raiz->dir, valor), que significa 30->dir = remover(30->dir, 50)
    -recebe o retorno da 3a it. que é 40, então 30->dir = 40;
    -retorna 30 pra execução anterior;
    
3a it.
    -função remover é chamada recebendo a raiz que é 40 e o valor que é 50
    -verifica se raiz é null, falso
    -verifica se raiz->valor == valor, 40 == 50, falso
    -no else if, verifica se raiz->num > valor, (40 > 50), falso
    -cai no else: CHAMA 4a it  raiz->dir = remover(raiz->dir, valor), que significa 40->dir = remover(40->dir, 50)    
    -recebe o retorno da 4a it. que é NULL, então 40->dir = NULL;
    -retorna 40 pra execução anterior;
    
4a it.
    -função remover é chamada recebendo a raiz que é NULL (ver linha 77, 40 que apontava pro 45 agora aponta para os elementos a esquerda do 45), e o valor que é 50
    -verifica se raiz é null, true retorna NULL

*/
Arvore* remover(Arvore* raiz, int valor){
    if(raiz == NULL) return NULL;
    if(raiz->num == valor){
        printf("\nachou %d\n", valor);
        if(raiz->esq == NULL && raiz->dir == NULL){
            free(raiz);
            return NULL;
        }
        else if(raiz->esq == NULL || raiz->dir == NULL){
            Arvore *filho = NULL;
            if(raiz->esq != NULL){
                filho = raiz->esq;
            }else{
                filho = raiz->dir;
            }
            free(raiz);
            return filho;
        }
        else{
            Arvore *filho = NULL;
            Arvore *anterior = NULL;
            
            //procura filho mais a direita na sub-arvore esquerda
            Arvore *iterator = raiz->esq;

            while(iterator->dir != NULL){
                anterior = iterator;
            	filho = iterator->dir;
            	iterator = iterator->dir;
            }
            
            //se não tiver filhos a direita na sub-arvore da esquerda, então procura filho mais a esquerda na sub-arvore direita
            if(filho == NULL){
            	iterator = raiz->dir;
	            while(iterator->esq != NULL){
	                anterior = iterator;
	            	filho = iterator->esq;
	            	iterator = iterator->esq;
	            }
	            
	            /*
	            se achou um filho mais a esquerda na sub-arvore da direita, então faz o pai desse filho (anterior), apontar pro filho a direita dele, 
	            porque esse filho é o elemento mais a esquerda então obviamente ele não vai ter filhos a esquerda.
	            E faz o filho receber os apontamentos do elemento a ser removido
	            */
	            if(filho != NULL){
	                anterior->esq = filho->esq;
	                filho->esq = remover(raiz->esq , valor);
    	            filho->dir = raiz->dir;
	            }
            }
            else{
                /*
	            se achou um filho mais a direita na sub-arvore da esquerda, então faz o pai desse filho (anterior), apontar pro filho a esquerda dele,
	            porque esse filho é o elemento mais a direita então obviamente ele não vai ter filhos a direita.
	            E faz o filho receber os apontamentos do elemento a ser removido
	            */
	            anterior->dir = filho->esq;
              filho->esq = remover(raiz->esq , valor);
	            filho->dir = raiz->dir;
            }

            /*se não tem filhos a direita na sub-arvore da esquerda e tbm não tem filhos a esquerda na sub-arvore da direita, 
            então escolhe o filho da esquerda do nó a ser removido pra ficar no lugar dele*/
            if(filho == NULL){
                filho = raiz->esq;
                filho->dir = raiz->dir;
            }
            free(raiz);
            return filho;
        }
    }
    else if(raiz->num > valor){
        raiz->esq = remover(raiz->esq, valor);
    }
    else{
        raiz->dir = remover(raiz->dir, valor);
    }
    return raiz;
}

int main(){
    Arvore *raiz = NULL;
    raiz = adicionar(raiz, 50);
    raiz = adicionar(raiz, 30);
    raiz = adicionar(raiz, 10);
    raiz = adicionar(raiz, 40);
    raiz = adicionar(raiz, 70);
    raiz = adicionar(raiz, 80);
    raiz = adicionar(raiz, 75);
    raiz = adicionar(raiz, 90);
    raiz = adicionar(raiz, 35);
    raiz = adicionar(raiz, 45);
    raiz = adicionar(raiz, 66);
    raiz = adicionar(raiz, 37);
    //raiz = adicionar(raiz, 15);
    imprime(raiz);
    
    raiz = remover(raiz, 50);
    imprime(raiz);
    
    //raiz = remover(raiz, 30);
    //imprime(raiz);
    
    //raiz = adicionar(raiz, 40);
    //imprime(raiz);
    
    //raiz = remover(raiz, 66);
    //imprime(raiz);
    return 0;
}
