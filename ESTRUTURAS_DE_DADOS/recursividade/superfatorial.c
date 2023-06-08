#include <stdio.h>
#include <stdlib.h>

int fatorial(int n){
	if(n==1) return 1;
	return n*fatorial(n-1);
}

int superfatorial(int n){
	if(n==0) return 1;
	int super = fatorial(n);
	return super*superfatorial(n-1);
}

void mostrar(int i,int n){
	if(i>n) return;
	printf("%d\t",i);
	i+=2;
	mostrar(i,n);
}

int main(){
	mostrar(0,90);
	printf("%d",superfatorial(4));
	return 0;
}
