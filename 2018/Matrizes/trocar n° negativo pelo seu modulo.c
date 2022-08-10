#include <stdio.h>
#include <conio.h>
#define linhas 3
#define colunas 3

int i,j,k;
main()
{
	int mat[3][3],num,pos[k],ios[9];
	for(i=0;i<linhas;i++)
	{
		for(j=0;j<colunas;j++)
		{
		printf("matriz[%d][%d]= ",i,j);
		scanf("%d",&mat[i][j]);
		}
	}
	
	for(i=0;i<linhas;i++)
	{
		for(j=0;j<colunas;j++)
		{
			if(mat[i][j]<0)
			{
			mat[i][j]=mat[i][j]*(-1);
			}
		}
	}
	
	for(i=0;i<linhas;i++)
	{
		for(j=0;j<colunas;j++)
		printf("%d\t",mat[i][j]);
		printf("\n");
	}
	
	getche();	
}
