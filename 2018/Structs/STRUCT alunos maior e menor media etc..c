/*Crie uma estrutura representando os alunos de um determinado curso. A estrutura deve
conter a matricula do aluno, nome, nota da primeira prova, nota da segunda prova e nota
da terceira prova.
(a) Permita ao usuario entrar com os dados de 5 alunos. ´
(b) Encontre o aluno com maior nota da primeira prova.
(c) Encontre o aluno com maior media geral. ´
(d) Encontre o aluno com menor media geral ´
(e) Para cada aluno diga se ele foi aprovado ou reprovado, considerando o valor 6 para
aprovacao.*/
#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct 
{
	char nome[10];
	int matr;
	int n1,n2,n3;
}desempenho;

main()
{
	desempenho aluno;
	int i=0,ind,inc,indice,maiorN1=0,maiorM=0,menorM=99999999999,soma=0;
	float media=0;
	
	printf("informe a matricula do aluno %d: ",i+1);
	scanf("%d",&aluno.matr);
	while(aluno.matr!=0)
	{
	printf("informe o NOME do aluno %d: ",i+1);
	scanf("%s",&aluno.nome);
	printf("informe nota 1 do aluno %d: ",i+1);
	scanf("%d",&aluno.n1);
	printf("informe nota 2 do aluno %d: ",i+1);
	scanf("%d",&aluno.n2);
	printf("informe nota 3 do aluno %d: ",i+1);
	scanf("%d",&aluno.n3);
			
	soma=aluno.n1+aluno.n2+aluno.n3;
	media=soma/3;
		printf("MEDIA %.1f\n",media);
	i++;	
		printf("informe a matricula do aluno %d: ",i+1);
		scanf("%d",&aluno.matr);
	
	if(aluno.n1>maiorN1){
		maiorN1=aluno.n1;
		indice=i;
		}
		
		if(media>maiorM){
		maiorM=media;
		ind=i;
		}
		
		if(media<menorM){
		menorM=media;
		inc=i;
	}
	
	}
	
	printf("aluno %d teve maior nota na prova 1 %d\n",indice,maiorN1);
	
	printf("aluno %d teve maior media -> %d\n",ind,maiorM);
	
	printf("aluno %d teve menor media -> %d\n",inc,menorM);
	
	getch();
}
