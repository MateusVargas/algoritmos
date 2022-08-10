#include <stdio.h>
#include <conio.h>
main()
{
int cont1=0,cont2=0,code;
float preco,novo_preco,somap=0,somanp=0,mediap=0,medianp=0;
	
printf("digite o codigo do produto: ");
scanf("%d",&code);
while(code>=0)
{
printf("digite o preco: ");
scanf("%f",&preco);cont1++;
	
novo_preco=preco*1.20;
	
	
printf("preco com reajuste de 20 por cento: %.2f R$\n\n",novo_preco);cont2++;
		
printf("digite o codigo do produto: ");
scanf("%d",&code);
		
somap=somap+preco;
mediap=somap/cont1;
		
somanp=somanp+novo_preco;
medianp=somanp/cont2;
	
}
printf("media dos precos antigos: %.2f R$\n",mediap);
printf("media dos precos com o reajuste: %.2f R$",medianp);
	
getch();
}
