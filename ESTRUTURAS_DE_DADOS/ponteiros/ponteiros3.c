#include <stdio.h>
#include <stdlib.h>

//recebe o valor quardado em p, por isso um *
//se recebesse o endereco de p, teria que ter outro *, um pro endereco de p, e outro pro valor que ele guarda
//porque ambos sao endereços de memória
void func(int *p){
    if(p==NULL){//verifica se o valor guardado em p = NULL
        printf("p = NULL\n");
    }
    else{
        printf("valor guardado em p: %x\n",p);
    }

    if(*p == NULL){//verifica se o valor do endereço que p aponta é igual a NULL
        printf("*p = NULL\n");
    }
    else{
        printf("valor do endereco que p aponta: %d\n",*p);
    }
}




//recebe o endereco de p, entao ao acessar p aparece o endereco dele
//entao ao usar *p vai até o valor que p guarda (que é o endereço de A)
//e **p, o primeiro * vai no valor que p guarda, e o segundo * vai nesse valor que p guarda (endereco de A) e traz o valor que ta nele (10)

void func2(int **p){
    if(p==NULL){//verifica se o endereco de p = NULL
        printf("p = NULL\n");
    }
    else{//cai no else pois foi passado o endereco de p, e nao o valor que ele guarda
        printf("endereco de p: %x\n",p);
    }

    if(*p == NULL){
        printf("*p = NULL\n");
    }
    else{
        printf("valor guardado em p: %x\n",*p);
    }

    if(**p == NULL){
        printf("**p = NULL");
    }
    else{
        printf("valor do endereco que aponta: %d\n",**p);
    }
}

int main()
{
    int a = 10;
    int *p;

    if(p==NULL){//true
        printf("p = NULL\n");
    }

    //func(p);
    //func2(&p);

    p = &a;
    printf("endereco de A: %x\n",&a);
    printf("endereco de P (pois p é uma variavel e tbm tem um endereco): %x\n",&p);

    func(p);
    func2(&p);

    return 0;
}


