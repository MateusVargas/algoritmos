#include <stdio.h>

int main(){
	int n;
	printf("valor de n:");
	scanf("%d",&n);
	int vet[n],total=0,num;
	
	while(total<n){
		printf("numero:");
		scanf("%d",&num);
	
		if(total==0){
			vet[0]=num;
			total++;
		}
		else if(total==1){
			if(vet[0]>num){
				vet[1]=vet[0];
				vet[0]=num;
			}
			else{
				vet[1]=num;
			}
			total++;
		}
		else{
			int posicao_insercao=0;
			while(vet[posicao_insercao]<num
				&& posicao_insercao<total){
				posicao_insercao++;
			}
			for(int i=total;i>=posicao_insercao;i--){
				vet[i+1]=vet[i];
			}
			vet[posicao_insercao]=num;
			total++;
		}
	}
	for(int i=0;i<total;i++){
		printf("%d\t",vet[i]);
	}
}
