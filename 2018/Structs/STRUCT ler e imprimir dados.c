/*Fac¸a um programa que realize a leitura dos seguintes dados relativos a um conjunto de
alunos: Matricula, Nome, Nota1 e Nota2. Considere uma turma de ´
ate 10 alunos. Ap ´ os ler todos os dados digitados, e depois de armazen ´ a-los em um vetor ´
de estrutura, exibir na tela a listagem final dos alunos com as suas respectivas medias ´
finais (use uma media ponderada: Nota1 com peso=1.0 e Nota2 com peso=2.0). ´*/
#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct 
{
	char nome[20];
	int matr;
	float n1,n2;
}dados;

#define alunos 4

main()
{
	dados d1[alunos];
	int i;
	
	for(i=0;i<alunos;i++)
	{
		printf("\ninforme nome: ");
		scanf("%s",&d1[i].nome);
		printf("informe matricula: ");
		scanf("%d",&d1[i].matr);
		printf("informe nota 1: ");
		scanf("%f",&d1[i].n1);
		printf("informe nota 2: ");
		scanf("%f",&d1[i].n2);
	}
	
	for(i=0;i<alunos;i++)
	{
	printf("ALUNO: %s\n",d1[i].nome);
	printf("MATRICULA: %d\n",d1[i].matr);
	printf("PRIMEIRA NOTA: %.1f\n",d1[i].n1);
	printf("SEGUNDA NOTA: %.1f\n",d1[i].n2);		printf("MEDIA %.1f\n\n",(d1[i].n1+d1[i].n2)/2);
}


}
