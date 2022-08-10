#include <stdio.h>
#include <stdlib.h>
int inverte (int vet[10])
{
	int i,aux;
	for(i=0;i<5;i++)
	{
		aux=vet[i];
		vet[i]=vet[9-i];
		vet[9-i]=aux;
	}
}
main()
{
	int vet[10],i;
	for(i=0;i<10;i++)
	{	
	printf("vet[%d]: ",i);
	scanf("%d",&vet[i]);
	}
	inverte(vet);
	printf("inverso do vetor digitado\n");
	for(i=0;i<10;i++)
	{
	printf("vet [%d] = %d\n",i,vet[i]);		
	}
	
	system("cls");	
}
