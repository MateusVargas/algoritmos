/*Determine o que a seguinte função recursiva em C calcula. Escreva 
uma função iterativa para atingir o mesmo objetivo:*/

#include <stdio.h>
#include <stdlib.h>

//soma anteriores recursivo
int func(int n) { 
	if(n==0){
		return 0;
	}
	return (n+ func(n-1)); 
}

//soma anteriores iterativo
int func2(int n){
	for(int i=n-1;i>=0;i--){
		n+=i;
	}
	return n;
}

int main(){
	printf("%d\n",func(5));
	printf("%d",func2(5));
	return 0;
}