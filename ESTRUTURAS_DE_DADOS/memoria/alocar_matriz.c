#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	srand(time(0));
	
	//declarando matriz [2][3], nesse caso deve ser um ponteiro para ponteiro
	int **mat;
	mat=(int *)calloc(2,sizeof(int));
	//alocando as 2 linhas, a funcao calloc multiplica a qtd de elementos pelo tamanho que o tipo de dado ocupa. int=4bytes
	
	if(mat==NULL){
		exit(0);
	}
	
	for(int i=0;i<3;i++){
		mat[i]=(int*) malloc(3*sizeof(int));
		//alocando as 3 colunas
		
		if(mat[i]==NULL){
			exit(0);
		}
	}
	
	//preencher e mostrar matriz normalmente
	for(int i=0;i<2;i++){
		for(int j=0;j<3;j++){
			mat[i][j]=rand()%10;
			printf("%d\t",mat[i][j]);
		}
		printf("\n");
	}
	
	//liberando da memoria
	for(int i=0;i<2;i++){
		free(mat[i]);//deve liberar memoria primeiro das linhas, e depois de toda a matriz
	}
	free(mat);
}
