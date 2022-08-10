#include <stdio.h>
#include <conio.h>
#include <string.h>
int i;
main()
{
	int soma=0,soma_sal=0,cont=0;
	float media_id=0,media_sal=0;
	
	typedef struct
	{
		int idade;
		int num_filhos;
		char sexo[10];
		float salario;
	}pesquisa;	
	
	pesquisa d1[5];
	
	for(i=0;i<5;i++)
	{
	printf("pessoa %d\n",i+1);
	printf("informe a idade: ");
	scanf("%d",&d1[i].idade);
	printf("informe o sexo: ");
	scanf("%s",&d1[i].sexo);
	printf("informe o salario: ");
	scanf("%f",&d1[i].salario);
	}
	if(d1[i].idade>0)
	cont++;
	
	for(i=0;i<5;i++){
	soma=soma+d1[i].idade;
	soma_sal=soma_sal+d1[i].salario;
	}
	for(i=0;i<5;i++){
	media_sal=soma_sal/5;
	}
	for(i=0;i<5;i++){
	media_id=soma/5;
	}
	printf("media das idades %.2f\n",media_id);
	printf("media salarial %.2f\n",media_sal);
	printf("%d",cont);
	
	getche();	
}
