#include <stdio.h>
#include <stdlib.h>
#include "circular.h"
#define SIZE 5

int main(){
    Tcl *circular = create_circular(), *search;
    int elem; 
    int i;

    for(i=1; i<= SIZE; i++){
        printf("Insira o elemento %d da lista circular: ", i);
        scanf("%d", &elem);
        circular = insert_circular (circular , elem);
    }

    search = search_circular (circular, 10);
    if (search){
        printf("Elemento encotrado\n\n");
    } else{
        printf("Elemento nao encontrado\n\n");
    }


    print_circular(circular);


    clear_circular(circular);

    return 0;


}