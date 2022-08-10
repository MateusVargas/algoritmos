#include <stdio.h>
#include <stdlib.h>
main()
{	float preco,total;
	printf("informe o preco de fabrica do carro: ");
	scanf("%f",&preco);
	total=preco*1.28*1.45;
	printf("preco do carro com os impostos: %.2f R$",total);
	system("cls");
}
