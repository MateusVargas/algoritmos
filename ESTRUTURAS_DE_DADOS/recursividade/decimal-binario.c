#include <stdio.h>

void converter(int n){
	if(n==0) return;
	converter(n/2);
	printf("%d",n%2);
}

int main(){
	converter(12);
}
