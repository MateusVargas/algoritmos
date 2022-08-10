#include <stdio.h>
#include <conio.h>
main()
{
	int mat[5][5],vet[5],i,j,soma=0;
	printf("informe os dados da matriz\n");	
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("mat[%d][%d]= ",i,j);
			scanf("%d",&mat[i][j]);
		}
	}
	
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		printf("%d  ",mat[i][j]);
		printf("\n");
	}
	
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(i==j)
			vet[i]=mat[i][j];
		}
	}
	
	printf("diagonal principal da matriz\n");
	for(i=0;i<5;i++)
	printf("   %d   ",vet[i]);
	
	for(i=0;i<5;i++)
	soma=soma+vet[i];
	
	printf("\nsoma da diagonal principal: %d",soma);
	
	getche();
}
