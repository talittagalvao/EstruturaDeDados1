#include <stdio.h>
#include "final_ex1.h"
#include  <math.h>
#include <string.h>
#include <stdlib.h>

long multiplication(int a, int b){
    if(a == 0 || b == 0){
        return 0;
    } else if (b>0){
        return multiplication(a, b-1) + a;
    } else {
        return multiplication(a, b+1) - a;
    }
}

int main(){

    int x, y;
    
    printf ("Bem vindo ao programa que realiza multiplicacao entre inteiros:.\n\n");

    printf(">Digite o primeiro valor inteiro: ");
    scanf("%d", &x);
    printf(">Digite o segundo valor inteiro: ");
    scanf("%d", &y);
    printf("\n>>>>> Resultado: %d x %d = %ld <<<<<", x, y, multiplication(x, y));
    
    goodbye_greeting();

    return 0;
}
