#include <stdio.h>
#include <conio.h>
main()
{
	int fat,i,soma,num,cont1=0;
	
	printf("digite um numero: ");
	scanf("%d",&num);
	
	if(num%2==0)
	{
	for(i=1;i<=num;i++)
	{
		if(num%i==0)cont1++;
		}	
	printf("o numero %d tem %d divisores\n",num,cont1);
	}
	
	if(num%2==0&&num<10)
	{
		for(fat=1;num>1;num=num-1)
		{
			fat=fat*num;
		}
		printf("fatorial: %d",fat);
	}
	
	if(num%2!=0&&num>10)
	{
		for(soma=1;num>1;num=num-1)
		{
			soma=soma+num;
			}
			printf("soma com anteriores: %d\n",soma);
		}
	
	getche();
}
