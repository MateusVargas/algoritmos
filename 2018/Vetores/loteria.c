#include <stdio.h>
#include <conio.h>
int contap(int gab[6], int aposta[6], int pontos)
{
	int i;
	for(i=0;i<6;i++)
	{
	if(aposta[i]==gab[i])
		pontos++;
		}
	if(pontos==6)
		printf("voce ganhou na loteria\n");

		else
		printf("voce fez %d pontos\n",pontos);
}
main()
{
	int gab[6], aposta[6], code, pontos=0;
	for(int i=0;i<6;i++)
	{
		printf("informe o gabarito: ",i);
		scanf("%d",&gab[i]);
		}	
	printf("informe o codigo do apostador: ");
	scanf("%d",&code);
		
		while(code!=0)
		{
		for(int i=0;i<6;i++)
		{
		printf("informe sua aposta: ",i);
		scanf("%d",&aposta[i]);
			}
			
	contap(gab,aposta,pontos);
			
	printf("informe o codigo do apostador: ");
	scanf("%d",&code);
			
}

getche();
}
