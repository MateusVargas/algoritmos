#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int total=0;

void empilhar(char pilha[100],char c){
	pilha[total]=c;
	total++;
}

char desempilha(char pilha[100]){
	char c=pilha[total-1];
	pilha[total-1]='\0';
	total--;
	return c;
}

void inverte(char texto[100]){
	char pilha[100];
	int k=0;
	for(int i=0;i<=strlen(texto);i++){
		if(texto[i]!=' ' && texto[i]!='\0') empilhar(pilha,texto[i]);
		else{
			for(int j=k;j<i;j++){
				texto[j]=desempilha(pilha);
			}
			k=i+1;
		}
		
	}
	
}

int main(){
	char texto[100]={"este exercicio e muito facil"};
	inverte(texto);
	puts(texto);
	
	return 0;
}
