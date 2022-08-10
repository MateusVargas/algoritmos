#include <stdio.h>
#include <conio.h>

int main ()
{
	int i,cont1=0;
	float nota,soma,media;
	for (i=0;i<5;i++)
	{
		printf("digite a nota do aluno %d: ",i+1);cont1++;
		scanf("%f",&nota);
		
		if (nota<7)
		printf("\texame\n");
		
		else
		printf("\taprovado\n");
		
	soma=soma+nota;
	media=soma/cont1;
		}

		printf("media geral das notas: %.2f",media);
			
	getche();
}
