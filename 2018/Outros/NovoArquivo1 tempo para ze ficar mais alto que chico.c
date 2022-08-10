#include <stdio.h>
#include <conio.h>
main()
{
	int anos;
	float alt1,alt2,tam1,tam2;
	alt1=1.50;
	alt2=1.10;
	tam1=0.02;
	tam2=0.03;
	anos=0;
	
	while(alt1>alt2)
	{
		alt1=alt1+tam1;
		alt2=alt2+tam2;
		
		anos++;		
	}
	printf("serao necessarios %d anos para que ze se torne mais alto que chico",anos);
	
	getche();	
}
