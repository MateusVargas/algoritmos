#include <stdio.h>

int div(int n,int y){
	if(n==y) return 1;
	if(n<y) return 0;
	return 1+div(n-y,y);
}

int mod(int x,int y){
	if(x==y) return 0;
	if(x<y) return x;
	return mod(x-y,y);
}
int main(){
	printf("%d",mod(12,1));
	printf("\n%d",div(16,2));
	return 0;
}
