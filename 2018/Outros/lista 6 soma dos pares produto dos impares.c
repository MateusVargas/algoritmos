#include <stdio.h>
#include <stdlib.h>
main()
{
	int num=0,soma=0,cont1=0,cont2=0,prod=1;
	do{
		
	printf("digite um numero: ");
	scanf("%d",&num);
		
	if(num%2==0){
		cont1++;
		soma=soma+num;
	}
	
	if (num%2!=0){
		cont2++;
		prod=prod*num;
	
	}
	
	}while(num>0);
	
	printf("soma dos pares: %d\n",soma);
	printf("produto dos impares: %d",prod);
	
	system("pause\n");
}
