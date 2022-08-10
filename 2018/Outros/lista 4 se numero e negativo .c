#include <stdio.h>
#include <conio.h>

int main ()
{
	int num,i;
	for(i=0;i<5;i++){
		printf("escreva um numero: ");
		scanf("%d",&num);
		if (num < 0)
		printf("numero negativo\n\n");
		}
	getche();
}
