#include <stdio.h>
#include <conio.h>

int transposta (int i,int j,int mat[4][4])
{
printf("\ntransposta da matriz digitada\n");
	
for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		printf("%d\t",mat[j][i]);
		printf("\n");
	}
}
main()
{
	int mat[4][4],i,j;
	
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
		printf("mat[%d][%d]= ",i,j);
		scanf("%d",&mat[i][j]);		
		}
	}
	
	printf("\n");
	
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		printf("%d\t",mat[i][j]);
		printf("\n");
	}

transposta(i,j,mat);
		
	getche();
}
