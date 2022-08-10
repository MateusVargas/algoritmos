#include <stdio.h>
#include <conio.h>
main()
{
	int mat[5][5],i,j,aux;
	printf("informe os dados da matriz\n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("[%d][%d]= ",i,j);
			scanf("%d",&mat[i][j]);	
		}
	}
	
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		printf("%d\t",mat[i][j]);
		printf("\n");
	}
	printf("\n");
	
/*-----------------------------------------	*/
	for(i=0;i<5;i++)
	{
		aux=mat[1][i];
		mat[1][i]=mat[4][i];
		mat[4][i]=aux;	
	}
	
	for(j=0;j<5;j++)
	{
		aux=mat[j][3];
		mat[j][3]=mat[j][2];
		mat[j][2]=aux;
	
	}
	
	
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		printf("%d\t",mat[i][j]);
		printf("\n");
	}
	
		
	getche();
}
