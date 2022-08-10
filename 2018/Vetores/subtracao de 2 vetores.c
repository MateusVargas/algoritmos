#include <stdio.h>
#include <conio.h>
main()
{
	int vetA[6],inv[6],i,aux,sub[6],soma_sub=0;
	printf("dados do vetor A\n");	
	for(i=0;i<6;i++)
	{
		printf("vetA[%d]= ",i);
		scanf("%d",&vetA[i]);
	}
	printf("\n");
	
	for(i=0;i<6;i++)
	{
		printf("vetB[%d]= ",i);
		scanf("%d",&inv[i]);
	}	
	printf("\n");
	
	
	for(i=0;i<3;i++)
	{
	aux=inv[i];
	inv[i]=inv[5-i];
	inv[5-i]=aux;
	}
		
	for(i=0;i<6;i++)
	{
		printf("inversoB[%d]= %d\n",i,inv[i]);	
	}
	printf("\n");
	
	for(i=0;i<6;i++)
	{
		sub[i]=vetA[i]-inv[i];
	}
	
	printf("subtracao do vetor A e do inverso de B\n");
	for(i=0;i<6;i++)
	{
		printf("subtracao[%d]= %d\n",i,sub[i]);
	}
	
	for(i=0;i<6;i++)
	{
		soma_sub=soma_sub+sub[i];
		}
		printf("soma dos elementos do vetor subtracao: %d",soma_sub);	
	
	getche();	
}
