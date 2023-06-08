#include <stdio.h>

int seq(int n){
	if(n<=1){
		return n;
	}
	return 2*seq(n-1)+seq(n-2);
}

int main(){
	printf("%d",seq(5));
	return 0;
}