/*Questão 4 (2,5 pontos) Leve em consideração, também, a existência de um tipo abstrato fila de
números inteiros, cuja a interface é definida no arquivo list.h da seguinte forma:

*/

#include <stdlib.h>
#include "q4.h"

int main(){
    printf("Bem vindo, este programa sorteia 6 numeros diferentes de uma lista que vai de 1 a 60.\n");
    Tlist *list = create ();

    list = mega_sena ();
    printf(">>Numeros sorteados:\n");
    print_list (list);

    printf("\nFim de programa!\n\n");

    clear(list);

    return 0;
}