#include <stdio.h>
#include <conio.h>	
main()
{
	int i,j,mat[3][3],sc[3],sl[3];
	printf("informe os elementos da matriz\n");
	
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
			printf("%d   ",mat[i][j]);
			printf("\n");
	}
				
	for(i=0;i<3;i++)
	{
		sl[i]=0;
		for(j=0;j<3;j++)
		sl[i]=sl[i]+mat[i][j];
	}
	
	for(j=0;j<3;j++)
	{
		sc[j]=0;
		for(i=0;i<3;i++)
		sc[j]=sc[j]+mat[i][j];
	}
	
	printf("\n");
	
	for(i=0;i<3;i++)
	{
		printf("soma da linha %d = %d\n",i,sl[i]);
	}
	
	for(j=0;j<3;j++)
	{
		printf("\nsoma da coluna %d = %d\n",j,sc[j]);
	}
	
			
	getche();	
}
