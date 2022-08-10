#include <stdio.h>
#include <conio.h>
main()
{
	int num,i,divisores=0;
	printf("digite um numero: ");
	scanf("%d",&num);
	for (i=1;i<=num;i++){	
	if (num%i==0){
		divisores++;
		}
	}
	
	if (divisores>2)
	printf("nao e primo\n",num);
	else
	printf("numero primo\n",num);
	
	getch();
}
