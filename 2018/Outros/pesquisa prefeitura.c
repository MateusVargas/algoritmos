#include <stdio.h>
#include <conio.h>
main()
{
	float cont3=0,pessoas_com_menos_de100reais,maior=0,cont2=0,cont1=0,filhos,salario,soma_f=0,mediaf=0,somas=0,medias=0;
	
	for(;;)//laço for infinito que para ao digitar salario negativo
	{
	printf("informe o salario ou numero negativo para encerrar: ");
	scanf("%f",&salario);
	if(salario<0)break;
		else cont1++;
		
		if(salario==0)
		maior=salario;
		else if(salario>maior)
		maior=salario;
		
		if(salario<100)cont3++;
		
	printf("informe o numero de filhos: ");
	scanf("%f",&filhos);
	if(filhos>=0)cont2++;
		
	soma_f=soma_f+filhos;
	mediaf=soma_f/cont2;
			
	somas=somas+salario;
	medias=somas/cont1;
		
	pessoas_com_menos_de100reais=(100*cont3)/cont1;
	}
	printf("media de salarios: %.2f R$\n",medias);
	printf("media de filhos: %.2f\n",mediaf);
	printf("maior salario: %.2f R$\n",maior);
	printf("percentual de salarios abaixo de 100 R$: %.2f porcento",pessoas_com_menos_de100reais);
	getche();
}
