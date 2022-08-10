#include <stdio.h>
#include <conio.h>
#include <string.h>
	typedef struct
	{	
		char nome[20];
		int identidade[5];
		char idade;
		float salario;
	}dados;
	
	typedef struct
	{
		int cep;
		char rua;
		char estado;
	
	}info;
	
main()
{
	int i,maior=0,ind,maiorS=0,indice,identidade_localizador[5];
	dados d1[3];
	info in[3];
	for(i=0;i<3;i++)
	{
		printf("nome pessoa %d: ",i+1);
		scanf("%s",&d1[i].nome);
		printf("idade pessoa %d: ",i+1);
		scanf("%d",&d1[i].idade);
		printf("salario pessoa %d: ",i+1);
		scanf("%f",&d1[i].salario);
		printf("identidade pessoa %d: ",i+1);
		scanf("%d",&d1[i].identidade);
		printf("cep pessoa %d: ",i+1);
		scanf("%d",&in[i].cep);
		printf("rua pessoa %d: ",i+1);
		scanf("%s",&in[i].rua);
		printf("estado pessoa %d: ",i+1);
		scanf("%s",&in[i].estado);
	}
	
	for(i=0;i<3;i++){
	if(d1[i].idade>maior){
		maior=d1[i].idade;
		ind=i+1;
		}
	}
	
	for(i=0;i<3;i++){
	if(d1[i].salario>maiorS){
		maiorS=d1[i].salario;
		indice=i+1;
		}
	}
	
	printf("\nmaior idade pessoa %d\n",ind);
	printf("\nmaior salario pessoa %d\n",indice);
	
	printf("digite a identidade que quer achar: ");
	scanf("%d",&identidade_localizador);
	
	int procura=0;
	for(i=0;i<3;i++)
	{
		if(strcmp(identidade_localizador,d1[i].identidade)==0)
		{
		procura=1;
		printf("\nnome\tidade\tsalario\tidentidade\tcep\n");
		printf("%s",d1[i].nome);
		printf("\t%d",d1[i].idade);
		printf("\t\t%.0f",d1[i].salario);	
		printf("\t\t%d",identidade_localizador);	
		printf("\t%d\t",in[i].cep);
				
		printf("%s",in[i].rua);	
			
			break;
		}
		
		if(procura==0)
		printf("pessoa inexiste");
	}
	

	getch();
}
