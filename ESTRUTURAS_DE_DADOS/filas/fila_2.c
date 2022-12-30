/*Se uma fila contiver 1000 ou 2000 elementos, cada elemento retirado da fila provocará o deslocamento de todos os demais elementos. A operação de remoção de um item na fila deveria logicamente trabalhar somente com aquele elemento, permanecendo os demais elementos em suas posições originais. 
A solução para o problema é definir o vetor como um circulo, em vez de uma linha reta. Neste caso, os elementos são inseridos como numa fila reta, e 
a remoção de um elemento da fila não altera os demais elementos da fila. Com o conceito de fila circular, ao chegar ao final da fila, o ponteiro de controle da fila vai imediatamente para o início da fila novamente (se este estiver vago).*/

//Implementando fila como se ela fosse um circulo

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10

struct fila{
	int itens[TAMANHO];
	int inicio;
	int fim;
};


int empty(struct fila *f){
	if(f->inicio==f->fim){
		return 1;
	}
	return 0;
}


void adicionar(struct fila *f, int num){
	/* Inversão das posições dos ponteiros. Se o final do vetor já foi alcançado, então retorna-se ao início do vetor
	so se pode adicionar no final, se a ultima
	posicao valida ja tiver ocupada vai pra posicao[0]
	pois e um circulo, se o inicio estiver na 
	posicao[0] vai dar conflito significando que nao tem mais espaco*/
	if(f->fim == TAMANHO-1) { 
		f->fim=0; 
	} 
	else { 
		f->fim++;
	} 
	if(f->fim == f->inicio){ 
		printf("\nEstouro da fila\n"); 
		exit(1); 
	} 
	f->itens[f->fim]=num;
}


int tamanho(struct fila *f){
	//se o final da fila ainda não alcançou o final do vetor
	/*ex: vetor de 10 elementos, e o final da fila esta na posicao 6, supondo que ja foi removido um elemento da fila entao o inicio da fila sera na posicao[1] (pois uma fila so se pode tirar elementos do inicio), 6-1=5, pois se esta trabalhando com uma fila circular entao se for removido um elemento do inicio, os demais nao serao alocados uma posicao pra tras*/
	
	if(f->inicio <= f->fim){ 
		return f->fim - f->inicio;
		//então o tamanho da fila é o final da fila menos o início da fila
	}
	 
	/*se não, quer dizer que o ponteiro de final da fila já alcançou o final do vetor e foi reposicionado para o início do vetor novamente (pois esta se trabalhando com fila circular), 
	  então o tamanho da fila é a quantidade de itens que ainda restam até chegar ao final do vetor somando itens que estão no início do vetor */ 
	
	return f->fim + f->inicio;
}


int front(struct fila *f){
	return f->itens[f->inicio+1];
}


int remover(struct fila *f){
	if(empty(f)){
		printf("fila vazia");
		exit(0);
	}
	
	/*
	so se pode remover do inicio, entao se o inicio
	for a ultima posicao valida, entao essa e retirada
	e o inicio vai pra posicao seguinte que e a zero,
	pois e um circulo, senao for a ultima posicao, o inicio e incrementado pra posicao seguinte
	*/
	if(f->inicio==TAMANHO-1){
		f->inicio=0;
	}
	else{
		f->inicio++;
	}
	return f->itens[f->inicio];
}


void exibir(struct fila *f){
	
	printf("\n\nfila: inicio: %d, fim: %d\n",f->inicio,f->fim);
	if(f->inicio <= f->fim){
		/*
		se inicio for menor que fim, ex: inicio=2 e fim=6 por exemplo, exibe normalmente
		*/
		int inicio=f->inicio;
		if(f->inicio==-1){
			inicio++;
		}
		
		for(int i=inicio;i<=f->fim;i++){
			printf("itens[%d]=%d\n",i,f->itens[i]);
		}
	}
	else{
		/*
		ex: inicio=4,fim=3, entao comeca exibindo os
		elementos da posicao 4,5,6... ate TAMANHO-1 e depois exibe os elementos 0,1 e 2, faz uma volta pois e um circulo
		*/
		
		int i=f->inicio;
		int sair=0;
		while(sair==0){
			if(i==f->fim){
				sair=1;
			}
			printf("itens[%d]=%d\n",i,f->itens[i]);
			i++;
			if(i==TAMANHO){
				i=0;
			}
		}
	}
	printf("\n");
}


int main(){
	struct fila *fila;
	fila=(struct fila*)malloc(sizeof(struct fila*));
	
	fila->inicio = -1;
	fila->fim = -1;
	
	adicionar(fila,1);
	adicionar(fila,2);
	adicionar(fila,3);
	adicionar(fila,4);
	adicionar(fila,5);
	adicionar(fila,6);
	adicionar(fila,7);
	adicionar(fila,8);
	adicionar(fila,9);
	
	exibir(fila);
	
	printf("\nTamanho da fila %d", tamanho(fila));
	printf("\nPrimeiro da fila %d", front(fila));
	printf("\nTirando da fila %d", remover(fila));
	printf("\nTirando da fila %d", remover(fila));
	printf("\nTirando da fila %d\n", remover(fila));
	
	exibir(fila);
	
	printf("\nPrimeiro da fila %d", front(fila));
	printf("\nTirando da fila %d", remover(fila));
	printf("\nTamanho da fila %d\n", tamanho(fila));
	
	exibir(fila);
	
	adicionar(fila,10);
	adicionar(fila,11);
	adicionar(fila,12);
	
	exibir(fila);
	
	printf("\nTamanho da fila %d", tamanho(fila));
	printf("\nPrimeiro da fila %d\n", front(fila));
	
	exibir(fila);
	
	adicionar(fila,13);
	exibir(fila);
	
	//adicionar(fila,67);
	printf("\nTirando da fila %d", remover(fila));
	adicionar(fila,67);
	
	exibir(fila);
	
	printf("\ntamanho da fila: %d",tamanho(fila));
	
	return 0;
}
