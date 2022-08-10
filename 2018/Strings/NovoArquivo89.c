/*#include <stdio.h>
main(int argc,char *argv[]) {
int i;
char aux;
char x[] = "abcdef";
for (i = 0; i < 5; i++) {
aux = x;
x = x[i + 1];
x[i + 1] = aux;
}
for (i = 0; i < 6; i++)
printf("\n X = %c",x[i]);


}*/
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
int i;
char aux; 
char x[] = "ABCDEF";
for (i = 0; i < 5; i++) {
aux = x[i];
x[i] = x[i + 1];
x[i + 1] = aux;
}
for (i = 0; i < 6; i++)
printf("\n X = %c\n\n", x[i]);

system("pause");
return 0;
}
