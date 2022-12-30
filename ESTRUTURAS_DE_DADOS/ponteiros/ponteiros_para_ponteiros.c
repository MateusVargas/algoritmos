#include <stdio.h>
#include <stdlib.h>

//a passagem de um ponteiro para uma funcao
//gera um ponteiro para ponteiro
void funcao(int **parametro){
	printf("&parametro: %d\n",&parametro);//endereco de memoria da variavel 'parametro'
	
	printf("parametro: %d\n",parametro);
	//retorna o valor que esta guardado em 'parametro', ele sera o endereco de memoria de 'p', pois 'parametro' e um ponteiro para 'p', e ponteiros guardam enderecos de memoria
	
	printf("*parametro: %d\n",*parametro);
	//retorna o valor da variavel que 'parametro' aponta, 'parametro' aponta para 'p', entao '*parametro' vai trazer o valor que esta guardado em 'p' que e um endereco de memoria
	
	printf("**parametro: %d\n",**parametro);
	//'parametro' aponta para 'p'
	//*parametro traz o valor que esta guardado em 'p' que e um endereco de memoria
	//**parametro vai trazer o valor da variavel que 'p' aponta, que sera 20
}

int main(){
	int *p;
	
	p=(int *)malloc(sizeof(int));//alocando espaco pra um inteiro, que sera 4 bytes
	
	*p=20;
	
	printf("&p: %d\n",&p);//endereco de memoria de p
	printf("p: %d\n",p);//valor que esta guardado em p
	printf("*p: %d\n\n",*p);//valor da variavel que p aponta
	
	funcao(&p);
	
	return 0;
}
