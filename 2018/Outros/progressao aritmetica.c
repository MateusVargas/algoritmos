#include <stdio.h>
#include <conio.h>
main()
{
	int n,a1,r,an,i,soma=0;
	printf("informe o numero de termos da PA: ");
	scanf("%d",&n);
	printf("informe a razao: ");
	scanf("%d",&r);
	printf("informe o primeiro termo: ");
	scanf("%d",&a1);
	
	for(i=1;i<=n;i++)
	{
	an=a1+(i-1)*r;
	printf("termo a%d: %d\n",i,an);
		
	soma=((a1+an)*n)/2;
		
	}
	
	printf("o ultimo termo: %d\n",an);
	printf("soma dos termos: %d",soma);
	
	getch();
}
