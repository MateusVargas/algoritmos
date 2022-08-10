// 1. Uma empresa está atualizando seu sistema de controle de pagamentos de funcionários
// e utiliza as seguintes informações para cada funcionário:
// Matrícula (inteiro)
// Nome (string)
// Cargo (string)
// Salário (real)
// O sistema inicialmente não possui dados, ou seja, a princípio nenhum funcionário está
// cadastrado (lista vazia). Desenvolva um programa para:
// a. A lista deve estar organizada por ordem crescente de matrícula. Inserir um novo
// funcionário na posição correta;
// b. Localizar um funcionário de acordo com sua matrícula;
// c. Deletar funcionários quando são demitidos;
// d. Listar todos os funcionários que possuam salários entre R$ 2500,00 e R$
// 6800,00

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct funcionarios{
    int matricula;
    char nome[30];
    char cargo[30];
    float salario;
};


#define TAMANHO 30


void imprimir(struct funcionarios f, int total_funcionarios){
    for(int i=0;i<total_funcionarios;i++){
        printf("matricula: %d\n",f[i].matricula);
        puts(f[i].nome);
        printf("\n");
        puts(f[i].cargo);
        printf("\n");
        printf("salario: %.2f\n",f[i].salario);
        printf("\n");
    }
    
    printf("\n\n");
}


int main(){
    struct funcionarios func[TAMANHO];
    int total_funcionarios=0, sair=0, inserir, apagar, localizar, pos;
    
    
    while(sair!=1){
        printf("digite 1 pra inserir um funcionario: ");
        scanf("%d",&inserir);
        
        if(inserir==1){
            
            if(total_funcionarios==TAMANHO){
                printf("limite de funcionarios atingido, remova para poder inserir\n");
            }
            else{
                
                if(total_funcionarios==0){
                    
                    printf("matricula: ");
                    scanf("%d",&func[0].matricula);
                    
                    printf("nome: ");
                    gets(func[0].nome);
                    
                    printf("cargo: ");
                    gets(func[0].cargo);
                    
                    printf("salario: ");
                    scanf("%f",&func[0].salario);
                    
                    total_funcionarios++;//total_funcionarios = 1
                    
                }
                else{
                    
                    struct funcionarios func_auxiliar, aux;
                    
                    printf("informe a posição para inserir: (0 ate %d)",total_funcionarios);
                    scanf("%d",&pos);
                    
                    while(pos<0||pos>total_funcionarios){
                        printf("informe a posição para inserir: (0 ate %d)",total_funcionarios);
                        scanf("%d",&pos);
                    }
                    
                    printf("matricula: ");
                    scanf("%d",&func_auxiliar.matricula);
                        
                    printf("nome: ");
                    gets(func_auxiliar.nome);
                        
                    printf("cargo: ");
                    gets(func_auxiliar.cargo);
                        
                    printf("salario: ");
                    scanf("%f",&func_auxiliar.salario);
                        
                    for(int i=total_funcionarios;i>=pos;i--){
                        func[i] = func[i-1];
                    }
                    
                    for(int i=0;i<total_funcionarios;i++){
                        if(func_auxiliar.matricula<func[i].matricula){
                            aux=
                        }
                    }
                    
                    func[total_funcionarios] = func_auxiliar;
                    
                    total_funcionarios++;
                    
                }
                
            }
            
        }
        
        
        printf("digite 1 pra apagar: ");
        scanf("%d",&apagar);
        
        if(apagar==1){
            
            if(total_funcionarios==0){
                printf("lista vazia, insira elementos\n");
            }
            else{
                
                
                
                
            }
        }
        
        
        imprimir(func,total_funcionarios);
        
        printf("digite 1 pra sair ou outro numero pra continuar: ");
        scanf("%d");
        
        printf("\n\n#############################\n\n\n\n");
    }
    
    return 0;
}
