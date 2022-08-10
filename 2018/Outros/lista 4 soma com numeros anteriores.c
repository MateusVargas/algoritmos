#include <stdio.h>
#include <conio.h>
main ()
{
	int Num,soma;
	printf("digite um numero: ");
	scanf("%d",&Num);
	for (soma=1;Num>1;Num=Num-1)
	soma=soma+Num;
	printf("resultado: %d",soma);
	getche();
}
