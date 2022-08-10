#include <stdio.h>
#include <conio.h>

int main ()
{
	int N,i;
	for (int i=1;i<10000;i++){
	printf("digite %d° numero: ",i);
	scanf("%d",&N);
	
	if (N==0)
	printf("zero\n");
	if (N<0)
	printf("negativo\n");
	if(N>0)
	printf("positivo\n");
	
	}
	
	
	
	getche();
}
