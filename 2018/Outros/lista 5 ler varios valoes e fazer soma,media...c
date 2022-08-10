#include <stdio.h>
#include <conio.h>
main()
{
	float media=0,soma=0;
	int num,cont1=0;
	do{
	printf("digite um numero positivo ou um negativo pra acabar: ");
	scanf("%d",&num);
	
		if(num>=0)cont1++;
		
		if(num>=0){
		soma=soma+num;
		}
		media=soma/cont1;
		
	}while(num>=0);
	
	printf("soma total: %.2f\n",soma);
	printf("media dos numeros: %.2f\n",media);
	printf("total de valores lidos: %d\n",cont1);
	
	
	getch();
}
