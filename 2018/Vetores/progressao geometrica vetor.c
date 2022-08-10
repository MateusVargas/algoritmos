#include <stdio.h>
#include <conio.h>
#include <math.h>

main()
{
	int i,an[10],a1,q;
	printf("primeiro termo da PG: ");
	scanf("%d",&a1);
	printf("razao da PG: ");
	scanf("%d",&q);
	for(i=0;i<10;i++)
	{
	a1=a1*q;
	printf("termo a%d= %d\n",i+1,an[10]);
	}
		
	getche();
}
