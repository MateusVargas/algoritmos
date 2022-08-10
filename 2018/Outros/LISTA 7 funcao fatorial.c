#include <stdio.h>
#include <conio.h>

int fatorial(int num)
{
	int fat=1;
	for(int i=1;i<=num;i++)
	{
	fat=fat*i;
		}
	printf("fatorial do numero digitado: %d",fat);
}
main()
{
	int num;
	printf("entre com um numero: ");
	scanf("%d",&num);
	fatorial(num);
	
	getch();	
}
