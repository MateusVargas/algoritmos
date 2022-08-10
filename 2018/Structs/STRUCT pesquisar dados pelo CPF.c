#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct 
{
	char nome[100];
	char cpf[11];
	float alt,peso;
	char sexo;
}dados;

#define total_pessoas 50

main()
{
	int i=0;
	char cpf_localizador[11];
	dados d1[total_pessoas];
	printf("digite o nome da pessoa %d: ",i+1);
	gets(d1[i].nome);
	while(strcmp(d1[i].nome,"fim")!=0)
	{
	printf("digite o sexo da pessoa %d: ",i+1);
	scanf("%c",&d1[i].sexo);
	printf("digite a altura da pessoa %d: ",i+1);
	scanf("%f",&d1[i].alt);
	printf("digite o peso da pessoa %d: ",i+1);
	scanf("%f",&d1[i].peso);
	fflush(stdin);
	printf("informe o CPF da pessoa %d: ",i+1);
	scanf("%s",&d1[i].cpf);
	i++;
		
	fflush(stdin);
	printf("digite o nome: ",i+1);
	scanf("%s",&d1[i].nome);
	}
	
	printf("informe o CPF da pessoa que voce quer achar: ");
	scanf("%s",&cpf_localizador);
	
	int t=i;
	
	int procura=0;
	for(i=0;i<t;i++)
	{
		if(strcmp(cpf_localizador,d1[i].cpf)==0)
		{
		procura=1;
		printf("\nsexo\tnome\tIMC");
		float imc = d1[i].peso / (d1[i].alt * d1[i].alt);
		printf("\n%c\t\t%s\t\t%.2f\n",d1[i].sexo,d1[i].nome,imc);
		break;	
		}
		
		if(procura==0)
		printf("pessoa inexiste");
	}
	
	getche();
}
