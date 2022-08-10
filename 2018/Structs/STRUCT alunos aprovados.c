#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct 
{
	char nome[50];
	int matricula;
	float media;
	
} info;

#define alunos 3

main()
{
	info v[alunos];
	int i,apr[3];
	
	for(i=0;i<alunos;i++){
	printf("informe nome do aluno %d: ",i+1);
	scanf("%s",&v[i].nome);
	printf("informe matricula do aluno %d ",i+1);
	scanf("%d",&v[i].matricula);
	printf("informe media do aluno %d ",i+1);
	scanf("%f",&v[i].media);
	}
	
	int ind,k=0;
	for(i=0;i<alunos;i++)
	{
		if(v[i].media>7)
		{
		apr[k]=v[i].media;
		ind=i;
		k++;
		}
	}
	
	for(i=0;i<k;i++){
	printf("alunos aprovados %d, media %d",ind,apr[i]);
	}
		
	getche();	
}
