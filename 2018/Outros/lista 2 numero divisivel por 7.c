#include <stdio.h>
#include <conio.h>

int main ()
{
	int num;
	printf("digite um numero:");
	scanf("%i",&num);
	
	if (num%7==0){
		printf("numero divisivel por 7.");
		} else
		printf("numero nao divisivel por 7.");
		
	getche();
}
