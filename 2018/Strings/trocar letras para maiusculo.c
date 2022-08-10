#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
main()
{
	char palavra[50];
	int i;
	puts("digite uma palavra: ");
	gets(palavra);
	int tamanho=strlen(palavra);
	printf("comprimento da string: %d \n",tamanho);
	for(i=0;i<tamanho;i++)
	{
		palavra[i]=toupper(palavra[i]);
	}
	printf("palavra convertida em maiusculo: %s",palavra);
	
	getche();	
}
