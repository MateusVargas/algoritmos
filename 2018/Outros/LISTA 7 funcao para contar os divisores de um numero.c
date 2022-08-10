#include <stdio.h>
#include <conio.h>

int divisores(int n)
{
	int i,div=0;
	for(i=1;i<=n;i++)
	{
		if(n%i==0)div++;	
	}
	printf("o numero %d tem %d divisores",n,div);
}
main()
{
	int n;
	printf("digite um numero: ");
	scanf("%d",&n);
	divisores(n);
	
	getche();
}
