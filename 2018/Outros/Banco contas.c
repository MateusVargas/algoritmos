#include <stdio.h>
#include <conio.h>
#include <string.h>

main()
{
	char mov;
	int code,num;
	float maior,saldof=0,saldo=0,soma_saldo=0,credito=0,debito=0;
	printf("digite seu codigo de cliente ou 0 para encerrar: ");
	scanf("%d",&code);
	
	printf("informe seu saldo inicial: ");
	scanf("%f",&saldo);
	
	do{
		
		printf("informe a movimentacao bancaria: \nC-credito    D-Debito     F-Fim\n");
		scanf("%s",&mov);
		
		if (mov!='C'&&mov!='D'&&mov!='F'){
		printf("opcao invalida\n");
		}
		else if(mov=='C'){
		printf("quanto voce vai depositar: ");
		scanf("%f",&credito);
		saldo=saldo+credito;
		printf("SEU NOVO SALDO: %.2f R$\n\n",saldo);
		}
		else if(mov=='D'){
		printf("quanto voce vai sacar: ");
		scanf("%f",&debito);
			if(debito>saldo){
			printf("voce nao pode fazer essa movimentao motivo: saldo insuficiente\n");
				}
		else
		 {
			saldo=saldo-debito;
		printf("SEU NOVO SALDO: %.2f R$\n\n",saldo);}
		}
		if(saldo<0)
		printf("voce nao tem saldo para essa movimentacao\n");
		
		if(mov=='F'){
		saldof=saldof+saldo;
			
		if(saldo==0)
			maior=saldo;
			else if(saldo>maior)
			{maior=saldo;
			num=code;}
		
		printf("digite seu codigo de cliente ou 0 para encerrar: ");
		scanf("%d",&code);
			if(code<=0)break;
		printf("informe seu saldo inicial: ");
		scanf("%f",&saldo);
		}
		
	}while(code>0);

	soma_saldo=soma_saldo+saldof;
	
	printf("soma de todos os clientes: %.2f R$\n",soma_saldo);
	printf("o cliente %d tem o maior saldo: %.2f R$",num,maior);
	getche();
}
