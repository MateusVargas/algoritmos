#include <stdio.h>

void imprime(char mat[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%c\t",mat[i][j]);
        }
        printf("\n");
    }
}


void valida_posicoes(char mat[3][3], int jogador, int *linha, int *coluna){
    int pos_livre;
    do{
        pos_livre = 0;
        
        printf("j%d, linha(1 a 3) para inserir:",jogador);   
        scanf("%d",&(*linha));
            
        while(*linha < 1 || *linha > 3){
            printf("linha invalida. j%d, linha(1 a 3) para inserir:",jogador);   
            scanf("%d",&(*linha));
        }
        
        printf("j%d, coluna(1 a 3) para inserir:",jogador);   
        scanf("%d",&(*coluna));
            
        while(*coluna < 1 || *coluna > 3){
            printf("coluna invalida. j%d, coluna(1 a 3) para inserir:",jogador);   
            scanf("%d",&(*coluna));
        }
        
        if(mat[(*linha)-1][(*coluna)-1] == '-'){
            pos_livre = 1;
        } else{
            printf("\nlinha ja ocupada.\n\n");   
        }
        
    }while(!pos_livre);
}


void verifica_vencedor(char mat[3][3], int *fim){
    if((mat[0][0]=='O' && mat[0][1]=='O' && mat[0][2]=='O') || (mat[0][0]=='X' && mat[0][1]=='X' && mat[0][2]=='X')){
        *fim = 1;
    }
    else if((mat[1][0]=='O' && mat[1][1]=='O' && mat[1][2]=='O') || (mat[1][0]=='X' && mat[1][1]=='X' && mat[1][2]=='X')){
        *fim = 1;
    }
    else if((mat[2][0]=='O' && mat[2][1]=='O' && mat[2][2]=='O') || (mat[2][0]=='X' && mat[2][1]=='X' && mat[2][2]=='X')){
        *fim = 1;
    }
    else if((mat[0][0]=='O' && mat[1][0]=='O' && mat[2][0]=='O') || (mat[0][0]=='X' && mat[1][0]=='X' && mat[2][0]=='X')){
        *fim = 1;
    }
    else if((mat[0][1]=='O' && mat[1][1]=='O' && mat[2][1]=='O') || (mat[0][1]=='X' && mat[1][1]=='X' && mat[2][1]=='X')){
        *fim = 1;
    }
    else if((mat[0][2]=='O' && mat[1][2]=='O' && mat[2][2]=='O') || (mat[0][2]=='X' && mat[1][2]=='X' && mat[2][2]=='X')){
        *fim = 1;
    }
    else if((mat[0][0]=='O' && mat[1][1]=='O' && mat[2][2]=='O') || (mat[0][0]=='X' && mat[1][1]=='X' && mat[2][2]=='X')){
        *fim = 1;
    }
    else if((mat[0][2]=='O' && mat[1][1]=='O' && mat[2][0]=='O') || (mat[0][2]=='X' && mat[1][1]=='X' && mat[2][0]=='X')){
        *fim = 1;
    }
}


int verifica_empate(char mat[3][3]){
    int empate = 1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(mat[i][j]=='-')
                empate = 0;
        }
    }
    return empate;
}


void jogar(char mat[3][3]){
    int fim = 0, vez_jogador = 1, escolha_j1, linha_inserir, coluna_inserir, pos_livre, vencedor=0;
    char char_j1, char_j2;
    
    do{
        printf("j1. O ou X:\n1-O\t2-X\n");
        scanf("%d",&escolha_j1);
    }while(escolha_j1 != 1 && escolha_j1 != 2);
    
    if(escolha_j1 == 1){
        char_j1 = 'O';
        char_j2 = 'X';
    } else {
        char_j1 = 'X';
        char_j2 = 'O';
    }
    
    while(!fim){
        valida_posicoes(mat,1,&linha_inserir,&coluna_inserir);
        mat[linha_inserir-1][coluna_inserir-1] = char_j1;
        imprime(mat);
        
        verifica_vencedor(mat,&fim);
        
        if(fim){
            vencedor = 1;
            break;
        }
        
        fim = verifica_empate(mat);
        if(fim) break;
        
        valida_posicoes(mat,2,&linha_inserir,&coluna_inserir);
        mat[linha_inserir-1][coluna_inserir-1] = char_j2;
        imprime(mat);
        
        verifica_vencedor(mat,&fim);
        if(fim) vencedor = 2;
        
        fim = verifica_empate(mat);
    }
    
    vencedor ? printf("\n\nvencedor jogador %d",vencedor) : printf("\n\nempate");
}


int main(){
    char tabuleiro[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            tabuleiro[i][j]='-';
        }
    }
    jogar(tabuleiro);
    return 0;
}
