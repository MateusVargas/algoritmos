#include <stdio.h>
#include <conio.h>
#include <string.h>
int i;
int conta(char letra, char nome[],int tamanho)
{
	char l;
	int k=0,n;
	for(i=0;i<tamanho;i++){
	if(nome[i]==letra){
		n=i;
		l=letra;
		k=k+1;
		}
	}
	
	for(i=0;i<k;i++)
	printf("%d %c",n,l);
	
}
main()
{
	char letra,nome[50];
	printf("escreva uma letra: ");
	scanf("%c",&letra);
	fflush(stdin);
	printf("escreva uma frase: ");
	scanf("%s",&nome);
	int tamanho=strlen(nome);
	
	conta(letra,nome,tamanho);
	
	getche();
}
