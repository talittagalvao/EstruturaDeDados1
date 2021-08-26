#include <stdio.h>
#include "final_ex1.h"
#include  <math.h>
#include <string.h>
#include <stdlib.h>

void max_min (int *v, int N, int *max, int *min){
    
    *min = v[0];
    *max = v[0];

    for (int i = 1; i < N; i++){

        if(&v[i] > max){
            *max = v[i];
        }
        if(&v[i] < min){
            *min = v[i];
        }
    }   
}

int main (){

    int N = 10;
    int v[N];

    printf ("Bem vindo ao programa que analisa valores de um vetor.\nPor favor, insira valores inteiros:\n\n");

    for (int i = 0; i < N; i++){
        printf("Digite o valor %d do vetor de %d posicoes:\n", (i+1), N);
        scanf("%d", &v[i]);
    }

    printf ("\nVetor digitado: { ");
    for (int i = 0; i < N; i++){
        printf("[%d] ", v[i]);
    }
    printf ("}");

    int max;
    int min;

    max_min (v, N, &max, &min);

    printf("\n\n\t------> O valor maximo: %d\n\t------> O valor minimo: %d\n\n", max, min);

    goodbye_greeting();
    

    return 0;

}