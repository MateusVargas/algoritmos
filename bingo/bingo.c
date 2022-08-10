#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"

int main(){
    srand(time(0));
    
    clear_console();

    char jogador_1[30],jogador_2[30],jogador_3[30], numero_ja_sorteado='n', codinome[30];
    char num_gerado_cartela_ja_existe, num_gerado_cartela_ja_existe_aux;
    int cartela_j1[3][5], cartela_j2[3][5], cartela_j3[3][5], num_sorteado_rodada, numeros_ja_sorteados[60], rodada=0;
    int pts_j1=0, pts_j2=0, pts_j3=0, num_generate_cartela;

    printf("NOME JOGADOR 1: ");
    gets(jogador_1);
    
    while(strlen(jogador_1)==0){
        printf("NOME INVÁLIDO, DIGITE NOVAMENTE: ");
        gets(jogador_1);
    }
    
    printf("NOME JOGADOR 2: ");
    gets(jogador_2);
    
    while(strlen(jogador_2)==0){
        printf("NOME INVÁLIDO, DIGITE NOVAMENTE: ");
        gets(jogador_2);
    }
    
    if(strcmp(jogador_1,jogador_2)==0){
        fflush(stdin);
        printf("NOME JÁ CADASTRADO! CODINOME PARA JOGADOR 2: ");
        gets(codinome);
        
        while(strlen(codinome)==0){
            printf("CODINOME PARA JOGADOR 2 INVÁLIDO, DIGITE NOVAMENTE: ");
            gets(codinome);
        }
        strcat(jogador_2,"_");
        strcat(jogador_2,codinome);
    }
    
    //memset(codinome,0,30);//deixa o vetor vazio novamente;
    
    printf("NOME JOGADOR 3: ");
    gets(jogador_3);
    
    while(strlen(jogador_3)==0){
        printf("NOME INVÁLIDO, DIGITE NOVAMENTE: ");
        gets(jogador_3);
    }
    
    while(strcmp(jogador_1,jogador_3)==0 || strcmp(jogador_2,jogador_3)==0){
        fflush(stdin);
        printf("NOME JÁ CADASTRADO! CODINOME PARA JOGADOR 3: ");
        gets(codinome);
        
        while(strlen(codinome)==0){
            printf("CODINOME PARA JOGADOR 3 INVÁLIDO, DIGITE NOVAMENTE: ");
            gets(codinome);
        }
        strcat(jogador_3,"_");
        strcat(jogador_3,codinome);
    }
    
    
    //preenchendo vetor numeros_ja_sorteados com zero para não dar problema com valores aleatórios nas posições vazias/não preenchidas
    for(int i=0;i<60;i++){
        numeros_ja_sorteados[i]=0;
    }


    printf("\n\n\npressione ENTER para gerar as cartelas dos jogadores: ");
    getchar();
    
    //preenchendo cartela 1 evitando numeros repetidos, depois que o numero é gerado verifica na cartela
    //se algum numero dela é igual ao numero gerado, se sim uma variavel é setada como 's' pra dizer que ja existe
    //depois como ela vale 's' entra no while que tem outra variavel que controla se o numero gerado dentro do while
    //ja existe na cartela, se sim ela é setada como 's' e vai ficar gerando numeros até essa variavel auxiliar 
    //dentro do while ser 'n' quando isso acontecer a primeira variavel (num_gerado_cartela_ja_existe) tambem 
    //será setada com 'n' pois foi gerado um numero inedito e sai do while e adiciona na cartela o numero gerado
    for(int i=0;i<3;i++){
        num_gerado_cartela_ja_existe='n';
        
        for(int j=0;j<5;j++){
            num_generate_cartela=generate_random_number();
            for(int k=0;k<3;k++){
                for(int l=0;l<5;l++){
                    if(num_generate_cartela==cartela_j1[k][l]){
                        num_gerado_cartela_ja_existe='s';
                    }
                }
            }
            
            while(num_gerado_cartela_ja_existe=='s'){
                num_gerado_cartela_ja_existe_aux='n';
                num_generate_cartela=generate_random_number();
                for(int u=0;u<3;u++){
                    for(int v=0;v<5;v++){
                        if(num_generate_cartela==cartela_j1[u][v]){
                            num_gerado_cartela_ja_existe_aux='s';
                        }
                    }
                }
                if(num_gerado_cartela_ja_existe_aux=='n'){
                    num_gerado_cartela_ja_existe='n';
                }
            }
            
            if(num_gerado_cartela_ja_existe=='n'){
                cartela_j1[i][j]=num_generate_cartela;
            }
        }
    }

    
    //preenchendo cartela 2
    for(int i=0;i<3;i++){
        num_gerado_cartela_ja_existe='n';
        
        for(int j=0;j<5;j++){
            num_generate_cartela=generate_random_number();
            for(int k=0;k<3;k++){
                for(int l=0;l<5;l++){
                    if(num_generate_cartela==cartela_j2[k][l]){
                        num_gerado_cartela_ja_existe='s';
                    }
                }
            }
            
            while(num_gerado_cartela_ja_existe=='s'){
                num_gerado_cartela_ja_existe_aux='n';
                num_generate_cartela=generate_random_number();
                for(int u=0;u<3;u++){
                    for(int v=0;v<5;v++){
                        if(num_generate_cartela==cartela_j2[u][v]){
                            num_gerado_cartela_ja_existe_aux='s';
                        }
                    }
                }
                if(num_gerado_cartela_ja_existe_aux=='n'){
                    num_gerado_cartela_ja_existe='n';
                }
            }
            
            if(num_gerado_cartela_ja_existe=='n'){
                cartela_j2[i][j]=num_generate_cartela;
            }
        }
    }

    
    //preenchendo cartela 3
    for(int i=0;i<3;i++){
        num_gerado_cartela_ja_existe='n';
        
        for(int j=0;j<5;j++){
            num_generate_cartela=generate_random_number();
            for(int k=0;k<3;k++){
                for(int l=0;l<5;l++){
                    if(num_generate_cartela==cartela_j3[k][l]){
                        num_gerado_cartela_ja_existe='s';
                    }
                }
            }
            
            while(num_gerado_cartela_ja_existe=='s'){
                num_gerado_cartela_ja_existe_aux='n';
                num_generate_cartela=generate_random_number();
                for(int u=0;u<3;u++){
                    for(int v=0;v<5;v++){
                        if(num_generate_cartela==cartela_j3[u][v]){
                            num_gerado_cartela_ja_existe_aux='s';
                        }
                    }
                }
                if(num_gerado_cartela_ja_existe_aux=='n'){
                    num_gerado_cartela_ja_existe='n';
                }
            }
            
            if(num_gerado_cartela_ja_existe=='n'){
                cartela_j3[i][j]=num_generate_cartela;
            }
        }
    }
    
    imprimir_cartelas(cartela_j1,cartela_j2,cartela_j3,numeros_ja_sorteados,jogador_1,jogador_2,jogador_3);
    
    printf("\n\n######################################################\n\n\n\n\n\n");
    
    
    //enquanto os acertos dos jogadores forem menores que 15, quando alguem chegar a 15 cai fora do while e acaba o jogo
    while(pts_j1!=15 && pts_j2!=15 && pts_j3!=15){
        
        printf("pressione ENTER para iniciar a %d° RODADA: ",rodada+1);
        getchar();
    
        printf("\n- %d° RODADA\n\n",rodada+1);
        
        num_sorteado_rodada = generate_random_number();
        
        //se num_sorteado_rodada ja existir no vetor de numeros sorteados é gerado outro até ser um numero inedito
        //usando a mesma logica da nao repeticao nas cartelas
        for(int i=0;i<60;i++){
            if(numeros_ja_sorteados[i]==num_sorteado_rodada){
                numero_ja_sorteado='s';
            }
        }
        
        while(numero_ja_sorteado=='s'){
            char numero_ja_sorteado_aux='n';
            num_sorteado_rodada = generate_random_number();
        
            for(int i=0;i<60;i++){
                if(numeros_ja_sorteados[i]==num_sorteado_rodada){
                    numero_ja_sorteado_aux='s';
                } 
            }
            
            if(numero_ja_sorteado_aux=='n'){
                numero_ja_sorteado='n';
            }
        }
        
        numeros_ja_sorteados[rodada]=num_sorteado_rodada;//numero sorteado na rodada é adicionado no vetor de numeros sorteados
        
        printf("NÚMERO SORTEADO: %d\n\n",num_sorteado_rodada);
    
        printf("ACERTADORES:\n");
        
        //verificação em cada uma das matrizes de cartelas dos jogadores se o numero sorteado existe na cartela, 
        //se sim mostra o nome do jogador e incrementa o total de acertos
        
        for(int i=0;i<3;i++){
            for(int j=0;j<5;j++){
                if(cartela_j1[i][j]==num_sorteado_rodada){
                    pts_j1++;
                    printf("\t-");
                    puts(jogador_1);
                }
                if(cartela_j2[i][j]==num_sorteado_rodada){
                    pts_j2++;
                    printf("\t-");
                    puts(jogador_2);
                }
                if(cartela_j3[i][j]==num_sorteado_rodada){
                    pts_j3++;
                    printf("\t-");
                    puts(jogador_3);
                }
            }
        }
        
        //mostra total de acertos até o momento
        printf("\nTOTAL DE ACERTOS POR JOGADOR:\n");
        printf("JOGADOR 1: ");
        puts(jogador_1);
        printf("acertos: %d\n\n",pts_j1);
        
        printf("JOGADOR 2: ");
        puts(jogador_2);
        printf("acertos: %d\n\n",pts_j2);
        
        printf("JOGADOR 3: ");
        puts(jogador_3);
        printf("acertos: %d\n\n",pts_j3);
        
        
        //chama funcao pra imprimir as cartelas dos jogadores
        imprimir_cartelas(cartela_j1,cartela_j2,cartela_j3,numeros_ja_sorteados,jogador_1,jogador_2,jogador_3);
        printf("\n\n######################################################\n\n\n\n\n\n");
        
        //verifica se numero de acertos chegou a 15, se sim mostra a mensagem com o nome do jogador vencedor
        //ou os jogadores caso tenha mais de um vencedor
        if(pts_j1==15){
            printf("\nBINGO!! ");
            printf("VENCEDOR JOGADOR 1: ");
            puts(jogador_1);
        }
        if(pts_j2==15){
            printf("\nBINGO!! ");
            printf("VENCEDOR JOGADOR 2: ");
            puts(jogador_2);
        }
        if(pts_j3==15){
            printf("\nBINGO!! ");
            printf("VENCEDOR JOGADOR 3: ");
            puts(jogador_3);
        }
        
        rodada++;
    }
    
    return 0;
}
