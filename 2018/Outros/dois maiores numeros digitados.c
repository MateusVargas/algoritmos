#include <stdio.h>
#include <conio.h>
main()
{
	int num,maior,segundo_maior;
	
	printf("digite o primeiro numero: ");
	scanf("%d",&num);
	printf("digite o segundo numero: ");
	scanf("%d",&num);
	if(maior>num)
	segundo_maior=num;
	else 
	{
	segundo_maior=maior;
	maior=num;
	}
	for(int i=2;i<10;i++)
	{
		printf("digite outro numero: ");
		scanf("%d",&num);
		
		if(num>maior){
		segundo_maior=maior;
		maior=num;
			}
		else if(num>segundo_maior)
			segundo_maior=num;
	}
	printf("maior numero digitado: %d\n",maior);
	printf("segundo maior numero: %d",segundo_maior);
	
	getche();
}
