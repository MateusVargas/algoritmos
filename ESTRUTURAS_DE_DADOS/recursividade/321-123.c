#include <stdio.h>
#include <stdlib.h>

int calc_tamanho(int parte,int tamanho){
	if(parte<10){
		return tamanho;
	}
	tamanho=tamanho*10;
	parte=parte/10;
	return calc_tamanho(parte,tamanho);
}

int calc_tamanho2(int parte){
	if(parte < 10){
		return 1;
	}
	
	int tamanho = 1;
	tamanho = tamanho*10*calc_tamanho2(parte/10);
	return tamanho;
}


int inverter(int parte,int resto,int tam,int soma){
	if(parte == 0 && resto == 0){
		return soma;
	}
	
	soma+=resto*tam;
	tam = tam/10;
	return inverter(parte/10,parte%10,tam,soma);
}

int main(){
	int num=321;
	int tam = calc_tamanho(num,1);
	int tam2 = calc_tamanho2(num);
	printf("%d, %d",tam,tam2);
	
	num = inverter(num/10,num%10,tam,0);
	printf("\n%d",num);
	
	return 0;
}
 
