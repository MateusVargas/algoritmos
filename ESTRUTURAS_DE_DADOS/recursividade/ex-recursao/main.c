#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//arara: length: 5
//a = a ? 1
//r = r ? 1
//1+1=2

//ama: length: 3
//a = a ? 1

//casa: length: 4
//c = a ? 0
//a = s ? 0

//verifica 1° caractere com ultimo, 2° com antepenultimo e assim por diante
//se forem iguais retorna 1, soma-se os retornos de todas as execucoes
//a soma deve ser igual a parte inteira da metade do tamanho da string
//se for significa que todas as comparacoes deram 1, ou seja, que sao iguais os caracteres
int palindromo(char *string, int inicio, int fim){
    int soma=0;

    if(inicio>=fim){
        return 0;
    }

    if(string[inicio]==string[fim]){
        soma=1;
    }
    else{
        soma=0;
    }

    soma+=palindromo(string,inicio+1,fim-1);
    return soma;
}





int main()
{
    char palavra[30] = {"a torre da derrota"};
    puts(palavra);
    printf("%d\n",strlen(palavra));

    //remove espaços em branco
    for(int i=0;i<strlen(palavra);i++){
        if(palavra[i]==' '){
            for(int j=i;j<strlen(palavra);j++){
                palavra[j]=palavra[j+1];
            }
        }
    }

    puts(palavra);
    printf("%d\n",strlen(palavra));

    int is_palindromo = palindromo(&palavra,0,strlen(palavra)-1);
    if(is_palindromo == strlen(palavra)/2){
        printf("e palindromo");
    }
    else{
        printf("nao e palindromo");
    }

    return 0;
}
