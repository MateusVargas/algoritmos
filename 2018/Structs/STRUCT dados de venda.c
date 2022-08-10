#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct
{
 	char prod[20];
 	char vend[8];
 	float preco;
}
Tvenda;

main()
{
	Tvenda v[10];	
 	int i=0;
	
	printf("digite produto vendedor e preco (para encerrar digite fim)\n");
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
 	int soma=0;
 	float media=0;
 	
 	for(i=0;i<=t;i++)
 	printf("%s %s %.2f \n",v[i].prod,v[i].vend,v[i].preco);
 	
 	for(i=0;i<=t;i++){
 	soma=soma+v[i].preco;
 	}
 	printf("soma %d",soma);
 	
 	for(i=0;i<=t;i++){
 	media=soma/t;	
 	}
 	printf("media %.2f",media);
 	
 	getche();
}
