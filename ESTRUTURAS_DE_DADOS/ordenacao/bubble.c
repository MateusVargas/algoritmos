#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 5

void ordenar(int vet[5]){
	int aux;
	for(int i=1;i<TAMANHO;i++){
		for(int j=TAMANHO-1;j>=i;j--){
			if(vet[j-1]>vet[j]){
				aux=vet[j-1];
				vet[j-1]=vet[j];
				vet[j]=aux;
			}
		}
	}
}

int main(void) { 
	int vet[TAMANHO]={10,9,7,13,5};
	ordenar(vet);
	
	printf("vetor ordenado:\n"); 
	for(int i=0;i<TAMANHO;i++){ 
		printf("%d\t",vet[i]); 
	}
	return 0; 
}

/*
iteracoes:
- i=1
for do j:
	j=4
	se vet[3]>vet[4] (13>5) troca 13 com 5
	vet=10,9,7,5,13
	
	j=3
	se vet[2]>vet[3] (7>5) troca 7 com 5
	vet=10,9,5,7,13
	
	j=2
	se vet[1]>vet[2] (9>5) troca 9 com 5
	vet=10,5,9,7,13
	
	j=1
	se vet[0]>vet[1] (10>5) troca 10 com 5
	vet=5,10,9,7,13

- i=2:
for do j:
	j=4
	se vet[3]>vet[4] (7>13) false
	
	j=3
	se vet[2]>vet[3] (9>7) troca 9 com 7
	vet=5,10,7,9,13
	
	j=2
	se vet[1]>vet[2] (10>7) troca 10 com 7
	vet=5,7,10,9,13
	
-i=3
for do j:
	j=4
	se vet[3]>vet[4] (9>13) falso
	
	j=3
	se ve[2]>vet[3] (10>9) troca 10 com 9
	vet=5,7,9,10,13
	
-i=4
for do j:
	j=4
	se vet[3]>vet[4] (10>13) falso
	
*/
