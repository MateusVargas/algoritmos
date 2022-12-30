/*
Colocar em ordem crescente os dois primeiros elementos;
O terceiro elemento é inserido na posição correta, de acordo com os dois primeiros, ou seja, antes do primeiro, entre os dois, ou depois do segundo;
Inserir o quarto elemento na posição correta, de acordo com os três primeiros;
Repetir este processo até que todos estejam ordenados
*/

#include <stdio.h>


/*
1a iteracao:

for i
i=1
aux=v[1] //32

    for j
        j=0
        aux < v[j] //32<3 false
    sai for j

linha 128
v[j+1] = aux //v[1]=32




2a iteracao:

for i
i=2
aux=v[2] //5

    for j
        j=1
        aux < v[j] //5 < 32 true
        v[j+1] = v[j] //v[2] = v[1], v = {3,32,32,56,80,0}
        
        j=0
        aux < v[j] //5 < 3 false
    sai for j

linha 128
v[j+1] = aux //v[1]=5,  v = {3,5,32,56,80,0}




3a iteracao:

for i
i=3
aux=v[3] //56

    for j
        j=2
        aux < v[j] //56 < 32 false
    sai for j

linha 128
v[j+1] = aux //v[3]=56,  v = {3,5,32,56,80,0}




4a iteracao:

for i
i=4
aux=v[4] //80

    for j
        j=3
        aux < v[j] //80 < 56 false
    sai for j

linha 128
v[j+1] = aux //v[4]=80,  v = {3,5,32,56,80,0}




5a iteracao:

for i
i=5
aux=v[5] //0

    for j
        j=4
        aux < v[j] //0 < 80 true
        v[j+1] = v[j] //v[5] = v[4], v = {3,5,32,56,80,80}
        
        j=3
        aux < v[j] //0 < 56 true
        v[j+1] = v[j] //v[4] = v[3], v = {3,5,32,56,56,80}
        
        j=2
        aux < v[j] //0 < 32 true
        v[j+1] = v[j] //v[3] = v[2], v = {3,5,32,32,56,80}
        
        j=1
        aux < v[j] //0 < 5 true
        v[j+1] = v[j] //v[2] = v[1], v = {3,5,5,32,56,80}
        
        j=0
        aux < v[j] //0 < 3 true
        v[j+1] = v[j] //v[1] = v[0], v = {3,3,5,32,56,80}
        
        j=-1
    sai for j

linha 128
v[j+1] = aux //v[0]=0,  v = {0,3,5,32,56,80}

*/



void insertion_sort(int v[6]){
    int j, aux;
    for(int i=1;i<6;i++){
        aux = v[i];
        for(j=i-1; j>=0 && aux<v[j]; j--){
            v[j+1] = v[j];
        }
        v[j+1] = aux;
    }
}

int main()
{
    int v[6]={3,32,5,56,80,0};
    
    for(int i=0;i<6;i++){
        printf("%d\t",v[i]);
    }
    
    insertion_sort(v);
    
    printf("\n");

    for(int i=0;i<6;i++){
        printf("%d\t",v[i]);
    }
    return 0;
}
