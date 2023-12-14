/*Imagine vet como um vetor de inteiros. Apresente programas iterativos e recursivos para calcular:
o elemento máximo do vetor; 
o elemento mínimo do vetor; 
a soma dos elementos do vetor; 
o produto dos elementos do vetor; 
a média dos elementos do vetor.*/

#include <stdio.h>
#include <stdlib.h>

//busca maior valor
int v_maior(int vet[5],int i, int maior){
	if(i==5){
		return maior;
	}
	
	if(vet[i]>maior){
		maior=vet[i];
	}
	
	maior=v_maior(vet,i+1,maior);
	return maior;
}

//busca menor valor
int v_menor(int *vet,int i, int menor){
	if(i<0){
		return menor;
	}
	if(vet[i]<menor){
		menor=vet[i];
	}
	menor=v_menor(vet,i-1,menor);
	return menor;
}

//soma elementos
int calc_soma(int vet[5],int i,int soma){
	if(i==5){
		return soma;
	}
	soma+=vet[i];
	
	soma=calc_soma(vet,i+1,soma);
	return soma;
}

//soma elementos outra forma
int calc_soma2(int vet[5],int i){
	int soma=0;
	
	if(i==5){
		return 0;
	}
	soma=vet[i];
	
	soma+=calc_soma2(vet,i+1);
	return soma;
}

//produto
int calc_produto(int vet[5],int i){
	int prod;
	
	if(i==5){
		return 1;
	}
	
	prod=calc_produto(vet,i+1)*vet[i];
	return prod;
}

//produto outra forma
void calc_produto2(int vet[5],int i,int prod){
	if(i==5){
		printf("produto: %d\n",prod);
		return;
	}
	prod*=vet[i];
	calc_produto2(vet,i+1,prod);
}

//media
void calc_media(int vet[5],int i,int soma,float media){
	if(i==5){
		printf("media: %.2f\n",media);
		return;
	}
	
	soma+=vet[i];
	media=(float)soma/(i+1);
	
	calc_media(vet,i+1,soma,media);
}


//media outra forma
float calc_media2(int vet[5],int i,int f){
	float media,soma;
	
	if(i==5){
		return 0;
	}
	soma=calc_media2(vet,i+1,f-1)+vet[i];
	
	if(f==5){
		return soma/5;
	}
	return soma;
}

float calc_media3(int vet[],int n,int i){
	if(n==0) return 0;
	int soma=0;
	soma+=vet[n-1]+calc_media3(vet,n-1,i+1);
	if(i==0) return (float)soma/n;
	return soma;
}

int main(){
	int vet[5]={6,34,9,2,20};
	printf("maior: %d\n",v_maior(vet,0,vet[0]));
	printf("menor: %d\n",v_menor(&vet,5-1,vet[0]));
	printf("soma: %d\n",calc_soma(vet,0,0));
	printf("soma: %d\n",calc_soma2(vet,0));
	printf("produto: %d\n",calc_produto(vet,0));
	calc_produto2(vet,0,1);
	calc_media(vet,0,0,0);
	printf("media: %.2f\n",calc_media2(vet,0,5));
	printf("media: %.2f",calc_media3(vet,5,0));
	
	return 0;
}
