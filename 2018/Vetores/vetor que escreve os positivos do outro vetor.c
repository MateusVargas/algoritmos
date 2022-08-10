#include <stdio.h>
#include <stdlib.h>
main()
{
	int v[10],z[10];
	printf("informe os elementos do vetor\n");
	for(int i=0;i<10;i++)
	{
	printf("V[%d] = ",i);
	scanf("%d",&v[i]);
	}
	int k=0;
	for(int i=0;i<10;i++)
	{
	if(v[i]>0)
	{
	z[k]=v[i];
	k=k+1;
	}		
	}
	for(int i=0;i<k;i++)
	printf("\nZ[%d] = %d \n",i,z[i]);
	
	system("cls");
}
