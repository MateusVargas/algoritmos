/*
Consiste em identificar o menor elemento da lista e trocá-lo com o da primeira posição, 
depois identificar o segundo menor elemento e trocá-lo com o da segunda posição e assim sucessivamente
*/

#include <stdio.h>

void selection_sort(int v[7]){
    int aux, posicao_menor;
    for(int i=0;i<7-1;i++){
        posicao_menor = i;
        for(int j=i+1;j<7;j++){
            if(v[j] < v[posicao_menor]){
                posicao_menor = j;
            }
        }
        
        aux = v[i];
        v[i] = v[posicao_menor];
        v[posicao_menor] = aux;
    }
}

int main()
{
    int v[7]={32,5,2,56,1,6,8};
    
    for(int i=0;i<7;i++){
        printf("%d\t",v[i]);
    }
    
    selection_sort(v);
    
    printf("\n");

    for(int i=0;i<7;i++){
        printf("%d\t",v[i]);
    }
    return 0;
}
