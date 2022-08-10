#include <stdio.h>
#include <conio.h>

int maior(int mat[4][3])
{
	int maior=0,l,i,j;
	for(i=0;i<4;i++)
	{
		for(j=1;j<2;j++)
		if(mat[i][j]>maior)
		{
		maior=mat[i][j];
		l=i;
			}
	}
	
	printf("maior numero arm: %d",l);
}

main()
{
	int mat[4][3],i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("[%d][%d]= ",i,j);
			scanf("%d",&mat[i][j]);	
		}
	}
	for(i=0;i<4;i++)
	{
		for(j=0;j<3;j++)
			printf("%d\t",mat[i][j]);
			printf("\n");
	}
	
	maior(mat);
	
	getche();
}
