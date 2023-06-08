/*baseia-se na idéia simples de partir um vetor(ou lista a ser ordenada)em dois subvetores, de tal maneira que todos os elementos do primeiro vetor sejam menores ou iguais a todos os elementos do segundo vetor. Estabelecida a divisão, o proble-
ma estará resolvido, pois aplicando recursivamente a mesma técnica a cada um dos subvetores, o vetor estará ordenado ao se obter um subvetor de apenas 1 
elemento. 

- passos para ordenar uma sequência S qualquer: 
1. Seleciona um elemento do conjunto S. O elemento selecionado (p) é chamado de pivô. 
2. Retire p de S e particione os elementos restantes de S em 2 seqüências distintas, L e G.
3. A partição L deverá ter os elementos menores ou iguais ao elemento pivô p, enquanto que a partição G conterá os elementos maiores ou iguais a p. 
4. Aplique novamente o algoritmo nas partições L e G.

Para organizar os itens, tais que os menores fiquem na primeira partição e os maiores na segunda partição, basta percorrer o vetor do início para o fim e do 
fim para o início simultaneamente, trocando os elementos. Ao encontrar-se no meio da lista, tem-se a certeza de que os menores estão na primeira partição e os maiores na segunda partição.

A escolha do elemento pivô é arbitrária, pegar o elemento do meio é apenas uma das possíveis implementações no algoritmo. Outro método para a escolha do pivô consiste em escolher três (ou mais) elementos aleatoriamente da lista, ordenar esta sublista e pegar o elemento médio
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordenar(int *vet, int inicio,int fim){
	int i=inicio, j=fim; 
	int pivo, aux; 
	pivo = vet[(inicio+fim)/2];
	/*
	pegando elemento do meio pra ser o pivo
	0+11/2 = 5, pivo=vet[5] //pivo=4
	*/
	
	/*particao das listas*/
	do{
	
		/*procura elementos maiores que o pivô na primeira parte*/
		while(vet[i]<pivo && i<fim){ 
			i++; 
		}
		
		/*procura elementos menores que o pivô na segunda parte*/
		while(pivo<vet[j] && j>inicio){ 
			j--; 
		}
		
		if(i<=j){ 
			/* processo de troca (ordenação) */
			aux = vet[i];
			vet[i] = vet[j];
			vet[j] = aux;
			
			i++;
			j--;
		} 
	}while(i<=j);
	
	//printf("ini%d j%d\n",inicio,j);
	//printf("i%d f%d\n",i,fim);
	
	/* chamada recursiva */
	if(inicio<j){ 
		ordenar(vet,inicio,j);
		//printf("e");
	}
	if(i<fim){
		ordenar(vet,i,fim);
		//printf("4"); 
	}
	
	return;
}

int main(){
	//char vet[]="3490bn09685lnv 3-49580bgojfog39458=9ugkj n098=526yh";
	int vet[12]={7,1,3,9,8,4,2,7,4,2,3,5};
	
	//passa-se as posicoes do inicio e fim do vetor
	ordenar(vet,0,12-1);
	
	printf("vetor ordenado\n");
	for(int i=0;i<12;i++){
		printf("%d\t",vet[i]);
	}
	return 0;
}


