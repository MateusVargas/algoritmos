#include <stdio.h>

int main()
{
    int numero, menor, qtd_ocorrencias_menor_num=0, total_valores_lidos=0;
    float percentual;
    
    printf("digite um número para iniciar: ");
    scanf("%d",&numero);
    
    while(numero != -999){
        total_valores_lidos++;
        
        //o primeiro valor lido será o menor na primeira iteração
        
        if(total_valores_lidos == 1){
            menor = numero;
        }
        
        //se o numero digitado for igual ao menor, qtd_ocorrencias_menor_num é incrementado
        //se o numero for menor que menor, a variável menor passa valer o valor de numero e qtd_ocorrencias_menor_num
        //começa em 1
        
        if(numero == menor){
            qtd_ocorrencias_menor_num++;
        }
        else if(numero < menor){
            menor = numero;
            qtd_ocorrencias_menor_num=1;
        }
        
        printf("digite um número ou -999 pra sair: ");
        scanf("%d",&numero);    
    }
    
    //convertendo para float o cálculo da divisao de inteiros para aparecer as casas decimais corretamente
    percentual = ((float)(qtd_ocorrencias_menor_num*100) / total_valores_lidos);
    
    printf("\ntotal de valores lidos: %d\n",total_valores_lidos);
    printf("menor número: %d\n",menor);
    printf("quantidade de vezes que o menor número aparece: %d\n",qtd_ocorrencias_menor_num);
    printf("percentual em relação ao total de valores lidos: %.2f %%",percentual);
    
    return 0;
}