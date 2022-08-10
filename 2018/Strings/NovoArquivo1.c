#include <stdio.h>
#include <conio.h>
#include <string.h>
main()
{
char nm1[20], nm2[20], nm3[20], cont;
        char alf[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','x','w','y','z'};
        char alfb[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','X','W','Y','Z'};
        printf("Nome 1: ");
        scanf("%s", &nm1);
        printf("Nome 2: ");
        scanf("%s", &nm2);
        printf("Nome 3: ");
        scanf("%s", &nm3);

        for(cont = 0; cont < 26; cont++){
            if(nm1[0] == alf[cont]|| nm1[0] == alfb[cont])
                printf("- %s", nm1);
            if(nm2[0] == alf[cont]|| nm2[0] == alfb[cont])
                printf("- %s", nm2);
            if(nm3[0] == alf[cont]|| nm3[0] == alfb[cont])
                printf("- %s", nm3);    
        }
 }       
