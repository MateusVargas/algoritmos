#include <stdio.h>
#include <stdlib.h>

#define valor 6

int fatorial(int num){
	int result;
	
	if(num==0||num==1){
		return 1;
	}
	
	result = fatorial(num-1) * num;
	return result;
}

int main(){
	printf("fatorial de %d: %d",valor,fatorial(valor));
	return 0;
}
