#include <stdio.h>
#include <conio.h>
main()
{
	int i,a,b,c,soma;
	
	printf("digite um valor para I: ");
	scanf("%d",&i);
	printf("digite um valor para A: ");
	scanf("%d",&a);
	printf("digite um valor para B: ");
	scanf("%d",&b);
	printf("digite um valor para C: ");
	scanf("%d",&c);
	
	switch(i)
	{
		case 1: printf("%d,%d,%d\n",a,b,c);
	{
		if(a>b&&a>c)
		printf("maior numero: %d",a);
		
		else if(b>a&&b>c)
		printf("maior numero: %d",b);
	
		else if(c>b&&c>a)
		printf("maior numero: %d",c);
	}break;
	
		case 2: printf("%d,%d,%d\n",a,b,c);
	{
		if(a<b&&a<c)
		printf("menor numero: %d",a);
		
		else if(b<a&&b<c)
		printf("menor numero: %d",b);
		
		else if(c<a&&c<b)
		printf("menor numero: %d",c);
	}break;
	
		case 3: printf("%d,%d,%d\n",a,b,c);
	{
		soma=a+b+c;
		printf("soma: %d",soma);
	
	}break;
	
	}
	getche();
}
