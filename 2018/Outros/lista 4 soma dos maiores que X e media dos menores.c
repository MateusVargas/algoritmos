#include <stdio.h>
#include <conio.h>
main()
{
	float soma=0,somam=0,mediam=0;
	int x,num,i,cont1=0,cont2=0,cont3=0,kx=0;
	
	printf("digite um valor para X: ");
	scanf("%d",&x);
	for(i=0;i<5;i++)
	{
	printf("digite um numero: ",i+1);
	scanf("%d",&num);
	if(num>x)
		{cont1++;
		soma=soma+num;
		}
	else if(num<x){
		cont2++;
		somam=somam+num;
		mediam=somam/cont2;
		}
		else
		kx++;
		
		}
	
	printf("soma dos valores maiores que X: %.2f\n",soma);
	printf("media dos valores menores que X: %.2f\n",mediam);
	if (kx==1)
	printf("somente um valor igual a X.");
	getch();
}
