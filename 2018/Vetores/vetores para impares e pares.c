#include <stdio.h>
#include <conio.h>
main()
{
	int i,par[10],impar[10],num[10];
	printf("escreva um numero os elementos do vetor\n");
	for(i=0;i<10;i++)
	{
	printf("V[%d] = ",i);
	scanf("%d",&num[i]);
	}
	
	int k=0,imp=0;
	
	for(i=0;i<10;i++)
	{
	if(num[i]%2==0)
	{
	par[k]=num[i];	
	k=k+1;
	}
	else
	{
	impar[imp]=num[i];
	imp=imp+1;
	}
	
	}
	for(i=0;i<imp;i++)
	printf("\nimpar[%d] = %d",i,impar[i]);
	
	for(i=0;i<k;i++)
	printf("\npar[%d] = %d",i,par[i]);
	
	getchar();	
}
