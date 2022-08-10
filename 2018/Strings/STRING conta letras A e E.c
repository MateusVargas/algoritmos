/*4- Preencher um vetor com 3 nomes e mostrar quantas letras A e E tem nos 3 
nomes*/
#include <stdio.h>
#include <conio.h>
#include <string.h>

int contaA_E(char nome[30],int tam)
{
	int contA=0,contE=0;
	for(int i=0;i<tam;i++){
	if(nome[i]=='a'){
	contA++;
	}
	if(nome[i]=='e'){
	contE++;
	}
}	
	printf("as palavras digitadas tem %d letras A e %d letras E.",contA,contE);
}

main()
{
	char nome[30];
	int tam;
	printf("digite 3 palavras: ");
	scanf("%[^\n]",nome);
	
	tam=strlen(nome );
	
	contaA_E(nome,tam);
	
	getche();
}
