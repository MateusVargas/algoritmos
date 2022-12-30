#include <stdio.h>
#include <stdlib.h>

void alocar(int ***p,int x,int y){
	*p=(int **)malloc(x*sizeof(int*));
	if(*p==NULL){
		exit(0);
	}
	for(int i=0;i<y;i++){
		(*p)[i]=(int*)malloc(y*sizeof(int));
		if((*p)[i]==NULL){
			exit(0);
		}
	}
	//(*p): nesse caso de ponteiro para ponteiro em matrizes deve-se colocar entre parenteses o ponteiro para cada dimensao da matriz que se esta manipulando
}

int main(){
	int **p;//declaracao de uma matriz com 2 dimensoes
	
	alocar(&p,4,5);
	//a funcao recebe o endereco de memoria do ponteiro
	//por isso alem dos 2 asteriscos por ser um 
	//ponteiro pra uma matriz, precisa de mais um
	//para indicar que se esta recebendo um ponteiro
	//pois foi passado pra funcao um endereco de memoria
	
	for(int i=0;i<4;i++){
		for(int j=0;j<5;j++){
			p[i][j]=i+j;
		}
	}
	
	for(int i=0;i<4;i++){
		for(int j=0;j<5;j++){
			printf("%d\t",p[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
