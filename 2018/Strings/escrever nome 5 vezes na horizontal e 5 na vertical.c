#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
main()
{
	char palavra[50];
	double k;//valor de k muito grande
	puts("digite o nome: ");
	gets(palavra);
	printf("\n");
	
	int tamanho=strlen(palavra);
	int x,y;
	
	for(x=0;x<tamanho;x++)
		printf("%s ",palavra); 
	
		printf("\n");
	
	for(x=0;x<tamanho;x++)
		printf("%s\n",palavra);
	
	for(y=0;y<tamanho;y++)
	{
		printf("%c \n",palavra[y]);
		printf("\n");
	
		for(k=0;k<10000000;k++);	
	}
	
	printf("\n");
	
	getche();	
}
