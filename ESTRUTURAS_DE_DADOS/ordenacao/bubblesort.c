/*
Percorre a lista da esquerda para direita, comparando elementos vizinhos e os trocando de lugar se estiverem fora de ordem.
Ao final da primeira varredura apenas o maior elemento encontra-se em sua posição definitiva.
Este processo deve ser repetido até que todos os elementos estejam em ordem
*/

#include <stdio.h>

void bubblesort(int v[5]){
    int aux;
    for(int i=0;i<5;i++){
        for(int j=0;j<5-1;j++){
            if(v[j] > v[j+1]){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}

int main()
{
    int v[5]={5,2,56,1,6};
    
    for(int i=0;i<5;i++){
        printf("%d\t",v[i]);
    }
    
    bubblesort(v);
    
    printf("\n");

    for(int i=0;i<5;i++){
        printf("%d\t",v[i]);
    }
    return 0;
}
