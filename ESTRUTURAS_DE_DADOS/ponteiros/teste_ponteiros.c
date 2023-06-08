/*Considerando as variáveis e ponteiros definidos abaixo; quais são as atribuições 
permitidas? todas menos b, d, g
int i, *pi, **ppi; 
float f, *pf, **ppf; 
a) i = f; 
b) pf = &i; 
c) *pf = 5.9; 
d) *ppi = &pi; 
e) *pf = 10; 
f) f = i; 
g) pi = &f; 
h) *pi = 7.3*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int i, *pi, **ppi;
	float f, *pf, **ppf;
	
	i = f; 
	pf = &i; 
	*pf = 5.9; 
	*ppi = &pi; 
	*pf = 10; 
	f = i; 
	pi = &f;
	*pi = 7.3;

	
	return 0;
}
