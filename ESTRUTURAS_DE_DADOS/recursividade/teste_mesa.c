#include <stdio.h>


/*
func(1){
    if(1>3) false
    
    else{
        a++; 1++ = 2
        a = func(2);
    }
    return a;
}



depois:

func(2){
    if(2>3) false
    
    else{
        a++; 2++ = 3
        a = func(3);
    }
    return a;
}



depois:

func(3){
    if(3>3) false
    
    else{
        a++; 3++ = 4;
        a = func(4);
    }
    return a;
}



depois:

func(4){
    if(4>3){ //true
        return a; return 4
    }
}


depois: 

func(3){
    if(3>3) false
    
    else{
        a++; 3++ = 4;
        a = func(4);
    }
    return a; // return 4, recebe o retorno da execucao anterior e retorna o valor recebido
}



func(2){
    if(2>3) false
    
    else{
        a++; 2++ = 3
        a = func(3);
    }
    return a; //return 4, recebe o retorno da execucao anterior e retorna o valor recebido
}



depois: 

func(1){
    if(1>3) false
    
    else{
        a++; 1++ = 2
        a = func(2);
    }
    return a; // return 4 pra chamada da main, recebe o retorno da execucao anterior e retorna o valor recebido
}

*/


int func(int a){
    if(a>3){
        return a;
    }
    else{
        a++;
        a = func(a);
    }
    return a;
}


int main(){
    int x = 1, resultado;
    resultado = func(x);//4
    printf("%d",resultado);

    return 0;
}
