#include <stdio.h>
main()
{
	int i,num;
	float fat=1;
	printf("digite um numero: ");
	scanf("%d",&num);
	for (i=1;i<=num;i++){	
	fat=fat*i;
		}
	printf("fatorial do numero digitado: %.0f",fat);
	
	return 0;
}
