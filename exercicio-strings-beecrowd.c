/*
Gene e Gina possuem um tipo peculiar de fazenda. Ao invés de criar animais e plantar vegetais como acontece em fazendas normais, eles cultivam strings. Uma string é uma sequência de caracteres. 
As strings, ao crescerem, adicionam caracteres à esquerda e/ou à direita delas mesmas, mas nunca perdem caracteres nem inserem caracteres no meio.

Gene e Gina possuem uma coleção de fotos de algumas strings durante diferentes etapas de seus crescimentos. O problema é que a coleção não é rotulada, portanto eles esqueceram a qual string pertence cada uma das fotos. 
Eles querem montar um painel para ilustrar os procedimentos do cultivo de strings, mas eles necessitam sua ajuda para encontrar uma sequência de fotos apropriada.

Cada foto ilustra uma string. A sequência de fotos precisa ter a seguinte propriedade: se si aparece imediatamente antes de si+1 na sequência, então si+1 é uma string que pode ter crescido a partir de si (ou seja, si é 
uma substring contígua de si+1). Além disso, eles não querem usar fotos repetidas, portanto todas as strings na sequência devem ser diferentes.

Dado um conjunto de strings representando todas as fotos disponíveis, sua tarefa é calcular o tamanho da maior sequência que pode ser produzida com as restrições acima.

Entrada
Cada caso de teste se estende por várias linhas. A primeira linha contém um inteiro N representando o número de strings no conjunto (1 ≤ N ≤ 104). Cada uma das próximas N linhas contém uma string não-vazia e única com no máximo 
1000 caracteres minúsculos do alfabeto inglês. Em cada caso de teste, a soma dos tamanhos das strings é no máximo 106.

O último caso de teste é seguido de uma linha contendo um zero.
Saída
Para cada caso de teste, imprima uma única linha com um único inteiro representando o tamanho da maior sequência de fotos que pode ser produzida.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n=0;
    int qtd = 1;
    char strings[n][1000];
    
    do{
        scanf("%d",&n);
        
        for(int i=0;i<n;i++){
            //printf("%d\n",i);
            getchar();
            fgets(strings[i], 1000 -1, stdin);
            //gets(strings[i]);
        }
        
        for(int i=0;i<n;i++){
            if((i+1 < n) && strstr(strings[i+1], strings[i]) == NULL){
                //printf("%s %s\n",strings[i+1], strings[i]);
                qtd++;
            }
        }
        
        printf("%d\n",qtd);
    }while(n != 0);
    
    // printf("\n%d\n",qtd);
    // for(int i=0;i<n;i++){
    //     puts(strings[i]);
    // }
    return 0;
}
