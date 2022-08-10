#include <stdio.h>
#include <conio.h>
int main ()
{
	int tipo, quant;
	float troco, valorpago;
	printf("informe o bilhete desejado\n");
	printf("\t1-unitario\n");
	printf("\t2-duplo\n");
	printf("\t3-10 viagens\n");
	scanf("%d",&tipo);
	printf("informe o valor pago: ");
	scanf("%f",&valorpago);
	
	switch (tipo)
	{	case 1 :
		quant=(valorpago/1.30);
		troco=valorpago-quant*1.30;
		break;
		
		case 2 :
		quant=(valorpago/2.60);
		troco=valorpago-quant*2.60;
		break;
		
		case 3 :
		quant=(valorpago/12);
		troco=valorpago-quant*12;
		break;
		
		default :
		quant=0;
		troco=valorpago;
		printf("tipo de bilhete invalido\n");
	
		}
		printf("%d bilhetes e troco: %.2f R$\n",quant,troco);
	
	getche();
}
