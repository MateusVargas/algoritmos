#include <stdio.h>
#include <conio.h>
main()
{
	int vet[5],i,cont1=0,n;
	for(i=0;i<5;i++)
	{
	printf("digite o %d° numero: ",i+1);
	scanf("%d",&vet[i]);
	}
	for(i=0;i<5;i++)
	{
	if(vet[i]==vet[4])
		cont1++;
		n=vet[4];
	}
	printf("o numero %d aparece %d vezes",n,cont1);
	
	getche();
}
