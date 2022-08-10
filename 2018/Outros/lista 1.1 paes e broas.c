#include <stdio.h>
#include <conio.h>

int main ()
{
	float pao, broa, total, poupanca;
	printf("quantos paes voce vendeu hoje: ");
	scanf("%f",&pao);
	printf("quantas broas voce vendeu hoje: ");
	scanf("%f",&broa);
	
	total=pao*0.12 + broa*1.50;
	printf("o total arrecadado hoje foi de: %.2f R$",total);
	
	poupanca=total / 10;
	printf("\n voce deve guardar na poupanca: %.2f R$",poupanca);
	
	getche();
}
