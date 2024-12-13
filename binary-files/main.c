/*

o arquivo binary.dat é um arquivo binário (0 e 1), o seu conteúdo é exibido em hexadecimal usando um editor hexadecimal para facilitar a visualização
o conteúdo dentro dele em hexadecimal é: 17 FD 40 70 4C 7B. ou seja, 6 bytes, pois cada dígito hexadecimal ocupa 4 bits, como são 12 dígitos, 12 * 4 = 48 / 8 = 6
o conteúdo do binário é o mesmo do arquivo txt, só que ele está representado em binário
para o SO os 2 arquivos são binários. só que o txt foi criado como texto e o binário com dados binários
a extensão do arquivo pouco importa, serve apenas para informar que tipo de arquivo é

*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *file = fopen("write-binary.dat", "wb"); //"w" abrir arquivo para escrita. "r" abrir o arquivo para leitura, "b" abrir em formato binário

    //escrevendo dados no arquivo binário
    
    int teste = 34;
    fwrite(&teste, sizeof(int), 1, file);
    //parametros: o endereço de memória do que se quer escrever, quantos bytes escrever, quantas vezes escrever o dado, o arquivo que se quer gravar


    //ao rodar e abrir o binário no editor hexadecimal, foi escrito "22 00 00 00". os zeros é porque um inteiro tem 4 bytes então foram preenchidos com zeros a direita devido ao big endian
    // que em decimal é 34

    char letra = 's';
    fwrite(&letra, sizeof(char), 1, file);
    //ao rodar e abrir o binário no editor hexadecimal, foi adicionado "73". o tipo char ocupa 1 byte, por isso não foi adicionado zeros
    // que em decimal é 115. Na tabela ascii o 115 simboliza o caractere 's'

    double d = 456;
    fwrite(&d, sizeof(double), 1, file);

    fclose(file);

    //lendo arquivo binário
    FILE *file2 = fopen("write-binary.dat", "rb");

    int ler_inteiro;
    fread(&ler_inteiro, sizeof(int), 1, file2); //o 3° parametro é a qtd de dados que se deseja ler. no caso 1 inteiro que é 4 bytes
    printf("\n\n %d \n\n", ler_inteiro); //34

    char ler_char;
    fread(&ler_char, sizeof(char), 1, file2);
    printf("\n\n %c \n\n", ler_char); //s

    double ler_double;
    fread(&ler_double, sizeof(double), 1, file2);
    printf("\n\n %lf \n\n", ler_double);//456

    //na leitura é preciso ler na ordem em que estão os dados
    //nesse exemplo aqui, depois de ler o inteiro com a função fread(), o ponteiro do arquivo é movido 4 bytes pra frente (pois inteiro = 4 bytes), 
    //para ler apartir do 5° byte na próxima leitura e assim por diante

    //, se tentasse ler o double primeiro não ia ler corretamente 
    //pois ia pegar os 8 primeiros bytes e ler eles como double, isso ia gerar um valor estranho 

    //* como os dados são binários dá pra ler os dados como qualquer tipo possível, pois tudo é 0s e 1s
    //então poderia ler o inteiro como um char por exemplo pq os dados estão em binário, não tem tipo, dá pra fazer qualquer coisa
    // só que o resultado será completamente diferente dependendo da forma que se lê

    fclose(file2);




    //lendo arquivo binary.dat
    FILE *file3 = fopen("binary.dat", "rb");

    int ler_teste;
    fread(&ler_teste, sizeof(int), 1, file3);
    printf("\n\n %d \n\n", ler_teste); //17

    int ler_teste2;
    fread(&ler_teste2, sizeof(int), 1, file3);
    printf("\n\n %d \n\n", ler_teste2); //253

    return 0;
}
