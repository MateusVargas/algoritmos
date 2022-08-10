#include <stdio.h>
#include <conio.h>
main()
{
	int i,mat[40][40],j,m,n,menor=99999999999,linha_menor;
	printf("informe o numero de linhas: ");
	scanf("%d",&m);
	printf("informe o numero de colunas: ");
	scanf("%d",&n);
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("mat[%d][%d]= ",i,j);
			scanf("%d",&mat[i][j]);
		}
	}
	
	printf("\n");
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		printf("%d   ",mat[i][j]);
		printf("\n");
	}
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		if(mat[i][j]<menor)
		{
			menor=mat[i][j];
			linha_menor=i;	
		}	
		
	}
	
	printf("linha em que esta o menor elemento\n");
	
	for(j=0;j<n;j++)
	printf("    %d\t",mat[linha_menor][j]);
	
	printf("\nmenor elemento: %d\n",menor);
	
	getche();
}
