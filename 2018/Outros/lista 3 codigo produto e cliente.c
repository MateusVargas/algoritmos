#include <stdio.h>
#include <conio.h>

int main ()
{
	int client_code,code,quant; float divida;
	printf("codigo do cliente: ");
	scanf("%d",&client_code);
	printf("informe o codigo do produto: ");
	scanf("%d",&code);
	printf("informe a quantidade comprada: ");
	scanf("%d",&quant);
	
	if (client_code <=0){
		printf("codigo de cliente invalido\n");
		}
	if (client_code >5){
	printf("codigo de cliente invalido\n");
		}
	
	switch (code)
	{	case 1001:divida = quant*5.32;
		printf("seu codigo de cliente e %d, o codigo do produto e 1001 e sua divida: %.2fR$",client_code,divida);break;
		
		case 1324:divida = quant*6.45;
		printf("seu codigo de cliente e %d, o codigo do produto e 1324 e sua divida: %.2fR$",client_code,divida);break;
		
		case 6548:divida = quant*2.37;
		printf("seu codigo de cliente e %d, o codigo do produto e 6548 e sua divida: %.2fR$",client_code,divida);break;
		
		case 987:divida = quant*5.32;
		printf("seu codigo de cliente e %d, o codigo do produto e 0978 e sua divida: %.2fR$",client_code,divida);break;
		
		case 7623:divida =quant*6.45;
		printf("seu codigo de cliente e %d, o codigo do produto e 7623 e sua divida: %.2fR$",client_code,divida);break;
		default :
		printf("codigo do produto invalido");
	}
	
	getche();
}
