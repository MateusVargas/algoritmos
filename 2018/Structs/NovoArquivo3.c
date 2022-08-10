#include <stdio.h>
#include <conio.h>
#include <string.h>

int i;
main()
{
	struct carro
	{
		int ano;
		float preco;
		char marca[15];
	};
	
	struct carro info[5];
	float  p;
	
	for(i=0;i<5;i++)
	{
		printf("informe a marca do carro: ");
		scanf("%s",&info[i].marca);
		printf("informe o preco do carro: ");
		scanf("%f",&info[i].preco);
		printf("digite o ano: ");
		scanf("%d",&info[i].ano);
		
			printf("informe um preco para comparacao: ");
		scanf("%f",&p);
		
	}
	
	int k=0;
	char vet[15];
	for(i=0;i<5;i++){
		
	if(info[i].preco < p)
		vet[k]=info[i].marca;
		k=k+1;
	}
	
	for(i=0;i<k;i++)
	printf("%s",vet[i]);
	
	
}
