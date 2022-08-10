#include <stdio.h>
#include <conio.h>

int conversao(int op)
{
	float f,c;
	
switch(op){
	case 1:
	printf("informe os graus farenheidt: ");
	scanf("%f",&f);
	c=5*(f-32)/9;
	printf("graus celsius correspondente: %.2f C°",c);
	break;
	
	case 2:
	printf("informe os graus celsius: ");
	scanf("%f",&c);
	f=(9*c/5)+32;
	printf("graus farenheidt correspondente: %.2f F°",f);
	break;
	default:
	printf("opcao invalida");
}
}
main()
{
	int op;
	printf("informe a conversao desejada:\n1-graus celsius\n2-graus farenheidt\t\t\t\t");
	scanf("%d",&op);
	conversao(op);
	
	getche();
}
