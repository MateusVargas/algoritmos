#include <stdio.h>
#include <stdlib.h>

int i,j;

int le_matriz(int matriz[30][30],int m,int n)
{
	for(i=0;i<m;i++)
	for(j=0;j<n;j++)
	{
	printf("mat[%d][%d]= ",i,j);
	scanf("%d",&matriz[i][j]);
}	
}

int escreve_matriz(int matriz[30][30],int m,int n)
{
	printf("\n");
	for(i=0;i<m;i++)	
	{
	for(j=0;j<n;j++)
		printf("%d\t",matriz[i][j]);
		printf("\n");
	}	
}

int transposta(int matriz[30][30],int m,int n)
{
	printf("\ntransposta\n");
	if(m==n)
	{
	for(i=0;i<m;i++)
	{
	for(j=0;j<n;j++)	
	printf("%d\t",matriz[j][i]);	
	printf("\n");		
	}
}
	if(m<n)
	{
		for(i=0;i<n;i++)
		{
		for(j=0;j<m;j++)
		printf("%d\t",matriz[j][i]);
		printf("\n");
		}
	}
	if(m>n)
	{
		for(i=0;i<n;i++)
		{
		for(j=0;j<m;j++)
		printf("%d\t",matriz[j][i]);
		printf("\n");
		}
	}
}

main()
{
	int matriz[30][30],m,n;
	printf("numero de linhas da matriz: ");
	scanf("%d",&m);
	printf("numero de colunas da matriz: ");
	scanf("%d",&n);
	
	le_matriz(matriz,m,n);
	escreve_matriz(matriz,m,n);
	transposta(matriz,m,n);
	
	system("pause");	
}
