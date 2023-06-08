#include <stdio.h>
#include <stdlib.h>

void fib_rec(int num, int prim, int seg, int i){
	if(i==num){
		printf("%d",prim+seg);
		return;
	}
	int aux=prim;
	prim=seg;
	seg=aux+prim;
	fib_rec(num, prim, seg, ++i);
}
int main(){
	int num=6;
	fib_rec(num,1,1,3);
	return 0;
}
