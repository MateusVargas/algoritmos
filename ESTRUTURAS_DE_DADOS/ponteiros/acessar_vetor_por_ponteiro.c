/*
Fazer um programa em C que implemente o algoritmo para acessar elementos de vetores via ponteiros. 
Crie uma função: imprime_array_elemento(int *aArray, int iElemento);
*/
#include <stdio.h>
#include <stdlib.h>

void this(int *a){
	*a=78;
}

void imprime_array_elemento(int *aArray,int i){
	printf("\n%d",*(aArray+i));
}

int main(){
	int *pont,c=47,**p2;
	pont = &c;
	p2 = &pont;
	
	printf("%d\n",*pont);
	printf("%x\n",pont);
	printf("%d",**p2);
	
	int g=9;
	printf("\n\n%d",g);
	this(&g);
	printf("\n%d",g);
	
	int vet[5]={1,5,3,6,2};
	
	for(int i=0;i<5;i++){
		imprime_array_elemento(&vet,i);
		//imprime_array_elemento(vet,i); //sem o & tambem funciona, pois vetores sao ponteiros e não precisa passar o endereço
	}
	return 0;
}