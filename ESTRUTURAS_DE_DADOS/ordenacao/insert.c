/*inicialmente, ela ordena os dois primeiros membros da lista, em seguida o algoritmo insere o terceiro membro na sua posição ordenada com relação aos dois primeiros membros. Na sequência, é inserido o quarto elemento na lista dos três primeiros elementos e o processo continua até que toda a lista esteja ordenada.
*/
#include <stdio.h>

#define tam 5

void ordenar(int vet[tam]){
	int aux,j;
	for(int i=1;i<tam;i++){
		aux=vet[i];
		for(j=i-1;(j>=0)&&(vet[j]>aux);j--){
			vet[j+1]=vet[j];
		}
		vet[j+1]=aux;
	}
}

int main(){
	int vet[tam]={13,7,5,1,4};
	ordenar(vet);
	
	printf("vetor ordenado\n");
	for(int i=0;i<tam;i++){
		printf("%d\t",vet[i]);
	}
	return 0;
}

/*
vet={13,7,5,1,4}

iteracoes
-i=1
	aux=7
	for do j:
		j=0
		j>=0 && vet[j]>aux (13>7) true
		vet[j+1]=vet[j] -> vet[1]=vet[0] //vet[1]=13
		vet={13,13,5,1,4}
		
		j=-1
		j>=0 && vet[j]>aux false, sai do for	
	depois do for do j:
	vet[j+1]=aux //vet[0]=7, j vale -1 depois do for
	vet={7,13,5,1,4}

-i=2
	aux=5
	for do j:
		j=1
		j>=0 && vet[j]>aux (13>5) true
		vet[j+1]=vet[j] -> vet[2]=vet[1] //vet[2]=13
		vet={7,13,13,1,4}
			
		j=0
		j>=0 && vet[j]>aux (7>5) true
		vet[j+1]=vet[j] -> vet[1]=vet[0] //vet[1]=7
		vet={7,7,13,1,4}
		
		j=-1
		j>=0 && vet[j]>aux false, sai do for		
	depois do for do j:
	vet[j+1]=aux //vet[0]=5
	vet={5,7,13,1,4}
	
-i=3
	aux=1
	for do j:
		j=2
		j>=0 && vet[j]>aux (13>1) true
		vet[j+1]=vet[j] -> vet[3]=vet[2] //vet[3]=13
		vet={5,7,13,13,4}
		
		j=1
		j>=0 && vet[j]>aux (7>1) true
		vet[j+1]=vet[j] -> vet[2]=vet[1] //vet[2]=7
		vet={5,7,7,13,4}
		
		j=0
		j>=0 && vet[j]>aux (5>1) true
		vet[j+1]=vet[j] -> vet[1]=vet[0] //vet[1]=5
		vet={5,5,7,13,4}
		
		j=-1
		j>=0 && vet[j]>aux false, sai do for	
	depois do for do j:
	vet[j+1]=aux //vet[0]=1
	vet={1,5,7,13,4}
	
-i=4
	aux=4
	for do j:
		j=3
		j>=0 && vet[j]>aux (13>4) true
		vet[j+1]=vet[j] -> vet[4]=vet[3] //vet[4]=13
		vet={1,5,7,13,13}
		
		j=2
		j>=0 && vet[j]>aux (7>4) true
		vet[j+1]=vet[j] -> vet[3]=vet[2] //vet[3]=7
		vet={1,5,7,7,13}
		
		j=1
		j>=0 && vet[j]>aux (5>4) true
		vet[j+1]=vet[j] -> vet[2]=vet[1] //vet[2]=5
		vet={1,5,5,7,13}
		
		j=0
		j>=0 && vet[j]>aux (1>4) falso, sai do for
	depois do for do j:
	vet[j+1]=aux //vet[1]=4
	vet={1,4,5,7,13}
*/
