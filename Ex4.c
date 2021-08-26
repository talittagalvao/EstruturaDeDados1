#include <stdio.h>
#include "final_ex1.h"
#include  <math.h>
#include <string.h>
#include <stdlib.h>
#define VECTOR_SIZE 8

int bin_search(int *v, int begin, int end, int value){
    int central = (begin + end) / 2; //determinando elemento central

    if(begin > end){ //elemento não está presente na lista
        return -1;
    } else if (value == v[central]){
        return central;
    } else if (value < v[central]){
       return bin_search(v, begin, central-1, value); //procura o elemento do primeiro indice até o meio - 1
    } else {
       return bin_search(v, central+1, end, value); //procura o elemento do meio + 1 até o último indice
    }
}

int main(){
    
    //tamanho do vetor e declaração de valores
    int request;
    int vector[VECTOR_SIZE] = {5, 12, 25, 30, 46, 83, 89, 90};
    int answer;

    printf ("Bem vindo ao programa que localiza um elemento em um vetor previamente inserido.\n\n");
    printf("Digite o elemento procurado: ");
    scanf("%d", &request);
    answer = bin_search(vector, 0, VECTOR_SIZE-1, request);

    if (answer == -1){
        printf("Elemento nao esta presente na lista!\n"); 
        printf_vector (vector, VECTOR_SIZE);
        
    } else{
        printf("Posicao do elemento digitado >>>> %d\n", answer+1);
        printf_vector (vector, VECTOR_SIZE);
    }

    goodbye_greeting();

    return 0;
    
}