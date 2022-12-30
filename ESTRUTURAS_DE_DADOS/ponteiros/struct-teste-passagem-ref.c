// Online C compiler to run C program online
#include <stdio.h>

struct teste{
    int valor;
};

void func(struct teste t){
    t.valor = 10;
}

int main() {
    struct teste t;
    t.valor = 45;
    printf("%d\n",t.valor);
    func(t);
    printf("%d\n",t.valor);

    return 0;
}