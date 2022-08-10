#include <stdio.h>
#include <math.h>

float eleva(float x, float y)
{
	float pot;
	pot=pow(x,y);
	return(pot);
}
main()
{
	float x,y,resultado;
	printf("informe um valor para X: ");
	scanf("%f",&x);
	printf("informe um valor para Y: ");
	scanf("%f",&y);
	resultado=eleva(x,y);
	printf("%.0f elevado na %.0f = %.0f",x,y,resultado);
}
