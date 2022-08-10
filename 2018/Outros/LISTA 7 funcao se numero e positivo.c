#include <stdio.h>
#include <conio.h>
int p(int n)
{
	if(n>=0)
	printf("numero positivo");
	else
	printf("numero negativo");
}

main()
{
	int n;
	printf("insira um numero: ");
	scanf("%d",&n);
	p(n);
}
