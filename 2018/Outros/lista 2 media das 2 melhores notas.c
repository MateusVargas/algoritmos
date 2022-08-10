#include <stdio.h>
#include <conio.h>
main()
{
	float n1,n2,n3,soma,media;
	printf("digite a primeira nota: ");
	scanf("%f",&n1);
	printf("digite a segunda nota: ");
	scanf("%f",&n2);
	printf("digite a terceira nota: ");
	scanf("%f",&n3);
	
	if(n1>n2&&n2>n3||n2>n1&&n1>n3){
	soma=n1+n2;
	media=soma/2;
	printf("media das 2 melhores notas: %.2f",media);
	}
	else if(n2>n3&&n3>n1||n3>n2&&n2>n1){
	soma=n2+n3;
	media=soma/2;
	printf("media das 2 melhores notas: %.2f",media);
	}
	else if(n3>n1&&n1>n2||n1>n3&&n3>n2){
	soma=n3+n1;
	media=soma/2;
	printf("media das 2 melhores notas: %.2f",media);
	}
	getche();
}
