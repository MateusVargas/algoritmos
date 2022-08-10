#include <stdio.h>
#include <conio.h>

int maior (int a, int b, int c)
{
	if(a>b&&a>c)
	return(a);
	else if(b>a&&b>c)
	return(b);
	else if(c>a&&c>b)
	return(c);
}
main()
{
	int a,b,c,r;
	printf("digite um numero: ");
	scanf("%d",&a);
	printf("digite um numero: ");
	scanf("%d",&b);
	printf("digite um numero: ");
	scanf("%d",&c);
	r=maior(a,b,c);
	printf("maior numero: %d",r);
	
	getch();
}
