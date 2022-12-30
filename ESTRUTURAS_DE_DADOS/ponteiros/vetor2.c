// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p;
    p=(int*)malloc(5*sizeof(int));
    
    for(int i=0;i<5;i++){
        *(p+i)=i;
    }
    
    //mostra os valores
    for(int i=0;i<5;i++){
        printf("%d\t",*(p+i));
    }
    
    //mostra os valores
    for(int i=0;i<5;i++){
        printf("%d\t",(*p+i));
    }
    
    //mostra os valores
    for(int i=0;i<5;i++){
        printf("%d\t",*p+i);
    }
    
    //mostra os enderecos
    for(int i=0;i<5;i++){
        printf("%d\t",(p+i));
    }

    return 0;
}