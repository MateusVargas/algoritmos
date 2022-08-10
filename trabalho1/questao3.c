#include <stdio.h>

int main(){
    char encerrar;
    int tipo_carro, dias_aluguel, adicional;
    float custo_total=0, total_carro=0, total_seguro=0, total_adicionais=0;
    
    do{
        //validando opções, se o numero digitado para a opção for diferente dos disponiveis
        
        printf("escolha o tipo do carro:\n");
        printf("1- Hatch\n2- Premium\n3- Utilitário\n");
        scanf("%d",&tipo_carro);
        
        while(tipo_carro !=1 && tipo_carro !=2 && tipo_carro !=3){
            printf("\nopção inválida\n");
            printf("escolha o tipo do carro:\n");
            printf("1- Hatch\n2- Premium\n3- Utilitário\n");
            scanf("%d",&tipo_carro);
        }
        
        printf("\ninforme por quantos dias vai alugar: ");
        scanf("%d",&dias_aluguel);
        
        while(dias_aluguel<0){
            printf("\nopção inválida\n");
            printf("informe por quantos dias vai alugar: ");
            scanf("%d",&dias_aluguel);
        }
        
        printf("\nadicional:\n");
        printf("1- Tag pedágio\n2- Cadeira de bebê\n3- Tag pedágio e Cadeira de bebê\n4- Nenhum\n");
        scanf("%d",&adicional);
        
        while(adicional !=1 && adicional !=2 && adicional !=3 && adicional !=4){
            printf("\nopção inválida\n");
            printf("escolha o tipo do carro:\n");
            printf("1- Tag pedágioh\n2- Cadeira de bebê\n3- Nenhum\n");
            scanf("%d",&adicional);
        }
        
        
        /*
            é verificado primeiro o tipo do carro pra depois calcular o valor da diaria, 
            depois verifica os dias de aluguel pra calcular o desconto e o valor do seguro
        */
        
        if(tipo_carro==1){
            total_carro = 50*dias_aluguel;
            
            if(dias_aluguel>=15){
                total_carro*=0.95;
            }
            
            if(dias_aluguel>10){
                total_seguro = 1200;
            }
            else{
                total_seguro = 100*dias_aluguel;
            } 
        }
        else if(tipo_carro==2){
            total_carro = 75*dias_aluguel;
            
            if(dias_aluguel>=10 && dias_aluguel<=15){
                total_carro*=0.90;
            }
            
            if(dias_aluguel>10){
                total_seguro = 1800;
            }
            else{
                total_seguro = 120*dias_aluguel;
            }
        }
        else{
            total_carro = 85*dias_aluguel;
            
            if(dias_aluguel>=10 && dias_aluguel<=15){
                total_carro*=0.90;
            }
            
            if(dias_aluguel>10){
                total_seguro = 1850;
            }
            else{
                total_seguro = 125*dias_aluguel;
            }
        }
        
        
        //cálculo adicionais, com base no número da opção calcula as taxas
        
        if(adicional==1){
            total_adicionais = 10*dias_aluguel;
        }
        else if(adicional==2){
            total_adicionais=80;
        }
        else if(adicional==3){
            total_adicionais = 10*dias_aluguel + 80;
        }
        else{
            total_adicionais = 0;
        }
        
        //custo_total sera a soma do total do carro, do seguro e adicionais
        custo_total = total_carro+total_seguro+total_adicionais;
        
        printf("\ntotal da diária do carro: R$ %.2f",total_carro);
        printf("\ntotal do seguro: R$ %.2f",total_seguro);
        total_adicionais == 0 ? printf("\nnenhum adicional escolhido, total: R$%.2f",total_adicionais) : printf("\ntotal dos adicionais: R$ %.2f",total_adicionais);
        printf("\n\nCUSTO TOTAL: R$ %.2f",custo_total);
        
        
        printf("\n\n\n1-DESEJA CONTINUAR? N PARA ENCERRAR OU QUALQUER LETRA PRA CONTINUAR: ");
        getchar();
        scanf("%c",&encerrar);
        
    }while(encerrar!='n' && encerrar!='N');
    
    
    return 0;
}