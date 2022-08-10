#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct{
	int code;
	int quant;
	char descricao;
	float preco;
} cad;

main()
{
	cad d1;
	int c=0,x;
	printf("codigo: ");
	scanf("%d",&d1.code);
	
	while(d1.code!=-999)
	{
	printf("descricao: ");
	scanf("%s",&d1.descricao);
	printf("preco: ");
	scanf("%f",&d1.preco);
	printf("quantia: ");
	scanf("%d",&d1.quant);
		
	printf("codigo: ");
	scanf("%d",&d1.code);	
		
	}
	
	printf("x: ");
	scanf("%d",&x);
	
	if(x>d1.quant)
	{
		for(int i=0;i<;i++)
		{
	printf("%f",d1.preco);
	printf("%d",d1.quant);	
	}
	
	}
}
