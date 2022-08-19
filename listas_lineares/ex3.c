/*1. Uma empresa está atualizando seu sistema de controle de pagamentos de funcionários
e utiliza as seguintes informações para cada funcionário:
Matrícula (inteiro)
Nome (string)
Cargo (string)
Salário (real)
O sistema inicialmente não possui dados, ou seja, a princípio nenhum funcionário está
cadastrado (lista vazia). Desenvolva um programa para:
a. A lista deve estar organizada por ordem crescente de matrícula. Inserir um novo
funcionário na posição correta;
b. Localizar um funcionário de acordo com sua matrícula;
c. Deletar funcionários quando são demitidos;
d. Listar todos os funcionários que possuam salários entre R$ 2500,00 e R$
6800,00*/

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

struct funcionarios cadastrar(int i){
    struct funcionarios func;
    printf("matricula funcionario %d: ",i+1);
    scanf("%d",&func.matricula);
    printf("nome: ");
    getchar();
    fgets(func.nome,31,stdin);
    printf("cargo: ");
    getchar();
    fgets(func.cargo,31,stdin);
    printf("salario: ");
    scanf("%f",&func.salario);
    return func;
}

void imprimir(struct funcionarios f[TAMANHO], int total_funcionarios){
    for(int i=0;i<total_funcionarios;i++){
        printf("matricula: %d\n",f[i].matricula);
        puts(f[i].nome);
        printf("\ncargo: ");
        puts(f[i].cargo);
        printf("\nsalario: %.2f\n",f[i].salario);
        printf("\n");
    }

    printf("\n\n");
}


int main(){
    struct funcionarios func[TAMANHO], func_aux;
    int total_funcionarios=0, opcao=0, mat;

    do{
        printf("1.cadastrar\n2.buscar\n3.apagar\n4.listar func. c/ salario entre 2500 e 6800\n5.listar tudo: ");
        scanf("%d",&opcao);

        if(opcao==1){

            if(total_funcionarios==TAMANHO){
                printf("limite de funcionarios atingido, remova para poder inserir\n");
            }
            else{

                if(total_funcionarios==0){
                    func[0]=cadastrar(0);
                    total_funcionarios++;//total_funcionarios = 1
                }
                else if(total_funcionarios==1){
                    func_aux=cadastrar(1);
                    if(func[0].matricula>func_aux.matricula){
                        func[1]=func[0];
                        func[0]=func_aux;
                    }
                    else{
                        func[1]=func_aux;
                    }
                    total_funcionarios++;
                }
                else{

                    int posicao_insercao=0;
                    func_aux=cadastrar(total_funcionarios);

                    while(func[posicao_insercao].matricula<func_aux.matricula && posicao_insercao<TAMANHO){
                        posicao_insercao++;
                    }

                    for(int i=total_funcionarios-1;i>=posicao_insercao;i--){
                        func[i+1] = func[i];
                    }

                    func[posicao_insercao] = func_aux;
                    total_funcionarios++;

                }
            }
        }

        else if(opcao==2){
            printf("\nmatricula: ");
            scanf("%d",&mat);
            for(int i=0;i<total_funcionarios;i++){
                if(func[i].matricula==mat){
                    printf("nome %s\n",func[i].nome);
                    printf("cargo %s\n",func[i].cargo);
                }
            }
        }

        else if(opcao==3){
            if(total_funcionarios==0){
                printf("lista vazia, insira elementos\n");
            }
            else{
                int posicao_deletar;
                printf("posicao para apagar: ");
                scanf("%d",&posicao_deletar);
                while(posicao_deletar<0||posicao_deletar>=total_funcionarios){
                    printf("posicao para apagar: ");
                    scanf("%d",&posicao_deletar);
                }
                for(int i=posicao_deletar;i<total_funcionarios;i++){
                    func[i]=func[i+1];
                }
                total_funcionarios--;
            }
        }

        else if(opcao==4){
            for(int i=0;i<total_funcionarios;i++){
                if(func[i].salario>2500 && func[i].salario<6800){
                    printf("nome %s\n",func[i].nome);
                    printf("cargo %s\n",func[i].cargo);
                }
            }
        }

        else if(opcao==5){
            imprimir(func,total_funcionarios);
        }

        printf("digite 6 pra sair ou outro numero pra continuar: ");
        scanf("%d",&opcao);

        printf("\n\n#############################\n\n\n\n");
    }while(opcao!=6);

    return 0;
}
