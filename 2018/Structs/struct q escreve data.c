#include <stdio.h>
#include <conio.h>
main()
{
	struct data
	{int dia, ano; char mes[20];	
	};
	
	struct data d1;
	printf("entre com o dia: ");
	scanf("%d",&d1.dia);
	printf("entre com o mes: ");
	scanf("%s",&d1.mes);
	printf("entre com o ano: ");
	scanf("%d",&d1.ano);
	printf("a data digitada e: ");
	printf("%d/%s",d1.dia,d1.mes);
	printf("/%d\n",d1.ano);
	
	getche();	
}
