// Desenvolva um algoritmo com funções para manipular duas listas lineares que permita:
// 1. Inserir elementos dinamicamente;
// 2. Concatenar duas listas;
// 3. Intercalar os elementos de duas listas (x1, y1, x2, y2, ..., xn, yn);
// 4. Dividir uma lista em duas;
// 5. Copiar uma lista para outra;
// 6. Ordenar por ordem crescente/decrescente;
// 7. Pesquisar elementos nas listas.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TAMANHO 10


int selecionar_opcao(){
    int opcao_menu;
    printf("1. Inserir elemento em uma lista\n");
    printf("2. Remover elemento de uma lista\n");
    printf("3. Concatenar duas listas\n");
    printf("4. Intercalar os elementos de duas listas (x1, y1, x2, y2, ..., xn, yn)\n");
    printf("5. Dividir uma lista em duas\n");
    printf("6. Copiar uma lista para outra\n");
    printf("7. Ordenar por ordem crescente/decrescente\n");
    printf("8. Pesquisar elementos nas listas\n");
    scanf("%d",&opcao_menu);
        
    while(opcao_menu<1 || opcao_menu>8){
        printf("\nopcao invalida!\n");
        printf("1. Inserir elemento em uma lista\n");
        printf("2. Remover elemento de uma lista\n");
        printf("3. Concatenar duas listas\n");
        printf("4. Intercalar os elementos de duas listas (x1, y1, x2, y2, ..., xn, yn)\n");
        printf("5. Dividir uma lista em duas\n");
        printf("6. Copiar uma lista para outra\n");
        printf("7. Ordenar por ordem crescente/decrescente\n");
        printf("8. Pesquisar elementos nas listas\n");
        scanf("%d",&opcao_menu);
    }
    
    return opcao_menu;
}


int selecionar_vetor(char mensagem[40]){
    int escolha;
    printf("%s\n",mensagem);
    printf("1. vetor1\n");
    printf("2. vetor2\n");
    scanf("%d",&escolha);
            
    while(escolha<1 || escolha>2){
        printf("\nopcao invalida!\n%s\n",mensagem);
        printf("1. vetor1\n");
        printf("2. vetor2\n");
        scanf("%d",&escolha);
    }
    
    return escolha;
}


void imprime(int vetor1[TAMANHO], int vetor2[TAMANHO], int items_vetor1, int items_vetor2){
    printf("\nimprimindo vetores:\n");
    if(items_vetor1==0){
        printf("\nnao ha elementos no vetor1.\n");
    }
    else{
        printf("\nVETOR 1:\n");
        for(int i=0;i<items_vetor1;i++){
            printf("%d\t",vetor1[i]);
        }
        printf("\n");
    }
    
    if(items_vetor2==0){
        printf("\nnao ha elementos no vetor2.\n");
    }
    else{
        printf("\nVETOR 2:\n");
        for(int i=0;i<items_vetor2;i++){
            printf("%d\t",vetor2[i]);
        }
        printf("\n");
    }
}


