#include <stdio.h>

void mostrar(int n,int i,int inicio){
	if(i==n) return;
	
	int divisores;
	while(divisores!=2){
		divisores=0;
		for(int p=inicio;p>=1;p--){
			if(inicio%p==0){
				divisores++;
			}
		}
		if(divisores!=2) inicio++;
	}
	printf("%d\n",inicio);
	mostrar(n,i+1,inicio+1);
}

int main(){
	mostrar(20,0,0);
	return 0;
}
