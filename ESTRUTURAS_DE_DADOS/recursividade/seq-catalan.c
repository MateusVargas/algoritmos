#include <stdio.h>
#include <stdlib.h>

int seq(int n){
	if(n==0) return 1;
	return (2*(2*n-1))/n+1*seq(n-1);
}

int main(){
	printf("%d",seq(5));
	return 0;
}
