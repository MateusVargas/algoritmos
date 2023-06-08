#include <stdio.h>

int ocorrencias(int num, int x, int cont){
	int a = num/10;
	int b = num%10;

	if(a==0 && b==0){
		printf("ocorrencias de %d: %d\n",x,cont);
		return cont;
	}
	
	if(b == x){
		cont++;
	}
	
	cont = ocorrencias(a,x,cont);
	return cont;
}

int main(){
	int n = 69494;
	int x = 9;
	
	printf("%d\n",ocorrencias(n,x,0));
	
	return 0;
}
