#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

int i;
char substitui(char nome[],char nome_novo[])
{
	for(i=0;i<=strlen(nome);i++)
	nome_novo[i]=toupper(nome[i]);
	puts(nome_novo);
	for(i=0;i<strlen(nome_novo);i++)
	{
		switch(nome_novo[i])
		{
		case 'A': nome_novo[i]='*';break;
		case 'E': nome_novo[i]='*';break;
		case 'I': nome_novo[i]='*';break;	
		case 'O': nome_novo[i]='*';break;	
		case 'U': nome_novo[i]='*';break;
		default: nome_novo[i]=nome[i];	
		}	
	}
}

main()
{
	char nome[50],nome_novo[50];
	printf("digite algo: ");
	gets(nome);
	substitui(nome,nome_novo);
	puts(nome_novo);
	
	getche();	
}
