#include <stdio.h>
#include <stdlib.h>

int main(){
	//declarando vetor de 10 elementos atraves de ponteiros
	int *vet;
	vet = (int *)malloc(10*sizeof(int*));
	
	if(vet==NULL){
		printf("erro de alocacao de memoria");
	}//malloc retorna NULL caso tenha erro de alocacao
	
	//malloc retorna um endereco de memoria, ou seja, um ponteiro do tipo void, por isso e preciso converter pro tipo do ponteiro, no caso int (int *), essa funcao recebe a qtd de memoria pra alocacao, no caso o vetor tera 10 elementos por isso o numero 10, sizeof(int *) retorna quantos bytes um tipo de dado ocupa na memoria, int ocupa 4 bytes entao 10x4=40bytes
	
	//preenchendo e exibindo normalmente
	for(int i=0;i<10;i++){
		printf("v[%d]=",i);
		scanf("%d",&vet[i]);
	}
	
	for(int i=0;i<10;i++){
		printf("%d\t",vet[i]);
	}
	
	return 0;
}
