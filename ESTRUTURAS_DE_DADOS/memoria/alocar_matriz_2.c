#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//retorna um ponteiro para uma matriz
//por isso o uso de 2 asteriscos
//pois uma matriz e um ponteiro para ponteiro
int** aloca(int i,int j){
	int **p;
	p=(int *)malloc(i*sizeof(int*));
	
	if(p==NULL){
		exit(0);
	}
	
	for(int a=0;a<i;a++){
		p[a]=(int *)malloc(j*sizeof(int));
		if(p[a]==NULL){
			exit(0);
		}
	}
	
	return p;
}

//** indica que recebe uma matriz
void liberar_memoria(int **p,int i,int j){
	for(int v=0;v<i;v++){
		free(p[v]);//libera colunas
	}
	free(p);//libera linhas
}

void ler(int **p,int i,int j){
	for(int x=0;x<i;x++){
		for(int y=0;y<j;y++){
			p[x][y]=rand()%100+1;
		}
	}
}

void imprimir(int **p,int i,int j){
	for(int k=0;k<i;k++){
		for(int l=0;l<j;l++){
			printf("%d\t",p[k][l]);
		}
		printf("\n");
	}
}

int main(){
	srand(time(NULL));
	
	int **p;
	int **p2;
	
	p=aloca(3,2);
	ler(p,3,2);
	
	p2=aloca(2,3);
	ler(p2,2,3);
	
	imprimir(p,3,2);
	
	printf("\n");
	
	imprimir(p2,2,3);
	
	liberar_memoria(p,3,2);
	liberar_memoria(p2,2,3);
	
	return 0;
}


/*
OUTRA FORMA:

﻿#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//retorna um ponteiro para uma matriz
//por isso o uso de 2 asteriscos
//pois uma matriz e um ponteiro para ponteiro
int** aloca(int i,int j){
	int **p;
	p=(int *)malloc(i*sizeof(int*));
	
	if(p==NULL){
		exit(0);
	}
	
	for(int a=0;a<i;a++){
		p[a]=(int *)malloc(j*sizeof(int));
		if(p[a]==NULL){
			exit(0);
		}
	}
	
	return p;
}

//** indica que recebe uma matriz
void liberar_memoria(int **p,int i,int j){
	for(int v=0;v<i;v++){
		free(p[v]);//libera colunas
	}
	free(p);//libera linhas
}

void ler(int **p,int i,int j){
	for(int x=0;x<i;x++){
		for(int y=0;y<j;y++){
			p[x][y]=rand()%100+1;
		}
	}
}

void imprimir(int ***p,int i,int j){
	for(int k=0;k<i;k++){
		for(int l=0;l<j;l++){
			printf("%d\t",(*p)[k][l]);
		}
		printf("\n");
	}
}

int main(){
	srand(time(NULL));
	
	int **p;
	int **p2;
	
	p=aloca(3,2);
	ler(p,3,2);
	
	p2=aloca(2,3);
	ler(p2,2,3);
	
	imprimir(&p,3,2);
	
	printf("\n");
	
	imprimir(&p2,2,3);
	
	liberar_memoria(p,3,2);
	liberar_memoria(p2,2,3);
	
	return 0;
}
*/





