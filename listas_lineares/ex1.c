// Criar uma lista para armazenar até 10 valores inteiros. Depois defina funções para:
// – Inserir um novo elemento na i-ésima posição (fornecidos pelo usuário e
// passados por parâmetro).
// – Acessar o elemento da i-ésima posição (fornecida pelo usuário e passada
// por parâmetro);
// – Retirar um elemento da i-ésima posição (fornecidos pelo usuário e passados
// por parâmetro).
// – Alterar o elemento da i-ésima posição (fornecidos pelo usuário e passados
// por parâmetro).
// – Defina uma função para apresentar os elementos da lista após cada
// alteração, inserção e retirada.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL 10

void imprimir(int vet[10],int items_validos){
    if(items_validos==0){
        printf("não há items no vetor");
        return;
    }
    
    for(int i=0;i<items_validos;i++){
        printf("%d\t",vet[i]);
    }
}

int main() {
    int vet[TOTAL], total_items_validos=0;
    int posicao, valor;
    char sair,opcao;
    
    while(sair!='s'){
        if(total_items_validos<TOTAL){
            printf("digite s pra inserir um elemento: ");
            scanf("%c",&opcao);
            
            if(opcao=='s'){
                printf("informe a posicao para insercao: ");
                scanf("%d",&posicao);
                
                while(posicao<0||posicao>TOTAL-1){
                    printf("posicao invalida! informe a posicao para insercao: ");
                    scanf("%d",&posicao);
                }
                
                printf("informe o valor: ");
                scanf("%d",&valor);
                
                //se a posicao digitada for maior/igual ao total de items validos
                //assume-se que a podicao para inserir é a proxima que estiver disponivel
                if(posicao>=total_items_validos){
                    printf("posicao informada invalida! pegando a proxima posicao disponivel (posicao %d)\n",total_items_validos);
                    posicao = total_items_validos;
                    
                    vet[posicao]=valor;
                    total_items_validos++;
                    
                    imprimir(vet,total_items_validos);
                }
                
                //se a posicao digitada for menor que o total de items validos
                //ex: total_items_validos = 5 então as posicoes do vetor vao de 0 a 4
                //ou seja ele quer inserir numa posicao ja ocupada, entao incrementa em 1
                //o total_items_validos passando a ser 6 e faz um for de total_items_validos-1 
                //até a posicao desejada para inserir supondo que a posicao desejada seja 2 
                //entao será um for recursivo de 5 até 2, lembrando que na posicao 5 nao tem nenhum valor
                //só tem nas posicoes de 0 a 4
                //exemplo: vetor com esses elementos: [2,4,6,1,8], deseja-se inserir na posicao 2 o numero 9
                //entao tem que ficar dessa forma: [2,4,9,6,1,8]
                //na 1° iteracao o i=5 entao vet[5]=vet[5-1], sendo que na posicao 5 não tem nada só tem numeros validos até a posicao 4
                //entao vai ficar ao final da 1° iteracao [2,4,6,1,8,8]
                //na 2° i=4, vet[4] = vet[4-1] resultado: [2,4,6,1,1,8]
                //na 3° i=3, vet[3] = vet[3-1] resultado: [2,4,6,6,1,8]
                //na 4° i=2, vet[2] = vet[2-1] resultado: [2,4,4,6,1,8]
                //depois sai do for e na posicao 2 é atribuido o 9 ficando [2,4,9,6,1,8]
                else{
                    total_items_validos++;
                    
                    for(int i=total_items_validos-1;i>=posicao;i--){
                        vet[i]=vet[i-1];
                    }
                    
                    vet[posicao]=valor;
                    imprimir(vet,total_items_validos);
                    
                    //outra forma
                    // int j=total_items_validos-1;
                    // while(j>=posicao){
                    //     vet[j+1]=vet[j];
                    //     j--;
                    // }
                    // vet[posicao]=valor;
                    // total_items_validos++;
                }
                
            }
        }
        
        if(total_items_validos>0){
            printf("\ndigite s para acessar um elemento: ");
            getchar();
            scanf("%c",&opcao);
            
            if(opcao=='s'){
                printf("informe a posicao para acessar: ");
                scanf("%d",&posicao);
                
                if(posicao>=total_items_validos){
                    printf("posicao invalida! retornando valor na ultima posicao valida\n");
                    posicao = total_items_validos-1;
                }
                
                printf("%d\n",vet[posicao]);
            }
        }
        
        if(total_items_validos>0){
            printf("\ndigite s para apagar um elemento: ");
            getchar();
            scanf("%c",&opcao);
            
            if(opcao=='s'){
                printf("informe a posicao para retirar: ");
                getchar();
                scanf("%d",&posicao);
                
                if(posicao>=total_items_validos){
                    printf("posicao invalida! removendo elemento da ultima posicao valida\n");
                    total_items_validos--;
                    posicao = total_items_validos-1;
                    imprimir(vet,total_items_validos);
                }
                else{
                    for(int i=posicao;i<total_items_validos-1;i++){
                        vet[i]=vet[i+1];
                    }
                    total_items_validos--;
                    imprimir(vet,total_items_validos);
                }
            }
        }
        
        if(total_items_validos>0){
            printf("\ndigite s para alterar um elemento: ");
            getchar();
            scanf("%c",&opcao);
            
            if(opcao=='s'){
                printf("informe a posicao para alterar: ");
                getchar();
                scanf("%d",&posicao);
                
                //lembrando: total_items_validos armazena os total de valores ja inseridos
                //se ele valer 5, serao 5 valores inseridos e as posicoes vao de 0 a 4
                while(posicao>=total_items_validos){
                    printf("não há items nessa posicao! digite posicao novamente: ");
                    scanf("%d",&posicao);
                }
                
                printf("digite o novo valor: ");
                scanf("%d",&valor);
                
                vet[posicao]=valor;
                imprimir(vet,total_items_validos);
            }
        }
        
        printf("\n\ns para sair, qualquer letra para continuar: ");
        getchar();
        scanf("%c",&sair);
        
        getchar();
    }
    
    imprimir(vet,total_items_validos);
    
    return 0;
}

