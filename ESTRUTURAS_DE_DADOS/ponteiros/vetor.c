#include <stdio.h>
#include <stdlib.h>

/*
float *p; ponteiro para float
p = &a; ponteiro recebe endereco de a
*p = 12; altera valor da variavel que o ponteiro aponta
*/

int main(){
	int v[4]={1,3,6,7,0};
	printf("%x\n",&v[0]);//retorna endereco de v[0]
	printf("%x\n",v);//retorna endereco de v[0]
	
	//acessando elementos do vetor atraves de ponteiros
	printf("\n%d",*(v));//retorna v[0]
	printf("\n%d",*(v+1));//retorna v[1]
	printf("\n%d",*(v+2));//v[2]
	
	printf("\n%x",v);//retorna endereco de v[0]
	++v;
	printf("\n%x",v);//retorna endereco de v[0]
	
	return 0;
}
