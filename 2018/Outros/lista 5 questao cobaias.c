#include <stdio.h>
#include <conio.h>
main()
{
	float cont1=0,cont2=0,porcento1,porcento2;
	int i,code;
	for(i=0;i<10;i++)
	{
	printf("informe o tipo de cobaia utilizada:\n 1-coelhos        2-ratos\n");
	scanf("%d",&code);
	if(code!=1&&code!=2)
		printf("opcao invalida.");
	if(code==1)cont1++;
		else
			if(code==2)cont2++;
		
		porcento1=(cont1/10)*100;
		porcento2=(cont2/10)*100;
	}
	printf("total de coelhos utilizados: %.0f\n",cont1);
	printf("total de ratos utilizados: %.0f\n",cont2);
	printf("a porcentagem de coelhos usados e %.2f porcento\n",porcento1);
	printf("e a porcentagem de ratos usados e %.2f porcento",porcento2);
	
	
	getche();
}
