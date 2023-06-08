#include <stdio.h>
#include <stdlib.h>

int main(){
	int i=20, *p=&i;
	printf("%d\n",*p);
	//p++;
	printf("%x\n",&i);
	printf("%x\n",*&p);
	return 0;
}
