
#include <stdio.h>

int main(){
    int numero_atual, num_anterior, num1_intervalo, num2_intervalo, calc_diferenca=0, diferenca_intervalo, i=0;
    
    printf("digite um número para iniciar: ");
    scanf("%d",&numero_atual);
    
    
    /*
        na primeira iteração o num_anterior, maior_num_intervalo, menor_num_intervalo
        serão serão iguais ao numero_atual, que é o primeiro digitado
        diferença será 0
    */
    
    /*
        encontrar diferença:
        subtrai o numero_atual - num_anterior, ex: (-400) - (-200), ou (100) - (50), ou (-45) - (2)
        caso o resultado da subtração der negativo (-400) - (-200) = -200 ou (-45)-(2)=-47 por exemplo
        multiplica-se por -1 para ficar positivo.
        se o calc_diferenca for maior ou igual que diferenca_intervalo, a diferenca_intervalo 
        passa a valer o valor de calc_diferenca, num1_intervalo fica sendo o num_anterior e 
        num2_intervalo fica sendo o numero_atual.
    */
    
    /*
        ao final do processamento do while o num_anterior fica sendo igual ao numero_atual,
        e depois o valor digitado no printf no fim do while sobrescreve o numero_atual
        dessa forma o num_anterior sempre fica um passo atrás do numero_atual
    */
    
    while(numero_atual != -999){
        i++;
        
        if(i==1){
            num_anterior = numero_atual;
            num1_intervalo = numero_atual;
            num2_intervalo = numero_atual;
            diferenca_intervalo = 0;
        }
        
        else{
            calc_diferenca = (numero_atual) - (num_anterior);
            
            if(calc_diferenca<0){
                calc_diferenca*=-1;
            }
            
            if(calc_diferenca >= diferenca_intervalo){
                diferenca_intervalo = calc_diferenca;
                num1_intervalo = num_anterior;
                num2_intervalo = numero_atual;
            }
            
            num_anterior = numero_atual;
        }
        
        
        printf("digite um número ou -999 para sair: ");
        scanf("%d",&numero_atual);
    }
    

    printf("\n%d e %d, pois o intervalo entre eles é %d.",num1_intervalo,num2_intervalo,diferenca_intervalo);
    
    return 0;
}