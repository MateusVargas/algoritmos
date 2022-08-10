#include <stdio.h>
#include <conio.h>

int main ()
{
	int x,y;
	printf("digite um numero: ");
	scanf("%d",&x);
	printf("digite outro numero: ");
	scanf("%d",&y);
	
	if (x < y){
		printf("ordem crescente: %d, %d",x,y);
		}else
		printf("ordem crescente: %d, %d",y,x);
		
	getche();
}
