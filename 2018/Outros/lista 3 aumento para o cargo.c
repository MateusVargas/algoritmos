#include <stdio.h>
#include <conio.h>
#include <string.h>
main()
{
	char cargo;
	float salario,novo_s,diferenca;
	printf("informe seu cargo: G-gerente E-engenheiro T-tecnico\n");
	scanf("%s",&cargo);
	printf("informe seu salario: ");
	scanf("%f",&salario);
	
	if(cargo!='G'&&cargo!='E'&&cargo!='T')
	{novo_s=salario*1.40;
	printf("novo salario: %.2f R$\n\n",novo_s);
	}
	else if(cargo=='G'){
	novo_s=salario*1.10;
	printf("novo salario: %.2f R$\n\n",novo_s);
	}
	else if(cargo=='E'){
	novo_s=salario*1.20;
	printf("novo salario: %.2f R$\n\n",novo_s);	
	}
	else if(cargo=='T'){
	novo_s=salario*1.30;
	printf("novo salario: %.2f R$\n\n",novo_s);
	}
	diferenca=novo_s-salario;
	
	printf("seu salario era %.2f R$ e agora e: %.2f R$, diferenca de %.2f R$",salario,novo_s,diferenca);
	
	getche();
}
