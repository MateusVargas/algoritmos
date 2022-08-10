#include <stdio.h>
#include <conio.h>
main()
{
	int i,j,M[3][3],N[3][3],soma[3][3],prod[3][3];
	printf("digite a matriz M\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
		printf("M[%d][%d]= ",i,j);
		scanf("%d",&M[i][j]);
		}
	}
	
	printf("\ndigite a matriz N\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
		printf("N[%d][%d]= ",i,j);
		scanf("%d",&N[i][j]);
		}
	}	
	
	printf("matriz M\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		printf("%d\t",M[i][j]);
		printf("\n");
	}
	
	printf("matriz N\n");
	for(i=0;i<3;i++)	
	{	
		for(j=0;j<3;j++)
		printf("%d\t",N[i][j]);
		printf("\n");
	}	
	
	printf("soma das matrizes M e N\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
		soma[i][j]=M[i][j]+N[i][j];
			}
	}
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		printf("%d\t",soma[i][j]);
		printf("\n");
	}
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
		prod[i][j]=M[i][j]*N[i][j];
			}
	}
	
	printf("produto das matrizes M e N\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		printf("%d\t",prod[i][j]);
		printf("\n");
	}
	
	getche();	
}
