#include <stdio.h>
#include <stdlib.h>

void insere(int vet[],int n,int total){
	if(total==n) return;
	
	int num;
	printf("v[%d]=",total);
	scanf("%d",&num);
	
	if(total==0){
		vet[0]=num;
	}
	else if(total==1){
		if(vet[0]>num){
			int aux=vet[0];
			vet[0]=num;
			vet[1]=aux;
		}
		else{
			vet[1]=num;
		}
	}
	else{
		int pos=0;
		while(vet[pos]<num && pos < total){
			pos++;
		}
		for(int i=total;i>pos;i--){
			vet[i]=vet[i-1];
		}
		vet[pos]=num;
	}
	total++;
	insere(vet,n,total);
}

int main(){
	int n=5;
	int p[n];
	insere(p,n,0);
	for(int i=0;i<n;i++){
		printf("%d\t",p[i]);
	}
	return 0;
}