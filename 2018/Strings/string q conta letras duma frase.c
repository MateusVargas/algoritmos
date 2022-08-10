#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
main()
{
	char palavra[50];
	int i,cont1=0;
	
	printf("escreva algo: ");
	gets(palavra);
	int tamanho=strlen(palavra);
	
	printf("comprimento da string: %d \n",tamanho);
	
	for(i=0;i<tamanho;i++)
	{
		if(palavra[i]!=' ')
		cont1++;
	}
	
	printf("numero de letras da palavra ou frase: %d",cont1);
	
	getche();
}
