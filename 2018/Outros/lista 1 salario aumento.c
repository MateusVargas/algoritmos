#include <stdio.h>

int main ()
{
	float salario, aumento, desconto;
	printf("informe seu salario R$: ");
	scanf("%f", &salario);
	aumento = (salario * 1.15);
	printf("com 15 por cento de aumento seu salario sera R$: %.2f \n",aumento);
	desconto = aumento * 0.92;
	printf("e depois descontando 8 por cento seu salario final sera R$: %.2f",desconto);

	return 0;
}
