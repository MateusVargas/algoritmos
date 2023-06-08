/*A ordenação por seleção consiste em trocar o menor elemento (ou maior) de uma lista com o elemento posicionado no início da lista, depois o segundo menor elemento para a segunda posição e assim sucessivamente com os (n - 1) elementos restantes, 
até os últimos dois elementos.

ideia e achar a posicao do menor valor e colocar o valor dessa posicao na 1a posicao do vetor, o segundo menor na 2a. posicao e assim por diante, ou achar o maior valor e move-lo pro final, o segundo maior pra penultimo e assim por diante*/

#include <stdio.h>
#include <stdlib.h>

void ordena(int vet[5]){
	int aux,indice_menor;
	
	for(int i=0;i<5-1;i++){
		indice_menor=i;
		for(int j=i+1;j<5;j++){
			if(vet[j]<vet[indice_menor]){
				indice_menor=j;
			}
		}
		aux=vet[i];
		vet[i]=vet[indice_menor];
		vet[indice_menor]=aux;
	}
	
}

int main(){
	int vet[5]={13,7,5,1,4};
	ordena(vet);
	
	printf("vetor ordenado\n");
	for(int i=0;i<5;i++){
		printf("%d\t",vet[i]);
	}
	return 0;
}

/*iteracoes
-i=0
	indice_menor=0
	for do j:
		j=1
		se vet[1]<vet[0] (7<13)
		indice_menor=1
	
		j=2
		se vet[2]<vet[1] (5<7)
		indice_menor=2
	
		j=3
		se vet[3]<vet[2] (1<5)
		indice_menor=3
	
		j=4
		se vet[4]<vet[3] (4<1) falso
 	depois do for do j:
	troca vet[0] com vet[3]	(13 com 1)
	vet=1,7,5,13,4

i=1
	indice_menor=1
	for do j:
		j=2
		se vet[2]<vet[1] (5<7)
		indice_menor=2
	
		j=3
		se vet[3]<vet[2] (13<5) falso
	
		j=4
		se vet[4]<vet[2] (4<5)
		indice_menor=4
	depois do for do j:
	troca vet[1] com vet[4] (7 com 4)
	vet=1,4,5,13,7
	
-i=2
	indice_menor=2
	for do j:
		j=3
		se vet[3]<vet[2] (13<5) falso
	
		j=4
		se vet[4]<vet[2] (7<5) falso
	
	depois do for do j:
	vet=1,4,5,13,7

-i=3
	indice_menor=3
	for do j:
		j=4
		se vet[4]<vet[3] (7<13)
		indice_menor=4
	depois do for do j:
	troca vet[3] com vet[4] (13 com 7)
	vet=1,4,5,7,13
*/
