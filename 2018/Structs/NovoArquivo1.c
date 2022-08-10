#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct
{
	char prod[20];
	char vend[8];
	float preco;	
}
tvenda;

float acha_mais_caro(tvenda vetor[],int t)
{
	int i,indice;
	float maior=0.0;
	for(i=0;i<t;i++)
	{
		if((vetor[i].preco)>maior)
		{
			maior=vetor[i].preco;
			indice=i;
		}
	}
	printf("produto mais caro %s preco e RS %.2f e o vendedor e %s",vetor[i].prod,maior,vetor[i].vend);
	
}

main()
{
	tvenda v[10];
	int i=0;
	
	printf("digite produto vendedor e preco(ou fim para encerrar)\n");
	printf("produto: ");
	scanf("%s",&v[i].prod);
	
	while(strcmp(v[i].prod,"fim")!=0)
	{
		printf("vendedor: ");
		scanf("%s",&v[i].vend);
		printf("preco: ");
		scanf("%f",&v[i].preco);
		i++;
		fflush(stdin);
		printf("produto: ");
		scanf("%s",&v[i].prod);
	}
	
	int t=i;
	
	for(i=0;i<=t;i++){
	printf("%s %s %.2f \n",v[i].prod,v[i].vend,v[i].preco);
	}
	acha_mais_caro(v,t);
	
	getche();
}
