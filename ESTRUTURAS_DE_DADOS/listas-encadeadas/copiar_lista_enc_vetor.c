#include <stdio.h>
#include <stdlib.h>

struct lista{
	int num;
	struct lista *prox;
};
typedef struct lista Lista;

Lista* inserir_inicio(Lista *inicio,int num){
	Lista *novo=(Lista*)malloc(sizeof(Lista));
	novo->num=num;
	novo->prox=inicio;
	return novo;
}

int tamanho(Lista *inicio){
	if(inicio==NULL){
		return 0;
	}
	return 1+tamanho(inicio->prox);
}

int* copiar(int *vet,int i,Lista *inicio){
	if(inicio==NULL){
		return vet;
	}
	*(vet+i)=inicio->num;
	return copiar(vet,i+1,inicio->prox);
}

int main(){
	Lista *inicio=NULL;
	inicio=inserir_inicio(inicio,4);
	inicio=inserir_inicio(inicio,3);
	inicio=inserir_inicio(inicio,2);
	inicio=inserir_inicio(inicio,1);
	int n, *vet;
	n=tamanho(inicio);
	vet=(int*)malloc(n*sizeof(int));
	vet=copiar(vet,0,inicio);
	for(int i=0;i<n;i++)
		printf("%d\t",*(vet+i));
	return 0;
}
