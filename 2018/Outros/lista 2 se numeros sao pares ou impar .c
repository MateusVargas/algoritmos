#include <stdio.h>
#include <conio.h>

int main ()
{
	long a,b;
	printf("digite um numero: ");
	scanf("%i",&a);
	printf("digite outro numero: ");
	scanf("%i",&b);
	
	if (a%2==0)
	if (b%2==0)
	printf("\n os dois sao pares");
	
	if (a%2==0)
	if (b%2!=0)
	printf("\n o primeiro e par e o segundo impar");
	
	if (a%2!=0)
	if (b%2==0)
	printf("\n o primeiro e impar e o segundo par");
	
	if (a%2!=0)
	if (b%2!=0)
	printf("\n os dois sao impares");

	getch();
	
}
