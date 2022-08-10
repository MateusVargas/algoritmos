#include <stdio.h>
#include <conio.h>

int main ()

{
	float pequeno, medio, grande, total;
	printf("quantas camisas tamanho P voce quer? ");
	scanf("%f",&pequeno);
	printf("quantas tamanho M? ");
	scanf("%f",&medio);
	printf("quantas tamanho G? ");
	scanf("%f",&grande);
	
	total=pequeno*10 + medio*12 + grande*15;
	printf("total a pagar: %.2f R$",total);
	
	getche();
}
	
	
	