/*
iteracoes no do while:

vet={7,1,3,9,8,4,2,7,4,2,3,5};
-pivo=4

1.iteracao:
	i=0
	j=11
	
	*procura elementos maiores que o pivô na primeira parte*
	while(vet[i]<pivo && i<fim){
		i++; 
	}
	vet[0]<4 && i<fim: (7<4 && 0<11) falso
	i=0
	
		
	*procura elementos menores que o pivô na segunda parte*
	while(pivo<vet[j] && j>inicio){ 
		j--; 
	}
	4<vet[11] && j>inicio: (4<5 && 11>0) true
	j=10

	* processo de troca (ordenação) *
	if(i<=j){ //0<=10 true
		aux = vet[i]; //aux = vet[0], aux = 7
		vet[i] = vet[j]; //vet[0]=vet[10], vet[0]=3
		vet[j] = aux; //vet[10]=aux, vet[10]=7
		i++; //i=1
		j--; //j=9
	} 

	vet={3,1,3,9,8,4,2,7,4,2,7,5};
	
	
2.iteracao:
	i=1
	j=9
	
	*procura elementos maiores que o pivô na primeira parte*
	while(vet[i]<pivo && i<fim){
		i++; 
	}
	vet[1]<4 && i<fim: (1<4 && 1<11) true
	i=2
	
	**roda while denovo:
	vet[2]<4 && i<fim: (3<4 && 2<11) true
	i=3
	
	**roda while denovo:
	vet[3]<4 && i<fim: (9<4 && 3<11) falso
		
	
	*procura elementos menores que o pivô na segunda parte*
	while(pivo<vet[j] && j>inicio){ 
		j--; 
	}
	4<vet[9] && j>inicio: (4<2 && 9>0) falso
	
	* processo de troca (ordenação) *
	if(i<=j){ //3<=9 true
		aux = vet[i]; //aux = vet[3], aux = 9
		vet[i] = vet[j]; //vet[3]=vet[9], vet[3]=2
		vet[j] = aux; //vet[9]=aux, vet[9]=9
		i++; //i=4
		j--; //j=8
	}
	
	vet={3,1,3,2,8,4,2,7,4,9,7,5}

		
3.iteracao:
	i=4
	j=8
	
	*procura elementos maiores que o pivô na primeira parte*
	while(vet[i]<pivo && i<fim){
		i++; 
	}
	vet[4]<4 && i<fim: (8<4 && 4<11) falso
	
	*procura elementos menores que o pivô na segunda parte*
	while(pivo<vet[j] && j>inicio){ 
		j--; 
	}
	4<vet[8] && j>inicio: (4<4 && 8>0) falso
	
	* processo de troca (ordenação) *
	if(i<=j){ //4<=8 true
		aux = vet[i]; //aux = vet[4], aux = 8
		vet[i] = vet[j]; //vet[4]=vet[8], vet[4]=4
		vet[j] = aux; //vet[8]=aux, vet[8]=8
		i++; //i=5
		j--; //j=7
	}
	
	vet={3,1,3,2,4,4,2,7,8,9,7,5}
	

4.iteracao:
	i=5
	j=7
	
	*procura elementos maiores que o pivô na primeira parte*
	while(vet[i]<pivo && i<fim){
		i++; 
	}
	vet[5]<4 && i<fim: (4<4 && 5<11) falso
	
	*procura elementos menores que o pivô na segunda parte*
	while(pivo<vet[j] && j>inicio){ 
		j--; 
	}
	4<vet[7] && j>inicio: (4<7 && 7>0) true
	j=6
	
	**roda while denovo:
	4<vet[6 && j>inicio: (4<2 && 6>0) falso
	
	* processo de troca (ordenação) *
	if(i<=j){ //5<=6 true
		aux = vet[i]; //aux = vet[5], aux = 4
		vet[i] = vet[j]; //vet[5]=vet[6], vet[5]=2
		vet[j] = aux; //vet[6]=aux, vet[6]=4
		i++; //i=6
		j--; //j=6
	}
	
	vet={3,1,3,2,4,2,4,7,8,9,7,5}


5.iteracao:
	i=6
	j=6
	
	*procura elementos maiores que o pivô na primeira parte*
	while(vet[i]<pivo && i<fim){
		i++; 
	}
	vet[6]<4 && i<fim: (4<4 && 6<11) falso
	
	*procura elementos menores que o pivô na segunda parte*
	while(pivo<vet[j] && j>inicio){ 
		j--; 
	}
	4<vet[6] && j>inicio: (4<4 && 6>0) falso
	
	* processo de troca (ordenação) *
	if(i<=j){ //6<=6 true
		aux = vet[i]; //aux = vet[6], aux = 4
		vet[i] = vet[j]; //vet[6]=vet[6], vet[6]=4
		vet[j] = aux; //vet[6]=aux, vet[6]=4
		i++; //i=7
		j--; //j=5
	}
	
	vet={3,1,3,2,4,2,4,7,8,9,7,5}
	
	i<=j false, sai do do while
	
	*dessa forma os elementos menores que o pivo estao a sua esquerda e os maiores que ele ficam a sua direita
*/

	
	
	
	
	
	
	
	