int main(){
    int vetor1[TAMANHO], vetor2[TAMANHO], total_items_inseridos_vetor1=0, total_items_inseridos_vetor2=0;
    int opcao_menu, sair, opcao_vetor, posicao_inserir, posicao_remover, numero;

    while(sair!=1){
        opcao_menu = selecionar_opcao();
        
        //1. Inserir elementos nos vetores
        if(opcao_menu==1){
            char mensagem[40] = {"qual vetor deseja inserir"};
            opcao_vetor = selecionar_vetor(mensagem);
            
            if(opcao_vetor==1){
                
                if(total_items_inseridos_vetor1==TAMANHO){
                    printf("\nvoce não pode mais inserir numeros no vetor1, capacidade esgotada, apague items!\n");
                }
                
                else{
                    printf("numero para inserir no vetor1: ");
                    scanf("%d",&numero);
                    
                    printf("posicao para inserir no vetor1: ");
                    scanf("%d",&posicao_inserir);
                    
                    while(posicao_inserir<0||posicao_inserir>=TAMANHO){
                        printf("\nposicao invalida!\nposicao para inserir no vetor1: ");
                        scanf("%d",&posicao_inserir);
                    }
                    
                    if(posicao_inserir>=total_items_inseridos_vetor1){
                        /*se o vetor tiver 3 elementos eles estão nas posicoes 0,1,2 e o cara quiser inserir na 
                        posicao 4 por exemplo*/
                        if(posicao_inserir>total_items_inseridos_vetor1){
                            printf("\nposicao invalida! pegando proxima posicao disponivel no vetor (pos: %d)\n",total_items_inseridos_vetor1);
                        }
                        
                        /*se o vetor tiver 3 elementos eles estão nas posicoes 0,1,2 a posicao pra inserir
                        será igual ao total de items inseridos que é 3, então será inserido na 
                        posicao 3 exatamente na posicao que dever ser, 
                        depois incrementa o total de valores inseridos*/
                        posicao_inserir = total_items_inseridos_vetor1;
                    }
                    else{
                        for(int i=total_items_inseridos_vetor1;i>=posicao_inserir;i--){
                            vetor1[i]=vetor1[i-1];
                        }
                    }
                    
                    total_items_inseridos_vetor1++;
                    vetor1[posicao_inserir] = numero;
                }
            }
            else{
                if(total_items_inseridos_vetor2==TAMANHO){
                    printf("\nvoce não pode mais inserir numeros no vetor2, capacidade esgotada, apague items!\n");
                }
                
                else{
                    printf("numero para inserir no vetor2: ");
                    scanf("%d",&numero);
                    
                    printf("posicao para inserir no vetor2: ");
                    scanf("%d",&posicao_inserir);
                    
                    while(posicao_inserir<0||posicao_inserir>=TAMANHO){
                        printf("\nposicao invalida!\nposicao para inserir no vetor1: ");
                        scanf("%d",&posicao_inserir);
                    }
                    
                    if(posicao_inserir>=total_items_inseridos_vetor2){
    
                        if(posicao_inserir>total_items_inseridos_vetor2){
                            printf("\nposicao invalida! pegando proxima posicao disponivel no vetor(pos: %d)\n",total_items_inseridos_vetor2); 
                        }
    
                        posicao_inserir = total_items_inseridos_vetor2;
                    }
                    else{
                        for(int i=total_items_inseridos_vetor2;i>=posicao_inserir;i--){
                            vetor2[i]=vetor2[i-1];
                        }
                    }
                    
                    total_items_inseridos_vetor2++;
                    vetor2[posicao_inserir] = numero;
                }
            }
        }
        
        
        //2. Remover elementos dos vetores
        else if(opcao_menu==2){
            char mensagem[40] = {"elemento de qual vetor deseja remover"};
            opcao_vetor = selecionar_vetor(mensagem);
            
            if(opcao_vetor==1){
                
                if(total_items_inseridos_vetor1==0){
                    printf("\nvoce não pode remover elementos do vetor1, ele esta vazio, insira items!\n");
                }
                
                else{
                    printf("posicao para remover no vetor1 (0 ate %d): ",total_items_inseridos_vetor1-1);
                    scanf("%d",&posicao_remover);
                    
                    while(posicao_remover<0||posicao_remover>=total_items_inseridos_vetor1){
                        printf("\nposicao invalida!\nposicao para remover no vetor1 (0 ate %d): ",total_items_inseridos_vetor1-1);
                        scanf("%d",&posicao_remover);
                    }
                    
                    //se for a ultima posicao com elementos validos, apenas decrementa o contador
                    if(posicao_remover==total_items_inseridos_vetor1-1){
                        total_items_inseridos_vetor1--;
                    }
                    else{
                        for(int i=posicao_remover;i<total_items_inseridos_vetor1;i++){
                            vetor1[i] = vetor1[i+1];
                        }
                        total_items_inseridos_vetor1--;
                    }
                }
            }
            
            else{
                
                if(total_items_inseridos_vetor2==0){
                    printf("\nvoce não pode remover elementos do vetor2, ele esta vazio, insira items!\n");
                }
                
                else{
                    printf("posicao para remover no vetor2 (0 ate %d): ",total_items_inseridos_vetor2-1);
                    scanf("%d",&posicao_remover);
                    
                    while(posicao_remover<0||posicao_remover>=total_items_inseridos_vetor2){
                        printf("\nposicao invalida!\nposicao para remover no vetor2 (0 ate %d): ",total_items_inseridos_vetor2-1);
                        scanf("%d",&posicao_remover);
                    }
                    
                    //se for a ultima posicao com elementos validos, apenas decrementa o contador
                    if(posicao_remover==total_items_inseridos_vetor2-1){
                        total_items_inseridos_vetor2--;
                    }
                    else{
                        for(int i=posicao_remover;i<total_items_inseridos_vetor2;i--){
                            vetor2[i] = vetor2[i+1];
                        }
                        total_items_inseridos_vetor2--;
                    }
                }
                
            }
        }
        
        
        
        //3. Concatenar duas listas
        else if(opcao_menu==3){
            int vetor_aux[TAMANHO*2];
            
            for(int i=0;i<total_items_inseridos_vetor1+total_items_inseridos_vetor2;i++){
                if(i<total_items_inseridos_vetor1){
                    vetor_aux[i] = vetor1[i];
                }
                else{
                    vetor_aux[i] = vetor2[i-total_items_inseridos_vetor1];
                }
            }
            
            printf("\nvetores concatenados:\n");
            for(int i=0;i<total_items_inseridos_vetor1+total_items_inseridos_vetor2;i++){
                printf("%d\t",vetor_aux[i]);
            }
           
        }
        
        
        
        //4. Intercalar os elementos de duas listas (x1, y1, x2, y2, ..., xn, yn)
        else if(opcao_menu==4){
            int indice_vetor1=0, indice_vetor2=0;
            printf("\nelementos dos vetores intercalados\n");
            
            if(total_items_inseridos_vetor1==total_items_inseridos_vetor2){
                for(int i=0;i<total_items_inseridos_vetor1+total_items_inseridos_vetor2;i++){
                    if(i%2==0){
                        printf("%d\t",vetor1[indice_vetor1++]);
                    }
                    else{
                        printf("%d\t",vetor2[indice_vetor2++]);
                    }
                }    
            }
            
            else if(total_items_inseridos_vetor1>total_items_inseridos_vetor2){
                for(int i=0;i<total_items_inseridos_vetor2*2;i++){
                    if(i%2==0){
                        printf("%d\t",vetor1[indice_vetor1++]);
                    }
                    else{
                        printf("%d\t",vetor2[indice_vetor2++]);
                    }
                }
                
                for(int i=total_items_inseridos_vetor2;i<total_items_inseridos_vetor1;i++){
                    printf("%d\t",vetor1[i]);
                }
            }
            else{
                for(int i=0;i<total_items_inseridos_vetor1*2;i++){
                    if(i%2==0){
                        printf("%d\t",vetor1[indice_vetor1++]);
                    }
                    else{
                        printf("%d\t",vetor2[indice_vetor2++]);
                    }
                }
                
                for(int i=total_items_inseridos_vetor1;i<total_items_inseridos_vetor2;i++){
                    printf("%d\t",vetor2[i]);
                }
            }
            
        }
        
        
        
        //5. Dividir uma lista em duas
        else if(opcao_menu==5){
            char mensagem[40] = {"qual vetor deseja dividir em 2"};
            opcao_vetor = selecionar_vetor(mensagem);
            
            int parte_A, parte_B;
            
            if(opcao_vetor==1){
                parte_A = total_items_inseridos_vetor1/2;
                parte_B = total_items_inseridos_vetor1 - parte_A;
                
                printf("\nvetor1 dividido em 2:\nParte 1\n");
                for(int i=0;i<parte_A;i++){
                    printf("%d\t",vetor1[i]);
                }
                printf("\nParte 2\n");
                for(int i=0;i<parte_B;i++){
                    printf("%d\t",vetor1[i+parte_A]);
                }
                printf("\n");
            }
            
            else{
                parte_A = total_items_inseridos_vetor2/2;
                parte_B = total_items_inseridos_vetor2 - parte_A;
                
                printf("\nvetor2 dividido em 2:\nParte 1\n");
                for(int i=0;i<parte_A;i++){
                    printf("%d\t",vetor2[i]);
                }
                printf("\nParte 2");
                for(int i=0;i<parte_B;i++){
                    printf("%d\t",vetor2[i+parte_A]);
                }
                printf("\n");
            }
            
        }
        
        
        
        
        //6. Copiar uma lista para outra
        else if(opcao_menu==6){
            printf("qual vetor deseja copiar\n");
            printf("1. copiar vetor2 para o vetor1\n");
            printf("2. copiar vetor1 para o vetor2\n");
            scanf("%d",&opcao_vetor);
            
            while(opcao_vetor<1 || opcao_vetor>2){
                printf("\nopcao invalida!\nqual vetor deseja copiar\n");
                printf("1. copiar vetor2 para o vetor1\n");
                printf("2. copiar vetor1 para o vetor2\n");
                scanf("%d",&opcao_vetor);
            }
            
            int vetor_aux[TAMANHO*2];
            
            if(opcao_vetor==1){
                for(int i=0;i<total_items_inseridos_vetor1;i++){
                    vetor_aux[i] = vetor1[i];
                }
                
                //copiar vetor2 pro vetor_aux que contem os valores do vetor1
                for(int i=0;i<total_items_inseridos_vetor2;i++){
                    vetor_aux[i+total_items_inseridos_vetor1] = vetor2[i];
                }
                
                printf("\nvetor2 copiado para o vetor1\n");
                for(int i=0;i<total_items_inseridos_vetor1+total_items_inseridos_vetor2;i++){
                    printf("%d\t",vetor_aux[i]);
                }
                printf("\n\n");
            }
            else{
                for(int i=0;i<total_items_inseridos_vetor2;i++){
                    vetor_aux[i] = vetor2[i];
                }
                
                //copiar vetor1 pro vetor_aux que contem os valores do vetor2
                for(int i=0;i<total_items_inseridos_vetor1;i++){
                    vetor_aux[i+total_items_inseridos_vetor2] = vetor1[i];
                }
                
                printf("\nvetor2 copiado para o vetor1\n");
                for(int i=0;i<total_items_inseridos_vetor1+total_items_inseridos_vetor2;i++){
                    printf("%d\t",vetor_aux[i]);
                }   
                printf("\n\n");
            }
        }
        
        
        
        
        //7. Ordenar por ordem crescente/decrescente
        else if(opcao_menu==7){
            char mensagem[40] = {"qual vetor deseja ordenar"};
            opcao_vetor = selecionar_vetor(mensagem);
            
            int ordem, vetor_aux[TAMANHO], aux;
            
            printf("1. crescente\n");
            printf("2. decrescente\n");
            scanf("%d",&ordem);
            
            while(ordem<1 || ordem>2){
                printf("ordem invalida!\n1. crescente\n");
                printf("2. decrescente\n");
                scanf("%d",&ordem);
            }
            
            if(opcao_vetor==1){
                //passando os valores do vetor1 pro vetor_aux para fazer as manipulacoes nele
                //sem mexer nos vetores originais
                for(int i=0;i<total_items_inseridos_vetor1;i++){
                    vetor_aux[i]=vetor1[i];
                }
                
                if(ordem==1){
                    
                    for(int i=0;i<total_items_inseridos_vetor1;i++){
                        for(int j=0;j<i;j++){
                            if(vetor_aux[i]<vetor_aux[j]){
                                aux=vetor_aux[i];
                                vetor_aux[i]=vetor_aux[j];
                                vetor_aux[j]=aux;
                            }
                        }
                    }
                    
                }
                else{
                    
                    for(int i=0;i<total_items_inseridos_vetor1;i++){
                        for(int j=0;j<i;j++){
                            if(vetor_aux[i]>vetor_aux[j]){
                                aux=vetor_aux[i];
                                vetor_aux[i]=vetor_aux[j];
                                vetor_aux[j]=aux;
                            }
                        }
                    }
                    
                }
                
                printf("\nvetor1 ordenado:\n");
                for(int i=0;i<total_items_inseridos_vetor1;i++){
                    printf("%d\t",vetor_aux[i]);
                }
            
            }
            
            else{
                
                for(int i=0;i<total_items_inseridos_vetor2;i++){
                    vetor_aux[i]=vetor2[i];
                }
                
                if(ordem==1){
                    
                    for(int i=0;i<total_items_inseridos_vetor2;i++){
                        for(int j=0;j<i;j++){
                            if(vetor_aux[i]<vetor_aux[j]){
                                aux=vetor_aux[i];
                                vetor_aux[i]=vetor_aux[j];
                                vetor_aux[j]=aux;
                            }
                        }
                    }
                    
                }
                else{
                    
                    for(int i=0;i<total_items_inseridos_vetor2;i++){
                        for(int j=0;j<i;j++){
                            if(vetor_aux[i]>vetor_aux[j]){
                                aux=vetor_aux[i];
                                vetor_aux[i]=vetor_aux[j];
                                vetor_aux[j]=aux;
                            }
                        }
                    }
                    
                }
                
                printf("\nvetor2 ordenado:\n");
                for(int i=0;i<total_items_inseridos_vetor2;i++){
                    printf("%d\t",vetor_aux[i]);
                }
            
            }
        }
        
        
        
        //8. Pesquisar elementos nas listas
        else if(opcao_menu==8){
            char mensagem[40] = {"qual vetor deseja pesquisar"};
            opcao_vetor = selecionar_vetor(mensagem);
            
            char existe='n';
            
            if(opcao_vetor==1){
                printf("digite um numero pra pesquisar no vetor1: ");
                scanf("%d",&numero);
                
                for(int i=0;i<total_items_inseridos_vetor1;i++){
                    if(numero==vetor1[i]){
                        existe='s';
                        printf("%d encontrado na posicao [%d].\n",vetor1[i],i);
                    }
                }
                
                if(existe=='n'){
                    printf("\nnumero não encontrado no vetor1\n");
                }
            }
            else{
                existe='n';
                
                printf("digite um numero pra pesquisar no vetor2: ");
                scanf("%d",&numero);
                
                for(int i=0;i<total_items_inseridos_vetor2;i++){
                    if(numero==vetor2[i]){
                        existe='s';
                        printf("%d encontrado na posicao [%d].\n",vetor2[i],i);
                    }
                }
                
                if(existe=='n'){
                    printf("\nnumero não encontrado no vetor2\n");
                }
            }
            
        }

        
        imprime(
            vetor1,
            vetor2,
            total_items_inseridos_vetor1,
            total_items_inseridos_vetor2
        );
        
        printf("\ndigite 1 pra sair, ou qualquer numero pra continuar: ");
        scanf("%d",&sair);
    }
    
    
    return 0;
}
