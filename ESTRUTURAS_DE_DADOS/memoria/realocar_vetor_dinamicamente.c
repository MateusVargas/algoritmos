#include <stdio.h>
#include <stdlib.h>

void imprimir(int *vet, int total){
	for(int i=0;i<total;i++){
		printf("%d\t",*(vet+i));
	}
}

int main(){
	int *vet, n, aumentar;
	printf("tamanho do vetor:");
	scanf("%d",&n);
	
	vet=(int *) malloc(n*sizeof(int *));
	
	if(vet==NULL){
		exit(0);
	}
	
	for(int i=0;i<n;i++){
		printf("vet[%d]:",i);
		scanf("%d",&vet[i]);
	}
	
	imprimir(vet,n);
	
	printf("\nadicionar quantos elementos:");
	scanf("%d",&aumentar);
	
	/*A função realloc aumenta ou diminui o tamanho de um vetor dinamicamente. Ela recebe o ponteiro para o vetor anterior e retorna o novo espaço alocado.*/
	vet=(int *)realloc(vet,(n+aumentar)*sizeof(int));
	
	if(vet==NULL){
		exit(0);
	}
	
	for(int i=n;i<n+aumentar;i++){
		printf("vet[%d]:",i);
		scanf("%d",&vet[i]);
	}
	
	imprimir(vet,n+aumentar);
	free(vet);//libera memoria
	
	return 0;
}
