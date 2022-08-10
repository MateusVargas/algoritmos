#include <stdio.h>
#include <conio.h>
main()
{
	int meses;
	float juros,aplic,divida,rend;
	divida=10000;
	aplic=1500;
	rend=0.004;
	juros=0.0025;
	meses=0;
	
	while(divida>aplic)
	{
	divida=(divida*juros)+divida;
	aplic=(aplic*rend)+aplic;
	meses++;
	}
	printf("meses para encerrar a divida: %d\n",meses);
	printf("sua divida esta em: %.2f\n",divida);
	printf("sua aplicacao esta em: %.2f\n",aplic);
	
	getche();
}
