#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* inverter(char *frase,int i,int j){
	if(i>=j){
		return frase;
	}
	char aux=frase[i];
	frase[i]=frase[j];
	frase[j]=aux;
	i++;
	j--;
	return inverter(frase,i,j);
}

int main(){
	char *frase=NULL;
	frase=(char*)malloc(30*sizeof(char));
	gets(frase);
	//int trocas = strlen(frase)/2;
	frase = inverter(frase,0,strlen(frase)-1);
	puts(frase);
	return 0;
}
