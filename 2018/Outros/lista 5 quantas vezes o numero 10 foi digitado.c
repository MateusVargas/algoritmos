#include <stdio.h>
#include <stdlib.h>
main ()
{
	int num,cont1=0;
	do{
		printf("escreva um numero ou digite 0 se quiser encerrar: ");
		scanf("%i",&num);
		
		if (num == 10)cont1++;
		
	}while(num!=0);
	
	printf("o numero 10 foi digitado %d vezes pelo usuario\n",cont1);
	
	
	system("pause\n");
}
