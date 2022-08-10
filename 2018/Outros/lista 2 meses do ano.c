#include <stdio.h>
#include <conio.h>

int main ()
{
	int num;
	printf("digite um numero: ");
	scanf("%i",&num);
	
	if (num<=0||num>12){
		printf("o numero nao corresponde a nenhum mes.");
		}
		if (num==1){
			printf("1 -> Janeiro");
			}
		if (num==2){
			printf("2 -> Fevereiro");
			}
		if (num==3){
			printf("3 -> Marco");
			}
		if (num==4){
			printf("4 -> Abril");
			}
		if (num==5){
			printf("5 -> Maio");
			}
		if (num==6){
			printf("6 -> Junho");
			}
		if (num==7){
			printf("7 -> Julho");
			}
		if (num==8){
			printf("8 -> Agosto");
			}
		if (num==9){
			printf("9 -> Setembro");
			}
		if (num==10){
			printf("10 -> Outubro");
			}
		if (num==11){
			printf("11 -> Novembro");
			}
		if (num==12){
			printf("12 -> Dezembro");
			}
			getche();
			
}
			

