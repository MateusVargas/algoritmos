#include <stdio.h>
#include <stdlib.h>

void func(int **vet){
	printf("endereco parametro vet: %x\n",&vet);
	//endereco qualquer
	
	printf("%d \n\n",*(vet+0));
	printf("endereco vet da main (recebido por parametro): %x\n",vet);
	//o mesmo endereco do vet da main, pois foi passado o endereco dele
	
	printf("*vet (valor guardado em vet da main, ponteiro pra 1a posicao): %x\n",*vet);
	//valor guardado em vet (ponteiro pra 1a posicao)
	
	printf("**vet, (valor de vet[0]): %x\n",**vet);//3
	printf("*(*vet+1) (valor de vet[1]): %x\n",*(*vet+1));//4
	
	//endereco de vet da main, nao e o valor que ele guarda e sim seu endereco, somado 4bytes
	printf("(vet+1): %x\n",(vet+1));
	
	//endereco da posicao[1] de vet da main
	printf("*(vet)+1 (endereco vet[1]): %x\n\n",*(vet)+1);
	
	
	//valor digitado vai ser posto no endereco alocado pelo malloc da main, ou seja, vai pra posicao[0], [1] ...
	for(int i=0;i<3;i++){
		printf("vet[%d]=",i);
		scanf("%d",*(vet)+i);
	}
	
	printf("*vet (valor guardado em vet da main): %x\n\n",*vet);
	
	
	//mostra o endereco da podicao e o valor dela
	//primeiro acessa o endereco que esta guardado no vet da main com o primeiro *
	//com o segundo * acessa o valor desse endereco que esta guardado
	for(int i=0;i<3;i++){
		printf("endereco: %x, valor: %d\n",*(vet)+i,*(*vet+i));
	}
}



void func2(int **vet){
	//valor digitado aqui nao sera alocado no espaco
	// reservado pelo malloc, mas vai ir pro endereco
	// de memoria do vet da main e nao pro endereco que ele guarda
	for(int i=0;i<3;i++){
		printf("vet[%d]=",i);
		scanf("%d",(vet+i));
	}
	//a funcao recebeu o endereco de vet da main e
	//nao o valor que ele guarda (que seria um ponteiro pra 1a posicao), entao usar um * vai fazer com que se va no endereco de memoria do vet da main e pegue o valor, o certo seria ir no endereco que vet guarda e buscar os valores e nao ir no endereco de memoria do ponteiro vet
	for(int i=0;i<3;i++){
		printf("endereco: %x, valor: %d\n",(vet+i),*(vet+i));
	}
}

int main(){
	int *vet,n=3;
	
	vet=(int*)malloc(n*sizeof(int));
	
	*vet=3;
	*(vet+1)=4;
	
	printf("endereco vet: %x\n",&vet);
	printf("valor que vet guarda (ponteiro pra 1a posicao): %x\n",vet);
	printf("vet+1 (endereco vet[1]): %x\n",(vet+1));
	printf("*vet+1 (valor vet[1]): %x\n\n",*(vet+1));
	
	func(&vet);
	free(vet);
	
	printf("\n\n");
	
	vet=(int*)malloc(n*sizeof(int));
	func2(&vet);
	free(vet);
	
	return 0;
}
