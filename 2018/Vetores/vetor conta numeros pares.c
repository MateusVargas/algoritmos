#include <stdio.h>
#include <conio.h>
main()
{
	int i,vet[10],cont1=0;
	for(i=0;i<=9;i++)
	{
	printf("digite o %d termo do vetor: ",i+1);
	scanf("%d",&vet[i]);
		
		if(vet[i]%2==0)cont1++;
	}
	printf("total de numeros pares: %d",cont1);
	
	getch();
}
