#include <stdio.h>
#include <conio.h>
main()
{
	int num,cont1=0;
	do
	{
	printf("\ndigite um numero ou -999 para encerrar: ");
	scanf("%d",&num);
		
		if (num%2!=0 && num!=-999){
		cont1++;
		printf("impar\n");
		}
		
	}while(num!=-999);
	
	printf("total de valores impares: %d",cont1);
	
	
	
	
	getch();
}
