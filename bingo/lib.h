//limpa o console, roda o comando apropriado pra cada SO verifica a constante (definição) do sistema operacional
void clear_console(){
    #ifdef __linux__
        system("clear");
    #elif
        system("cls");
    #else

    #endif
}


//funcao gera numero aleatório
int generate_random_number(){
    //srand(time(0));
    int number = (rand()%60)+1;
    return number;
}


//função recebe por parametro as cartelas, vetor com os numeros sorteados e os nomes dos jogadores 
//e imprime com um simbolo marcando os numeros acertados com um simbolo para destacar os numeros que ja acertou
void imprimir_cartelas(int cj1[3][5], int cj2[3][5], int cj3[3][5], int numeros_sorteados[60], char nomej1[30], char nomej2[30], char nomej3[30]){
    char acertou;
    
    printf("\nCARTELAS DOS JOGADORES (acertos marcados com o simbolo '<-')\n");
    
    printf("\nCARTELA JOGADOR 1: ");
    puts(nomej1);
    
    //verifica cada numero da cartela no vetor de numeros_sorteados e se achar a variavel acertou é setada pra 's'
    for(int i=0;i<3;i++){
        for(int j=0;j<5;j++){
            acertou='n';
            for(int k=0;k<60;k++){
                if(cj1[i][j]==numeros_sorteados[k]){
                    acertou='s';
                }
            }
            acertou=='s' ? printf("%d <-\t",cj1[i][j]) : printf("%d\t",cj1[i][j]);
        }
        printf("\n");
    }
    
    printf("\nCARTELA JOGADOR 2: ");
    puts(nomej2);
    
    for(int i=0;i<3;i++){
        for(int j=0;j<5;j++){
            acertou='n';
            for(int k=0;k<60;k++){
                if(cj2[i][j]==numeros_sorteados[k]){
                    acertou='s';
                }
            }
            acertou=='s' ? printf("%d <-\t",cj2[i][j]) : printf("%d\t",cj2[i][j]);
        }
        printf("\n");
    }
    
    printf("\nCARTELA JOGADOR 3: ");
    puts(nomej3);
    
    for(int i=0;i<3;i++){
        for(int j=0;j<5;j++){
            acertou='n';
            for(int k=0;k<60;k++){
                if(cj3[i][j]==numeros_sorteados[k]){
                    acertou='s';
                }
            }
            acertou=='s' ? printf("%d <-\t",cj3[i][j]) : printf("%d\t",cj3[i][j]);
        }
        printf("\n");
    }
}