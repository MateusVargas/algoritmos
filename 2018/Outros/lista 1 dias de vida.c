#include <stdio.h>

int main ()
{
	int a, m, d, total;
	
	printf("digite os anos: ");
	scanf("%d", &a);
	printf("digite os meses: ");
	scanf("%d", &m);
	printf("digite os dias: ");
	scanf("%d", &d);
	
	total = a * 365 + m * 30 +d;
	
	printf("total em dias: %d",total);
	return 0;	
}
