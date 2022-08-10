#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
main()
{
	typedef struct
	{
		char nome[30];
		int idade;
		char sexo;
		float altura;
	}pessoas;
	
		int i=0;
	pessoas povo[20];
	
	printf("nome(fim-para encerrar): ");
	scanf("%s",&povo[i].nome);
	
	while(strcmp((povo[i].nome),"fim")!=0)
	{
	printf("digite sua idade: ");	
	scanf("%d",&povo[i].idade);
	printf("digite o sexo: ");	
	scanf("%c",&povo[i].sexo);
	printf("digite a altura: ");
	scanf("%f",&povo[i].altura);	
	fflush(stdin);
	i=i+1;
			
	printf("nome(FIM-para encerrar): ");
	scanf("%s",&povo[i].nome);
			
	}
	
	int t=i;
	printf("valor de i %d",i);
	for(i=0;i<=t;i++){
	printf("\n");printf("\n");
	puts(povo[i].nome);
	printf("idade-----> %d\t",povo[i].idade);
	printf("sexo------> %c\t",povo[i].sexo);
	printf("altura----> %.2f\t",povo[i].altura);
			
	}
	
	getche();	
}
