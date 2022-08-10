#include <stdio.h>
#include <stdlib.h>

void recebe (int num)
{
	if(num>0)
	printf("o valor nao e nulo");
	else if(num<0)
	printf("o valor e negativo");
	else if(num==0)
	printf("numero nulo");
}
main()
{
	int num;
	printf("digite um numero: ");
	scanf("%d",&num);
	recebe(num);
	
	system("\npause");
}
