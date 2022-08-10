#include <stdio.h>
#include <conio.h>
main()
{
	int mat[3][3],i,j,aux;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)	
		{
			printf("[%d][%d]= ",i,j);
			scanf("%d",&mat[i][j]);
		}
	}
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		printf("%d\t",mat[i][j]);
		printf("\n");
	}
	
	for(i=0;i<3;i++)
	{
		printf("\n");
		for(j=0;j<3;j++)
		{
			aux=mat[1][i];
			mat[1][i]=mat[j][1];
			mat[j][1]=aux;
		}
	}
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		printf("%d\t",mat[i][j]);
		printf("\n");
	}
	
	getche();	
}
