#include <stdio.h>
#include <conio.h>

int main ()
{
	int num,i,cont1=0,cont2=0;
	for(int i=0;i<10;i++){
		printf("digite um numero: ",i+1);
		scanf("%d",&num);
		
		if (num >= 10 && num <= 20) cont1++;
		else
		cont2++;
		}
		printf("total de numeros entre 10,20: %d \n e total de numeros fora: %d",cont1,cont2);
	
	getche();
}
