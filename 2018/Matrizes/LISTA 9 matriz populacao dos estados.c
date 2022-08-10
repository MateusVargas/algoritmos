#include <stdio.h>
#include <conio.h>
main()
{
	int mat[3][3],i,j,est,mun,maior=0,soma=0;
	printf("digite os elementos da martriz\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)	
		{
			printf("mat[%d][%d]= ",i,j);
			scanf("%d",&mat[i][j]);
		}
	}
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		printf("%d\t",mat[i][j]);
		printf("\n");
	}
	printf("\n");
	
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		if(mat[i][j]>maior)
		{
		maior=mat[i][j];
		est=i;
		mun=j;
		}
	
	}
	
	for(i=0;i<3;i++)
		for(j=0;j<1;j++)
			soma=soma+mat[i][j];
	
	printf("maior populacao: estado %d municipio %d\n",est,mun);
	
	printf("soma coluna 0: %d",soma);
	
	getche();	
}
