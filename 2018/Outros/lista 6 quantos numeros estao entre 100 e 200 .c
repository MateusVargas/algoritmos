#include <stdio.h>
#include <stdlib.h>

main ()
{
	int num,cont1=0;
	do{
		
	printf("digite um numero: ");
	scanf("%d",&num);
		
		if(num >=100 && num <= 200)cont1++;
	
	}while(num !=0);
	
	printf("numeros entre 100 e 200: %d",cont1);
	

	
	system("pause");
}
