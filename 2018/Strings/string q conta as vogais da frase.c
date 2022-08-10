#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

int verifica_vogal (char M)
{
	if(M=='A'||M=='E'||M=='I'||M=='O'||M=='U')
		return(1);
	else
		return(0);
}
main()
{
	char x[50];
	int i,cont1=0;
	printf("digite uma frase: ");
	gets(x);
	
	for(i=0;i<strlen(x );i++)
	{
	x[i]=toupper(x[i]);
	}
	
	for(i=0;i<strlen(x );i++)
	{
		if(verifica_vogal(x[i])==1)
		{
	printf("\n A letra [ %c ] e uma vogal: ",x[i]);
	cont1++;
		}
		else
		printf("\n A letra [ %c ] e uma constante: ",x[i]);
	}
	
	printf("\no numero de vogais e %d",cont1);
	printf("\n\n");
	
	getche();	
}
