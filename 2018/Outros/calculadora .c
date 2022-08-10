#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
	setlocale(LC_ALL,"portugues");
	int op;
	float x,y,raiz,seno,resultado;
	printf("informe a operação desejada.\n");
	printf("1-Soma\n");
	printf("2-Subtração\n");
	printf("3-Multiplicação\n");
	printf("4-Divisão\n");
	printf("5-Raíz Quadrada\n");
	printf("6-Seno\n\n");
	scanf("%d",&op);
	
	if(op==5){
		printf("digite um numero: ");
		scanf("%f",&raiz);
	}
	if(op==6){
		printf("digite um numero: ");
		scanf("%f",&seno);	
	}
	else if (op>0&&op<5)
	{
	printf("\ndigite um numero: ");
	scanf("%f",&x);
	printf("\ndigite outro numero: ");
	scanf("%f",&y);
	}
	
	switch(op)
	{
		case 1:
		resultado=x+y;
		printf("\nresultado: %.0f",resultado);
		break;
		
		case 2:
		resultado=x-y;
		printf("\nresultado: %.0f",resultado);
		break;
		
		case 3:
		resultado=x*y;
		printf("\nresultado: %.0f",resultado);
		break;
		
		case 4:
		resultado=x/y;
		printf("\nresultado: %.2f",resultado);
		break;
		
		case 5:
		resultado=sqrt(raiz);
		printf("\nraiz de %.0f: %.2f",raiz,resultado);
		break;
		
		case 6:
		resultado=sin(seno);
		printf("\nseno de %.0f: %.4f",seno,resultado);
		break;
		
		default:
		printf("\noperação inválida");
		
	}
}
