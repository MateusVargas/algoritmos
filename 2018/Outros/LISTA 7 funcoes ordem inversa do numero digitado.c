#include <stdio.h>
#include <conio.h>

int inverso(int a, int b, int c)
{
	printf("ordem inversa: %d,%d,%d",c,b,a);

}
main()
{
	int a,b,c;
	printf("digite um numero: ");
	scanf("%d",&a);
	printf("digite um numero: ");
	scanf("%d",&b);
	printf("digite um numero: ");
	scanf("%d",&c);
	inverso(a,b,c);
	
	getche();
}
