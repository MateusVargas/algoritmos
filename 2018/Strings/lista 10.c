#include <stdio.h>
#include <errno.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
main()
{
	char nome[20];
	char nomeB[20];
	printf("digite uma frase: ");
	scanf("%s",&nome);
	int i,k=0;
	int tamanho=strlen(nome);
	
	for(i=0;i<tamanho;i++)
	{
		if(nome[i]!=isspace(nome[i]))
		{
		nomeB[k]=nome[i];
		k=k+1;
		}
	}
	
	for(i=0;i<k;i++)
	printf("%s",nomeB[i]);
	
	
	
	getche();	
}
