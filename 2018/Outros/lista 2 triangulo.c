#include <stdio.h>
#include <conio.h>

int main()
{
	int a,b,c;
	printf("informe o lado do triangulo: ");
	scanf("%d",&a);
	printf("informe o valor do outro lado: ");
	scanf("%d",&b);
	printf("informe o valor do ultimo lado: ");
	scanf("%d",&c);
	
	if (a==b && a==c)
		printf("triangulo equilatero");
		
	else if (a==b||b==c||a==c){
		printf("triangulo isoceles");
		}
		
	else
		printf("triangulo escaleno");
	
	
	
	getche();
}
