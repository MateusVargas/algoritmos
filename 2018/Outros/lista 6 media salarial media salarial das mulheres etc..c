#include <stdio.h>
#include <conio.h>
#include <string.h>

main()
{
	char sexo;
	int idade,nent=0,nh500=0;
	float salario,sal_soma=0,msalm35=0;
	
	printf("digite a idade do entrevistado ou 0 pra encerrar: ");
	scanf("%d",&idade);
	
	do
	{
	printf("digite o sexo do entrevistado = M-masculino ou F-feminino: ");
	scanf("%s",&sexo);
		
	if(sexo!='M'&&sexo!='F')
	printf("opcao invalida");
		
	printf("digite o salario do entrevistado: ");
	scanf("%f",&salario);
	sal_soma=sal_soma+salario;
	nent=nent+1;
		
	if(sexo=='F'&&idade<35)
	{
	if(salario>msalm35)
	msalm35=salario;
	}
	if(sexo=='M'&&salario>500)
	nh500++;
	
	printf("digite a idade do entrevistado ou 0 pra encerrar: ");
	scanf("%d",&idade);
		
	}while(idade>0);
	
	float  media=sal_soma/nent;
	printf("\n\na media salarial do grupo e %.2f R$\n",media);
	printf("o maior salario das mulheres com menos de 35 anos e: %.2f R$\n",msalm35);
	
	float p;
	p=100*nh500/nent;
	printf("o percentual de homens com salario maior que 500 R$ e: %.2f por cento",p);
	
	
	getche();
}
