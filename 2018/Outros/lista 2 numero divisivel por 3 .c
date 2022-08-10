#include <stdio.h>
#include <conio.h>

int main ()
{
	int num;
	
	printf("digite um numero: ");
	scanf("%i",&num);
	
	if (num%2==0){
		printf("numero par\n");
	}else
	printf("numero impar\n");
	
	if (num%3==0){
		printf("divisivel por 3\n");
		}else
		printf("nao divisivel por 3\n");
	
	getche();	
}
	
	
