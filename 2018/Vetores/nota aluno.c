#include <stdio.h>
#include <conio.h>
main()
{
	float nota[5],media=0,soma=0;
	int i,cont=0;
	for(i=0;i<5;i++)
	{
	printf("informe a nota do aluno: ");
	scanf("%f",&nota[i]);
	soma=soma+nota[i];
	}
	media=soma/5;
	for(i=0;i<5;i++)
	{
	if(nota[i]>media)
	cont++;
	}
	printf("media das notas: %.2f\n",media);
	printf("alunos acima da media: %d",cont);
	
	getche();
}
