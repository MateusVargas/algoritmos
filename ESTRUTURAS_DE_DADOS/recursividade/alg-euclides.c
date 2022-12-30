/*
O algoritmo de Euclides busca encontrar o máximo divisor comum (MDC) entre dois números inteiros diferentes de zero. O procedimento é simples: 
Chame o primeiro número de m e o segundo número de n; 
Divida m por n e chame o resto de r; 
Se r for igual a zero, então o MDC é n e o procedimento termina, se não o procedimento continua; Atribua n para m e r para n; Recomece o procedimento do segundo passo.
*/

#include <stdio.h>
#include <stdlib.h>

void this(int m,int n){
	int r=m % n;
	
	while(r!=0){
		m=n;
		n=r;
		r=m % n;
	}
	printf("%d",n);
}

/*versao recursiva*/
int func(int m,int n,int r){
	r=m%n;
		
	if(r==0){
		return n;
	}

	m=n;
	n=r;
	
	/*passando valores pra proxima execucao, pra que 
	o resultado da execucao atual seja acessado na proxima execucao */
	return func(m,n,r);
}

int main(){
	int m,n;
	scanf("%d %d",&m,&n);
	this(m,n);
	printf("\n%d",func(m,n,1));
	return 0;
}
