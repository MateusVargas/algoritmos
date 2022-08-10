#include <stdio.h>
#include <stdlib.h>
main()
{
	float positivos,mat[3][5];
	int i,j,cont1=0;
	printf("digite os dados da matriz");
	
	for(i=0;i<3;i++)
	{
	for(j=0;j<5;j++)
	{
	printf("\nMat [%d] [%d] = ",i,j);	
	scanf("%f",&mat[i][j]);
		
	if(mat[i][j]>0)	
		positivos=positivos+mat[i][j];
	else if(mat[i][j]<0)
		cont1++;
	
	}
	}
	printf("\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<5;j++)
		printf("%.0f\t",mat[i][j]);
		printf("\n");
	}
	printf("soma dos positivos: %.2f\n",positivos);
	printf("numeros negativos %d",cont1);
	
	system("\npause");
}
