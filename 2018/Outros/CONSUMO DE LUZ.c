#include <stdio.h>

main()
{
	float a=0.38226655,b=0.45337890;
	int kwh;
	float adicionalV1=3.00,adicionalA=1.10,adicionalV2=5.50,tip=4.90,total=0;
	
	printf("informe o valor gasto em kWh: ");
	scanf("%d",&kwh);
	
	total=(kwh*a)+(kwh*b)+tip+adicionalA+adicionalV1;
	
	printf("total a pagar R$: %.2f",total);	
}
