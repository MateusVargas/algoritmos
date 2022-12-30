/*
PESQUISA BINARIA
*/

#include <stdio.h>


int rec(int vet[],int n, int meio,int meio2,int q, int l){
    
    if(vet[meio] == q) return vet[meio];

    if(vet[meio2] > q){
        
        if(vet[meio] < q){
            meio=(l+meio)/2;
        }
        else if(vet[meio] > q){
            meio/=2;
        }
            
        return rec(vet,n,meio,meio2,q,l);
    }
    
    else if(vet[meio2] < q){
       
        if(vet[meio] < q){
            meio=(n+meio)/2;
        }
        else if(vet[meio] > q){
            meio=(n-meio)*2;
        }
        
        return rec(vet,n,meio,meio2,q,l);
    }
    
}


int main()
{
    int n = 7, meio = n/2, c;
    int vet[7] = {1,2,3,4,5,6,7};
    c=rec(vet,n,meio,meio,5,n);
    printf("\n%d",c);
    
    return 0;
}
