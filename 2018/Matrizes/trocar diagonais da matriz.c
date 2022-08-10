#include <stdio.h>
#include <conio.h>
main()
{
	int mat[4][4],i,j,aux,vet[4],vetb[4];
	printf("elementos da matriz\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("[%d][%d]= ",i,j);
			scanf("%d",&mat[i][j]);
		}
	}
	
	printf("matriz digitada\n");
	for(i=0;i<4;i++)
	{
		
		for(j=0;j<4;j++)
		printf("%d\t",mat[i][j]);
		printf("\n");
	
	}
	
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++){
			
		if(i+j==3)
			{
		vet[i]=mat[i][j];
			}
		if(i==j)
			{
		vetb[i]=mat[i][j];	
			}
		}
	}
	
	printf("diagonal principal\n");
	for(i=0;i<4;i++){	
		printf("%d\t",vetb[i]);
		}
	printf("\n\n");
	
	printf("diagonal secundaria\n");	
	for(i=0;i<4;i++){
		printf("%d\t",vet[i]);
		}
		printf("\n\n");
		
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
		if(i==j)
		mat[i][j]=vet[i];
			
		if(i+j==3)
		mat[i][j]=vetb[i];
	}
	}
	
	printf("matriz digitada com as diagonais trocadas\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		printf("%d\t",mat[i][j]);
		printf("\n");
	}
	
	getche();	
}
