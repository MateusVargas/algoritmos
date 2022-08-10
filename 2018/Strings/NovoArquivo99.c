#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct 
{
	char nome[20];
	char endereco[20];
	char rua;
}ordem;

#define pessoas 3

main()
{
	ordem vet[pessoas];
	char temp[20];
	int i,j,soma=0;
	
	for(i=0;i<pessoas;i++){
	 printf("informe nome: ");   
      scanf("%s",&vet[soma].nome);
      fflush(stdin);                
      soma ++;
	 
	 printf("informe endereco: ");
	 scanf("%s",&vet[i].endereco);
	 
	 printf("informe rua: ");
	 scanf("%s",&vet[i].rua);
}

	     for(i = 1; i < soma; i++)
	     {
         for (j = 0; j < soma-1; j++)
	     	{
      if(strcmp(vet[j].nome,vet[j+1].nome) > 0){
                strcpy(temp,vet[j].nome);
                 strcpy(vet[j].nome,vet[j+1].nome);
                 strcpy(vet[j+1].nome,temp);
                } 
}
}
   for(i=0;i<soma;i++)
   { 
     printf("\n");   
     printf("nome = %s\t",vet[i].nome);
     }  
      
}
