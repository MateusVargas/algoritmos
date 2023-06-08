#include <stdio.h>
#include <stdlib.h>

int soma_cubos(int i,int n){
	if(i>n) return 0;
	
	int soma,multi=1,j=0;
	while(j<3){
		multi*=i;
		j++;
	}
	soma=multi;
	return soma+soma_cubos(i+1,n);
}

int conta_digitos(int n){
	if(n==0) return 0;
	return 1+conta_digitos(n/10);
}

int soma_digitos(int n){
	if(n==0) return 0;
	int r = n%10;
	return r+soma_digitos(n/10);
}

int soma_digitos2(int x,int y){
	if(x==0 && y==0) return 0;
	int soma=y;
	soma+=soma_digitos2(x/10,x%10);
	return soma;
}

int main(){
	printf("%d",soma_cubos(1,4));
	printf("\n%d",conta_digitos(123));
	printf("\n%d",soma_digitos(460));
	printf("\n%d",soma_digitos2(123/10,123%10));
	return 0;
}
