#include <stdio.h>
#include <conio.h>

main()
{
	char gab[10],resp[10];
	int i,pontos=0;
	printf("informe o gabarito\n");
	for(i=0;i<10;i++)
	{
		printf("gab[%d]= ",i);
		scanf("%c",&gab[i]);
	}
	
	printf("informe as respostas do aluno\n");
	for(i=0;i<10;i++)
	{
		printf("resp[%d]= ",i);
		scanf("%c",&resp[i]);
	}
	
	for(i=0;i<10;i++)
	{
	if(resp[i]==gab[i])
	pontos++;
	}
	
	printf("o aluno fez %d pontos\n",pontos);
	
	if(pontos<6)
	printf("reprovado");
	else
	printf("aprovado");
	
	
	getche();	
}
