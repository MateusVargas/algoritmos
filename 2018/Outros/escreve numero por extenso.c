#include <stdio.h>
#include <string.h>

main()
{
	char t[10];
	int tamanho;
	printf("digite um numero: ");
	gets(t);
	tamanho=strlen(t);
	
	/*if(t!='1'&&t!='2'&&t!='3'&&t!='4'&&t!='5'&&t!='6'&&t!='7'&&t!='8'&&t!='9'&&t!='0')
	printf("digite apenas numeros!");
	*/	
	
	if(tamanho==1){
		if(t[0]=='0')
		printf("zero");
		if(t[0]=='1')
		printf("um");
		if(t[0]=='2')
		printf("dois");
		if(t[0]=='3')
		printf("tres");
		if(t[0]=='4')
		printf("quatro");
		if(t[0]=='5')
		printf("cinco");
		if(t[0]=='6')
		printf("seis");
		if(t[0]=='7')
		printf("sete");
		if(t[0]=='8')
		printf("oito");
		if(t[0]=='9')
		printf("nove");
		
		}
	if(tamanho==2&&t[0]=='1'){
		if(t[1]=='0')
		printf("dez");
		if(t[1]=='1')
		printf("onze");
		if(t[1]=='2')
		printf("doze");
		if(t[1]=='3')
		printf("treze");
		if(t[1]=='4')
		printf("catorze");
		if(t[1]=='5')
		printf("quinze");
		if(t[1]=='6')
		printf("dezeseis");
		if(t[1]=='7')
		printf("dezesete");
		if(t[1]=='8')
		printf("dezoito");
		if(t[1]=='9')
		printf("dezenove");
	}
		
	if(tamanho==2){		
		if(t[0]=='2')
		printf("vinte ");
		if(t[0]=='3')
		printf("trinta ");
		if(t[0]=='4')
		printf("quarenta ");
		if(t[0]=='5')
		printf("cinquenta ");
		if(t[0]=='6')
		printf("sessenta ");
		if(t[0]=='7')
		printf("setenta ");
		if(t[0]=='8')
		printf("oitenta ");
		if(t[0]=='9')
		printf("noventa ");
}
	if(tamanho==2&&t[0]!='1'){
		if(t[1]=='0')
		printf("");
		if(t[1]=='1')
		printf("e um");
		if(t[1]=='2')
		printf("e dois");
		if(t[1]=='3')
		printf("e tres");
		if(t[1]=='4')
		printf("e quatro");
		if(t[1]=='5')
		printf("e cinco");
		if(t[1]=='6')
		printf("e seis");
		if(t[1]=='7')
		printf("e sete");
		if(t[1]=='8')
		printf("e oito");
		if(t[1]=='9')
		printf("e nove");
		}
		
	if(tamanho==3){
		if(t[0]=='1')
		printf("cento ");
		if(t[0]=='2')
		printf("duzentos ");
		if(t[0]=='3')
		printf("trezentos ");
		if(t[0]=='4')
		printf("quatrocentos ");
		if(t[0]=='5')
		printf("quinhentos ");
		if(t[0]=='6')
		printf("seiscentos ");
		if(t[0]=='7')
		printf("setecentos ");
		if(t[0]=='8')
		printf("oitocentos ");
		if(t[0]=='9')
		printf("novecentos ");
		}
		
	if(tamanho==3&&t[1]=='1'){
		if(t[2]=='0')
		printf("e dez");
		if(t[2]=='1')
		printf("e onze");
		if(t[2]=='2')
		printf("e doze");
		if(t[2]=='3')
		printf("e treze");
		if(t[2]=='4')
		printf("e catorze");
		if(t[2]=='5')
		printf("e quinze");
		if(t[2]=='6')
		printf("e dezeseis");
		if(t[2]=='7')
		printf("e dezesete");
		if(t[2]=='8')
		printf("e dezoito");
		if(t[2]=='9')
		printf("e dezenove");
	}
		
	if(tamanho==3){		
		if(t[1]=='2')
		printf("e vinte ");
		if(t[1]=='3')
		printf("e trinta ");
		if(t[1]=='4')
		printf("e quarenta ");
		if(t[1]=='5')
		printf("e cinquenta ");
		if(t[1]=='6')
		printf("e sessenta ");
		if(t[1]=='7')
		printf("e setenta ");
		if(t[1]=='8')
		printf("e oitenta ");
		if(t[1]=='9')
		printf("e noventa ");
}
	if(tamanho==3&&t[1]!='1'){
		if(t[2]=='0')
		printf("");
		if(t[2]=='1')
		printf("e um");
		if(t[2]=='2')
		printf("e dois");
		if(t[2]=='3')
		printf("e tres");
		if(t[2]=='4')
		printf("e quatro");
		if(t[2]=='5')
		printf("e cinco");
		if(t[2]=='6')
		printf("e seis");
		if(t[2]=='7')
		printf("e sete");
		if(t[2]=='8')
		printf("e oito");
		if(t[2]=='9')
		printf("e nove");
		}	
}
