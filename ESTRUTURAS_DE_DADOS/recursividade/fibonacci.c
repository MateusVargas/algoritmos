#include <stdio.h>
#include <stdlib.h>

int fib(int n,int v){
	printf("%d  %d\n",n,v);
	if(n<=2){
		return 1;
	}
	return fib(n-1,5)+fib(n-2,80);
}

int main(void){
	//for(int i=0;i<7;i++){
		printf("%d",fib(6,1));
	//}
	
	
	return 0;
}