/*
chamadas recursivas:
	if(inicio<j){ 
		ordenar(vet,inicio,j);
	}
	se inicio<j (0<5) true
	funcao ordenar e chamada passando como fim a ultima posicao antes do pivo, ou seja, apenas os elementos da esquerda do pivo, porque o quicksort subdivide o vetor em pequenas partes e ordena cada uma delas:
	
	ordenar(vet,0,5)
	
	vet={3,1,3,2,4,2}
	pivo = vet[(inicio+fim)/2];
	//pivo = (inicio+fim)/2, (0+5)/2=2, pivo=vet[2]
	//pivo=3

	1.iteracao:
		i=0
		j=5
		
		*procura elementos maiores que o pivô na primeira parte*
		while(vet[i]<pivo && i<fim){
			i++; 
		}
		vet[0]<3 && i<fim: (3<3 && 0<5) falso
			
		*procura elementos menores que o pivô na segunda parte*
		while(pivo<vet[j] && j>inicio){ 
			j--; 
		}
		3<vet[5] && j>inicio: (3<2 && 5>0) false
	
		* processo de troca (ordenação) *
		if(i<=j){ //0<=5 true
			aux = vet[i]; //aux = vet[0], aux = 3
			vet[i] = vet[j]; //vet[0]=vet[5], vet[0]=2
			vet[j] = aux; //vet[5]=aux, vet[5]=3
			i++; //i=1
			j--; //j=4
		} 
	
		vet={2,1,3,2,4,3}
		
		
	2.iteracao:
		i=1
		j=4
		
		*procura elementos maiores que o pivô na primeira parte*
		while(vet[i]<pivo && i<fim){
			i++; 
		}
		vet[1]<3 && i<fim: (1<3 && 1<5) true
		i=2
		
		**roda while denovo:
		vet[2]<3 && i<fim: (3<3 && 2<5) falso
	
		*procura elementos menores que o pivô na segunda parte*
		while(pivo<vet[j] && j>inicio){ 
			j--; 
		}
		3<vet[4] && j>inicio: (3<4 && 4>0) true
		j=3
		
		**roda while denovo:
		3<vet[3] && j>inicio: (3<2 && 3>0) falso
		
		
		* processo de troca (ordenação) *
		if(i<=j){ //2<=3 true
			aux = vet[i]; //aux = vet[2], aux = 3
			vet[i] = vet[j]; //vet[2]=vet[3], vet[3]=2
			vet[j] = aux; //vet[3]=aux, vet[3]=3
			i++; //i=3
			j--; //j=2
		}
		
		vet={2,1,2,3,4,3}

		i<=j false, sai do do while
	
		*dessa forma os elementos menores que o pivo estao a sua esquerda e os maiores/iguais que ele ficam a sua direita
		
	
	if(inicio<j){ 
		ordenar(vet,inicio,j);
	}
	se 0<2 true
	chama funcao ordenar novamente, passando os elementos a esquerda do pivo, ou seja menores do que ele.
	
	
	ordenar(vet,0,2)

	
	
	vet={2,1,2,3,4,3}
	pivo = vet[(inicio+fim)/2];
	//pivo = (inicio+fim)/2, (0+2)/2=1, pivo=vet[1]
	//pivo=1

	1.iteracao:
		i=0
		j=2
		
		*procura elementos maiores que o pivô na primeira parte*
		while(vet[i]<pivo && i<fim){
			i++; 
		}
		vet[0]<1 && i<fim: (2<1 && 0<2) falso
			
		*procura elementos menores que o pivô na segunda parte*
		while(pivo<vet[j] && j>inicio){ 
			j--; 
		}
		1<vet[2] && j>inicio: (1<2 && 2>0) true
		j=1
		
		**roda while denovo:
		1<vet[1] && j>inicio: (1<1 && 1>0) falso
	
		* processo de troca (ordenação) *
		if(i<=j){ //0<=1 true
			aux = vet[i]; //aux = vet[0], aux = 2
			vet[i] = vet[j]; //vet[0]=vet[1], vet[0]=1
			vet[j] = aux; //vet[1]=aux, vet[1]=2
			i++; //i=1
			j--; //j=0
		} 
	
		vet={1,2,2,3,4,3}

		i<=j false, sai do do while
	
		*dessa forma os elementos as 3 primeiras posicoes ja estao ordenadas usando a tecnica de diminuir o vetor em pequenos vetores separados e ordenar cada um deles, o pivo(1) acabou indo para o inicio
	
	if(inicio<j){ 
		ordenar(vet,inicio,j);
	}
	se 0<0 false
	
	if(i<fim){
		ordenar(vet,i,fim); 
	}
	se 1<2 true
	
	chama funcao ordenar novamente, passando os elementos a direita do pivo(1), ou seja maiores do que ele.
	
	
	ordenar(vet,1,2);
	
	
	
	vet={1,2,2,3,4,3}
	pivo = vet[(inicio+fim)/2];
	//pivo = (inicio+fim)/2, (1+2)/2=1, pivo=vet[1]
	//pivo=2

	1.iteracao:
		i=1
		j=2
		
		*procura elementos maiores que o pivô na primeira parte*
		while(vet[i]<pivo && i<fim){
			i++; 
		}
		vet[1]<2 && i<fim: (2<2 && 1<2) falso
			
		*procura elementos menores que o pivô na segunda parte*
		while(pivo<vet[j] && j>inicio){ 
			j--; 
		}
		2<vet[2] && j>inicio: (2<2 && 2>1) falso
		
		* processo de troca (ordenação) *
		if(i<=j){ //1<=2 true
			aux = vet[i]; //aux = vet[1], aux = 2
			vet[i] = vet[j]; //vet[1]=vet[2], vet[1]=2
			vet[j] = aux; //vet[2]=aux, vet[2]=2
			i++; //i=2
			j--; //j=1
		} 
	
		vet={1,2,2,3,4,3}

		i<=j false, sai do do while
	
		*dessa forma os elementos das 3 primeiras posicoes ja estao ordenadas usando a tecnica de diminuir o vetor em pequenos vetores separados e ordenar cada um deles
	
	if(inicio<j){ 
		ordenar(vet,inicio,j);
	}
	se 1<1 false
	
	if(i<fim){
		ordenar(vet,i,fim); 
	}
	se 2<1 false
	
*/
