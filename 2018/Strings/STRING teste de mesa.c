#include <stdio.h>
#include <conio.h>
#include <string.h>
main()
{
	char nome[]="errar";
	char apag;	
	int i=0;
	int j=0;
	
	scanf("%c",&apag);
	for(;i<strlen(nome);)
	{
		if(nome[i]!=apag) i++;
		
		if(nome[i]==apag)
		{
	nome[i]=nome[i+1];
	for(j=i+1;j<=strlen(nome);j++){
		nome[j]=nome[j+1];
		}
		
		}
	
	}

	printf("%s",nome);
}
