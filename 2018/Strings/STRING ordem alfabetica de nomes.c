#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	
   char  nome[30];

   }dados;

main()     
{
	  dados vet[100];
      int op=0,soma=0,i,j;
      char temp[30];
                   
while(op!=3){
                  
      printf("\n==============MENU==================\n");            
      printf("1-Cadastrar Pessoa: \n");                    
      printf("2-Ordenar por Nome: \n");      
      printf("3-Sair\n\n");
      scanf("%d",&op);
     
      if(op==1)
     { 
      printf("informe nome: ");   
      scanf("%s",&vet[soma].nome);
      fflush(stdin);                
      soma ++;
      }
         
            
    if(op==2)
      {
    printf("=================================\n");
    printf("Ordenando por nome");       
              
    //ordena
     for(i = 1; i < soma; i++){
         for (j = 0; j < soma-1; j++){
                       
              if(strcmp(vet[j].nome,vet[j+1].nome) > 0){
                strcpy(temp,vet[j].nome);
                 strcpy(vet[j].nome,vet[j+1].nome);
                 strcpy(vet[j+1].nome,temp);}                               
           }      
         }
                      
     //imprime                   
      for(i=0;i<soma;i++){ 
      printf("\n");   
      printf("nome = %s\n",vet[i].nome);}}
                     
    if(op==3){
    printf("Encerrando Programa...\n");
    system("pause");        
    exit(0);} 

  }// fim while
}// fim main}
