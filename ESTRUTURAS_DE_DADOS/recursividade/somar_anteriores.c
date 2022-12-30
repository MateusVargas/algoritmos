#include <stdio.h>
#include <stdlib.h>

/*
1.execucao:
somar(5);

2.execucao:
linha 64: return 5+somar(5-1);

3.execucao:
return 4+somar(4-1);

4.execucao:
return 3+somar(3-1);

5.execucao:
return 2+somar(2-1);

6.execucao:
caiu no if, não entra no return, ou seja, nao é feita uma nova execucao, e é retornado 1, pra execução anterior.


depois das execuções:

- a 6.execução caiu na condição de parada e retornou 1
pra 5.execucao.

- a 5.execucao recebe 1, então no return que era:
return 2+somar(2-1); fica assim: return 2+1;
ou seja, a chamada pra função somar(2-1) é substituída
e colocado o retorno recebido por ela, no caso 1.
então como ficou return 2+1, será retornado 3 pra execução anterior.

- a 4.execucao recebe 3, então no return que era:
return 3+somar(3-1); fica assim: return 3+3;
ou seja, a chamada pra função somar(3-1) é substituída
e colocado o retorno recebido por ela, no caso 3.
então como ficou return 3+3, será retornado 6 pra execução anterior.

- a 3.execucao recebe 6, então no return que era:
return 4+somar(4-1); fica assim: return 4+6;
ou seja, a chamada pra função somar(4-1) é substituída
e colocado o retorno recebido por ela, no caso 6.
então como ficou return 4+6, será retornado 10 pra execução anterior.

- a 2.execucao recebe 10, então no return que era:
return 5+somar(5-1); fica: return 5+10;
ou seja, a chamada pra função somar(5-1) é substituída
e colocado o retorno recebido por ela, no caso 10.
então como ficou return 5+10, será retornado 15 pra execução anterior.

- a 1.execucao recebe 15, então no return que era:
return somar(5); fica: return 15;
ou seja, a chamada pra função somar(5) é substituída
e colocado o retorno recebido por ela, no caso 15.
*/

int somar(int n){
	//condição de parada para não entrar em loop infinito.
	if(n==1){
		return n;
	}
	return n+somar(n-1);
}

int main(){
	printf("%d",somar(5));
	return 0;
}
