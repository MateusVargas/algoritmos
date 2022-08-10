#include <stdio.h>
#include <conio.h>
#define linha 3
#define coluna 3

int i,j;
int maior(int x,int mat[][coluna])
{
	int vet[linha*coluna],k=0;
	
	for(i=0;i<linha;i++)
	{	
		for(j=0;j<coluna;j++)
		{
			if(x<mat[i][j])
			{
			vet[k]=mat[i][j];
			k=k+1;
				}
		}
	}

printf("vetor com os elementos maiores que X\n");
	for(i=0;i<k;i++)
	printf("V[%d]= %d\n",i,vet[i]);

}

main()
{
	int mat[linha][coluna],x;
	printf("digite um valor para X: ");
	scanf("%d",&x);
	printf("elementos da matriz\n");
	for(i=0;i<linha;i++)
	{
		for(j=0;j<coluna;j++)
		{
		printf("[%d][%d]= ",i,j);
		scanf("%d",&mat[i][j]);
		}
	}
	maior(x,mat);
	
	getche();
}
