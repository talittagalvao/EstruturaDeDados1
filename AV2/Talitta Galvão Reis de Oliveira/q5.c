/*
void imprime_invertido (Tlist *l)
*/
#include <stdio.h>
#include <stdlib.h>
#include "q5.h"

int main(){
    printf("Bem vindo, esse programa imprime de forma invertida uma lista.\n\n");
    Tlist *list = create(); printf(">>Lista criada\n");
    int elem; 

    for (int i = 1; i <= 5; i++) {
        printf ("Insira o valor de info para o elemento da lista: ");
        scanf ("%d", &elem);
        list = ordered_insert (list, elem);
    }
    printf("\n\n>>Imprimindo lista: \n");
    print_list(list);

    printf("\n\n>>Imprimindo lista invertida: \n");
    imprime_invertido (list);

    printf("\nFim de programa!\n\n");

    clear(list);
    return 0;
}