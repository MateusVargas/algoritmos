#include <stdio.h>
#include <stdlib.h>

int v_maior(int vet[5],int i,int maior,int n){
	if(i==n){
		return maior;
	}
	if(vet[i]>maior){
		maior=vet[i];
	}
	maior = v_maior(vet,i+1,maior,n);
	return maior;
}

int main(){
	int n;
	printf("valor de n:");
	scanf("%d",&n);
	int vet[n];
	
	for(int i=0;i<n;i++){
		printf("vet[%d]:",i);
		scanf("%d",&vet[i]);
	}
	printf("maior numero: %d",v_maior(vet,0,vet[0],n));
	return 0;
}
