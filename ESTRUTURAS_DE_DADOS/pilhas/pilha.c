/*se usa un vetor pra armazenar os dados da pilha*/

#include <stdio.h>
#include <stdlib.h>

int pilha[20];
int pos=0;

//adiciona um novo elemento na pilha
void push(int valor){
	pilha[pos]=valor;
	pos++;
}

//retira o elemento do topo da pilha e retorna o elemento do topo
int pop(){
	return pilha[--pos];
}

//retorna o tamanho da pilha
int size(){
	return pos;
}

//retorna o elemento do topo da pilha
int stackpop(){
	return pilha[pos];
}


int main(){
	printf("\nadicionado elementos na pilha");
	push(1);
	push(7);
	push(5);
	
	printf("\ntamanho da pilha: %d",size());
	printf("\nretirando dado da pilha: %d",pop());
	printf("\nretirando dado da pilha: %d",pop());
	printf("\nelemento no topo da pilha: %d",stackpop());
	printf("\nretirando dado da pilha: %d",pop());
	
	printf("\ntamanho da pilha: %d",size());

	return 0;
}
