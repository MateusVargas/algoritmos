#include <stdio.h>
#include <conio.h>

int troca(int b[9],int x,int p)
{
	int i;
	
for (i=0;i<p;i++)
	{
	printf("\nb[%d]= %d\n",i,b[i]);
	}
for (i=p;i<=p;i++)
	{
	printf("b[%d]= %d\n",p,x);	
	}
for (i=p;i<10;i++)
	{
	printf("b[%d]= %d\n",i+1,b[i]);
	}
}
main()
{
	int b[9],x,p;
	printf("informe o valor de X: ");
	scanf("%d",&x);
	printf("informe de 0 a 9 o valor de P: ");
	scanf("%d",&p);
	
	printf("informe os dados do vetor\n");	
	for(int i=0;i<10;i++)
	{
	printf("B[%d]= ",i);
	scanf("%d",&b[i]);		
	}
	troca(b,x,p);
	
	getche();	
}
