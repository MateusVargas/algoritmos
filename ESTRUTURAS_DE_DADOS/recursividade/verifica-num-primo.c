#include <stdio.h>
#include <stdlib.h>

int conta_divisores(int num,int numDec,int totalDiv){
	if(numDec==0){
		return totalDiv;
	}
	
	if(num%numDec==0){
		totalDiv++;
	}
	
	numDec--;
	return conta_divisores(num,numDec,totalDiv);
}

int main(){
	int num=7;
	if(conta_divisores(num,num,0)==2){
		printf("primo");
	}
	else{
		printf("nao eh primo");
	}
	return 0;
}
