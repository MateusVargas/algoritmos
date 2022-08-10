#include <stdio.h>
#include <conio.h>
main()
{
	int vet[6],i,j,aux;
	printf("elementos do vetor\n");
	for(i=0;i<6;i++)
	{
	printf("v[%d]= ",i);
	scanf("%d",&vet[i]);
	}
	
	printf("vetor na ordem crescente\n");
	for(i=0;i<6;i++)
	{
	for(j=i+1;j<6;j++)
		{
		if(vet[i]>vet[j])
		{
		aux=vet[i];
		vet[i]=vet[j];
		vet[j]=aux;
			}
	}
	}	
		for(i=0;i<6;i++){	
	printf("V[%d]= %d\n",i,vet[i]);
	}
	
	getche();	
}
