#include <stdio.h>
#include <conio.h>

typedef struct {
	int matricula;
	char nome[100];
	float nota1;
	float nota2;
} aluno;
#define quantidade_de_alunos 3
main()
{
aluno alunos[quantidade_de_alunos];
	printf("dados: nome(sem espaco), matricula, nota1, nota2\n");
	for(int i=0;i<quantidade_de_alunos;i++)
	{
	printf("\ninforme os dados do aluno(%i): ",i+1);
	scanf("%s %i %f %f",alunos[i].nome,&alunos[i].matricula,&alunos[i].nota1,&alunos[i].nota2);
	}
	printf("\nMatricula\t\tNome\t\tMedia\n");
	for(int i=0;i<quantidade_de_alunos;i++)
	{
	printf("%i\t\t\t%s\t\t\t%.2f\n",alunos[i].matricula,alunos[i].nome,(alunos[i].nota1+alunos[i].nota2)/2);	
	}
	
	getche();
}
