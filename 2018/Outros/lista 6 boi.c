#include <stdio.h>
#include <conio.h>
main()
{
	int n,n1,num,code,peso,maior=0,menor=100000000;
	
		printf("informe o numero de identificacao do boi: ");
		scanf("%d",&code);
	do{
		printf("informe o peso do boi: ");
		scanf("%d",&peso);
		
		if(peso==0){
		maior=peso;
		}
		else if(peso>maior){
			maior=peso;
			n=code;
		}
		
		if(peso==100000000){
		menor=peso;
			}
		else if(peso<menor){
		menor=peso;
		n1=code;
		}
		printf("informe o numero de identificacao do boi: ");
		scanf("%d",&code);
		
	}while(code>0);
	
	printf("\n o boi mais gordo e o boi %d com o peso %d Kg\n",n,maior);
	printf("o boi mais magro e o boi %d com o peso %d Kg",n1,menor);
	
	
	
	
	
	getche();
}
