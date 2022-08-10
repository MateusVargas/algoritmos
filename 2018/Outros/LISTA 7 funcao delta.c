#include <stdio.h>
#include <conio.h>
#include <math.h>

float delt(float a, float b, float c)
{
	float del;
	del=pow(-b,2)-4*a*c;
	return(del);	
}
main()
{
	float a,b,c,r;
	printf("digite um valor para o A: ");
	scanf("%f",&a);
	printf("digite um valor para o B: ");
	scanf("%f",&b);
	printf("digite um valor para o C: ");
	scanf("%f",&c);
	r=delt(a,b,c);
	printf("o valor do delta e: %.2f",r);
	
	getche();	
}
