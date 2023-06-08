#include <stdio.h>
#include <stdlib.h>

int main(){
	int a=10;
	int *p,*p2,**p3,**p4,***p5;
	p=&a;
	p2=p;
	p3=&p;
	p4=&p2;
	p5=&p3;
	
	printf("%d\n",a);
	printf("%d\n",*p);
	printf("%x\n",p);
	printf("%x\n",&p);
	printf("%d\n",*p2);
	printf("%x\n",p2);
	printf("%x\n",&p2);
	printf("%x\n",*p3);
	printf("%x\n",p3);
	printf("%x\n",&p3);
	printf("%d\n",**p3);
	printf("%x\n",*p4);
	printf("%x\n",p4);
	printf("%x\n",&p4);
	printf("%d\n",**p4);
	printf("%x\n",*p5);
	printf("%x\n",p5);
	printf("%x\n",&p5);
	printf("%x\n",**p5);
	printf("%d\n",***p5);
	
	***p5=12;
	printf("%d",a);
	return 0;
}
