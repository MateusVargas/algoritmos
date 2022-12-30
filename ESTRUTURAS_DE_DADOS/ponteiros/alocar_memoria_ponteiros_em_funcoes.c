#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int idade;
} Lista;


//passagem por referencia, pois se recebe o endereco
//do ponteiro, pra que as mudancas reflitam fora

void alocar(Lista **lista){
	//lista=(Lista*)malloc(sizeof(Lista));
	//aloca no endereco de memoria de lista da main
	
	*lista=(Lista*)malloc(sizeof(Lista));
	//aloca no valor guardado em lista da main

	(*lista)->idade=10;
}







/*alocando memoria desse jeito, sem receber o
endereco do ponteiro, recebendo apenas o valor
que ele guarda, a alocacao funciona mas ela 
nao eh refletida fora da funcao, o endereco
eh passado (&lista), pra que aconteca uma 
passagem por referencia, entao eh feito 
*lista=malloc()... a mudanca reflete fora
por isso eh passado o endereco */

void alocar2(Lista *lista2){
	lista2=(Lista*)malloc(sizeof(Lista));
	lista2->idade = 20;
	
	printf("lista2->idade %d\n",lista2->idade);//20
	printf("(*lista2)->idade %d\n",(*lista2).idade);//20
	printf("lista2 %x\n\n",lista2);
	//imprime certo, mas as alteracoes nao
	//valem fora da main
}

int main(){
	Lista *lista = NULL, *lista2 = NULL;
	
	printf("&lista %x\n",&lista);
	
	alocar(&lista);
	//alocar memoria em funcao, deve passar endereco
	//pra que seja uma passagem por referencia, e as
	//mudancas reflitam fora da funcao
	
	printf("lista %x\n",lista);
	printf("&lista %x\n",&lista);
	
	//printf("%d\n",lista.idade);
	//erro porque lista eh um ponteiro pra uma 
	//struct e nao uma struct, precisa usar '->'
	
	//printf("%x\n",*lista.idade);//erro
	
	printf("lista->idade %d\n",lista->idade);//10
	printf("(*lista).idade %d\n",(*lista).idade);//10
	
	
	printf("\n\n&lista2 %x\n",&lista2);
	alocar2(lista2);
	
	printf("lista2 %x\n",lista2);
	printf("&lista2 %x\n",&lista2);
	
	printf("lista2->idade %d\n",lista2->idade);//erro
	printf("(*lista2)->idade %d\n",(*lista2).idade);//erro
	return 0;
}
