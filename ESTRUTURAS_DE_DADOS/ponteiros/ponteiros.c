/*
Fazer um programa em C que implemente o algoritmo para acessar elementos de vetores via ponteiros. Crie uma função: imprime_array_elemento(int *aArray, int iElemento);
*/

#include <stdio.h>
#include <stdlib.h>

void teste(int a){
	printf("a:%d\n",a);
}

void this(int *a){
	*a=78;
	//vai na memoria e altera o valor da variavel que o ponteiro aponta, por isso a mudanca vai refletir fora da funcao tambem
}

//acessa elementos do vetor atraves de ponteiros
void imprime_array_elemento(int *aArray,int i){
	printf("\n%d",*(aArray+i));
}

int main(){
	int *pont,c=47,**p2;
	float *pf;
	pont = &c; //ponteiro guarda o endereco da variavel
	p2 = &pont; //p2 e um ponteiro que aponta pra outro ponteiro por isso tem um * a mais
	
	pf++; //nesse caso sera somado no ponteiro a qtd de enderecos de memoria relativos ao tipo do ponteiro

	(*pont)++; //incrementa valor da variavel 'c'
	printf("c: %d\n\n",c);//48
	
	//passando pra funcao o valor da variavel que o ponteiro aponta, entao na funcao se recebe apenas um parametro int normal
	teste(*pont);
	
	printf("*pont: %d\n",*pont);
	//valor da variavel que o ponteiro aponta
	
	printf("pont: %d\n",pont);
	//endereco da variavel que o ponteiro aponta
	
	printf("&pont: %d\n",&pont);
	//endereco de memoria do ponteiro
	
	printf("**p2: %d",**p2);
	//valor da variavel 'c', pois p2 aponta pro ponteiro 'pont' que aponta pra variavel 'c'
	
	int g=9;
	printf("\n\n%d",g);
	
	this(&g);
	//passado pra funcao o endereco de memoria da variavel 'g' entao na funcao esse parametro deve ser recebido como um ponteiro
	
	printf("\n%d",g);
	
	int vet[5]={1,5,3,6,2};
	
	for(int i=0;i<5;i++){
		imprime_array_elemento(&vet,i);
	}
	return 0;
}
