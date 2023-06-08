#include <stdio.h>
#include <stdlib.h>

int main(){
	int x=10, *px=&x, **ppx=&x;
	float y=5.9, *py=&y, **ppy=&py;
	
	printf("x %x\n",&x);
	printf("y %x\n",&y);
	printf("px %x\n",&px);
	printf("py %x\n",&py);
	printf("ppy %x\n",&ppy);
	printf("ppx %x\n",&ppx);
	
	printf("\nx= %d\n",x);
	printf("*py= %f\n",*py);
	printf("px= %x\n",px);
	printf("&y= %x\n",&y);
	printf("*px= %d\n",*px);
	printf("y= %f\n",y);
	
	printf("\n*ppx= %d\n",*ppx);
	printf("py= %x\n",py);
	printf("&x= %x\n",&x);
	printf("py++= %x\n",py++);
	printf("*px--= %d\n",*px--);
	printf("**ppy= %f\n",**ppy);
	
	printf("\n&ppy= %x\n",&ppy);
	printf("*&px= %x\n",*&px);
	//printf("**ppx++= %x\n",**ppx++);
	printf("px++= %x\n",px++);
	printf("&ppx= %x\n",&ppx);
	
	return 0;
}
