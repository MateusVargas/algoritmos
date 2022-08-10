#include <stdio.h>
#include <conio.h>
main()
{
	int num,i,soma=0,cont1=0,cont2=0;
	float media;
	for(i=0;i<10;i++)
	{
		printf("digite um numero: ",i);
		scanf("%d",&num);
		soma=soma+num;
		media=soma/i;
		
		if(num>0)
		soma=soma+num;
		media=soma/10;
		
		if (num<0)cont1++;
		
		if (num==0)cont2++;
		
	}
	printf("media dos numeros digitados: %.2f\n",media);
	printf("media dos numeros positivos: %.2f\n",media);
	printf("numeros negativos digitados: %d\n",cont1);
	printf("numeros nulos digitados: %d\n",cont2);
	
	
	
	
	getche();
}
