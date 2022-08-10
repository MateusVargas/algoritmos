#include <stdio.h>
#include <conio.h>
main()
{
	int i,a[5],b[5],c[5];
	printf("dados do vetor A\n");
	for(i=0;i<5;i++)
	{
	printf("A[%d]= ",i);
	scanf("%d",&a[i]);
		}
		
	printf("dados do vetor B\n");
	for(i=0;i<5;i++)
	{
	printf("B[%d]= ",i);
	scanf("%d",&b[i]);
		}
	
	printf("\nvetor C\n");
	for(i=0;i<5;i++)
	{
	c[i]=a[i]*b[i];
		printf("C[%d]= %d\n",i,c[i]);
		}
		
	getche();	
}
