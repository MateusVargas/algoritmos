#include <stdio.h>
#include <conio.h>
main()
{
	float media=0,soma=0;
	int n,maior,menor=9999999999,cont1=0;
	do
	{
		printf("informe o peso de uma pessoa ou 0 para encerrar: ");
		scanf("%d",&n);
		if(n>0)cont1++;
		
		if (n==1)
		maior=n;
		else
			if (n>maior)
			maior=n;
		
		if (n==1)
		menor=n;
		else
			if(n<menor&&n!=0)
			menor=n;
		
		soma=soma+n;
		media=soma/cont1;
		
	}while(n>0);
	printf("maior peso: %d Kg\n",maior);
	printf("menor peso: %d Kg\n",menor);
	printf("media dos pesos: %.2f",media);
	
	
	
	
	
	getche();
}
