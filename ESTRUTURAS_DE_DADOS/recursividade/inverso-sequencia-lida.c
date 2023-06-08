#include <stdio.h>
#include <stdlib.h>

void seq(){
	int num;
	//printf("num:");
	scanf("%d",&num);
	
	if(num==-999) return;
	
	seq();
	printf("\n%d",num);
}

int main(){
	seq();
	return 0;
}
