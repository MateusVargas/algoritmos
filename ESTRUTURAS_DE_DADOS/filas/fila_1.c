/*usa-se um vetor pra armazenar os dados da fila*/
#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 100

struct fila{
	int itens[TAMANHO];
	int inicio;
	int fim;
};


//verifica se a fila esta vazia, se inicio e fim sao iguais entao esta vazia
int empty(struct fila *f){
	if(f->inicio==f->fim){
		return 1;
	}
	return 0;
}


//retorna o tamanho da fila
int tamanho_da_fila(struct fila *f){
	return f->fim;
}


//retorna o primeiro elemento da fila
int front(struct fila *ff){
	return ff->itens[0];
}


//adiciona um elemento no fim da fila
void adicionar(struct fila *f,int valor){
	if(f->fim+1 >= TAMANHO){
		printf("\nnao e possivel inserir mais itens");
		exit(0);
	}
	else{
		f->itens[f->fim]=valor;
		f->fim++;
	}
}

//retira o elemento da posicao[0] da fila
void remover(struct fila *f){
	if(empty(f)){
		printf("\nfila vazia");
		exit(0);
	}
	for(int i=0;i<(f->fim);i++){
		f->itens[i]=f->itens[i+1];
	}
	f->fim--;
}


void mostrar_fila(struct fila *f){
	printf("\nelementos da fila:\n");
	for(int i=0;i<(f->fim);i++){
		printf("%d\t",f->itens[i]);
	}
	printf("\n");
}

int main(){
	struct fila fila;
	fila.inicio=0;
	fila.fim=0;
	
	adicionar(&fila, 1);
	adicionar(&fila, 2);
	adicionar(&fila, 3);
	mostrar_fila(&fila);
	
	printf("\nfila vazia: %d",empty(&fila));
	printf("\ntamanho da fila: %d",tamanho_da_fila(&fila));
	printf("\nprimeiro elemento da fila: %d\n",front(&fila));
	
	remover(&fila);
	mostrar_fila(&fila);
	
	printf("\nprimeiro elemento da fila: %d\n",front(&fila));
	
	return 0;
}
