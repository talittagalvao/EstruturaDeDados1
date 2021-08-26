/*
Questão 3 (2,0 pontos) Considerando as seguintes declarações de lista encadeada: 
Escreva a função para receba uma lista linear e retorne uma lista circular, preservando a lista de
entrada. O protótipo da função deve ser o seguinte: 
TLC *gera_circular (Tlista *l);
*/

#include <stdlib.h>
#include "q3.h"
#define SIZE 5

int main(){
    printf("Bem vindo, recebe uma lista e transforma em uma lista circular.\n\n");

    Tlist *list = create(); printf(">>Lista criada\n");
    Tcl *circular = create_circular(); printf(">>Lista circular criada\n\n");
    int value;

    for(int i = 1; i <= SIZE; i++){
        printf("Insira um elemento: ");
        scanf("%d", &value);
        list = ordered_insert(list,value);
        print_list(list);
        printf("\n-------------\n\n");
    }
    
    circular = gera_circular (list);

    printf("Lista criada:\n");
    print_list(list);

    printf("Lista circular criada:\n");
    print_circular(circular);

    clear(list);
    clear_circular(circular);

    printf("\nFim de programa!\n\n");

    return 0;
}
