#include <stdio.h>
#include <conio.h>
#define colunas 3
#define linhas 3

int i,j;

int le_matriz(int matriz[][colunas])
{
	printf("digite os dados da matriz\n");
	for(i=0;i<colunas;i++)
		for(j=0;j<linhas;j++)
		{
		printf("matriz [%d][%d] = ",i,j);
		scanf("%d",&matriz[i][j]);	
		}
	getche();
}

int escreve_matriz(int matriz[][colunas])
{
	printf("\n");
	for(i=0;i<linhas;i++)
	{
		for(j=0;j<colunas;j++)
		printf("%d\t",matriz[i][j]);
		printf("\n");
	}
	
}

int soma(int matr[][colunas],int vetor[])
{
	int SL[3];
	for(i=0;i<linhas;i++)
	{
		SL[i]=0;
		for(j=0;j<colunas;j++)
		SL[i]=SL[i]+matr[i][j];
		vetor[i]=SL[i];	
	}
	for(i=0;i<linhas;i++)
	printf("soma da linha %d = %d\n",i,vetor[i]);
}

main()
{
int matriz[linhas][colunas];
int vetor[linhas];
	
le_matriz(matriz);
	
escreve_matriz(matriz);
	
soma(matriz,vetor);
	
	getche();	
}
