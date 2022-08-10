#include <stdio.h>
#include <conio.h>

int desloca (int v[5])
{
for(int i=0;i<4;i++)
{
	v[i]=v[i+1];
	printf("\nV[%d] = %d\n",i,v[i]);	
}	
	
}
main()
{
	int v[5],i;
	printf("informe os elementos do vetor\n");
	for(i=0;i<5;i++)
	{
	printf("V [%d] = ",i);
	scanf("%d",&v[i]);
	}
	desloca(v);
	
	getche();
}
