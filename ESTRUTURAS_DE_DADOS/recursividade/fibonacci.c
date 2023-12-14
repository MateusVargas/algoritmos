#include <stdio.h>
#include <stdlib.h>

int fib(int n,int v){
	printf("%d  %d\n",n,v);
	if(n<=2){
		return 1;
	}
	return fib(n-1,5)+fib(n-2,80);
}

void sequencia(int prim,int seg,int i,int n){
	if(i==n) return;
	
	if(i<2){
		printf("%d\t",prim);
	}
	else{
		int aux=prim;
		prim = seg;
		seg = aux+prim;
		printf("%d\t",seg);
	}

	sequencia(prim,seg,i+1,n);
}

int main(void){
	//for(int i=0;i<7;i++){
		printf("tt %d\n\n\n",fib(6,1));
	//}
	
	sequencia(1,1,0,12);
	
	return 0;
}
